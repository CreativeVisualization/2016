import peasy.*;

String lines[];

ArrayList<Meme> memes;

  float max_focus = 0;
  float min_focus = 0;
  float max_calm = 0;
  float min_calm = 0;
  float max_posture = 0;
  float min_posture = 0;

PeasyCam cam;

void setup() {
  size(500,500,P3D);
  //sizeの直後にhint関数を実行し、depth（背面の描画）を設定する。
  //fillのアルファ値が使えるようになる。実行速度が遅くなるので注意
  //hint(ENABLE_DEPTH_SORT);
  //blendModeをaddに設定すると、重なった色が加算される。
  //blendMode(ADD);
  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(50);
  cam.setMaximumDistance(500);
  
  //データを配列に読み込む
  //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
  lines = loadStrings("tamabi01.csv");
  
  
  //可変型配列memesにMemeのデータを格納する
  //memesを初期化する。
  memes = new ArrayList<Meme>();
  for (int i = 1 ; i < lines.length; i++) {
    String[] data = split(lines[i], ',');
    
    //memeオブジェクトを作成
    Meme meme = new Meme();
    
    meme.user_id = data[0];
    meme.zone_date = data[1];
    meme.zone_focus = float(data[3]);
    meme.zone_calm = float(data[4]);
    meme.zone_posture = float(data[5]);
    
    //memeオブジェクトを可変型配列memesに追加
    memes.add(meme);
  }
  
  //最大、最小を調べる
  float[] values_focus = new float[memes.size()];
  float[] values_calm = new float[memes.size()];
  float[] values_posture = new float[memes.size()];

  for(int i = 0; i<memes.size(); i++){
    Meme meme = memes.get(i);
    values_focus[i] = meme.zone_focus;
    values_calm[i] = meme.zone_calm;
    values_posture[i] = meme.zone_posture;
  }
  max_focus = max(values_focus);
  min_focus = min(values_focus);
  max_calm = max(values_calm);
  min_calm = min(values_calm);
  max_posture = max(values_posture);
  min_posture = min(values_posture);
  
  println("maxforcus:"+ max_focus);
  println("minforcus:"+ min_focus);
  println("maxcalm:"+ max_calm);
  println("mincalm:"+ min_calm);
  println("maxposture:"+ max_posture);
  println("minposture:"+ min_posture);
  
  noStroke();
  
}
void draw() {
  background(0);
  
  ambientLight(280,128,128);
  lightSpecular(204,204,204);
  directionalLight(128,128,128,1,1,0); 

  // boxの大きさ
  float dim = 1;

  for(int i=0; i<memes.size(); i++){
    
    Meme meme = memes.get(i);
    
    pushMatrix();
    
    //map関数でデータを高さに適した値に変換
    float boxHeight = map(meme.zone_focus, min_focus, max_focus, 0.1, 30);
    
    //map関数でデータをX座標に適した値に変換
    float posX = map(meme.zone_calm, min_calm, max_calm, -50, 50);
    
    //map関数でデータをZ座標に適した値に変換
    float posZ = map(meme.zone_posture, min_posture, max_posture, -50, 50);
    
    //map関数でデータを色さに適した値に変換
    float boxColorR = map(meme.zone_calm, min_calm, max_calm, 64, 255);
    float boxColorG = map(meme.zone_posture, min_posture, max_posture, 64, 255);
    
    //boxを描く位置に原点を移動
    translate(posX, -boxHeight/2, posZ);
    
    //物体の色と反射光に色を割り当てる
    fill(boxColorR, boxColorG, 255, 128);
    specular(boxColorR, boxColorG, 255);
    shininess(100);
    
    box(dim, boxHeight, dim);
    
    //原点を移動する前の座標系を復元
    popMatrix();
    
  }
  
  //XZ平面のグリッドを描く
  stroke(64);
  int minGrid = -100;
  int maxGrid = 100;
  int gridMargin = 10;
  for(int i=minGrid; i<=maxGrid; i+=gridMargin){
    if(i==0) {
      strokeWeight(1);
    }
    else{
      strokeWeight(0.25);
    }

    line(i,0,minGrid,i,0,maxGrid);
    line(minGrid,0,i,maxGrid,0,i);
  }
  noStroke();

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