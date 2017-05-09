//複数のデータを、データ間をモーフィングさせながら可視化/可聴化してみる
//データを、形と角度と音（周波数）に変換

//sound library がない場合は インストールします。
//スケッチメニュー > ライブラリをインポート... > ライブラリを追加
//右のプルダウンメニューで「sound」
//リストの上から4つめくらいの「sound」を選択してinstallをクリック

import processing.sound.*; //sound library をインポート

float [] data = {100,150,400,300,70}; //データの配列
int index = 0;                        //表示するデータのインデックス

float size = data[index];            //表示するデータ
float next_size = data[index + 1];   //次に表示するデータ
float morph_size;                    //データ間をモーフィングしたデータ

float percent = 0;                   //モーフィングの割合（lerp関数で使うため、1を超えないようにする）

float data_max = max(data);          //データの最大値
float data_min = min(data);          //データの最小値
float morph_rotate;                   //角度の変数

SinOsc sine;                         //サイン波のオブジェクト
float morph_freq = 100;              //音の周波数の変数

void setup(){
  size(900,500);
  noStroke();
  fill(255);
  textAlign(CENTER);
  rectMode(CENTER);
  
  //サイン波のオブジェクトを初期化して再生
  sine = new SinOsc(this);
  sine.play();
}


void draw(){
  background(0);
  
  //モーフィングの計算
  morph_size = lerp(size, next_size, percent);
  
  //角度の計算
  //map関数を使って、morph_size　を -90 〜 90の間の数値に変換する。
  morph_rotate = map( morph_size, data_min, data_max, -90, 90);
  
  //周波数の計算
  //map関数を使って、morph_size　を 80Hz 〜 1000Hzの間の数値に変換する。
  morph_freq = map( morph_size, data_min, data_max, 80.0, 1000.0);
  sine.freq(morph_freq); //周波数を変更
  
  pushMatrix();
  
  translate(width/2,height/2);
  rotate( radians(morph_rotate) );
  
  //結果を四角形で可視化
  rect(0, 0, morph_size, 10);
  
  popMatrix();
  
  fill(255);
  text(morph_size, width/2, height/2 + morph_size/2 +30);
  text(morph_rotate, width/2, height/2 + morph_size/2 +50);
  text(morph_freq, width/2, height/2 + morph_size/2 +70);
  
  //モーフィングの割合を更新
  percent += 0.01;
  
  //モーフィングの割合が1になった時の処理
  if(percent >=1.0){
    
    //表示するデータのインデックスを進める
    index += 1;
    
    //配列の最後に到達したら停止
    if(index == data.length - 1){
      noLoop();
    }
    else{
      //表示するデータと、次に表示するデータを更新
      size = data[index];
      next_size = data[index + 1];
    }
    
    //モーフィングの割合を初期化
    percent = 0;
  }
 
}