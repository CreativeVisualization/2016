#pragma once

#include "ofMain.h"
#include "Tamabi01.hpp"
#include "ofxWatchdog.h"

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
    
    
    Tamabi01 *tamabi01,*tamabi02,*tamabi03,*tamabi04,*tamabi05,*tamabi06,*tamabi07,*tamabi08,*tamabi09,*tamabi10,*tamabi11;
    
};
