//PDF書き出し(画面表示あり, キー入力で書き出し)

import processing.pdf.*;

//PDF書き出しフラグ
boolean savePDF = false;

void setup() {
  size(400, 400);
  frameRate(15);
  //カーソル表示しない
  noCursor();

  //PDFの記録を開始
  beginRecord(PDF, "output.pdf");

  //描画の設定
  noFill();
  strokeCap(SQUARE);
  strokeWeight(3.0);
  background(255);
}

void draw() {
  stroke(random(180));
  line(random(width), random(height), random(width), random(height));

  //もしPDF書き出しONなら
  if (savePDF) {
    //PDF書き出しフラグリセット
    boolean savePDF = false;
    //PDFファイル書き出し
    endRecord();
    //プログラム停止(ループOFF)
    noLoop();
  }
}

//もし何かのキー入力があったら
void keyPressed() {
  //PDF書き出しフラグをONに
  savePDF = true;
}