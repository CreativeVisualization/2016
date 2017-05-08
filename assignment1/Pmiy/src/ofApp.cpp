#include "ofApp.h"
  float radius;
#define NUM 200
ofPoint pos[NUM];
ofPoint speed[NUM];

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofSetBackgroundColor(250);
    
    //初期数値
    for(int i =0;i<NUM; i++){
        pos[i].set(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
        speed[i].set(ofRandom(-4,4),ofRandom(-4,4));
    }
    //カラーグラデーしょん
#ifdef TARGET_OPENGLES
    shader.load("shadersES2/shader");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
        shader.load("shadersGL2/shader");
    }
    
#endif
}

//--------------------------------------------------------------
void ofApp::update(){
    
    radius=sin(1.0*ofGetElapsedTimef())*5*mouseY/100.0f+1;
    
    
    //壁判定
    for(int i=0;i<NUM;i++){
        pos[i]+=speed[i];
        
        if(pos[i].x<0||pos[i].x>ofGetWidth()){
            speed[i].x*=-1;}
        
        if(pos[i].y<0||pos[i].y>ofGetHeight()){
            speed[i].y*=-1;}
    }
    
}
    

//--------------------------------------------------------------
void ofApp::draw(){
    
    //円の解像度
    ofSetCircleResolution(100);
    shader.begin();
    
    //円の描画
    for(int i=0;i<NUM*mouseX/500;i++){
        ofSetColor(50, 50, 100);
        ofCircle(pos[i].x,pos[i].y,radius);
        ofDrawLine(ofGetWidth()/2, ofGetHeight()/2,pos[i].x, pos[i].y);
    }
    
    //中心の円
    ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2, 100); //半径40の円を描画
    shader.end();
    
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
