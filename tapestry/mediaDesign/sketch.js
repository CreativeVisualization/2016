var main;

var shibu;
var shin;
var baba;
var ike;

var mainStationName=[];
var mainStationX=[];
var mainStationY=[];
var mainPassengers=[];

var stationName=[];
var radian=[];
var time=[];
var passengers=[];
var difference=[];

var mainRowCount;
var shibuRowCount;
var shinRowCount;
var babaRowCount;
var ikeRowCount;


var moji = 0;

var j = 0;

function preload(){
	main=loadTable("main90.csv")
  	shibu=loadTable("shibu.csv");
  	shin=loadTable("shin.csv");
  	baba=loadTable("baba.csv");
  	ike=loadTable("ike.csv");
}

function setup(){
	createCanvas(3000,3000, SVG);
    colorMode(HSB, 360, 100, 100, 100);
	mainRowCount = main.getRowCount();
	shibuRowCount = shibu.getRowCount();
	shinRowCount = shin.getRowCount();
	babaRowCount = baba.getRowCount();
	ikeRowCount = ike.getRowCount();
	
  	textAlign(CENTER); rectMode(CENTER);

  	for(var i=0; i<mainRowCount;i+=1){
    	mainPassengers[i]=main.getNum(i,3);
    	mainStationY[i]=main.getNum(i,2);
    	mainStationX[i]=main.getNum(i,1);
    	mainStationName[i]=main.getString(i,0);
  	}

  	for(var i=0; i<shibuRowCount;i+=1){
    	difference[i]=shibu.getNum(i,4);
    	passengers[i]=shibu.getNum(i,3);
    	time[i]=shibu.getNum(i,2);
    	radian[i]=shibu.getNum(i,1);
    	stationName[i]=shibu.getString(i,0);
  	}
  	
  	for(i; i<(shibuRowCount+shinRowCount);i+=1){
    	difference[i]=shin.getNum(i-shibuRowCount,4);
    	passengers[i]=shin.getNum(i-shibuRowCount,3);
    	time[i]=shin.getNum(i-shibuRowCount,2);
    	radian[i]=shin.getNum(i-shibuRowCount,1);
    	stationName[i]=shin.getString(i-shibuRowCount,0);
  	}
 
  	for(i; i<(shibuRowCount+shinRowCount+babaRowCount);i+=1){
    	difference[i]=baba.getNum(i-shibuRowCount-shinRowCount,4);
    	passengers[i]=baba.getNum(i-shibuRowCount-shinRowCount,3);
    	time[i]=baba.getNum(i-shibuRowCount-shinRowCount,2);
    	radian[i]=baba.getNum(i-shibuRowCount-shinRowCount,1);
    	stationName[i]=baba.getString(i-shibuRowCount-shinRowCount,0);
  	}
  	for(i; i<(shibuRowCount+shinRowCount+babaRowCount+ikeRowCount);i+=1){
    	difference[i]=ike.getNum(i-shibuRowCount-shinRowCount-babaRowCount,4);
    	passengers[i]=ike.getNum(i-shibuRowCount-shinRowCount-babaRowCount,3);
    	time[i]=ike.getNum(i-shibuRowCount-shinRowCount-babaRowCount,2);
    	radian[i]=ike.getNum(i-shibuRowCount-shinRowCount-babaRowCount,1);
    	stationName[i]=ike.getString(i-shibuRowCount-shinRowCount-babaRowCount,0);
  	}

}

/*
東京	0
品川	1
渋谷	2
新宿	3
馬場	4
池袋	5
日暮里	6
北千住	7
上野	8
秋葉原	9
錦糸町	10
*/

