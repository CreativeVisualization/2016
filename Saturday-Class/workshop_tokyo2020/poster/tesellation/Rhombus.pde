class Rhombus {
  float rotation;
  PVector[] vertices;
  
  
  Rhombus(float div, float index){
    rotation = TWO_PI / div;
    vertices = new PVector[4];
    vertices[0] = new PVector(0, 0);
    vertices[1] = new PVector(cos(rotation * index * -0.5), sin(rotation * index * -0.5));
    vertices[2] = new PVector(cos(rotation * index * 0.5) * 2, 0);
    vertices[3] = new PVector(cos(rotation * index * 0.5), sin(rotation * index * 0.5));
  }
  
  void draw(){
      
      float p = 0.5;//(easing + 0.5) % 1.0; // 0.5 -> 0.99 -> 0.0 -> 0.49
      float colorp = 0.5;//abs(easing - 0.5);
    
      if(rhombusMode == 0||rhombusMode == 2){
        stroke(200);
        noFill();
        beginShape();
        for (int i = 0; i < vertices.length; i++) {
          vertex(vertices[i].x, vertices[i].y);
        }
        endShape(CLOSE);
      }
      if(rhombusMode == 1||rhombusMode == 2){
        
        noStroke();
        fill(0);
        beginShape();
        for (int i = 0; i < vertices.length; i++) {
          float x = lerp(this.vertices[i].x, this.vertices[(i+1)%this.vertices.length].x, p);
          float y = lerp(this.vertices[i].y, this.vertices[(i+1)%this.vertices.length].y, p);
          vertex(x, y);
        }
        endShape(CLOSE);
      }
    
    
  }
}