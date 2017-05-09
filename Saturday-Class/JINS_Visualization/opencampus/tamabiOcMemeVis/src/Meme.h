//
//  Meme.h
//  loadCsvTherad
//
//  Created by Masaki Yamabe on 2016/07/09.
//
//

//memeから取得したデータ各種を格納するクラス
class Meme {
    
public:
    
    float eyeMoveRout;
    float sleepy;
    float focus;

    int vertsIndex;
    int stime;
    
    float bar_height;
    ofVec3f bar_pos;
    
    void setup(vector<string> &data ){
        focus = ofToFloat(data[18]);
        eyeMoveRout = ofToFloat(data[13]);
        sleepy = ofToFloat(data[32]);
        
        // データの時刻はあらかじめエクセル上でシリアル値に変換したものを読み込んで使う（serialMin）
        stime = ofToInt(data[12]); //serialMin;
        
    }
};


//ユーザーのクラス
class MemeUser {
    
public:
    string user_id;
    bool isSelected;
    
    //Memeのデータを格納する連想配列
    map<int,Meme> memesm;
    
    void setup(vector<string> &data ){
        user_id = data[0];
    }
    
};

//データの時刻を管理するクラス
class GraphTime {
    
public:
    int start;  //グラフ化を開始する時刻
    int end;    //グラフ化を終了する時刻
    int current; //現在の時刻
    int startMonth;
    int startDay;
    
    int step;
    
    void setup(int startSerial, int endSerial, int stepSerial, int month, int day){
        start = startSerial;
        end = endSerial;
        step = stepSerial;
        startMonth = month;
        startDay = day;
        current = start;
    }
    void update(){
        current += step;
        if(current >= end){
            current = start;
        }
    }
    
    string toTimeString(int serialMin){
        
        //sirialから時間の文字列に変換する
        int pastMin = serialMin;
        int pastHour = pastMin / 60;
        int pastDay = pastMin / 1440; //60*24
        
        int currentMonth = startMonth;
        int currentDay = startDay + pastDay;
        int currentHour = pastHour % 24;
        int currentMin = pastMin % 60;
        
        string time = toDisimalString(currentMonth)+"/"+toDisimalString(currentDay) + " " + toDisimalString(currentHour)+ ":" + toDisimalString(currentMin);
        
        return time;
        
    }
    
    string toMinString(int serialMin){
        
        int pastMin = serialMin;
        int pastHour = pastMin / 60;
        
        int currentHour = pastHour % 24;
        int currentMin = pastMin % 60;
        string time = toDisimalString(currentHour)+ ":" + toDisimalString(currentMin);
        
        return time;
    }
    
private:
    string toDisimalString(int n){
        //一桁だったら二桁にする
        string dis = (n < 10) ? "0"+ ofToString(n) : ofToString(n);
        return dis;
    }
    
};


// グラフに描くグリッドのクラス
class GraphGrid {
    
public:
    
    //グリッドを描く平面の開始点と終了点
    ofVec3f cornerBegin;
    ofVec3f cornerEnd;
    
    //時刻管理のオブジェクト
    GraphTime gt;
    
    //データ間のマージン、x,z方向それぞれ
    float dataMarginX;
    float dataMarginZ;
    
    //グリッドのマージン、x,z方向それぞれ
    float gridStepX;
    float gridStepZ;
    
    //y軸の長さと最大値
    float axisY_length;
    float axisY_value;
    
    //ユーザー名の配列
    vector<string> username;
    
    ofTrueTypeFont fontSmall;
    ofTrueTypeFont fontXSmall;
    
    void setup(GraphTime &g, float pixelPerMin, int userNum, float pixelPerUser, float gridPerMin, float gridPerUser, float maxValue, float maxHeight){
        gt = g;
        dataMarginX = pixelPerMin;
        dataMarginZ = pixelPerUser;
        cornerBegin = ofVec3f(gt.start * dataMarginX, 0, -1*int(userNum/2+1)*dataMarginZ);
        cornerEnd = ofVec3f(gt.end * dataMarginX, 0 , int(userNum/2+1)*dataMarginZ);
        gridStepX = gridPerMin;
        gridStepZ = gridPerUser;
        axisY_value = maxValue;
        axisY_length = maxHeight;
    }
    
    //ユーザーを追加する
    void addUser(string name){
        username.push_back(name);
    }
    
    void setFonts( ofTrueTypeFont &fontS, ofTrueTypeFont &fontXS ){
        
        fontSmall = fontS;
        fontXSmall = fontXS;
        
    }
    