function draw(){
  	background(0, 0, 100);
  	noStroke();
  	translate(1500, 1500); //東京駅の位
/* 東京	0 */
	j=0;

/* 品川	1 */
	j=1;
	translate(mainStationX[j], mainStationY[j]);
	translate(-mainStationX[j], -mainStationY[j]);

/* 渋谷	2 */
	j=2;
	translate(mainStationX[j], mainStationY[j]);
	mainStation();
	noStroke();
  	fill(0);
  	
  	for(var i=0; i< shibuRowCount;i++){
    	var diameter = sqrt(map(passengers[i], 0, 1000000, 0, 33333));
    	var x = (cos(radians(radian[i]-180)) * time[i])*20;
    	var y = (sin(radians(radian[i]-180)) * time[i])*20;
    	var c = map(difference[i], 0.7, 1.3, 210, 360);
    	fill(c, 60, 100, 30);

    	ellipse(x, y, diameter, diameter);
        fill(0, 0, 50, 100);
        textAlign(CENTER);
        text(stationName[i], x, y+5);
	}
	


	translate(-mainStationX[j], -mainStationY[j]);

/* 新宿	3 */
	j=3;
	translate(mainStationX[j], mainStationY[j]);
	mainStation();

    noStroke();
  	fill(0);
  	
  	for(i; i< shibuRowCount+shinRowCount;i++){
    	diameter = sqrt(map(passengers[i], 0, 1000000, 0, 33333));
    	x = (cos(radians(radian[i]-180)) * time[i])*20;
    	y = (sin(radians(radian[i]-180)) * time[i])*20;
    	if (i>159 && i <=209) { fill(300, 60, 100, 20);
    	ellipse(x, y, diameter*1.15+10, diameter*1.15+10);
    	}
    	if (i>209) { fill(30, 60, 100, 20);
    	ellipse(x, y, diameter*1.15+10, diameter*1.15+10);
    	}

	}

  	
  	
  	for(i=shibuRowCount; i< shibuRowCount+shinRowCount;i++){
    	diameter = sqrt(map(passengers[i], 0, 1000000, 0, 33333));
    	x = (cos(radians(radian[i]-180)) * time[i])*20;
    	y = (sin(radians(radian[i]-180)) * time[i])*20;
    	c = map(difference[i], 50, 400, 120, 360);
    	if (i<160) { fill(c, 60, 100, 30);}
    	else { fill(c, 60, 100, 70);}
    	ellipse(x, y, diameter, diameter);
    	textAlign(CENTER);
    	if (i<160) { fill(0, 0, 50, 100);
   		text(stationName[i], x, y+5);
    	}
	}

  	for(i=shibuRowCount; i< shibuRowCount+shinRowCount;i++){
    	diameter = sqrt(map(passengers[i], 0, 1000000, 0, 33333));
    	x = (cos(radians(radian[i]-180)) * time[i])*20;
    	y = (sin(radians(radian[i]-180)) * time[i])*20;

    	if (i>159) { fill(0, 0, 100, 100);
   		text(stationName[i], x, y+5);
    	}
	}







    	
    	

	translate(-mainStationX[j], -mainStationY[j]);

/* 高田馬場	4 */
	j=4;
	translate(mainStationX[j], mainStationY[j]);
	mainStation();
	noStroke();
  	fill(0);
  	
  	for(i; i< shibuRowCount+shinRowCount+babaRowCount;i++){
    	diameter = sqrt(map(passengers[i], 0, 1000000, 0, 33333));
    	x = (cos(radians(radian[i]-180)) * time[i])*20;
    	y = (sin(radians(radian[i]-180)) * time[i])*20;
    	c = map(difference[i], 50, 400, 120, 360);
    	fill(c, 59, 99, 29);
    	ellipse(x, y, diameter, diameter);
        fill(0, 0, 50, 100);
        textAlign(CENTER);
        text(stationName[i], x, y+5);
	}
	translate(-mainStationX[j], -mainStationY[j]);
	
/* 池袋	5 */
	j=5;
	translate(mainStationX[j], mainStationY[j]);
	mainStation();
	noStroke();
  	fill(0);
  	
  	for(i; i< shibuRowCount+shinRowCount+babaRowCount+ikeRowCount;i++){
    	diameter = sqrt(map(passengers[i], 0, 1000000, 0, 33333));
    	x = (cos(radians(radian[i]-180)) * time[i])*20;
    	y = (sin(radians(radian[i]-180)) * time[i])*20;
    	c = map(difference[i], 50, 400, 120, 360);
    	fill(c, 59, 99, 29);
    	ellipse(x, y, diameter, diameter);
        fill(0, 0, 50, 100);
        textAlign(CENTER);
        text(stationName[i], x, y+5);
	}
	translate(-mainStationX[j], -mainStationY[j]);


/* 日暮里	6 */
	j=6;
	translate(mainStationX[j], mainStationY[j]);
	translate(-mainStationX[j], -mainStationY[j]);

/* 北千住	7 */
	j=7;
	translate(mainStationX[j], mainStationY[j]);
	translate(-mainStationX[j], -mainStationY[j]);

/* 上野	8 */
	j=8;
	translate(mainStationX[j], mainStationY[j]);
	translate(-mainStationX[j], -mainStationY[j]);

/* 秋葉原	9 */
	j=9;
	translate(mainStationX[j], mainStationY[j]);
	translate(-mainStationX[j], -mainStationY[j]);

/* 錦糸町	10 */
	j=10;
	translate(mainStationX[j], mainStationY[j]);
	translate(-mainStationX[j], -mainStationY[j]);

    if (frameCount > 0) {
        noLoop();
        save();
    }
}

function mainStation() {
    fill(5, 100, 100, 15);
    if(j==3){fill(5, 100, 100, 30);}
    diameter = sqrt(map(mainPassengers[j], 0, 1000000, 0, 33333));
    ellipse(0, 0, diameter, diameter);
    textAlign(LEFT);
    stroke(360, 0, 100);
//    text(mainStationName[j], 0, 0);
    textAlign(CENTER);
}

