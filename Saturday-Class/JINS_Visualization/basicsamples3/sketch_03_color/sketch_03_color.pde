import peasy.*;

PeasyCam cam;

void setup() {
  size(200,200,P3D);
  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(50);
  cam.setMaximumDistance(500);
  
  noStroke();
  
}
void draw() {
  background(0);
  
  //環境光（指向性のない光）
  //パラメータはライトの色
  ambientLight(128,128,128);
  
  //指向性ライトの光を光の当たった方向に反射するときの色（ハイライトの色）
  lightSpecular(204,204,204);
  
  if(keyPressed){
    //指向性のライトを設定
    //パラメータはライトの色と方向
    //directonalLight(r,g,b,x,y,z)
    directionalLight(255,255,255,-1,-1,0); 
  }
  else{
    directionalLight(128,128,128,1,1,0); 
  }
  
  //物体そのものの色
  fill(255,0,0);
  //物体が指向性ライトの光を反射するときの色
  specular(255,255,255);
  //物体の光沢の強さ
  shininess(1);
  
  sphere(30);  
}