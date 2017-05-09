#ifndef ____Tamabi01__
#define ____Tamabi01__

#pragma once

#include "ofMain.h"
#include <stdio.h>

struct Meme {
    //meme„Åã„ÇâÂèñÂæó„Åó„Åü„Éá„Éº„ÇøÂêÑÁ®Æ„ÇíÊ†ºÁ¥ç„Åô„Çã„ÇØ„É©„Çπ
    string user_id;
    string zone_date;
    float zone_focus;
    float zone_calm;
    float zone_posture;
};


class Tamabi01{
    
public:
    
    Tamabi01( string filePath );
    
    void setup();
    void update();
    void draw();
    
    int index = 0;
    float focus;        //Ë°®Á§∫„Åô„Çã„Éá„Éº„Çø
    float next_focus;
    float morph_focus;  //„Éá„Éº„ÇøÈñì„Çí„É¢„Éº„Éï„Ç£„É≥„Ç∞„Åó„Åü„Éá„Éº„Çø
    
    float calm;
    float next_calm;
    float morph_calm;
    
    float posture;
    float next_posture;
    float morph_posture;
    
    float percent = 0;
    float step =0;
    
    // ÊåáÂÆö„Åï„Çå„Åücsv„ÇíË™≠„ÅøËæº„Çì„Åß„ÄÅMemes„ÅÆÈÖçÂàó„Çí‰Ωú„ÇãÈñ¢Êï∞
    void loadCsvToMemes(string filePath);
    
    //Meme„ÅÆ„Éá„Éº„Çø„ÇíÊ†ºÁ¥ç„Åô„ÇãmemesÈÖçÂàó
    vector<Meme> memes;
    
    //ÂêÑ„Éá„Éº„Çø„ÅÆÊúÄÂ§ßÊúÄÂ∞è„ÇíÊ†ºÁ¥ç„Åô„ÇãÂ§âÊï∞
    float max_focus, min_focus;
    float max_calm, min_calm;
    float max_posture, min_posture;
    
    //Processing„ÅÆPeasyCam„Å®„Åª„ÅºÂêå„Åò„ÄÅofEasyCam„Ç™„Éñ„Ç∏„Çß„ÇØ„Éà
    ofEasyCam cam;
    
};


#endif /* defined(____Tamabi01__) */
