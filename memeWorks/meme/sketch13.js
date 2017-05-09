var data;

var blinkStrength=[];
var cadence=[];
var numBlinks=[];
var pitchAvg=[];
var sleepy=[];
var capturedAt=[];
var sittingPostureIndex=[];

var dataRowCount;

var roop=0;

function preload(){
  	data=loadTable("013_ST_.csv");
}

function setup(){
    canvas = createCanvas(144, 1080);
    canvas.class("p513");
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
  	noStroke();
  	i = frameCount - roop * 550;
//	clear();
	fill(0, 0, 100);
	rect(24, 0, 288, 20);
	textSize(9);
	fill(0);
	text(capturedAt[i], 72, 7);

  	translate(36, 0);

    	var diameter = sqrt(map(numBlinks[i], 0, 1, 0, 100));
    	var x = sittingPostureIndex[i]*4;
//    	var x = (cos(radians(sittingPostureIndex[i]-90)) * sittingPostureIndex[i])*10;
    	var c = map(blinkStrength[i], 1, 100, 0, 240);
    	var y = i*2;
//    	var y = i*2+((sin(radians(sittingPostureIndex[i]-90)) * sittingPostureIndex[i])*2);
//    	var y = (sin(radians(pitchAvg[i]-90)) * pitchAvg[i])*1;
    	var c = map(blinkStrength[i], 1, 100, 0, 240);
    	var c2 = map(sittingPostureIndex[i], 0, 20, 10, 70);
//cadence[i]
    	fill(c, 59, 99, c2);

    	ellipse(x, y, diameter, diameter);
        noStroke();

	if(i == 549) {
		roop = roop + 1;
	  	translate(-36, 0);
	  	clear();
	}
}
