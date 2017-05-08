//PDF書き出し(カラーモードの設定)

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
  //カラーモードをHSBに
  colorMode(HSB, 360, 100, 100);
}

void draw() {
  //HSBで色を設定
  stroke(random(360), 60, 100);
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