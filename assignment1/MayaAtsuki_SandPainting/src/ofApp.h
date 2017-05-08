#pragma once

#include "ofMain.h"
#include "Powder.hpp"
#include "ofxFilterLibrary.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVec2f location; // 位置
    ofVec2f velocity; // 速度
    
    ofImage photo, bottle;
    ofShader shader;
    deque<Powder> powder;
    ofFbo fbo;
    float powderY;
    
    vector<AbstractFilter *> filters;
    ofVideoGrabber video;
    ofImage captureImage;
    bool isUpdate;
    
    ofTrueTypeFont font;
    ofxPanel gui;
    ofxFloatSlider _min;
    bool isDraw;
    
};
