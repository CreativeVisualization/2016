import peasy.*;

//3種類のデータ（データの数は7個ずつ）を用意して3次元で可視化する
float[] dataA = {0.3,35.4,41.2,28.4,69.5,110.1,33,5};
float[] dataB = {10.3,35.4,53.7,27.3,78.6,85.3,33,19.1};
float[] dataC = {54.5,95.9,32.1,23.2,87.3,69.6,112.1,86.1};

float maxA,minA;
float maxB,minB;
float maxC,minC;

PeasyCam cam;

void setup() {
  size(500,500,P3D);
  //sizeの直後にhint関数を実行し、depth（背面の描画）を設定する。
  //fillのアルファ値が使えるようになる。ただし、実行速度が遅くなるので注意
  hint(ENABLE_DEPTH_SORT);
  //blendModeをaddに設定すると、重なった色が加算される。
  blendMode(ADD);
  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(50);
  cam.setMaximumDistance(500);
  
  //最大、最小を調べる
  
  maxA = max(dataA);
  minA = min(dataA);
  maxB = max(dataB);
  minB = min(dataB);
  maxC = max(dataC);
  minC = min(dataC);
  
  noStroke();
  
}
void draw() {
  background(0);
  
  ambientLight(280,128,128);
  lightSpecular(204,204,204);
  directionalLight(128,128,128,1,1,0); 

  // boxの大きさ
  float dim = 4;
  // box同士のマージン
  float margin = 1;
  
  //datAを高さに指定して、boxをx軸の方向に並べる
  for(int i=0; i<dataA.length; i++){
    
    pushMatrix();
    
    //map関数でデータを高さに適した値に変換
    float boxHeight = map(dataA[i], minA, maxA, 0.1, 30);
    
    //map関数でデータを色さに適した値に変換
    float boxColor = map(dataA[i], minA, maxA, 64, 255);
    
    //boxを描く位置に原点を移動
    translate(i * (dim + margin), -boxHeight/2, 0);
    
    //物体の色と反射光に色を割り当てる
    fill(0,boxColor/2,boxColor, 128);
    specular(0,boxColor/2,boxColor);
    shininess(100);
    
    box(dim, boxHeight, dim);
    
    //原点を移動する前の座標系を復元
    popMatrix();
    
  }

}