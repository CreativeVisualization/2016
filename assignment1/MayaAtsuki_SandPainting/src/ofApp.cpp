#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofDisableArbTex();
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(255); //背景色を黒に
    ofSetBackgroundAuto(false);
    ofToggleFullscreen();
    ofEnableAlphaBlending();
    
    //video filter
    video.initGrabber(ofGetWidth(), ofGetHeight());
    filters.push_back(new SobelEdgeDetectionFilter(video.getWidth(), video.getHeight()));
    isUpdate = false;
    
    //image
    bottle.load("20091130214951982.png");
    bottle.rotate90(2);
    bottle.resize(bottle.getWidth()/1.5, bottle.getHeight()/1.5);
    shader.load("", "shader.frag");
    fbo.allocate(ofGetWidth(), ofGetHeight());
    powderY = -bottle.getHeight()/2;
    
    //位置と速度を初期化
    location = ofVec2f(0, powderY); //画面の中心に
    velocity = ofVec2f(6, 0); //ランダムな速度で
    
    //font
    font.load("PoiretOne-Regular.ttf", 38);
    
    //gui
    gui.setup();
    gui.add(_min.setup("Light and shade", .315, .01, 1.));
    isDraw = true;
    
    ofEnableArbTex();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    location += velocity; //速度から位置を更新
    
    if(isUpdate) video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255);
    
    //take photo
    if(isUpdate) {
        ofBackground(0, 0, 0, 255);
        ofPushMatrix();
        ofScale(-1, -1);
        ofTranslate(-video.getWidth(), -video.getHeight());
        filters[0]->begin();
        video.draw(0,0);
        filters[0]->end();
        ofPopMatrix();
        captureImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        captureImage.save("photo/image" + ofToString(ofGetFrameNum()) + ".jpg");
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    //shader
    shader.begin();
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    shader.setUniformTexture("_texture", captureImage.getTexture(), 1);
    shader.setUniform1f("_min", _min);
    ofSetColor(255,255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
    //bottle
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateZ(30);
    bottle.draw(0,0, bottle.getWidth(), bottle.getHeight());
    ofPopMatrix();
    
    //powder
    int num = 2;
    for (int i=0; i<num; i++) {
        Powder p;
        p.drop(ofPoint(location.x-50, bottle.getHeight()+powderY-10 ));
        powder.push_back(p);
    }
    
    while(powder.size() > 2000){
        powder.pop_front();
    }
    
    
    
    //画面の端でバウンドするように
    if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
    }
    for(int i=0; i<powder.size(); i++){
        powder[i].draw();
    }
    
    
    ofSetColor(255, 255);
    ofDrawRectangle(20, ofGetHeight()-100, 438, 65);
    ofSetColor(0, 255);
    font.drawString("Press the space key", 30, ofGetHeight()-50);
    
    if(isDraw)gui.draw();
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        isUpdate = true;
        powder.clear();
        deque<Powder>().swap(powder);
    }
    if(key == 'h'){
        isDraw = !isDraw;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' ')isUpdate = false;
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){}
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