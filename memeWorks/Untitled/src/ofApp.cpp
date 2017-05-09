#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofHideCursor();
    ofSetFullscreen(true);
    
    string filePath = "tamabi01.csv";
    tamabi01 = new Tamabi01( filePath );
    string filePath2 = "tamabi02.csv";
    tamabi02 = new Tamabi01( filePath2 );
    string filePath3 = "tamabi03.csv";
    tamabi03 = new Tamabi01( filePath3 );
    string filePath4 = "tamabi04.csv";
    tamabi04 = new Tamabi01( filePath4 );
    string filePath5 = "tamabi05.csv";
    tamabi05 = new Tamabi01( filePath5 );
    string filePath6 = "tamabi08.csv";
    tamabi06 = new Tamabi01( filePath6 );
    string filePath7 = "tamabi09.csv";
    tamabi07 = new Tamabi01( filePath7 );
    string filePath8 = "tamabi10.csv";
    tamabi08 = new Tamabi01( filePath8 );
    string filePath9 = "tamabi11.csv";
    tamabi09 = new Tamabi01( filePath9 );
    string filePath10 = "tamabi12.csv";
    tamabi10 = new Tamabi01( filePath10 );
    
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    ofSetFrameRate(30);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofTranslate(-990,0);
    tamabi01->draw();
    
    
    ofTranslate(220, 0);
    ofPopMatrix();
    tamabi02->draw();
    ofPushMatrix();
    
    ofTranslate(220, 0);
    tamabi03->draw();
    
    ofTranslate(220, 0);
    tamabi04->draw();
    
    ofTranslate(220, 0);
    tamabi05->draw();
    
    ofTranslate(220, 0);
    tamabi06->draw();
    
    ofTranslate(220, 0);
    tamabi07->draw();
    
    ofTranslate(220, 0);
    tamabi08->draw();
    
    ofTranslate(220, 0);
    tamabi09->draw();
    
    ofTranslate(220, 0);
    tamabi10->draw();
    
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