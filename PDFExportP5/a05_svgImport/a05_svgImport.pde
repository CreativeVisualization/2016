//SVG形式の画像を読み込んで表示
import processing.pdf.*;

//SVGを読み込むシェイプ
PShape shape;

void setup() {
  size(640, 480);
  noLoop();

  //SVGファイルを読み込み
  shape = loadShape("tiger.svg");
}

void draw() {
  //PDFの記録を開始
  beginRecord(PDF, "output.pdf");

  background(102);
  //10回くりかえし
  for (int i = 0; i < 10; i++) {
    //位置と大きさを設定
    float position = map(i, 0, 10, 20, 120);
    float size = map(i, 0, 10, 80, 400);
    //SVGデータを描画
    shape(shape, position, position, size, size);
  }

  //PDFの記録を終了してファイルに書き出し
  endRecord();
}
