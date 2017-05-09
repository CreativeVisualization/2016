import processing.video.*;

Capture cam;
int cameraW = 640;
int cameraH = 480;

color cente_of_camera;
float brightness;
float brightness_pre;

float brightness_sence = 20;
int time_sence = 5;

int stay_counter = 0;
boolean isMove = false;

void setup() {
  size(640, 480);
  cam = new Capture(this, cameraW,cameraH);
  cam.start();     
}

void draw() {
  if (cam.available() == true) {
    cam.read();
    cente_of_camera = cam.get(cameraW/2,cameraH/2);
    brightness = brightness(cente_of_camera);
    
    if(abs(brightness-brightness_pre)>brightness_sence && !isMove){
      stay_counter = 0;
      isMove = true;
    }
    else{
      stay_counter +=1;
    }
    
    if(isMove){
        someMoved(); 
    }
    if(stay_counter > time_sence){
      someStayd();
      isMove = false;      
    }
    brightness_pre = brightness;
    
    ellipse(width/2,height/2,100,100);
    
  }
  
  

}

void someMoved(){
  fill(255,0,0); 
  println("moved");
  
}

void someStayd(){
  fill(255,255,255); 
  println("stayd");
}


