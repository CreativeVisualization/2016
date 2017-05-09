String myCode = "776583657573896577656669";
String myName = "MASAKI YAMABE";
int myCodeLength = myCode.length();

int margin = 11;
float bar_x, bar_y, bar_h;
int bar_w = 10;

float visualWidth = myCodeLength*(margin -1);

size(500, 500);
background(0);
fill(255);
noStroke();

rectMode(CENTER);

for (int i=0; i<myCodeLength; i++) {
  bar_x = (width - visualWidth)/2 + i*margin;
  bar_y = height/2;
  int num = parseInt(myCode.substring(i, i+1));
  bar_h = num*10;
  rect(bar_x, bar_y, bar_w, bar_h);
}

PFont f;
f = createFont("Georgia", 14);
textFont(f);
textAlign(CENTER, CENTER);

text(myName, width/2, height-80);