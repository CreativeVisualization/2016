import peasy.*;

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