
float radius = 300;
PVector rectA = new PVector(radius*cos(15*PI/180),radius*sin(15*PI/180));
PVector rectB = new PVector(radius*cos(30*PI/180),radius*sin(30*PI/180));
PVector rectC = new PVector(radius*cos(45*PI/180),radius*sin(45*PI/180));

PVector defv = new PVector(100,100);

void setup(){
  size(400,400);
  noFill();
  strokeWeight(2);
  rectMode(CENTER);
  noLoop();
}

void draw(){
  
  
  translate(width/2,height/2);
  
  ellipse(0,0,radius,radius);
  line(-radius/2,0,radius/2,0);
  
  rotate(15*PI/180);
  
  //Aの四角形
  stroke(0,0,255);
  rect(0,0,rectA.x,rectA.y);

  rotate(15*PI/180);
  //Bの四角形
  stroke(255,0,0);
  rect(0,0,rectB.x,rectB.y);
  
  rotate(15*PI/180);
  
  //Cの四角形
  stroke(0,128,32);
  rect(0,0,rectC.x,rectC.y);

}