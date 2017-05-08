#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(20, 200, 44);
        ofBackground(255,255,255);
    ofSetBackgroundAuto(false);
    
    //location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    //velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10));
    velocity = ofVec2f(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity + ofRandom(-10,10);
    r-= 0.3;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);



    ofPushMatrix();
    ofRotate(r);
    for (int i=0; i<100; i+=10) {
        ofSetColor(ofRandom(255), 188, 246, 100-i);
        ofDrawCircle(location+i, 3);
        ofDrawCircle(location-i, 5);
    }
    ofPopMatrix();
    
    if (location.x+100 > ofGetWidth()/2 || location.x-100 < -ofGetWidth()/2) {
        velocity.x *= -1;
    }
    if (location.y+100 > ofGetHeight()/2 || location.y-100 < -ofGetHeight()/2) {
        velocity.y *= -1;
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
