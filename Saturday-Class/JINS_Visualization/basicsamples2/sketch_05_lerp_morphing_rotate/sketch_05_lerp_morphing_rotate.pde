//複数のデータを、データ間をモーフィングさせながら可視化してみる
//データを、形と角度に変換

float [] data = {100,150,400,300,70}; //データの配列
int index = 0;  //表示するデータのインデックス

float size = data[index];            //表示するデータ
float next_size = data[index + 1];   //次に表示するデータ
float morph_size;                    //データ間をモーフィングしたデータ

float percent = 0;                   //モーフィングの割合（lerp関数で使うため、1を超えないようにする）

float data_max = max(data);          //データの最大値
float data_min = min(data);          //データの最小値
float morph_rotate;                   //角度の変数

void setup(){
  size(900,500);
  noStroke();
  fill(255);
  textAlign(CENTER);
  rectMode(CENTER);
}


void draw(){
  background(0);
  
  //モーフィングの計算
  morph_size = lerp(size, next_size, percent);
  
  //角度の計算
  //map関数を使って、morph_size　を -90 〜 90の間の数値に変換する。
  morph_rotate = map( morph_size, data_min, data_max, -90, 90);
  
  pushMatrix();
  
  translate(width/2,height/2);
  rotate( radians(morph_rotate) );
  
  //結果を四角形で可視化
  rect(0, 0, morph_size, 10);
  
  popMatrix();
  
  fill(255);
  text(morph_size, width/2, height/2 + morph_size/2 +30);
  text(morph_rotate, width/2, height/2 + morph_size/2 +50);
  
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