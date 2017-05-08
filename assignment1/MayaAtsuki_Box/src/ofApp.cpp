#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
    ofEnableDepthTest();
    ofToggleFullscreen();
    
    //位置と速度を初期化
    location = ofVec3f(0, 0, 0); //画面の中心に
    int speed = 7;
    velocity = ofVec3f(ofRandom(-speed, speed), ofRandom(-speed, speed), ofRandom(-speed, speed)); //ランダムな速度で
    
    cam.setup();
    float camspeed = abs(velocity.x+velocity.y+velocity.z)/3/100;
    cam.setCamSpeed(camspeed);
    boxSize = 300;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    location += velocity; //速度から位置を更新
    cam.update();
}

//--------------------------------------------------------------
void ofApp::createParticle(){
    
    int n = ofRandom(3, 20);
    Particle p;
    for(int i=0; i<n; i++){
        p.create(location, location-pvec);
        particle.push_back(p);
    }
    while (particle.size() > 200) {
        particle.pop_front();
    }
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofSetSphereResolution(10);
    //計算した位置に円を描画
    ofSetColor(255); //円の色
    ofDrawSphere(location, boxSize/10);
    
    //画面の端でバウンドするように
    if (abs(location.x) > boxSize/2) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
        createParticle();
        cam.setRandomPos(270);
    }
    if (abs(location.y) > boxSize/2) { //画面の左右ではみ出したら
        velocity.y *= -1; //横向きの速度を反転(バウンド)
        createParticle();
        cam.setRandomPos(270);
        
    }
    if (abs(location.z) > boxSize/2) { //画面の左右ではみ出したら
        velocity.z *= -1; //横向きの速度を反転(バウンド)
        createParticle();
        cam.setRandomPos(270);
    }
    
    
    //particle
    for(int i=0; i<particle.size(); i++){
        particle[i].draw();
    }
    
    //box
    ofPushStyle();
    ofSetColor(255, 255);
    ofNoFill();
    ofDrawBox(0, 0, 0, boxSize, boxSize, boxSize);
    ofSetColor(255, ofRandom(80));
    ofFill();
    ofDrawBox(0, 0, 0, boxSize, boxSize, boxSize);
    ofPopStyle();
    
    
    cam.end();
    pvec = ofVec3f(location);
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
