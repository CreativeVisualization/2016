//PDF書き出し(画面表示あり)

import processing.pdf.*;

void setup() {
  size(400, 400);

  //ループなし(シングルフレーム)
  noLoop();
}

void draw() {
  //PDFの記録を開始
  beginRecord(PDF, "output.pdf");

  //描画の設定
  noFill();
  strokeCap(SQUARE);
  strokeWeight(3.0);

  //線を描画
  background(255);
  for (int i = 0; i < 100; i++) {
    stroke(random(180));
    line(random(width), random(height), random(width), random(height));
  }

  //PDFの記録を終了してファイルに書き出し
  endRecord();
}