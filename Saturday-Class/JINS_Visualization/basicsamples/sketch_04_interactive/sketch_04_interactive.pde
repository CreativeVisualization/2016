String lines[];

int selected = -1;
int dataNum = -1;

ArrayList<Meme> memes;

void setup(){
  size(1000,600);
  
  //1.データを配列に読み込む
  //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
  lines = loadStrings("meme_sample.csv");  
  
  //2.可変型配列memesにMemeのデータを格納する
  //memesを初期化する。
  memes = new ArrayList<Meme>();
  
  
  for (int i = 1 ; i < lines.length; i++) {
    
    //1行分のデータをセパレータ「,」で区切った配列にする。
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
  
  dataNum = memes.size();
  
}


void draw(){
  background(0);
  
  //3. データの出力
  /*
  for(int i = 0; i<memes.size(); i++){
    //memes配列からひとつのmemeを取り出す
    Meme meme = memes.get(i);
    println(meme.user_id + ":" + meme.zone_focus);
  }
  */

  //4. 最大値と最小値を調べる
  float[] values = new float[memes.size()];
  float max_value = 0;
  float min_value = 0;
  for(int i = 0; i<memes.size(); i++){
    Meme meme = memes.get(i);
    values[i] = meme.zone_focus;
    max_value = max(values);
    min_value = min(values);
  }

  //5.選択されたx座標に応じてデータを表示
  stroke(255);
  textAlign(CENTER);
  noFill();
  if(selected>=0 && selected<memes.size()){
    Meme meme = memes.get(selected);
    float d = map(meme.zone_focus, min_value, max_value, 0, 400);
    ellipse(width/2,height/2, d,d);
    
    text("zone focus", width/2,height/2-20);
    text(meme.zone_focus, width/2,height/2);
    text(meme.zone_date, width/2,height/2+20);
    
  }
  
}

void mouseMoved(){
  if(mouseX >0 && mouseX<width && mouseY >0 && mouseY <height && dataNum>0){
    println(selected);
    selected = int(map(mouseX,0,width,0,dataNum));
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