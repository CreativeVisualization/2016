#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0, 211, 186); //背景色を黒に
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2); //画面の中心に
    velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); //ランダムな速度で
    ofSetCircleResolution(64); //円の解像度
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity; //速度から位置を更新
    angle += 10;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    

    ofSetColor(0); //円の色
    ofDrawCircle(location, 600); //半径80の円を描画
    
    ofSetColor(255); //円の色
    ofDrawCircle(location, 80); //半径80の円を描画
    ofSetColor(0, 166, 216); //円の色
    ofDrawCircle(location, 40); //半径40の円を描画
    
    ofTranslate(300, 200);
    ofSetColor(255); //円の色
    ofDrawCircle(location, 80); //半径80の円を描画
    ofSetColor(0, 166, 216); //円の色
    ofDrawCircle(location, 40); //半径40の円を描画
    
    ofTranslate(-230, 20);
    ofSetColor(255); //円の色
    ofDrawCircle(location, 20); //半径20の円を描画
   
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angle);

    ofSetColor(229,164,0); //三角の色
    ofDrawTriangle(100,100,200,200,100,200); //三角形を描画
    
    ofTranslate(175, 175);
    ofSetColor(255,248,121); //三角の色
    ofDrawTriangle(100,100,200,200,100,200); //三角形を描画
    
    ofTranslate(200, 200);
    ofSetColor(158,256,255); //三角の色
    ofDrawTriangle(100,100,200,200,100,200); //三角形を描画
    
    
    ofTranslate(201, 201);
    ofSetColor(255); //三角の色
    ofDrawTriangle(100,100,200,200,100,200); //三角形を描画
    
    
    
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
