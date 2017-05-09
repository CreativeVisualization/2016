#pragma once

#include "ofMain.h"

#define WIDTH 1118
#define HEIGHT 4500

struct Words {
    string  design;
    float   dPercent;
    string  art;
    float   aPercent;
    string  media;
    float   mPercent;
    string  mediaDesign;
    float   mdPercent;
    string  mediaArt;
    float   maPercent;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
        void loadCSV(string filePath);
    
    const int       scale = 5;
    bool    save;
    vector <ofTrueTypeFont> dFont, aFont, mFont, mdFont, maFont;
    ofTrueTypeFont fontForInit, title;
    
    vector  <Words> words;
    int     index;
    
    string  design_;
    float   dPercent_;
    string  art_;
    float   aPercent_;
    string  media_;
    float   mPercent_;
    string  mediaDesign_;
    float   mdPercent_;
    string  mediaArt_;
    float maPercent_;
    float dis = 3;
    const int xOffSet = 40 / scale;
    float   wD, hD, xD, yD,
            wA, hA, xA, yA,
            wM, hM, xM, yM,
            wMD, hMD, xMD, yMD,
            wMA, hMA, xMA, yMA,
            wT, hT, xT, yT;
    ofPoint dPoint, aPoint, mPoint, mdPoint, maPoint;
    ofColor dColor = ofColor(255, 133, 123),
            aColor = ofColor(0, 130, 123),
            mColor = ofColor(131, 130, 123),
            mdColor = ofColor(184, 130, 123),
            maColor = ofColor(69, 130, 123);
    string titleS = "ARTS AND DESIGNS VIA MEDIA";
    vector <ofVec2f>    dRand, aRand, mRand, mdRand, maRand;
    vector <float>      dDeg, aDeg, mDeg, mdDeg, maDeg;
};
