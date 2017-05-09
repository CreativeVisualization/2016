#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    ofEnableDepthTest();
    
    light.enable();
    light.setPosition(-100, 100, 1000);
    light.setAmbientColor(ofFloatColor(0.5, 0.5, 0.5, 1.0));
    light.setDiffuseColor(ofFloatColor(0.3, 0.3, 0.3, 1.0));
    light.setPointLight();
    
    cam.setDistance(4000);
    
    
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    Particles *p;

    for (int i = 1; i < 6; i++) {
        p = new Particles("tamabi0" + ofToString(i) + ".csv", "00" + ofToString(i) + "_ST.csv");
        particles.push_back(p);
    }
    for (int i = 10; i < 15; i++) {
        p = new Particles("tamabi" + ofToString(i) + ".csv", "0" + ofToString(i) + "_ST.csv");
        particles.push_back(p);
    }
    p = new Particles("tamabi08.csv", "008_ST.csv");
    particles.push_back(p);
    p = new Particles("tamabi01.csv", "001_ST.csv");
    particles.push_back(p);
    p = new Particles("tamabi18.csv", "018_ST.csv");
    particles.push_back(p);
    
}


//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->updatePos();
        particles[i]->resetOffWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->draw();
    }
    cam.end();
    
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
