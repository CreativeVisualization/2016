#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(255,255,0); //背景色を黒に
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/5, ofGetHeight()/2); //画面の中心に
    velocity = ofVec2f(ofRandom(-10, 80), ofRandom(-10, 100)); //ランダムな速度で
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity; //速度から位置を更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    ofSetColor(50, 50, 255); //円の色
    ofDrawCircle(230,150,100); //半径40の円を描画
    
    ofDrawLine(900, 500, 500, 500);
    ofDrawEllipse(500, 500, 50, 200);
    ofDrawRectangle(600, 60, 300, 300);
    ofDrawRectRounded(400, 550, 50, 100, 20);
    
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
