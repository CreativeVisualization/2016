String myCode = "776583657573896577656669";
String myName = "MASAKI YAMABE";
int myCodeLength = myCode.length();

int margin = 11;
float bar_x, bar_y;
int bar_w = 10;
int bar_h = 10;

float visualWidth = myCodeLength*(margin -1);

size(500, 500);
background(0);
fill(255);
noStroke();

colorMode(HSB,10,100,100,100);

for (int i=0; i<myCodeLength; i++) {
  bar_x = (width - visualWidth)/2 + i*margin;
  bar_y = height/2;
  int num = parseInt(myCode.substring(i, i+1));
  fill(num,100,100,100);
  rect(bar_x, bar_y, bar_w, bar_h);
}

fill(10,0,100,100);

PFont f;
f = createFont("Georgia", 14);
textFont(f);
textAlign(CENTER, CENTER);

text(myName, width/2, height-80);