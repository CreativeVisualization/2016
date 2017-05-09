#include "Particles.hpp"

Particles::Particles(string filePath_meme, string filePath_first){
    
    centerPos = ofVec3f(ofRandom(ofGetWidth()/2-1800, ofGetWidth()/2+1800), ofRandom(ofGetHeight()/2 -300, ofGetHeight()/2 +300), 500);
    //centerPos = ofVec3f(0,0, 200);
    centerVelocity = ofVec3f(ofRandom(min_cadence, max_cadence *2), ofRandom(min_cadence, max_cadence *2), ofRandom(min_cadence, max_cadence *2));
    //centerVelocity = ofVec3f(0,0,0);
    
    loadCsvToMemes(filePath_meme);
    loadCsvToMemes02(filePath_first);
    
    wire = 20;
    mesh = ofSpherePrimitive(2, wire).getMesh();
    outside = ofSpherePrimitive(2, wire).getMesh();
    mesh_line = ofSpherePrimitive(2, wire).getMesh();
    
    glPointSize(3.0);
    mesh_line.setMode(OF_PRIMITIVE_POINTS);

    for (int i = 0; i < mesh.getVertices().size(); i++) {
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
    for (int i = 0; i < outside.getVertices().size(); i++) {
        outside.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
    for (int i = 0; i < mesh_line.getVertices().size(); i++) {
        mesh_line.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
}

void Particles::resetOffWalls(){
    float meshSize = 0;
    float minx = ofGetWidth()/2  -1800;
    float miny = ofGetHeight()/2 -300;
    float minz = -1000;
    float maxx = ofGetWidth()/2  +1800;
    float maxy = ofGetHeight()/2 +300;
    float maxz = -300;
    
    if (centerPos.x > maxx || centerPos.x < minx){
        centerVelocity.x *= -1;
    }
    if (centerPos.y > maxy || centerPos.y < miny){
        centerVelocity.y *= -1;
    }

    if (centerPos.z > maxz|| centerPos.z < minz){
        centerVelocity.z *= -1;
    }

}

void Particles::updatePos(){
    centerPos += centerVelocity;
}

void Particles::draw(){
    ofPushMatrix();
    ofTranslate(centerPos);
    
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        int m = ofMap(i, 0, mesh.getVertices().size(), 0, memes.size());
        int f = ofMap(i, 0, mesh.getVertices().size(), 0, firsts.size());
        Meme meme = memes[m];
        First first = firsts[f];
        
        morph_focus = ofLerp(focus, next_focus, percent);
        morph_calm = ofLerp(calm, next_calm, percent);
        morph_posture = ofLerp(posture, next_posture, percent);
        
        float posture_loc = ofMap(morph_posture, min_posture, max_posture, 0, 500);
        ofVec3f loc = mesh.getVertices()[i] / posture_loc;

        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, min_posture , max_posture *2);
        ofVec3f newLoc = loc.normalize()* noise;
        mesh.setVertex(i, newLoc);
        mesh_line.setVertex(i, newLoc*1.2);
        outside.setVertex(i, newLoc*1.2);
        
        float G = ofMap(meme.zone_focus, min_focus, max_focus, 0, 1.0);
        float R = ofMap(meme.zone_calm, min_calm, max_calm, 0, 1.0);
        float B = ofMap(first.sleepy, min_sleepy, max_sleepy, 0, 1.0);
        
        mesh.setColor(i, ofFloatColor(R, G, B, 1));
        outside.setColor(i, ofFloatColor(1.0, 1.0, 1.0, 0.1));
        mesh_line.setColor(i, ofFloatColor(R, G, B, 1));
        //mesh_line.setColor(i, ofFloatColor(1.0,1.0,1.0,0.1));
    }
    

    ofSetLineWidth(2);
    mesh.draw();
    ofDisableLighting();
    mesh_line.draw();
    ofEnableLighting();
    outside.drawWireframe();
    
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        First first = firsts[i];
        ofRotateY(first.pitchAvg *1000);
        ofRotateX(first.rollAvg *1000);
    }
    ofRotate(ofGetFrameRate());
    
    percent += 0.01;
    if(percent >= 1.0){
        index += 1;
        
        if(index == memes.size() - 1){
            
        }else {
            focus = memes[index].zone_focus;
            calm = memes[index].zone_calm;
            posture = memes[index].zone_posture;
            next_focus = memes[index+1].zone_focus;
            next_calm = memes[index+1].zone_calm;
            next_posture = memes[index+1].zone_posture;
        }
        percent = 0;
    }
    ofPopMatrix();
    
}




//--------------------------------------------------------------
void Particles::loadCsvToMemes(string filePath_meme){
    ofFile file_meme(filePath_meme);
    
    if(!file_meme.exists()){
        ofLogError("The file " + filePath_meme + " is missing");
    }
    
    ofBuffer buffer(file_meme);
    
    //データをVector(配列)に読み込む
    //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        vector<string> data = ofSplitString(line, ",");
        if (data.size()>=6) {
            
            Meme meme;
            meme.user_id = data[0];
            meme.zone_date = data[1];
            meme.zone_focus = ofToFloat(data[3]);
            meme.zone_calm = ofToFloat(data[4]);
            meme.zone_posture = ofToFloat(data[5]);
            memes.push_back(meme);
            
            if(it == buffer.getLines().begin()){
                max_focus = min_focus = meme.zone_focus;
                max_calm = min_calm = meme.zone_calm;
                max_posture  = min_posture = meme.zone_posture;
            }
            else{
                //データをひとつずつ比較しながら最小値最大値を調べる
                max_focus = (meme.zone_focus > max_focus) ? meme.zone_focus : max_focus;
                min_focus = (meme.zone_focus < min_focus) ? meme.zone_focus : min_focus;
                max_calm = (meme.zone_calm > max_calm) ? meme.zone_calm : max_calm;
                min_calm = (meme.zone_calm < min_calm) ? meme.zone_calm : min_calm;
                max_posture = (meme.zone_posture > max_posture) ? meme.zone_posture : max_posture;
                min_posture = (meme.zone_posture < min_posture) ? meme.zone_posture : min_posture;
                
            }
            
        }
    }
    
}
//--------------------------------------------------------------
void Particles::loadCsvToMemes02(string filePath_first){
    ofFile file_first(filePath_first);
    
    if(!file_first.exists()){
        ofLogError("The file " + filePath_first + " is missing");
    }
    ofBuffer buffer(file_first);
    
    //データをVector(配列)に読み込む
    //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        vector<string> data = ofSplitString(line, ",");
        if (data.size()>=6) {
            
            First first;
            first.cadence = ofToFloat(data[10]);
            first.pitchAvg = ofToFloat(data[47]);
            first.rollAvg = ofToFloat(data[50]);
            first.sleepy = ofToFloat(data[54]);
            firsts.push_back(first);
            
            if(it == buffer.getLines().begin()){
                max_cadence = min_cadence = first.cadence;
                max_sleepy = min_sleepy = first.sleepy;
            }
            else{
                //データをひとつずつ比較しながら最小値最大値を調べる
                max_cadence = (first.cadence > max_cadence) ? first.cadence : max_cadence;
                max_sleepy = (first.sleepy > max_sleepy) ? first.sleepy : max_sleepy;
            }
            
        }
    }
}

