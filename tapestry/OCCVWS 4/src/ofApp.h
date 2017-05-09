#pragma once

#include "ofMain.h"

struct Meme {
    //memeから取得したデータ各種を格納するクラス
    //string user_id;
    //string zone_date;
    //float zone_focus;
    //float zone_calm;
    //float zone_posture;
    float eyeMoveRout;
    float cadence;
    float blink;
    float sleepy;
    float focus;
    float date=0;
    
};

struct Meme1{
    
    float eyeMoveRout1;
    float cadence1;
    float blink1;
    float sleepy1;
    float focus1;
};


class ofApp : public ofBaseApp{
    
private: ofTrueTypeFont font;
    
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
    
    //Memeのデータを格納するmemes配列
    vector<Meme> memes;
    vector<Meme1> memes1;
    
    
    
    int index = 0;      //表示するデータのインデックス
    int index1 = 0;
    
    
    //float focus;        //表示するデータ
    //float next_focus;   //次に表示するデータ
    //float morph_focus;  //データ間をモーフィングしたデータ
    float sle;
    float next_sle;
    float morph_sle;
    float sle1;
    float next_sle1;
    float morph_sle1;
    
    float foc;
    float next_foc;
    float morph_foc;
    float foc1;
    float next_foc1;
    float morph_foc1;
    
    float eye;
    float next_eye;
    float morph_eye;
    float eye1;
    float next_eye1;
    float morph_eye1;
    
    float cad;
    float next_cad;
    float morph_cad;
    float cad1;
    float next_cad1;
    float morph_cad1;
    
    float bli;
    float next_bli;
    float morph_bli;
    float bli1;
    float next_bli1;
    float morph_bli1;
    
    
    
    float h;
    
    float percent = 0;  //モーフィングの割合（lerp関数で使うため、1を超えないようにする）
    
    // 指定されたcsvを読み込んで、Memesの配列を作る関数
    void loadCsvToMemes(string filePath);
    void loadCsvToMemes1(string filePath1);
    
    
    //ofApp::draw()内での変数
    
    float max_value_sle = 0;
    float min_value_sle = 0;
    float max_value_foc = 0;
    float min_value_foc = 0;
    float max_value_eye = 0;
    float min_value_eye = 0;
    float max_value_cad = 0;
    float min_value_cad = 0;
    float max_value_bli = 0;
    float min_value_bli = 0;
    
    float max_value_sle1 = 0;
    float min_value_sle1 = 0;
    float max_value_foc1 = 0;
    float min_value_foc1 = 0;
    float max_value_eye1 = 0;
    float min_value_eye1 = 0;
    float max_value_cad1 = 0;
    float min_value_cad1 = 0;
    float max_value_bli1 = 0;
    float min_value_bli1 = 0;
    
    
    
    
    
    
    
    
    float color_sle = 0;
    float color_foc = 0;
    float color_eye = 0;
    float color_cad = 0;
    float color_bli = 0;
    
    
    float color_sle1 = 0;
    float color_foc1 = 0;
    float color_eye1 = 0;
    float color_cad1 = 0;
    float color_bli1 = 0;
    
    
    
    
    
    float Rotate = 0;
    
    ofLight light;
    
    bool loop;
    
    
    
    
};
