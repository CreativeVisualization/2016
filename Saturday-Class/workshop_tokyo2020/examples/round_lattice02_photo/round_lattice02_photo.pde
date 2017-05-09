int VNUM = 16;  // 頂点の数を指定。（6以上） set nunber of corners(6 or over)
float DIAMETER = 68;
float rotateAng = 180/float(VNUM);
int rectTypeNum = int(90/rotateAng - 1);
PVector[] rectVec = new PVector[rectTypeNum];

PImage photo;


void setup(){
  size(800, 800);
  background(255);
  noStroke();
  noLoop();
  fill(30);
  
  //画像の読み込み 参照：https://processing.org/reference/PImage.html
  photo = loadImage("photo.png");
  
  for(int i=0; i<rectVec.length; i++){
    rectVec[i] = new PVector(DIAMETER*cos((i+1)*rotateAng*PI/180),DIAMETER*sin((i+1)*rotateAng*PI/180)); 
  }
}

void draw(){
  translate((width-rectVec[0].x)/2, 30);
  for(int j=0; j<VNUM; j++){
    pushMatrix();
    for(int i=0; i<rectVec.length; i++){
      drawRect(rectVec[i]);
      translate(rectVec[i].x,rectVec[i].y);
      rotate(rotateAng*PI/180);
    }
    popMatrix(); 
    translate(rectVec[0].x,rectVec[0].y);
    rotate(rotateAng*PI/180);
    translate(rectVec[1].x,0);
    rotate(rotateAng*PI/180);
    translate(0,-rectVec[0].y);
  }
}

void drawRect(PVector vec){

  //画像をリサイズして表示 視覚を埋め尽くすようにリサイズ
  //参照 https://processing.org/reference/image_.html
  image(photo,0,0,vec.x,vec.y);
}