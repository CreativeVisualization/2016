#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < location.size(); i++) {
        location[i] += velocity[i]; //速度から位置を更新
    }
    while (location.size() > 1000) {
        location.erase(location.begin());
        velocity.erase(velocity.begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 30);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < location.size(); i++) {
        //計算した位置に円を描画
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofSetColor(31, 255, 255, 127); //円の色
        ofDrawCircle(location[i], 5); //半径40の円を描画
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        
        //画面の端でバウンドするように
        if (location[i].x < 0 || location[i].x > ofGetWidth()) { //画面の左右ではみ出したら
            velocity[i].x *= -1; //横向きの速度を反転(バウンド)
        }
        if (location[i].y < 0 || location[i].y > ofGetHeight()) { //画面の左右ではみ出したら
            velocity[i].y *= -1; //横向きの速度を反転(バウンド)
        }
    }
    ofSetColor(255);
    ofDrawBitmapStringHighlight("object num = " + ofToString(location.size()), 20, 20);
    ofDrawBitmapStringHighlight("framerate = " + ofToString(ofGetFrameRate()), 20, 40);

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
    for (int i = 0; i < 10; i++) {
        //新規に物体を1つ追加
        ofVec2f loc = ofVec2f(x, y);
        location.push_back(loc);
        ofVec2f vel = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
        velocity.push_back(vel);
    }
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
