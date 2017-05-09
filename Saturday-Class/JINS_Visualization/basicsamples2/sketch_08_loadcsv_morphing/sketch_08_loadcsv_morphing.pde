String lines[];

ArrayList<Meme> memes; //memeのデータ配列

int index = 0;  //表示するデータのインデックス

float focus;        //表示するデータ
float next_focus;   //次に表示するデータ
float morph_focus;  //データ間をモーフィングしたデータ

float percent = 0; //モーフィングの割合（lerp関数で使うため、1を超えないようにする）


void setup(){
  size(1000,600);
  textAlign(CENTER);
  rectMode(CENTER);
  
  //データの読み込み
  loadData("meme_sample.csv");
  
  focus = memes.get(index).zone_focus;
  next_focus = memes.get(index+1).zone_focus;
  
}


void draw(){
  background(0);
  
  //モーフィングの計算
  morph_focus = lerp(focus, next_focus, percent);
  
  //結果を四角形で可視化
  rect(width/2, height/2, morph_focus, morph_focus);
  text(morph_focus, width/2, height/2 + morph_focus/2 +30);
  text(memes.get(index).zone_date, width/2, height-50);

  //モーフィングの割合を更新
  percent += 0.05;
  
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