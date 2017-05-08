#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    ofxLeapMotion leap; //LeapMotionアドオン本体
    vector <ofxLeapMotionSimpleHand> simpleHands; //検出された手の配列
    vector <int> fingersFound; //検出された手の番号
    ofEasyCam cam; //カメラ
    ofLight light; //ライト
};
