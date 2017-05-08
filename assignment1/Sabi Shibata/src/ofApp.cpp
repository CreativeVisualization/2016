#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(255); //背景色を黒に
    ofSetBackgroundAuto(false);
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2); //画面の中心に
    velocity = ofVec2f(ofRandom(-10, 30), ofRandom(-10, 30)); //ランダムな速度で
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity; //速度から位置を更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    ofSetColor(255, 255, 255); //円の色
    ofDrawCircle(location, 10); //半径40の円を描画
    
    ofSetColor(199, 197, 190,20); //円の色
    ofDrawCircle(location+10, 83); //半径40の円を描画
    
    ofSetColor(198, 164, 115,10); //円の色
    ofDrawCircle(location/2 -10, 85); //半径40の円を描画
    
    ofSetColor(197, 130, 135,20); //円の色
    ofDrawCircle(location/2 -2, 800); //半径40の円を描画
    
    ofSetColor(194, 100, 115,10); //円の色
    ofDrawCircle(location/3 -10, 900); //半径40の円を描画
    
    ofSetColor(190, 100, 150,10); //円の色
    ofDrawCircle(location/2 -5, 208); //半径40の円を描画
    
    ofSetColor(180, 160, 150,10); //円の色
    ofDrawCircle(location/4 -7, 102); //半径40の円を描画
    
    ofSetColor(194, 64, 5,10); //円の色
    ofDrawCircle(location/2 +10, 8); //半径40の円を描画
    
    ///float radius = 200.0;
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ///for(int i = 0; i< 100; i++){
    ///    ofPoint pos;
    ///    pos.x = ofRandom(-radius, radius);
    ///    pos.y = ofRandom(-radius, radius);
        
    ///    float dist = ofDist(pos.x, pos.y, 0, 0);
        
    ///    if(dist < radius){
    ///        ofSetColor(0, 127, 255);
    ///        ofRect(pos.x, pos.y,1,1);
    ///    }
    ///}
    
    
    
    //画面の端でバウンドするように
    if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location.y < 0 || location.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity.y *= -1; //横向きの速度を反転(バウンド)
    }
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
