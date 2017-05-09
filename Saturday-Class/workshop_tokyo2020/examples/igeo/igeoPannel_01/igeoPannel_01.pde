import processing.opengl.*;
import igeo.*;

size( 1024, 768, IG.GL );
IG.open("surface1.obj"); ///input geometry from OBJ file

ISurface srf = IG.surface(0);

IImageMap map = new IImageMap("map1.jpg");

int unum = 50;
int vnum = 50;
double uinc = 1.0/unum;
double vinc = 1.0/vnum;

for(int i = 0; i < unum; i++){
  for(int j = 0; j < vnum; j++){
    if((i+j)%2 == 0){
      double val = map.get(i*uinc, j*vinc);
      IVec p1 = srf.pt(i*uinc, j*vinc, 0 );
      IVec p2 = srf.pt((i+1)*uinc, (j-1)*vinc,0);
      IVec p3 = srf.pt((i+2)*uinc, (j)*vinc, 10*val);
      IVec p4 = srf.pt((i+1)*uinc, (j+1)*vinc, 0);
      ISurface pannel = new ISurface(p1, p2, p3, p4);
    }
  }
}
  
srf.del();



//IVec p1 = srf.pt(0.5,0.5); //center of the surface u = 0.5, v = 0.5;
//IVec p2 = srf.pt(0.8,0.5);
//IVec p3 = srf.pt(0.8,0.8);
//IVec p4 = srf.pt(0.5,0.8);
//new ISurface(p1, p2, p3, p4);

