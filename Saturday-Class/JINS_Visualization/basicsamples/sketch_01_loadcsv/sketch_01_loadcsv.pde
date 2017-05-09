String lines[];

ArrayList<Meme> memes;

void setup(){
  size(1000,600);
  noLoop();
  
  //1.データを配列に読み込む
  //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
  lines = loadStrings("meme_sample.csv");
  println("データの行数は " + lines.length);
  println("==========================");
  
  println("1行目のデータは " + lines[0]);
  println("2行目のデータは " + lines[2]);
  println("==========================");
  
  
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
  
  println("格納されたmemeオブジェクトの個数 " + memes.size());
  println("==========================");
  
}


void draw(){
  background(0);
  
  //3. データの出力
  for(int i = 0; i<memes.size(); i++){
    //memes配列からひとつのmemeを取り出す
    Meme meme = memes.get(i);
    println(meme.user_id + ":" + meme.zone_focus);
  }
  
  println("==========================");
  
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
  
  println("zone_focusの最大値は "+ max_value);
  println("zone_focusの最小値は "+ min_value);
  println("==========================");
  
  
  //5.点をplotしてみる。
  strokeWeight(3);
  stroke(200,220,225);
  float Xaxis_y = height-50;
  float Xaxis_x = 50;
  float step = 7;
  for(int i = 0; i<memes.size(); i++){
    Meme meme = memes.get(i);
    
    //点のx座標の計算
    float point_x = Xaxis_x + step * i;
    
    //点のy座標の計算
    //zone_focusの値を0〜400の範囲に引き延ばす。
    //https://processing.org/reference/map_.html
    float point_y = map(meme.zone_focus, min_value, max_value, 0, 400);
    point_y = Xaxis_y - point_y;
    point(point_x, point_y);
  }
  strokeWeight(1);
  line(Xaxis_x,Xaxis_y ,width-50, Xaxis_y);
  line(50,50,Xaxis_x,Xaxis_y);
  
  
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