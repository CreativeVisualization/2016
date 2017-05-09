
 
Tile tile;
float damping = 0.09;
 
void setup() {
  size(640, 480);
  frameRate(60);
  smooth();
   
  tile = new Tile(width/2, height/2);
}
 
void draw() {
  background(0);
  tile.display();
}
 
void keyPressed() {
  tile.position(random(width), random(height));
}