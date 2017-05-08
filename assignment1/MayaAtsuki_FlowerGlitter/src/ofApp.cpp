#include "ofApp.h"
ofVec3f flowerPos[] = {
    ofVec3f(64, 326, 0.617474),
    ofVec3f(142, 327, 0.394911),
    ofVec3f(450, 340, 0.445911),
    ofVec3f(547, 342, 0.403244),
    ofVec3f(591, 382, 0.614321),
    ofVec3f(583, 566, 0.724945),
    ofVec3f(379, 162, 0.493335),
    ofVec3f(395, 112, 0.23),
    ofVec3f(438, 126, 0.310455),
    ofVec3f(276, 96, 0.200073),
    ofVec3f(198, 131, 0.589790),
    ofVec3f(315, 85, 0.376922),
    ofVec3f(469, 254, 0.379391),
    ofVec3f(429, 274, 0.278453),
    ofVec3f(286, 568, 0.378553),
    ofVec3f(199, 535, 0.209758),
    ofVec3f(201, 35, 0.306094),
    ofVec3f(265, 147, 0.320007),
    ofVec3f(100, 418, 0.375053),
    ofVec3f(97, 252, 0.265486),
    ofVec3f(23, 253, 0.311530),
    ofVec3f(19, 454, 0.712467),
    ofVec3f(304, 342, 0.258887),
    ofVec3f(404, 395, 0.394778),
    ofVec3f(367, 309, 0.301653)
};
int num = sizeof(flowerPos)/sizeof(flowerPos[0]);

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    //    ofToggleFullscreen();
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
    ofSetCircleResolution(100);
    ofSetLineWidth(5);
    
    
    //位置と速度を初期化
    location = ofVec2f(311, 444); //最初の花の位置
    velocity = ofVec2f(6.5, 5); //ランダムな速度で
    
    //glitter
    ofDirectory dir;
    dir.open("glitter");
    dir.listDir();
    vector<ofFile> fileNamebuffer = dir.getFiles();
    for(int i=0; i<fileNamebuffer.size(); i++){
        ofImage img;
        img.load("glitter/" + fileNamebuffer.at(i).getFileName());
        glitter.push_back(img);
    }
    count = 0;
    
    //background
    background.load("flower26882.png");
    
    //sound
    sound.load("shine1.mp3");
    
    //font
    font.load("PoiretOne-Regular.ttf", 28);
    isStart = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if (isStart) {
        location += velocity; //速度から位置を更新
        
        //glitter
        for(int i=0; i<glitterNum; i++){
            gset[i].pos += gset[i].speed;
        }
        if(ofGetFrameNum()%2 == 0){
            
            GlitterSet gs;
            gs.pos = ofVec2f(location.x-30, location.y-30);
            ofVec2f v = pvec - location;
            gs.speed = ofVec2f( v.x*ofRandom(.2, .55) , v.y*ofRandom(.2, .55) );
            gs.size = ofRandom(2, 75);
            gs.number = ofRandom(glitter.size());
            gset[count] = gs;
            count = (count+1)%glitterNum;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //background
    ofSetColor(255, 255);
    background.draw(-30, 0, background.getWidth()*ofGetHeight()/background.getHeight(), ofGetHeight());
    
    //花
    float size = 1.;
    ofColor c, fc = ofColor(255, 255);
    for(int i=0; i<num; i++){
        if( ofDist(flowerPos[i].x, flowerPos[i].y, location.x, location.y) <  100*size ){
            c = ofColor(255, ofRandom(255), ofRandom(255), 255);
            fc.setHsb(ofRandom(255), 50, 255, 255);
            //sound
            if(!sound.isPlaying()) sound.play();
        }else{
            c = ofColor(255, 255);
        }
        drawFlower(flowerPos[i], flowerPos[i].z, c, false);
    }
    
    //glitter
    for (int i=0; i<glitterNum; i++){
        ofSetColor(ofColor::fromHsb(ofRandom(255), 80, 255));
        glitter[gset[i].number].draw(gset[i].pos.x, gset[i].pos.y, gset[i].size, gset[i].size);
    }
    
    drawFlower(location, size, fc, isStart);
    
    
    //画面の端でバウンドするように
    if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location.y < 0 || location.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity.y *= -1; //横向きの速度を反転(バウンド)
    }
    
    //font
    if(!isStart){
        ofSetColor(255, ofGetFrameNum()*5%255);
        font.drawString("Press the space key to start", ofGetWidth()-440, 70);
    }
    
    pvec.set(location);
}
//--------------------------------------------------------------
void ofApp::drawFlower(ofVec2f pos, float size, ofColor color, bool isRotate){
    ofPushStyle();
    int rad = 40*size;
    for(int i=0; i<5; i++){
        float t;
        if(isRotate){
            t = ofDegToRad(ofGetFrameNum()*7 + 72*i);
        }else{
            t = ofDegToRad(72*i);
        }
        //花びら
        ofSetColor(color);
        ofNoFill();
        ofDrawCircle(pos.x+rad*cos(t), pos.y+ rad*sin(t), 22*size);
        ofFill();
        ofDrawCircle(pos.x+rad*cos(t), pos.y+ rad*sin(t), 22*size);
        //花
        ofDrawCircle(pos, 33*size);
        ofSetColor(0, 255);
        ofNoFill();
        ofDrawCircle(pos, 18*size);
    }
    ofPopStyle();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ')isStart = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    printf("ofVec3f(%d, %d, %f),\n", x, y, ofRandom(.25, .8));
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
