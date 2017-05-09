#pragma once


#include "ofThread.h"
#include "Meme.h"

class ThreadedObject: public ofThread
{
public:
    
    string filePath;
    bool isLoadFinished = false;
    
    //データを格納するmemes配列
    vector<MemeUser> users;
    
    ///各データの最大最小を格納する変数
    float max_focus, min_focus;
    float max_sleepy, min_sleepy;    
    float max_eyeMoveRout, min_eyeMoveRout;
    int max_stime, min_stime;
    
    //データの全体数
    int allDataCount;
    
    
    ThreadedObject(): count(0), shouldThrowTestException(false)
    {
    }
    
    void start()
    {
        startThread();
    }
    
    void stop()
    {
        stopThread();
    }
    
    /// Our implementation of threadedFunction.
    void threadedFunction()
    {
        while(isThreadRunning())
        {
            
            if(lock())
            {
                
                loadCsvToMemes(filePath);
                
                unlock();
                
                if(shouldThrowTestException > 0)
                {
                    shouldThrowTestException = 0;
                    throw Poco::ApplicationException("We just threw a test exception!");
                }
            }
            else
            {
                ofLogWarning("threadedFunction()") << "Unable to lock mutex.";
            }
            
            stop();
        }
    }
    
    void setFilePath(string path){
        filePath = path;
    }
    
    
    void throwTestException()
    {
        shouldThrowTestException = 1;
    }
    
    void loadCsvToMemes(string filePath){
        
        
        ofFile file(filePath);
        
        if(!file.exists()){
            ofLogError("The file " + filePath + " is missing");
        }
        
        ofBuffer buffer(file);
        
        bool isFirstline = true;
        //データをVector(配列)に読み込む
        //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
            string line = *it;
            vector<string> data = ofSplitString(line, ",");
            if (data.size()>=6 && it != buffer.getLines().begin()) {
                
                
                Meme meme;
                allDataCount ++;
                
                //既に登録済みのUserか調べる
                string user_id = data[0];
                int match_user_index = -1;
                for(int i=0; i<users.size(); i++){
                    if(user_id == users[i].user_id){
                        match_user_index = i;
                    }
                }
                
                //未登録の場合
                if( match_user_index == -1){
                    //Make New User
                    MemeUser user;
                    
                    meme.setup(data);
                    user.setup(data);
                    
                    //連想配列への追加
                    user.memesm[meme.stime] = meme;
                    
                    users.push_back(user);
                }
                //登録済みの場合
                else{
                    meme.setup(data);
                    
                    //連想配列への追加
                    users[match_user_index].memesm[meme.stime] = meme;
                }
                
                if(isFirstline){
                    max_focus = min_focus = meme.focus;
                    max_stime = min_stime = meme.stime;
                    max_eyeMoveRout = meme.eyeMoveRout;
                    max_sleepy = meme.sleepy;
                    
                    ofLog() <<"stime "<< meme.stime;
                    isFirstline = false;
                }
                else{
                    //データをひとつずつ比較しながら最小値最大値を調べる
                    max_focus = (meme.focus > max_focus) ? meme.focus : max_focus;
                    min_focus = (meme.focus < min_focus) ? meme.focus : min_focus;
                    max_stime = (meme.stime > max_stime) ? meme.stime : max_stime;
                    min_stime = (meme.stime < min_stime) ? meme.stime : min_stime;
                    max_eyeMoveRout = (meme.eyeMoveRout > max_eyeMoveRout) ? meme.eyeMoveRout : max_eyeMoveRout;
                    min_eyeMoveRout = (meme.eyeMoveRout < min_eyeMoveRout) ? meme.eyeMoveRout : min_eyeMoveRout;
                    
                    max_sleepy = (meme.sleepy > max_sleepy) ? meme.sleepy : max_sleepy;
                    min_sleepy = (meme.sleepy < min_sleepy) ? meme.sleepy : min_sleepy;

                }
                
            }
        }
        
        isLoadFinished = true;
        
        ofLog() << "Users: " << users.size();
        ofLog() << "Data Size " << allDataCount;
        ofLog() << "Max_stime " << max_stime;
        ofLog() << "Min_stime " << min_stime;
        ofLog() <<"max_sleepy "<< max_sleepy;
    }
    
    
    
    
    
protected:
    Poco::AtomicCounter shouldThrowTestException;
    int count;
    
};
