import processing.pdf.*;
boolean saveFrameToPdf = false;
int rhombusMode = 1;

void setup() {
  size(600, 600);
}

void draw() {
  float size = width;
  float division = 60;

  background(255);

  drawTessellation(width * 0.5, height * 0.5, size, division);
}

void drawTessellation(float x, float y, float size, float div) {
  
  if(saveFrameToPdf){
    beginRecord(PDF, hour()+minute()+second()+"_"+frameCount+".pdf"); 
  }
  float rounds = (div / 2) - 1;
  float rotation = TWO_PI / div;

  ArrayList<Rhombus> rhombuses = new ArrayList<Rhombus>();
  for (int i = 0; i < rounds; i++) {
    rhombuses.add(new Rhombus(div, i + 1));
  }

  FloatList offsets = new FloatList();
  for (int i = 0; i < rhombuses.size(); i++) {
    float offset = 0;
    if (i == 1) {
      offset = 1;
    } else if (i > 1) {
      offset += offsets.get(i-2);
      offset += rhombuses.get(i-2).vertices[2].x;
    }
    offsets.append(offset);
  }

  float maxRadius = (offsets.get(rhombuses.size() - 1) + rhombuses.get(rhombuses.size() - 1).vertices[2].x);
  float scaling = size / maxRadius * 0.5;

  pushMatrix();
    translate(x, y);
    scale(scaling);
    strokeWeight(1/scaling);

    for (int i = 0; i < int(map(mouseY,0,height-10,1,rhombuses.size())); i++) {
      for (int j = 0; j < int(map(mouseX,0,width-10,1,div)); j++) {
        pushMatrix();

          rotate(rotation * (i * -0.5 +j));
          translate(offsets.get(i), 0);


          rhombuses.get(i).draw();
        popMatrix();
      }
    }

  popMatrix();
  
  if(saveFrameToPdf){
    endRecord();
    saveFrameToPdf = false;
  }
  
  text("press 'p' to save pdf", 5,20);
  text("press 'r' to change mode. now mode is "+ rhombusMode ,5,40);
}

void keyPressed(){
  
 if(key=='p'){
  saveFrameToPdf = true; 
 }
 
 if(key=='r'){
  rhombusMode ++;
  if(rhombusMode>2) rhombusMode = 0;  
 }
}