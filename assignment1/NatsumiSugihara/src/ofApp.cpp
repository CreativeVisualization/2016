#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(20); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
    ofEnableSmoothing();
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2); //画面の中心に
    velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); //ランダムな速度で
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity; //速度から位置を更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    //算した位置に円を描画
    ofSetColor(255); //円の色
    ofDrawCircle(location, 300); //半径40の円を描画
    
    //画面の端でバウンドするように
    if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location.y < 0 || location.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity.y *= -1; //横向きの速度を反転(バウンド)
    }
    
    for (int i=0; i<n; i++) {
        float x = ofRandom(1024);
        float y = ofRandom(768);
        
        float r = ofRandom(0,20);
        float g = ofRandom(0,255);
        float b = ofRandom(220,255);
        float w = ofRandom(5,50);
        
        ofSetColor(r,g,b,70);
        ofDrawCircle(x, y, w, w);
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
    location + 1;
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
