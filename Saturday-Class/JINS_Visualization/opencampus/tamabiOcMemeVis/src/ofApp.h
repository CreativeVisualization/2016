#pragma once

#include "ofMain.h"
#include "threadObject.h"

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
    
    
    //カメラの情報
    ofCamera cam;       //寄りのレンダリング用カメラ
    ofCamera camLong;   //引きのレンダリング用カメラ
    
    vector<ofCamera> movingCameras;         //切り替え用のカメラの配列
    vector<ofVec3f> cameraRelativePosition; //カメラの位置を設定するための配列（注視点からの相対位置）
    int selectedCamera = 0; //表示しているカメラの番号
    
    //引きの映像を描くFBO
    ofFbo   fboLong;
    
    //Memeデータ格納用オブジェクト
    //大量のデータを読み込むのでthreadを使う
    //threadについては下記を参照
    //of_v0.9.0_osx_release/examples/utils/threadExample
    
    ThreadedObject data;
    
    //バーチャートを表現するための頂点バッファオブジェクト(ofVBO)
    //ofVBOについては、田所さんのサイト参照　http://yoppa.org/ma2_13/5062.html
    
    int vertsCount = 0; //頂点数のカウンタ
    ofFloatColor* vertsColor;
    ofVec3f* verts;
    ofIndexType* vertsIndex;
    ofVbo vboBarChart;
    int vboBarChartSize = 0;
    bool isVboBarChartInit = false;
    
    float camX = -40;
    float camY = 60;
    float camZ = 150;
    float camLongX = -400;
    float camLongY = 2500;
    float camLongZ = 2500;
    
    float lookAtX = 0;
    float camSpeed = 1.0;
    
    ofVec3f camDirection;
    
    
    //データの時刻を管理するオブジェクト
    GraphTime gtime;
    
    //グリッドを管理するオブジェクト
    GraphGrid grid;
    
private:
    ofTrueTypeFont fontXS;
    ofTrueTypeFont fontS;
    ofTrueTypeFont fontM;
    void makeVboBarchart();
    void camerasSetup();
    void camerasUpdate();
    
};
