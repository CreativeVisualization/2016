#include "Particle.hpp"

void Particle::create(ofVec3f p, ofVec3f v){
    pos = p;
    float min = .05;
    float max = 1.85;
    speed = ofVec3f(v.x * ofRandom(min, max),
                    v.y * ofRandom(min, max),
                    v.z * ofRandom(min, max));
    
    resolution = ofRandom(3, 8);
    size = ofRandom(.5, 10);
    fill = ofRandom(2);
}

void Particle::draw(){
    
    //update
    pos += speed;
    
    ofPushStyle();
    ofSetLineWidth(.1);
    if(fill) ofFill();
    else ofNoFill();
    ofNoFill();
    ofSetSphereResolution(resolution);
    ofSetColor(ofColor::fromHsb(ofRandom(255), 80, 255));
    ofDrawSphere(pos, size);
    ofPopStyle();
    
}