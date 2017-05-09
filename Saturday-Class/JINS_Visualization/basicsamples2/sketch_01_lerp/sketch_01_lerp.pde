float a = 100;
float b = 800;
float c;

void setup(){
  size(900,500);
  stroke(255);
  fill(255);
  textAlign(CENTER);
}


void draw(){
  background(0);
  
  //lerp(ラープ)と読む
  //lerpとは「Linear Interpolation」（線形補完）
  //ある値aと値bの間を補完した、aとbの間の値を計算することができる。
  //lerp関数には3つのパラメータがある。
  //
  // c = lerp(a, b, 0.5);
  //
  // この場合、cはaとbのちょうど中間の値となる。
  // 第３パラメータは必ず0〜1の間の値を指定する。
  // 第３パラメータが0 の時 cはaと同じにり、1の時 cはbと同じになる。
  
  stroke(255,0,0);
  
  // 第３パラメータが0.1 の時 cはab間の差の10%だけaから離れた値。
  c = lerp(a,b,0.1);
  line(c,100,c,height-100);
  text("c="+c,c,height-80);
  
  //第３パラメータが0.5 の時cはaとbのちょうど中間の値となる。
  c = lerp(a,b,0.5);
  line(c,100,c,height-100);
  text("c="+c,c,height-80);
  
  //第３パラメータが0.9 の時 cはab間の差の90%aから離れた値。
  c = lerp(a,b,0.9);
  line(c,100,c,height-100);
  text("c="+c,c,height-80);
  
  stroke(255);
  line(a,100,a,height-100);
  text("a="+a,a,height-80);
  line(b,100,b,height-100);
  text("b="+b,b,height-80);
  
}