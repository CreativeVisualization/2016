#pragma once
#include "ofMain.h"
struct Meme {
    //memeから取得したデータ各種を格納するクラス
    string user_id;
    string zone_date;
    float zone_focus;
    float zone_calm;
    float zone_posture;
};
struct First {
    float cadence;
    float sleepy;
    float pitchAvg;
    float rollAvg;
};



class Particles {
public:
    Particles(string filePath_meme, string filePath_first);
    void setup();
    void draw();
    void resetOffWalls();
    void updatePos();
    void loadCsvToMemes(string filePath_meme);
    void loadCsvToMemes02(string filePath_first);
    
    
    //Meme
    vector<Meme> memes;
    float max_focus, min_focus;
    float max_calm, min_calm;
    float max_posture, min_posture;
    
    float morph_focus;
    float morph_calm;
    float morph_posture;
    
    float next_focus;
    float next_calm;
    float next_posture;
    
    float focus;
    float calm;
    float posture;
    
    float percent = 0;
    int index = 0;
    
    //First
    vector<First> firsts;
    float max_cadence,min_cadence;
    float max_sleepy,min_sleepy;
    
    
    
    //mesh
    ofMesh mesh;
    ofMesh outside;
    ofVboMesh mesh_line;
    
    int wire;
    ofVec3f centerVelocity;
    ofVec3f centerPos;
    
};

