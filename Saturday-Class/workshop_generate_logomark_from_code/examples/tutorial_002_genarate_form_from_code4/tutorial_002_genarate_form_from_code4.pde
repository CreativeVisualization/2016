String myCode = "776583657573896577656669";
String myName = "MASAKI YAMABE";
int myCodeLength = myCode.length();

int margin = 11;
float point_x, point_y;

float visualWidth = myCodeLength*(margin -1);

size(500, 500);
background(0);
noFill();
stroke(255);

beginShape();
for (int i=0; i<myCodeLength; i++) {
  point_x = (width - visualWidth)/2 + i*margin;
  int num = parseInt(myCode.substring(i, i+1));
  point_y = height/2 + num*10;
  vertex(point_x,point_y);
}
endShape();

PFont f;
f = createFont("Georgia", 14);
textFont(f);
textAlign(CENTER, CENTER);

text(myName, width/2, height-80);