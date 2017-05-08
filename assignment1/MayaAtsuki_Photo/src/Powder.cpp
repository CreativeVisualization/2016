#include "Powder.hpp"

void Powder::drop(ofPoint pos){
    position = pos;
    speed = ofPoint(ofRandom(-.2, .2), ofRandom(.05, 1.));
}
void
Powder::draw(){
    ofPushStyle();
    //update
    position += speed;
    
    //draw
    int alpha = ofRandom(5);
    if(alpha == 0) ofSetColor(ofRandom(255), 255);
    else ofSetColor(ofRandom(255), 0);
    ofDrawCircle(position, 2);
    ofPopStyle();
}
