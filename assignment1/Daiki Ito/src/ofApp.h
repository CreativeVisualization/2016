#pragma once

#include "ofMain.h"

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
    
    
    //配列を定義
    vector<ofVec2f> location; //NUM個の位置ベクトル
    vector<ofVec2f> velocity; //NUM個の速度ベクトル
    vector<ofVec2f> Tscale;

    ofTrueTypeFont font; //True Type fontを取り扱うインスタンスを作成
    char text[255]; //テキストデータの変数の宣言
    
    int fontcolor;
    int R;
    int G;
    int B;
    int bcolor;
    
};
