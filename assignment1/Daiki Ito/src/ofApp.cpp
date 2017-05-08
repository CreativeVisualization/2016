#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(255); //背景色を白に
    ofSetBackgroundAuto(false);
    fontcolor = 0;
    R = 0;
    G = 0;
    B = 0;
    bcolor = 255;
    font.load("Geotica_2012.otf",40);
    sprintf(text, "DRAW");//配列textに文字データを代入
    float w = font.stringWidth(text); //テキストの幅を調べる
    float h = font.stringHeight(text);//テキストの高さを調べ
    /*
    for (int i = 0; i < NUM; i++) {
        //位置と速度を初期化
        location[i] = ofVec2f(ofGetWidth()/2-w/2, ofGetHeight()/2-h/2);
        velocity[i] = ofVec2f(ofRandom(-50, 50), ofRandom(-50, 50));
        Tscale[i] = ofVec2f(ofRandom(0.25, 10), ofRandom(0.25, 10));
     
    }*/
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < location.size(); i++) {
        location[i] += velocity[i];
    }//速度から位置を更新
    ofVec2f loc = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    location.push_back(loc);
    ofVec2f vel = (ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)));
    velocity.push_back(vel);
    ofVec2f sca = (ofVec2f(ofRandom(0.25, 10), ofRandom(0.25, 10)));
    Tscale.push_back(sca);
    
    if(location.size() > 200){
        location.erase(location.begin());
        velocity.erase(velocity.begin());
        Tscale.erase(Tscale.begin());//先頭のものから取り除かれる
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    ofSetColor(fontcolor); //文字の色
    float w = font.stringWidth(text); //テキストの幅を調べる
    float h = font.stringHeight(text);//テキストの高さを調べ
    font.drawString(text, ofGetWidth()/2-w/2, ofGetHeight()/2-h/2);
    
    for (int i = 0; i < location.size(); i++) {// i++ i = i+1
        //計算した位置に円を描画
        ofEnableAlphaBlending();
        ofSetColor(R, G, B, 50); //円の色
        ofPushMatrix();
        ofScale(Tscale[i].x, Tscale[i].y);
        font.drawString(text, location[i].x, location[i].y);
        ofPopMatrix();
        
        //画面の端でバウンドするように
        if (location[i].x < 0 || location[i].x > ofGetWidth()) {
            velocity[i].x *= -1; //横向きの速度を反転(バウンド)
        }
        if (location[i].y < 0 || location[i].y > ofGetHeight()) {
            velocity[i].y *= -1; //横向きの速度を反転(バウンド)
        }
    }
    
    cout << "object num" << location.size() << endl;
    cout << "frame rate" << ofGetFrameRate() << endl;
    
    ofDrawBitmapStringHighlight("object NUM = " + ofToString(location.size()), 20, 20);
    ofDrawBitmapStringHighlight("frame rate = " + ofToString(ofGetFrameRate()), 20, 60);
    
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
    ofSetBackgroundColor(50);
    fontcolor = 255;
    R = 255;
    G = 255;
    B = 255;
    for (int i = 0; i < velocity.size(); i++) {
        velocity[i] = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofSetBackgroundColor(255);
    fontcolor = 0;
    R = 0;
    G = 0;
    B = 0;
    for (int i = 0; i < velocity.size(); i++) {
        velocity[i] = ofVec2f(ofRandom(-20, 20), ofRandom(-20, 20));
        
    }
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
