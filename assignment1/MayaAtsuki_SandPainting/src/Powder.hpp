
#ifndef Powder_hpp
#define Powder_hpp

#include <stdio.h>
#include "ofMain.h"


class Powder{
public:
    void drop(ofPoint pos);
    void draw();
private:
    ofPoint position, speed;
};
#endif /* Powder_hpp */
