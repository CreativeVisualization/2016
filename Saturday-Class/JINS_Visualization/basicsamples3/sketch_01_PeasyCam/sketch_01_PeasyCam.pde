import peasy.*; //PeasyCamライブラリをインストールしてインポート

PeasyCam cam;

void setup() {
  size(200,200,P3D);
  cam = new PeasyCam(this, 100);  //原点からの距離の初期値100
  cam.setMinimumDistance(50);     //ズームインの最小値
  cam.setMaximumDistance(500);    //ズームアウト最大値
  
  /*
  PeasyCamの使い方
  マウスドラッグ：視点の回転
  [command]+マウスドラッグ：視点の移動
  [shift]+マウスドラッグ：軸を固定して視点の回転
  ダブルクリック：元の位置に戻る
  */
  
  noStroke();
  
}
void draw() {
  background(0);
  box(30);  
}