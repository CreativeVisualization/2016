#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(215, 220, 225); //背景色を黒に
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2); //画面の中心に
    velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); //ランダムな速度で
    ofLight light;
    light.enable();
    
    light.setSpotlight();
    
    light.setPosition(-50, 50, 50);
    //環境反射光
    light.setAmbientColor(ofFloatColor(0.5,0.5,0.5,1.0));
    //拡散反射光
    light.setDiffuseColor(ofFloatColor(0.5,0.5,0.5));
    //鏡面反射光
    light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity; //速度から位置を更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    //int i;
    
    //for (i=0; i>6; i++) {
    
    ofSetColor(128, 128, 128); //円の色
    ofDrawBox(location, 40); //半径40の円を描画
    
    //画面の端でバウンドするように
    if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location.y < 0 || location.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity.y *= -1; //横向きの速度を反転(バウンド)
    }
    //}
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
