String lines[];

ArrayList<Meme> memes; //memeのデータ配列

int index = 0;  //表示するデータのインデックス

float focus;        //表示するデータ
float next_focus;   //次に表示するデータ
float morph_focus;  //データ間をモーフィングしたデータ
float min_focus;    //最小値
float max_focus;    //最大値

float calm;          //表示するデータ
float next_calm;    //次に表示するデータ
float morph_calm;   //データ間をモーフィングしたデータ
float min_calm;    //最小値
float max_calm;    //最大値

float posture;          //表示するデータ
float next_posture;    //次に表示するデータ
float morph_posture;   //データ間をモーフィングしたデータ
float min_posture;    //最小値
float max_posture;    //最大値

float percent = 0; //モーフィングの割合（lerp関数で使うため、1を超えないようにする）

float x;
float y;
float px=-9999;
float py=-9999;
float viewAreaWidth = 600;
float viewAreaHeight = 600;


void setup(){
  size(1000,600);
  textAlign(CENTER);
  rectMode(CENTER);
  
  //データの読み込み
  loadData("meme_sample.csv");
  
  focus = memes.get(index).zone_focus;
  next_focus = memes.get(index+1).zone_focus;
  
  calm = memes.get(index).zone_calm;
  next_calm = memes.get(index+1).zone_calm;
  
  posture = memes.get(index).zone_posture;
  next_posture = memes.get(index+1).zone_posture;
  
  //最小値、最大値を計算する
  float[] focus_values = new float[memes.size()];
  float[] calm_values = new float[memes.size()];
  float[] posture_values = new float[memes.size()];
  for(int i = 0; i<memes.size(); i++){
    Meme meme = memes.get(i);
    focus_values[i] = meme.zone_focus;
    calm_values[i] = meme.zone_calm;
    posture_values[i] = meme.zone_posture;
  }
  max_focus = max(focus_values);
  min_focus = min(focus_values);
  max_calm = max(calm_values);
  min_calm = min(calm_values);
  max_posture = max(posture_values);
  min_posture = min(posture_values);
  

  background(0);
  noStroke();
  smooth();
  
  blendMode(ADD);
  
  stroke(200,200,255, 90);
  fill(200,200,255, 30);
  strokeWeight(0.5);
}


void draw(){
  
  translate(width/2, height/2);
  
  //モーフィングの計算
  morph_focus = lerp(focus, next_focus, percent);
  morph_calm = lerp(calm, next_calm, percent);
  morph_posture = lerp(posture, next_posture, percent);
  
  //結果を座標で表現　x軸 = focus、　y軸 = calm
  //float x = map(morph_focus, min_focus, max_focus, -250, 250);
  float y = map(morph_posture, min_posture, max_posture, -250, 250);
  float x = map(morph_calm, min_calm, max_calm, -250, 250);
  
  if(px > -9999){
   noStroke();
   fill(200,200,255, 30);
   //ellipse(x,y,weight,weight);
   
   stroke(200,200,255, 60);
   noFill();
   line(0,0,x,y); 
  }
  
  px = x;
  py = y;
  
  
  text(memes.get(index).zone_date, width/2, height-50);

  //モーフィングの割合を更新
  percent += 0.02;
  
  //モーフィングの割合が1になった時の処理
  if(percent >=1.0){
    
    //表示するデータのインデックスを進める
    index += 1;
    
    //配列の最後に到達したら停止
    if(index == memes.size() - 1){
      noLoop();
    }
    else{
      //表示するデータと、次に表示するデータを更新
      focus = memes.get(index).zone_focus;
      next_focus = memes.get(index+1).zone_focus;
      calm = memes.get(index).zone_calm;
      next_calm = memes.get(index+1).zone_calm;
      posture = memes.get(index).zone_posture;
      next_posture = memes.get(index+1).zone_posture;
    }
    
    //モーフィングの割合を初期化
    percent = 0;
  }


}

void loadData(String filename){
  
  //データを配列に読み込む
  //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
  lines = loadStrings(filename);
  
  //2.可変型配列memesにMemeのデータを格納する
  //memesを初期化する。
  memes = new ArrayList<Meme>();
  
  
  for (int i = 1 ; i < lines.length; i++) {
    String[] data = split(lines[i], ',');
    
    //memeオブジェクトを作成
    Meme meme = new Meme();
    
    meme.user_id = data[0];
    meme.zone_date = data[1];
    meme.zone_focus = float(data[2]);
    meme.zone_calm = float(data[3]);
    meme.zone_posture = float(data[4]);
    
    //memeオブジェクトを可変型配列memesに追加
    memes.add(meme);
    
  }
}

void keyPressed(){
  
  if(key == ' '){
    background(0);
    index = 0;
    percent = 0;
    px=-9999;
    loop();
  }
}

class Meme {
  String user_id;
  String zone_date;
  float zone_focus;
  float zone_calm;
  float zone_posture;
  String create_date;
  String update_date;
  
  Meme(){}
}