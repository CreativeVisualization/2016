//PDF書き出し(画面表示なし)

//PDFライブラリのインポート
import processing.pdf.*;

void setup() {
  //PDFの出力先を指定
  size(400, 400, PDF, "output.pdf");

  //描画の設定
  noLoop();
  noFill();
  strokeCap(SQUARE);
  strokeWeight(3.0);
  background(255);
}

void draw() {
  //線を描画
  for (int i = 0; i < 100; i++) {
    stroke(random(180));
    line(random(width), random(height), random(width), random(height));
  }

  //描画が完了したらプログラムを終了
  exit();
}