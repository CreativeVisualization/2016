import peasy.*;

//3種類のデータ（データの数は7個ずつ）を用意して3次元で可視化する
float[] dataA = {0.3,35.4,41.2,28.4,69.5,110.1,33,5};
float[] dataB = {10.3,35.4,53.7,27.3,78.6,85.3,33,19.1};
float[] dataC = {54.5,95.9,32.1,23.2,87.3,69.6,112.1,86.1};

PeasyCam cam;

void setup() {
  size(500,500,P3D);
  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(50);
  cam.setMaximumDistance(500);
  
  noStroke();
  
}
void draw() {
  background(0);
  
  //環境光（指向性のない光）
  ambientLight(128,128,128);
  
  //指向性ライトの光を光の当たった方向に反射するときの色（ハイライトの色）
  lightSpecular(204,204,204);
  
  //指向性のライトを設定
  //パラメータはライトの色と方向
  directionalLight(128,128,128,1,1,0); 

  // boxの大きさ
  float dim = 4;
  
  // box同士のマージン
  float margin = 1;
  
  //box10個をx軸の方向に並べる
  for(int i=0; i<10; i++){
    
    //原点を移動する前の座標系を記録
    pushMatrix();
    
    //boxを描く位置に原点を移動
    translate(i * (dim + margin), 0, 0);
    
    //物体そのものの色
    fill(25*i,64,64);
    //物体が指向性ライトの光を反射するときの色
    specular(255,255,255);
    //物体の光沢の強さ
    shininess(1);
    
    box(dim, dim, dim);
    
    //原点を移動する前の座標系を復元
    popMatrix();
    
  }

}