#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // window size
    ofBackground(255);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetWindowShape(WIDTH / scale, HEIGHT / scale);
    
    //csv
    string filePath = "CSV/source.csv";
    loadCSV(filePath);
    design_         = words[0].design;
    dPercent_       = words[0].dPercent;
    art_            = words[0].art;
    aPercent_       = words[0].aPercent;
    media_          = words[0].media;
    mPercent_       = words[0].mPercent;
    mediaDesign_    = words[0].mediaDesign;
    mdPercent_      = words[0].mdPercent;
    mediaArt_       = words[0].mediaArt;
    maPercent_      = words[0].maPercent;
    
    //font
    title.load("font/AxisCondStd-UltraLight.otf", 60 / scale , true, true, true);
    
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) {
            fontForInit.load("font/AxisCompStd-Light.otf", ofMap(words[i].dPercent, 0, 100, 40 / scale, 100 / scale) , true, true, true);
            dFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", ofMap(words[i].aPercent, 0, 100, 40 / scale, 100 / scale), true, true, true);
            aFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", ofMap(words[i].mPercent, 0, 100, 40 / scale, 100 / scale), true, true, true);
            mFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", ofMap(words[i].mdPercent, 0, 100, 40 / scale, 100 / scale), true, true, true);
            mdFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", ofMap(words[i].maPercent, 0, 100, 40 / scale, 100 / scale), true, true, true);
            maFont.push_back(fontForInit);
        }
        else {
            fontForInit.load("font/AxisCompStd-Light.otf", words[i].dPercent / scale, true, true, true);
            dFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", words[i].aPercent / scale, true, true, true);
            aFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", words[i].mPercent / scale, true, true, true);
            mFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", words[i].mdPercent / scale, true, true, true);
            mdFont.push_back(fontForInit);
            fontForInit.load("font/AxisCompStd-Light.otf", words[i].maPercent / scale, true, true, true);
            maFont.push_back(fontForInit);
        }
    }
    
    for (int i = 0; i < words.size(); i++) {
        ofVec2f dVec = ofVec2f(ofRandom(1.8, 2.2) / scale, ofRandom(1.8, 2.2) / scale);
        dRand.push_back(dVec);
        ofVec2f aVec = ofVec2f(ofRandom(1.8, 2.2) / scale, ofRandom(1.8, 2.2) / scale);
        aRand.push_back(aVec);
        ofVec2f mVec = ofVec2f(ofRandom(1.8, 2.2) / scale, ofRandom(1.8, 2.2) / scale);
        mRand.push_back(mVec);
        ofVec2f mdVec = ofVec2f(ofRandom(1.8, 2.2) / scale, ofRandom(1.8, 2.2) / scale);
        mdRand.push_back(mdVec);
        ofVec2f maVec = ofVec2f(ofRandom(1.8, 2.2) / scale, ofRandom(1.8, 2.2) / scale);
        maRand.push_back(maVec);
        float dDVec = ofRandom(360);
        dDeg.push_back(dDVec);
        float aDVec = ofRandom(360);
        aDeg.push_back(aDVec);
        float mDVec = ofRandom(360);
        mDeg.push_back(mDVec);
        float mdDVec = ofRandom(360);
        mdDeg.push_back(mdDVec);
        float maDVec = ofRandom(360);
        maDeg.push_back(maDVec);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // save as pdf
    if (save) ofBeginSaveScreenAsPDF("exportedData/exported-"+ ofToString(ofGetDay()) + ofToString(ofGetHours()) + ofToString(ofGetMinutes()) + ofToString(ofGetSeconds()) +".pdf", false);
    
    //draw
    ofSetColor(0);
    ofNoFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    wT = title.stringWidth(titleS);
    hT = title.stringHeight(titleS);
    xT = ofGetWidth() / 2 - wT / 2;
    yT = ofGetHeight() / 20 * 19 +  hT / 2;
    title.drawStringAsShapes(titleS, xT, yT);
    
    for (int i = words.size() - 1; i >= 0 ; i--) {
        ofPushMatrix();
        //font centering
        wD = dFont[i].stringWidth(words[i].design);
        hD = dFont[i].stringHeight(words[i].design);
        xD = ofGetWidth() / 2 - wD / 2 - xOffSet;
        yD = ofGetHeight() / 7 * 3 +  hD / 2;
        wA = aFont[i].stringWidth(words[i].art);
        hA = aFont[i].stringHeight(words[i].art);
        xA = ofGetWidth() / 2 - wA / 2 - xOffSet;
        yA = ofGetHeight() / 7 * 3 +  hA / 2;
        wM = mFont[i].stringWidth(words[i].media);
        hM = mFont[i].stringHeight(words[i].media);
        xM = ofGetWidth() / 2 - wM / 2 - xOffSet;
        yM = ofGetHeight() / 7 * 3 +  hM / 2;
        wMD = mdFont[i].stringWidth(words[i].mediaDesign);
        hMD = mdFont[i].stringHeight(words[i].mediaDesign);
        xMD = ofGetWidth() / 2 - wMD / 2 - xOffSet;
        yMD = ofGetHeight() / 7 * 3 +  hMD / 2;
        wMA = maFont[i].stringWidth(words[i].mediaArt);
        hMA = maFont[i].stringHeight(words[i].mediaArt);
        xMA = ofGetWidth() / 2 - wMA / 2 - xOffSet;
        yMA = ofGetHeight() / 7 * 3 +  hMA / 2;
        
        float deg = ofRandom(360);
        
        if (i > 0) {
            dPoint = ofPoint(xD + (105 - words[i].dPercent) * sin(dDeg[i]) * dis * dRand[i].x,
                             yD + (105 - words[i].dPercent) * cos(dDeg[i]) * dis * dRand[i].y - ofGetHeight() / 6 * 2);
            aPoint = ofPoint(xA + (105 - words[i].aPercent) * sin(aDeg[i]) * dis * aRand[i].x,
                             yA + (105 - words[i].aPercent) * cos(aDeg[i]) * dis * aRand[i].y + ofGetHeight() / 6 * 2);
            mPoint = ofPoint(xM + (105 - words[i].mPercent) * sin(mDeg[i]) * dis * mRand[i].x,
                             yM + (105 - words[i].mPercent) * cos(mDeg[i]) * dis * mRand[i].y);
            mdPoint = ofPoint(xMD + (105 - words[i].mdPercent) * sin(mdDeg[i]) * dis * mdRand[i].x,
                              yMD + (105 - words[i].mdPercent) * cos(mdDeg[i]) * dis * mdRand[i].y - ofGetHeight() / 6);
            maPoint = ofPoint(xMA + (105 - words[i].maPercent) * sin(maDeg[i]) * dis * maRand[i].x,
                              yMA + (105 - words[i].maPercent) * cos(maDeg[i]) * dis * maRand[i].y + ofGetHeight() / 6);
            
            ofFill();
            dFont[i].setLetterSpacing(1);
            aFont[i].setLetterSpacing(1);
            mFont[i].setLetterSpacing(1);
            mdFont[i].setLetterSpacing(1);
            maFont[i].setLetterSpacing(1);
            ofSetColor(dColor, ofMap(words[i].dPercent, 0, 100, 123, 255));
            dFont[i].drawStringAsShapes(words[i].design, dPoint.x, dPoint.y);
            ofSetColor(aColor, ofMap(words[i].aPercent, 0, 100, 123, 255));
            aFont[i].drawStringAsShapes(words[i].art, aPoint.x, aPoint.y);
            ofSetColor(mColor, ofMap(words[i].mPercent, 0, 100, 123, 255));
            mFont[i].drawStringAsShapes(words[i].media, mPoint.x, mPoint.y);
            ofSetColor(mdColor, ofMap(words[i].mdPercent, 0, 100, 123, 255));
            mdFont[i].drawStringAsShapes(words[i].mediaDesign, mdPoint.x, mdPoint.y);
            ofSetColor(maColor, ofMap(words[i].maPercent, 0, 100, 123, 255));
            maFont[i].drawStringAsShapes(words[i].mediaArt, maPoint.x, maPoint.y);
            
            ofNoFill();
            ofSetColor(0, ofMap(words[i].dPercent, 0, 100, 123, 255));
            dFont[i].drawStringAsShapes(words[i].design, dPoint.x, dPoint.y);
            ofSetColor(0, ofMap(words[i].aPercent, 0, 100, 123, 255));
            aFont[i].drawStringAsShapes(words[i].art, aPoint.x, aPoint.y);
            ofSetColor(0, ofMap(words[i].mPercent, 0, 100, 123, 255));
            mFont[i].drawStringAsShapes(words[i].media, mPoint.x, mPoint.y);
            ofSetColor(0, ofMap(words[i].mdPercent, 0, 100, 123, 255));
            mdFont[i].drawStringAsShapes(words[i].mediaDesign, mdPoint.x, mdPoint.y);
            ofSetColor(0, ofMap(words[i].maPercent, 0, 100, 123, 255));
            maFont[i].drawStringAsShapes(words[i].mediaArt, maPoint.x, maPoint.y);
            
        }
        else {
            ofFill();
            dFont[i].setLetterSpacing(0.85);
            aFont[i].setLetterSpacing(1);
            mFont[i].setLetterSpacing(0.9);
            mdFont[i].setLetterSpacing(1);
            maFont[i].setLetterSpacing(1);
            ofSetColor(dColor);
            dFont[i].drawStringAsShapes(words[i].design, xD, yD - ofGetHeight() / 6 * 2);
            ofSetColor(aColor);
            aFont[i].drawStringAsShapes(words[i].art, xA, yA + ofGetHeight() / 6 * 2);
            ofSetColor(mColor);
            mFont[i].drawStringAsShapes(words[i].media, xM, yM);
            ofSetColor(mdColor);
            mdFont[i].drawStringAsShapes(words[i].mediaDesign, xMD, yMD - ofGetHeight() / 6);
            ofSetColor(maColor);
            maFont[i].drawStringAsShapes(words[i].mediaArt, xMA, yMA + ofGetHeight() / 6);
        }
        
        
        ofPopMatrix();
    }
    
    // end pdf
    if( save ){
        ofEndSaveScreenAsPDF();
        save = false;
    }
    ofDrawBitmapStringHighlight("Press 's' key to save.", 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') save = true;
}

//--------------------------------------------------------------
void ofApp::loadCSV(string filePath){
    ofFile file(filePath);
    
    if(!file.exists()){
        ofLogError("The file " + filePath + " is missing");
    }
    
    ofBuffer buffer(file);
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        vector<string> data = ofSplitString(line, ",");
        
        Words wordCSV;
        wordCSV.design      = ofToString(data[0]);
        wordCSV.dPercent    = ofToFloat(data[1]);
        wordCSV.art         = ofToString(data[2]);
        wordCSV.aPercent    = ofToFloat(data[3]);
        wordCSV.media       = ofToString(data[4]);
        wordCSV.mPercent    = ofToFloat(data[5]);
        wordCSV.mediaDesign = ofToString(data[6]);
        wordCSV.mdPercent   = ofToFloat(data[7]);
        wordCSV.mediaArt    = ofToString(data[8]);
        wordCSV.maPercent   = ofToFloat(data[9]);
        words.push_back(wordCSV);
    }
}
