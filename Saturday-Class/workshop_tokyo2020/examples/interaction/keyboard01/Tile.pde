class Tile {
  
 float x;
 float y;
 float endX;
 float endY;
  
 Tile(float x_, float y_) {
   x = x_;
   y = y_;
   endX = x_;
   endY = y_;
 }
  
 void display() {
   fill(255);
   noStroke();
    
   x = x + (endX - x) * damping;
   y = y + (endY - y) * damping;
    
   ellipse(x, y, 100, 100);
 }
  
 void position(float x_, float y_) {
   endX = x_;
   endY = y_;
 }
}