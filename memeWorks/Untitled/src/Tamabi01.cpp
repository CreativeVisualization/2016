#include "Tamabi01.hpp"



Tamabi01::Tamabi01( string filePath ){
    
    loadCsvToMemes(filePath);
    
    //対象からの距離の初期値を指定
    focus = memes[index].zone_focus;
    next_focus = memes[index+1].zone_focus;
    calm = memes[index].zone_calm;
    next_calm = memes[index+1].zone_calm;
    posture = memes[index].zone_posture;
    next_posture = memes[index+1].zone_posture;
    
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(64);
    
}




//--------------------------------------------------------------
void Tamabi01::setup(){
    
}

//--------------------------------------------------------------
void Tamabi01::update(){
    
}

//--------------------------------------------------------------
void Tamabi01::draw(){
    
    morph_focus = ofLerp(focus,next_focus,percent);
    morph_calm = ofLerp(calm,next_calm,percent);
    morph_posture = ofLerp(posture,next_posture,percent);
    percent += 0.02;
    
    float background = 0;
    float basecolor = 100;
    float basealph = 10;
    float baser = 3;
    float margin = 70;
    step ++;
    if(step>ofGetHeight()){
        step = 0;
    }
    
    //BaceBlack
    ofSetColor(background,50);
    ofDrawRectangle(0, ofGetHeight()-100, ofGetWidth(), ofGetHeight());
    
    //string NAME
    ofSetColor(255,morph_focus);
    ofDrawBitmapString(memes[2].user_id, ofGetWidth()/2-25, ofGetHeight()-50);
    
    //    //string DATE
    //    ofSetColor(255);
    //    ofDrawBitmapString(memes[index].zone_date, ofGetWidth()/2, ofGetHeight()-50);
    
    //strinf focus//
    ofSetColor(morph_focus/2,basecolor/2,basecolor/2,morph_focus + basecolor);
    ofDrawBitmapString(morph_focus, ofGetWidth()/2, ofGetHeight()-25);
    
    //strinf calm//
    ofSetColor(basecolor/2,morph_calm/2,basecolor/2,morph_calm + basecolor);
    ofDrawBitmapString(morph_calm, ofGetWidth()/2-margin-2, ofGetHeight()-25);
    
    //strinf posture//
    ofSetColor(basecolor/2,basecolor/2,morph_posture/2,morph_posture + basecolor);
    ofDrawBitmapString(morph_posture, ofGetWidth()/2+margin-20,  ofGetHeight()-25);
    
    
    //focus//
    ofSetColor(morph_focus,basecolor,basecolor,morph_focus / basealph);
    ofDrawCircle(ofGetWidth()/2,step,morph_focus/baser);
    
    //calm//
    ofSetColor(basecolor,morph_calm,basecolor, morph_calm  / basealph);
    ofDrawCircle(ofGetWidth()/2-margin,step,morph_calm/baser);
    
    //posture//
    ofSetColor(basecolor,basecolor,morph_posture, morph_posture / basealph);
    ofDrawCircle(ofGetWidth()/2+margin,step,morph_posture/baser);
    
    
    //モーフィングの割合が1になった時の処理
    if (percent >=1.0) {
        //noLoop();
        //表示するデータのインデックスを進める
        index += 1;
        
        //配列の最後に到達したら停止
        if (index == memes.size() - 1) {
            index = 0;
            ofSetColor(0,100);
            ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
            
        } else {
            //表示するデータと、次に表示するデータを更新
            focus = memes[index].zone_focus;
            next_focus = memes[index+1].zone_focus;
            
            calm = memes[index].zone_calm;
            next_calm = memes[index+1].zone_calm;
            
            posture = memes[index].zone_posture;
            next_posture = memes[index+1].zone_posture;
        }
        
        //モーフィングの割合を初期化
        percent = 0;
    }
}


////--------------------------------------------------------------
void Tamabi01::loadCsvToMemes(string filePath){
    ofFile file(filePath);
    
    if(!file.exists()){
        ofLogError("The file " + filePath + " is missing");
    }
    
    ofBuffer buffer(file);
    
    //データをVector(配列)に読み込む
    //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        vector<string> data = ofSplitString(line, ",");
        if (data.size()>=6) {
            
            Meme meme;
            meme.user_id = data[0];
            meme.zone_date = data[1];
            meme.zone_focus = ofToFloat(data[3]);
            meme.zone_calm = ofToFloat(data[4]);
            meme.zone_posture = ofToFloat(data[5]);
            memes.push_back(meme);
            
            if(it == buffer.getLines().begin()){
                max_focus = min_focus = meme.zone_focus;
                max_calm = min_calm = meme.zone_calm;
                max_posture  = min_posture = meme.zone_posture;
            }
            else{
                //データをひとつずつ比較しながら最小値最大値を調べる
                max_focus = (meme.zone_focus > max_focus) ? meme.zone_focus : max_focus;
                min_focus = (meme.zone_focus < min_focus) ? meme.zone_focus : min_focus;
                max_calm = (meme.zone_calm > max_calm) ? meme.zone_calm : max_calm;
                min_calm = (meme.zone_calm < min_calm) ? meme.zone_calm : min_calm;
                max_posture = (meme.zone_posture > max_posture) ? meme.zone_posture : max_posture;
                min_posture = (meme.zone_posture < min_posture) ? meme.zone_posture : min_posture;
                
            }
            
        }
    }
}