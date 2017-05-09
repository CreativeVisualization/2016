var data;

var blinkStrength=[];
var cadence=[];
var numBlinks=[];
var pitchAvg=[];
var sleepy=[];
var capturedAt=[];
var sittingPostureIndex=[];

var dataRowCount;

function preload(){
  	data=loadTable("001_ST_.csv");
}

function setup(){
	createCanvas(144,1080);
	frameRate(24);
    colorMode(HSB, 360, 100, 100, 100);
	dataRowCount = data.getRowCount();
	
  	textAlign(CENTER);
  	rectMode(CENTER);

  	for(var i=0; i<dataRowCount;i+=1){
    	blinkStrength[i]=data.getNum(i,5);
    	cadence[i]=data.getNum(i,9);
    	numBlinks[i]=data.getNum(i,20);
    	pitchAvg[i]=data.getNum(i,46);
    	sittingPostureIndex[i]=data.getNum(i,51);
    	sleepy[i]=data.getNum(i,54);
    	capturedAt[i]=data.getString(i,10);
  	}
}


function draw(){
//	clear();
// 	background(0, 0, 90, 100);
  	noStroke();
  	translate(72-48, 0);


    noStroke();
  	fill(0);
  	
  	i = frameCount;
    	var diameter = sqrt(map(numBlinks[i], 0, 1, 0, 100));
    	var x = sittingPostureIndex[i]*4;
//    	var x = (cos(radians(sittingPostureIndex[i]-90)) * sittingPostureIndex[i])*10;
    	var y = i*2+((sin(radians(sittingPostureIndex[i]-90)) * sittingPostureIndex[i])*2);
//    	var y = (sin(radians(pitchAvg[i]-90)) * pitchAvg[i])*1;
    	var c = map(blinkStrength[i], 1, 100, 0, 240);
    	var c2 = map(sleepy[i], 3, 0, 20, 60);
//cadence[i]
    	fill(c, 59, 99, c2);
    	stroke(0, 0, 0);
		if(i<=10){    	beginShape();}
		vertex(x, y);
		vertex(x+100, y+100);

		
		noStroke();
    	ellipse(x, y, diameter, diameter);
        noStroke();

}