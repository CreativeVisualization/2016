#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    counter = 0;
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(252,145,83); //背景色を黒に
    
    
    ofSetCircleResolution(50);
    bSmooth = false;
    ofSetWindowTitle("assinment");
    
    
    
    
    font.loadFont("Georgia",20);

    
   
    
    
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2); //画面の中心に
    //velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); //ランダムな速度で
}

//--------------------------------------------------------------
void ofApp::update(){
    //location += velocity; //速度から位置を更新
    counter = counter + 0.045f;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    //ofSetColor(31, 127, 255); //円の色
    //float radius = 50 + 10 * sin(counter);
    //ofFill();
    //ofDrawCircle(100, 400, radius);
    //ofDrawCircle(location, 40); //半径40の円を描画
    
    //ofNoFill();
    //ofSetColor(102,204,153);
    //ofDrawCircle(100,400,80);
    
    
    //画面の端でバウンドするように
   // if (location.x < 0 || location.x > ofGetWidth()) { //画面の左右ではみ出したら
        //velocity.x *= -1; //横向きの速度を反転(バウンド)
    //}
    //if (location.y < 0 || location.y > ofGetHeight()) { //画面の左右ではみ出したら
        //velocity.y *= -1; //横向きの速度を反転(バウンド)
    //}
    
    
    //ofSetHexColor(0xCCCCCC);
    //ofDrawBitmapString("circle",75,500);
    
    
    // -------------------------- mouse
    ofFill();
    
    ofSetColor(255);
    ofDrawCircle(mouseX,mouseY,70,70);
    
    
    
    
    
    //--------------------------- rectangles
    ofFill();
    for (int i = 0; i < 200;  i++){
        ofSetColor((int)ofRandom(69,366),(int)ofRandom(124,200),(int)ofRandom(118,204));
        ofDrawRectangle(ofRandom(-280,1980),ofRandom(-240,1080),ofRandom(450,30),ofRandom(450,30));
   }
    ofFill();
    for (int i = 0; i < 200; i++){
        ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
        ofDrawRectangle(ofRandom(-50,1980),ofRandom(-50,1080),ofRandom(50,20),ofRandom(50,20));
    }

    ofSetColor(153,204,204);
    font.drawString("what  is  hidden?", 285,620);
    
    //PFont f;
    //f = creatFont("Georgia" , 26);
    //textFont(f);
    //ofSetColor(153,204,204);
    
    

    //---------------------------  transparency
    //ofSetHexColor(0x00FF33);
    //ofDrawRectangle(400,350,100,100);
    // alpha is usually turned off - for speed puposes.  let's turn it on!
    //ofEnableAlphaBlending();
    //ofSetColor(255,0,0,127);   // red, 50% transparent
    //ofDrawRectangle(450,430,100,33);
    //ofSetColor(255,0,0,(int)(counter * 10.0f) % 255);   // red, variable transparent
    //ofDrawRectangle(450,370,100,33);
    //ofDisableAlphaBlending();
    
    //ofSetHexColor(0x000000);
    //ofDrawBitmapString("transparency", 410,500);
    
    //---------------------------  lines
    // a bunch of red lines, make them smooth if the flag is set
    
    //ofSetHexColor(0xFF0000);
    //for (int i = 0; i < 20; i++){
        //ofDrawLine(600,300 + (i*5),800, 250 + (i*10));
    //}

    
    
    
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
    x = mouseX;
    y = mouseY;

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