    //シンプルなグリッドを描く（引きの映像用）
    void drawSimple(){
        ofPushStyle();
        
        ofSetColor(255,255,255,25);
        
        int serial = gt.start;
        
        
        for(float i = cornerBegin.x; i <= cornerEnd.x ; i += dataMarginX * gridStepX){
            
            
            if(serial%60==0) {
                //60分おきに太くする
                ofSetLineWidth(1);
                
            }
            else{
                ofSetLineWidth(0.1);
            }
            
            if(serial%1440==0 || i == cornerBegin.x) {
                //1440分＝24時間おきに時間を表示する、線を太くする
                ofPushStyle();
                ofSetColor(255, 200);
                ofDrawBitmapString(gt.toTimeString(serial), i, cornerBegin.y-100, cornerEnd.z);
                ofPopStyle();
                ofPushStyle();
                ofSetLineWidth(1);
                ofSetColor(255);
                ofDrawLine(i, cornerBegin.y, cornerBegin.z, i, cornerBegin.y, cornerEnd.z);
                ofPopStyle();
                
            }
            
            ofDrawLine(i, cornerBegin.y, cornerBegin.z, i, cornerBegin.y, cornerEnd.z);
            
            serial += gridStepX;
        }
        
        
        ofSetLineWidth(0.1);
        for(float i = cornerBegin.z; i <= cornerEnd.z; i += dataMarginZ * gridStepZ ){
            
            ofDrawLine(cornerBegin.x, cornerBegin.y , i, cornerEnd.x ,cornerEnd.y ,i);
        }
        
        ofPopStyle();
        
    }
    
    //ノーマルなグリッドを描く（寄りの映像用）
    void draw(int currentSerial){
        
        ofPushStyle();
        
        ofSetColor(255,255,255,100);
        
        int serial = gt.start;
        
        
        for(float i = cornerBegin.x; i <= cornerEnd.x ; i += dataMarginX * gridStepX){
            
        
            ofSetLineWidth(1);
            if(serial % 180 ==0){
                //180分＝3時間おきに時間を表示する、線を太くする
                ofPushMatrix();
                
                ofPushStyle();
                float currentx = currentSerial * dataMarginX;
                float distanceFromCurrentX = abs(currentx - i);
                float textAlpha;
                float alphaRatio;
                //現在を示す軸との距離が離れるほど文字のアルファを低くする。
                if( pow(distanceFromCurrentX, 2) < 1){
                    alphaRatio = 1;
                }
                else{
                    alphaRatio = 300000 / pow(distanceFromCurrentX, 2);
                    if(alphaRatio > 1.0) alphaRatio = 1.0;
                }
                textAlpha = 220 * alphaRatio;
                ofSetColor(255,textAlpha);
                ofTranslate(i, cornerBegin.y, cornerBegin.z);
                ofRotateY(-90);
                fontSmall.drawStringAsShapes(gt.toTimeString(serial), 0 - fontSmall.stringWidth(gt.toTimeString(serial)), 0);
                ofPopStyle();
                
                ofPopMatrix();
                
            }
            if(serial % 720 ==0){
                //720分＝12時間おきにユーザー名を表示する
                ofPushStyle();
                ofSetColor(255,128);
                
                for(int j=0; j < username.size(); j++){
                    ofPushMatrix();
                    ofTranslate(i, cornerBegin.y, cornerBegin.z + (j+1) * dataMarginZ);
                    
                    ofRotateX(-90);
                    fontXSmall.drawStringAsShapes(username[j], 0 - fontXSmall.stringWidth(gt.toTimeString(serial)), 0);
                    
                    ofPopMatrix();
                }
                
                ofPopStyle();
            }
            ofDrawLine(i, cornerBegin.y, cornerBegin.z, i, cornerBegin.y, cornerEnd.z);
            serial += gridStepX;
        }
        
        ofSetLineWidth(0.1);
        for(float i = cornerBegin.z; i <= cornerEnd.z; i += dataMarginZ * gridStepZ ){
            
            ofDrawLine(cornerBegin.x, cornerBegin.y , i, cornerEnd.x ,cornerEnd.y ,i);
        }
        
        ofPopStyle();
    }
    
    //現在時刻のX座標を返す
    float getCurrentX(int serial){
        return serial * dataMarginX;
    }
    
    //現在時刻を示すラインの表示
    void drawCurrentLine(int serial, bool isNear){
        
        float x = serial * dataMarginX;
        ofPushStyle();
        ofSetColor(0,180,255,180);
        ofSetLineWidth(1);
        if(!isNear){ ofPushStyle(); ofSetLineWidth(2);}
        ofDrawLine(x, cornerBegin.y, cornerBegin.z, x, cornerEnd.y, cornerEnd.z+10);
        ofDrawLine(x, cornerBegin.y, cornerBegin.z, x, cornerBegin.y + axisY_length, cornerBegin.z);
        if(!isNear){ofPopStyle();}
        if(isNear){
            ofSetColor(255,180);
            ofDrawBitmapString("eyeMoveBigHorizontal", x+5, cornerBegin.y + axisY_length-5, cornerBegin.z);
            ofDrawBitmapString(gt.toTimeString(serial), x, 0, cornerEnd.z+10);
        }
        ofPopStyle();
        
    }
    
    
};