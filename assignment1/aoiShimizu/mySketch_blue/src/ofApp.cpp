#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofSetBackgroundColor(0);
    
    ofSetBackgroundAuto(false);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    

    for (int i = 0; i < NUM; i++) {

        location[i] = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        velocity[i] = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) {
        location[i] += velocity[i];
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(0, 0, 0, 3);
    ofRectangle(0, 0, ofGetWidth(), ofGetHeight());

    for (int i = 0; i < NUM; i++) {

        ofSetColor(ofRandom(0,100), ofRandom(60,150), ofRandom(200,255),ofRandom(0,5));
        ofNoFill();
        ofDrawCircle(location[i]+ofRandom(-1,1), ofRandom(0,20));
        
        ofSetColor(ofRandom(0,100), ofRandom(100,150), ofRandom(200,255),ofRandom(0,1));
        ofDrawLine(ofGetWidth()/2, ofGetHeight()/2, location[i].x, location[i].y);
        

        if (location[i].x < -50 || location[i].x > ofGetWidth()+50) {
            velocity[i].x *= -1;
        }
        if (location[i].y < -50 || location[i].y > ofGetHeight()+50) {
            velocity[i].y *= -1;
        }
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