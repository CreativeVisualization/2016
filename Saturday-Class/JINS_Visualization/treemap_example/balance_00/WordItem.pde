class WordItem extends SimpleMapItem {
  String word;
  float focus;
  float calm;
  float posture;

  WordItem(String word, float f, float c, float p) {
    this.word = word;
    this.focus = f;
    this.calm = c;
    this.posture = p;
  }

  void draw(){
    
    //四角形を描く色を決める
    float r = map(this.focus, 0, 100, 0, 255);
    float g = map(this.calm, 0, 100, 0, 255);
    float b = map(this.posture, 0, 100, 0, 255);
    fill(r,g,b);
    rect(x, y, w, h);

    fill(0);
    if (w > textWidth(word) + 6) {
      if (h > textAscent() + 6) {
        textAlign(CENTER, CENTER);
        text(word, x + w/2, y + h/2);
      }
    }
  }
}