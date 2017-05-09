float size_a = 100;
float size_b = 200;
float size_c;



void setup(){
  size(900,500);
  stroke(255);
  fill(255);
  textAlign(CENTER);
  rectMode(CENTER);
}


void draw(){
  background(0);
 
  
  float percent = map(sin(frameCount*0.05),-1,1,0,1);  //0〜1の間で変化する変数を作る
  
  size_c = lerp(size_a,size_b,percent); // size_c は、size_aとsize_bをモーフィングする

  rect(width/2, height/2, size_c, size_c);
  
  rect(width/4, height/2, size_a, size_a);
  
  rect(width*3/4, height/2, size_b, size_b);
  
  text(size_c, width/2, height/2 + size_c/2 + 30);
  
  text(size_a, width/4, height/2 + size_a/2 +30);
  
  text(size_b, width*3/4, height/2 + size_b/2 + 30);
  
}