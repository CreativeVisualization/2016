import peasy.*;

//3種類のデータ（データの数は7個ずつ）を用意して3次元で可視化する
//dataAを高さに割り当てる（）
//dataBをXZ平面のXに割り当てる
//dataCをXZ平面のZに割り当てる
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
  //fillのアルファ値が使えるようになる。
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
    
    //map関数でデータをX座標に適した値に変換
    float posX = map(dataB[i], minB, maxB, -10, 10);
    
    //map関数でデータをZ座標に適した値に変換
    float posZ = map(dataC[i], minC, maxC, -10, 10);
    
    //map関数でデータを色さに適した値に変換
    float boxColorR = map(dataB[i], minB, maxB, 64, 255);
    float boxColorG = map(dataC[i], minC, maxC, 64, 255);
    
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