#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(255); //背景色を黒に
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2); //画面の中心に
    velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); //ランダムな速度で
    
    photo.load("pc-wallpaper-09.jpg");
    photo.mirror(true, true);
    shader.load("", "shader.frag");
    
    
    font.load("powder.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity; //速度から位置を更新
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255);
    //    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()/2);
    //    font.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    //計算した位置に円を描画
    ofSetColor(31, 12, 255); //円の色
    //    ofDrawCircle(location, 40); //半径40の円を描画
    
    //画面の端でバウンドするように
    if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location.y < 0 || location.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity.y *= -1; //横向きの速度を反転(バウンド)
    }
    
    for(int i=0; i<powder.size(); i++){
        powder[i].draw();
    }
    
    
    
    shader.begin();
    
    float coef[] = {
        1.0,  1.0,  1.0,
        1.0, -8.0,  1.0,
        1.0,  1.0,  1.0
    };
    
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    shader.setUniformTexture("_texture", photo.getTexture(), 1);
    shader.setUniform1fv("coef", coef);
    ofSetColor(255,255);
//    ofDrawRectangle(0, 0, 600, 400);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2d(0, 0);
    glVertex2d(0, 0);
    
    glTexCoord2d(600, 0);
    glVertex2d(600, 0);
    
    glTexCoord2d(0, 400);
    glVertex2d(0, 400);
    
    glTexCoord2d(600,400);
    glVertex2d(600, 400);
    glEnd();
    
    shader.end();
    
    
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    int num = 100;
    for (int i=0; i<num; i++) {
        Powder p;
        p.drop(ofPoint(x, y));
        powder.push_back(p);
    }
    
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){}
