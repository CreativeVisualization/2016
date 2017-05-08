#include "ofApp.h"

struct Particle{
    float x, y, rd, vx, vy;
    int r, g, b, a;
    
    void draw(){
        ofSetColor(r, g, b, a);
        ofDrawCircle(x, y, rd);
    }
    
    void update(){
        this -> x += vx;
        this -> y += vy;
    }
};

static const int N = 1000; //数
int W, H;
Particle particles[N];


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
    
    W = ofGetWidth();
    H = ofGetHeight();
    for(int i = 0; i < N; i++){
        Particle p;
        p.x = ofRandom(100, W-100); //座標
        p.y = ofRandom(100, H-100); //座標
        p.rd = ofRandom(5.0, 50.0); //円の大きさ
        p.vx = ofRandom(-5, 3); //はやさ
        p.vy = ofRandom(-5, 3); //はやさ
        p.r = ofRandom(0,255); //赤
        p.g = ofRandom(0,255); //緑
        p.b = ofRandom(0,255); //青
        p.a = 150; //透明
        p.draw();
        particles[i] = p;
    }
    
    
    /*
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2); //画面の中心に
    velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); //ランダムな速度で

    */
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < N; i++){
        Particle& p = particles[i];
        p.update();
        if(p.x < p.rd){
            p.x = p.rd;
            p.vx *= -1;
        }else if(p.x > W-p.rd){
            p.x = W-p.rd;
            p.vx *= -1;
        }
        
        if(p.y < p.rd){
            p.y = p.rd;
            p.vy *= -1;
        }else if(p.y > H-p.rd){
            p.y = H-p.rd;
            p.vy *= -1;
        }
    }
    
    
    /*
    location += velocity; //速度から位置を更新
    */

     
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < N; i++){
        particles[i].draw();
    }
    
    
    /*
    
    //計算した位置に円を描画
    ofSetColor(31, 129, 255); //円の色
    ofDrawCircle(location, 40); //半径40の円を描画
    
    //画面の端でバウンドするように
    if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location.y < 0 || location.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity.y *= -1; //横向きの速度を反転(バウンド)
    }
     
    */
     
     
     
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
