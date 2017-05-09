/*
このサンプルの詳しい解説は、「ビジュアライジング・データ――Processingによる情報視覚化手法」の
「7.3.2ツリーマップの簡単な例」を参考にしてください。
https://www.oreilly.co.jp/books/9784873113784/

元のソースコードは、著者であるBenFryのページからダウンロードできます。
Chapter 7 (hierarchies, recursion, word treemap, disk space treemap)

http://benfry.com/writing/archives/3


実行にはtreemapライブラリが必要です。以下のURLでダウンロードできます。
Processingフォルダの「libraries」フォルダに解凍した「treemap」を移します。
http://benfry.com/writing/treemap/library


*/

import treemap.*;

Treemap map;

String lines[];
ArrayList<Meme> memes;

void setup() {
  size(1024, 768);

  smooth();
  strokeWeight(0.25f);
  PFont font = createFont("Serif", 13);
  textFont(font);

  WordMap mapData = new WordMap();
  
  //データを配列に読み込む
  //CSVファイルを読み込んで、1行ごとに配列linesの要素として読み込む
  lines = loadStrings("tamabi01.csv");
  
  
  //可変型配列memesにMemeのデータを格納する
  //memesを初期化する。
  memes = new ArrayList<Meme>();
  for (int i = 1 ; i < lines.length; i++) {
    String[] data = split(lines[i], ',');
    
    //memeオブジェクトを作成
    Meme meme = new Meme();
    
    meme.user_id = data[0];
    meme.zone_date = data[1];
    meme.zone_focus = float(data[3]);
    meme.zone_calm = float(data[4]);
    meme.zone_posture = float(data[5]);
    
    //memeオブジェクトを可変型配列memesに追加
    memes.add(meme);
  }
    

  int focusLevel = 0;
  int calmLevel = 0;
  int postureLevel = 0;
    
  for(int i=0; i<memes.size(); i++){
    
    Meme meme = memes.get(i);
    
    //focusの値を10段階のレベルに判定する
    focusLevel = int(map(meme.zone_focus,0,100,0,9));
    //calmの値を10段階のレベルに判定する
    calmLevel = int(map(meme.zone_calm,0,100,0,9));
    //postureの値を10段階のレベルに判定する
    postureLevel = int(map(meme.zone_posture,0,100,0,9));
    
    //それぞれのレベルを組み合わせたラベルを作る
    String labelName = "F"+str(focusLevel) +"C"+ str(calmLevel) +"P" + str(postureLevel);
    
    mapData.addWord(labelName, meme.zone_focus, meme.zone_calm, meme.zone_posture);
    
    
  }
  
  mapData.finishAdd();
  map = new Treemap(mapData, 0, 0, width, height);

  // only run draw() once
  noLoop();
}


void draw() {
  background(255);
  map.draw();
}



class Meme {
  String user_id;
  String zone_date;
  float zone_focus;
  float zone_calm;
  float zone_posture;
  String create_date;
  String update_date;
  
  Meme(){}
}