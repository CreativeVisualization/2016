//元となるプログラム
//100本の線をランダムに引く

void setup() {
  size(400, 400);
  //ループなし
  noLoop();
  
  //描画の設定
  noFill();
  strokeCap(SQUARE);
  strokeWeight(3.0);
  background(255);
}

void draw() {
  //100本の線を引く
  for (int i = 0; i < 100; i++) {
    stroke(random(180));
    line(random(width), random(height), random(width), random(height));
  }
}