#pragma once

#include "ofMain.h"

typedef struct{
    ofVec2f pos, speed;
    float size;
    int number;
}GlitterSet;

const int glitterNum = 50;

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
    ofVec2f velocity, pvec; // 速度
    
    void drawFlower(ofVec2f pos, float size, ofColor color, bool isRotate);
    vector<ofImage>glitter;
    GlitterSet gset[glitterNum];
    ofImage background;
    bool isStart;
    ofSoundPlayer sound;
    ofTrueTypeFont font;
    int count;
};
