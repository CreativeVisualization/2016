#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle: public ofBaseApp{
public:
    void create(ofVec3f p, ofVec3f v);
    void draw();
private:
    ofVec3f pos, speed;
    int resolution, fill;
    float size;
};

#endif /* Particle_hpp */
