#include "Powder.hpp"

void Powder::drop(ofPoint pos){
    position = pos;
    speed = ofPoint(ofRandom(-.2, .2), ofRandom(2., 3.));
}
void Powder::draw(){
    ofPushStyle();
    //update
    position += speed;
    
    //draw
    ofSetColor(0, ofRandom(255));
    ofDrawCircle(position, ofRandom(2));
    ofPopStyle();
}
