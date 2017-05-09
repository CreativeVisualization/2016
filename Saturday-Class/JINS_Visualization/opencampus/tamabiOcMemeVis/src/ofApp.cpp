#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //dataフォルダに配置したcsvファイルの名前
    string filePath = "AllUser_ST.csv";
    
    //
    data.setFilePath(filePath);
    data.start();
    
    //fboの初期化
    fboLong.allocate(2560, 200);
    fboLong.begin();
    ofClear(0,0,0,255);
    fboLong.end();
    
    //フォントのロード
    ofTrueTypeFont::setGlobalDpi(400);
    fontXS.load("Bauhaus-Bold.otf",0.5,true,true,true);
    fontS.load("AxisLatinCondPro-UL.otf",4,true,true,true);
    fontM.load("AxisLatinCondPro-UL.otf",20,true,true,true);
    
    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(data.isLoadFinished && !isVboBarChartInit){
        
        //以下はデータのロード完了時に1度だけ行う処理
        
        //VBOの頂点をメイクする
        makeVboBarchart();
        
        //視覚化する時刻の初期化
        gtime.setup(data.min_stime-120, data.max_stime+120, 2.0, 5, 17);
        
        //グリッドの初期化
        grid.setup(gtime, 0.5, data.users.size(), 10, 60.0, 1.0, data.max_eyeMoveRout, 90); //1min = 0.5px, //1user = 10px
        for(int i = 0; i < data.users.size(); i++){
            grid.addUser(data.users[i].user_id);
        }
        grid.setFonts(fontS,fontXS);
        
        //カメラの初期化
        camerasSetup();
        
    }
    
    if(isVboBarChartInit){
        
        //以下は描画開始後に繰り返し行う処理
        
        //表示時刻を進行させる
        gtime.update();
        
        //カメラ位置のアップデート
        camerasUpdate();
        
        //一定時間でカメラ切り替え
        if(ofGetFrameNum() % (600) ==0){
            if(data.isLoadFinished){
                
                selectedCamera ++;
                if(selectedCamera >= movingCameras.size()){
                    selectedCamera = 0;
                }
            }
        }        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    fontM.drawString("Creative Visualization Workshop", 40,120);
    fontS.drawString("Data: \"eyeMoveBigHorizontal\", \"focus\", \"sleepy\", by JINS MEME", 50,160);
    fontS.drawString("Period: 5/17 07:00 to 5/30 : 15:40", 50,190);
    fontS.drawString("Amount: " + ofToString(vertsCount/2), 50,220);
    

    if(isVboBarChartInit){
        
        //引きの映像をFBOに描画する（開始）
        fboLong.begin();
        ofBackground(0);
        camLong.begin();
        
        //バーチャート全体のVBOをレンダリング
        vboBarChart.drawElements(GL_LINES,vertsCount);
        
        //XZ平面のグリッドを描く
        grid.drawSimple();
        
        //現在時刻のラインを描く
        grid.drawCurrentLine(gtime.current,false);
        
        camLong.end();
        fboLong.end();
        //引きの映像をFBOに描画する（ここまで）
        
        ofEnableDepthTest();
        
        //寄りの映像を描画する（開始）
        cam.begin();
        
        //現在時刻に該当するデータの視覚化
        for(int i=0; i< data.users.size(); i++){
            int currentSerial = gtime.current;
            
            float barHeight,posX, posZ;
            //表示しようとする時刻のデータが存在しているかのチェック
            map<int, Meme>::iterator it;
            it = data.users[i].memesm.find(currentSerial);
            if(it != data.users[i].memesm.end()){
                //存在していて、かつバーの高さが0以上のものだけofDrawBoxする
                barHeight = data.users[i].memesm[currentSerial].bar_height;
                posX = data.users[i].memesm[currentSerial].bar_pos.x;
                posZ = data.users[i].memesm[currentSerial].bar_pos.z;
                if(barHeight > 0){
                    
                    ofPushStyle();
                    ofSetColor(255,200);
                    ofDrawBox(posX, barHeight/2, posZ, 0.5, barHeight, 0.5);
                    ofDrawBitmapString(data.users[i].memesm[currentSerial].eyeMoveRout, posX, barHeight+1, posZ);
                    ofPopStyle();
                }
            }
        }
        
        //バーチャート全体のVBOをレンダリング
        vboBarChart.drawElements(GL_LINES,vertsCount);
        
        
        //XZ平面のグリッドを描く
        grid.draw(gtime.current);
        //現在時刻のラインを描く
        grid.drawCurrentLine(gtime.current,true);
        
        cam.end();
        //寄りの映像を描画する（ここまで）
        
        ofDisableDepthTest();
        
        //引きのFBOを画面下部に配置
        fboLong.draw(0,ofGetWindowHeight() - fboLong.getHeight());
        
        //引きの映像と寄りの映像の境界を描画
        ofPushStyle();
        ofSetColor(128);
        ofSetLineWidth(1);
        ofDrawLine(0, ofGetWindowHeight() - fboLong.getHeight(), ofGetWidth(), ofGetWindowHeight() - fboLong.getHeight() );
        ofPopStyle();
        
        
        
    }
    else{
        //データのロード中の描画
        ofDrawBitmapString("LOADING...", 10, 10);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //fキーを押したらフルスクリーンと通常を切り替える
    if(key=='f'){
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    //何かキーを押したらカメラ切り替え
    if(data.isLoadFinished){
        
        selectedCamera ++;
        if(selectedCamera >= movingCameras.size()){
            selectedCamera = 0;
        }
        
        
    }
    
    
}
//バーチャートのVBOを初期化するメソッド-------------------------------------
void ofApp::makeVboBarchart(){

    
    //頂点数のカウンタ
    vertsCount = 0;
    
    if(data.isLoadFinished){
        
        //VBOで使う頂点、カラー、インデックスのメモリを確保
        verts = (ofVec3f*)malloc(sizeof(ofVec3f)*data.users.size()*( data.max_stime - data.min_stime +1));
        vertsColor = (ofFloatColor*)malloc(sizeof(ofFloatColor)*data.users.size()*( data.max_stime - data.min_stime +1));
        vertsIndex = (ofIndexType*)malloc(sizeof(ofIndexType)*data.users.size()*( data.max_stime - data.min_stime +1));
        
        //ある時刻のデータが存在するかどうか
        bool isMemeExist = false;
        
        for(int i=0; i< data.users.size(); i++){
            
            for(int j = data.min_stime; j <= data.max_stime; j++){
                
                //表示しようとする時刻のデータが存在しているかのチェック
                map<int, Meme>::iterator it;
                it = data.users[i].memesm.find(j);
                if(it == data.users[i].memesm.end()){
                    isMemeExist = false;
                }
                else{
                    isMemeExist = true;
                }
                
                if(isMemeExist){
                    
                    //データが存在していればデータを取得
                    Meme meme = data.users[i].memesm[j];
                    
                    //map関数でデータを高さに適した値に変換
                    float barHeight = ofMap(meme.eyeMoveRout, data.min_eyeMoveRout, data.max_eyeMoveRout, 0, 90);
                    
                    //バーの高さが0より大きい場合だけ頂点を登録する
                    if(barHeight > 0){
                        
                        float posX = j * 0.5;
                        float posZ = (i-7)*10;
                        
                        //map関数でデータを色さに適した値に変換
                        float boxColorR = ofMap(meme.focus, data.min_focus, data.max_focus, 0, 255);
                        float boxColorB = ofMap(meme.sleepy, data.min_sleepy, data.max_sleepy, 0, 255);
                        if( boxColorR ==0 && boxColorB ==0){
                            boxColorR = 255;
                            boxColorB = 255;
                        }
                        ofColor c = ofColor(boxColorR, 0, boxColorB, 200);
                        
                        verts[vertsCount] = ofVec3f(posX, 0, posZ);
                        vertsColor[vertsCount] = c;
                        vertsIndex[vertsCount] = vertsCount;
                        vertsCount ++;
                        
                        verts[vertsCount] = ofVec3f(posX, barHeight, posZ);
                        vertsColor[vertsCount] = c;
                        vertsIndex[vertsCount] = vertsCount;
                        vertsCount ++;
                        
                        
                        data.users[i].memesm[j].bar_pos = ofVec3f(posX, 0, posZ);
                        
                    }
                    
                    data.users[i].memesm[j].bar_height = barHeight;
                }
            }
        }
        vboBarChart.setVertexData(&verts[0], vertsCount, GL_DYNAMIC_DRAW);
        vboBarChart.setColorData (&vertsColor[0], vertsCount, GL_DYNAMIC_DRAW);
        vboBarChart.setIndexData (&vertsIndex[0], vertsCount, GL_STATIC_DRAW);
        
    }
    
    
    isVboBarChartInit = true;
}

//カメラを初期化するメソッド-------------------------------------
void ofApp::camerasSetup(){
    
    //引きのカメラの設定
    ofVec3f camLongPosition = ofVec3f((grid.cornerBegin.x + grid.cornerEnd.x)/2, camLongY, camLongZ);
    camLong.setPosition(camLongPosition);
    camLong.lookAt(ofVec3f((grid.cornerBegin.x + grid.cornerEnd.x)/2,0,0));
    camLong.setFov(10);
    camLong.setFarClip(10000);
    
    //３つの寄りのカメラの位置を設定（注視点からの相対位置で設定する）
    ofVec3f camRelativePosition0 = ofVec3f(-50, 60, 150);
    ofVec3f camRelativePosition1 = camRelativePosition0.getNormalized() * 600;
    ofVec3f camRelativePosition2 = ofVec3f(-90, 45, 55);
    
    cameraRelativePosition.push_back(camRelativePosition0);
    cameraRelativePosition.push_back(camRelativePosition1);
    cameraRelativePosition.push_back(camRelativePosition2);
    
    //上の設定を配置位置に反映させる
    for(int i = 0; i < cameraRelativePosition.size(); i++){
        
        ofCamera movingCam;
        ofVec3f relativePosition = cameraRelativePosition[i];
        movingCam.setPosition( ofVec3f(grid.cornerBegin.x , 0, 0) + relativePosition);
        movingCam.lookAt(ofVec3f(grid.cornerBegin.x , 0, 0));
        movingCameras.push_back(movingCam);
        
    }
    
    //初期の寄りのカメラの位置を設定
    cam.setPosition(movingCameras[0].getPosition());

    
}

//カメラを位置を更新するメソッド-------------------------------------
void ofApp::camerasUpdate(){
    
    ofVec3f lookAt;
    
    //３つの寄りのカメラの位置更新
    for(int i = 0; i < movingCameras.size(); i++){
        lookAt = ofVec3f(grid.getCurrentX(gtime.current)-60, 5, 0);
        ofVec3f relativePosition = cameraRelativePosition[i];
        movingCameras[i].setPosition(lookAt + relativePosition);
    }
    
    cam.setPosition(movingCameras[selectedCamera].getPosition());
    cam.lookAt(lookAt);
    
    //引きのカメラの位置更新
    ofVec3f relativePosition = cameraRelativePosition[0].getNormalized() *6400;
    camLong.setPosition(lookAt + relativePosition);
    camLong.lookAt(lookAt);
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

