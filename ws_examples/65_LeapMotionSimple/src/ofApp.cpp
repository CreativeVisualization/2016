#include "ofApp.h"

void ofApp::setup(){
    //画面の基本設定
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    //カメラとライトの設定
    cam.setOrientation(ofPoint(-20, 0, 0));
    light.setPosition(0, 0, 1000);
    light.enable();
    
    //LeapMotion開始
    leap.open();
}

void ofApp::update(){
    //検出した手を配列に格納
    simpleHands = leap.getSimpleHands();
    //フレーム更新
    leap.markFrameAsOld();
}

void ofApp::draw(){
    //背景
    ofBackgroundGradient(ofColor(90, 90, 90), ofColor(30, 30, 30),  OF_GRADIENT_BAR);
    
    //ログ表示
    ofSetColor(200);
    ofDrawBitmapString("ofxLeapMotion - Example App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);
    
    ofEnableDepthTest();
    cam.begin();
    
    //地面のグリッドを描画
    ofPushMatrix();
    ofRotate(90, 0, 0, 1);
    ofSetColor(20);
    ofDrawGridPlane(800, 20, false);
    ofPopMatrix();
    
    //検出した手を描画
    for(int i = 0; i < simpleHands.size(); i++){
        simpleHands[i].debugDraw();
    }
    
    cam.end();
    ofDisableDepthTest();
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    //プログラム終了したらLeapMotionを閉じる
    leap.close();
}
