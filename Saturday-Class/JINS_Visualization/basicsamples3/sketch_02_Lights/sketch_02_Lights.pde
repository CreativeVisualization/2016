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
  
  if(keyPressed){
    //指向性のライトを設定
    //パラメータはライトの色と方向
    //directonalLight(r,g,b,x,y,z)
    directionalLight(255,255,255,-1,-1,0); 
  }
  else{
    directionalLight(255,255,255,1,1,0); 
  }
  

  
  sphere(30);  
}