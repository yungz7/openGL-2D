//Computer Graphics 2D
//Created by Yung, Max, Acap, Carl, Carlos and Amirul

#include <Windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\freeglut.h>
#include <math.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700
#define PI 3.141592
#define FPS 60

double w, h;
double dx, dy, dxa, dya, walk, walk1, op, cmove, cmove1, cmoveup, dxb;
double count = 0;

void rectangle(double x, double y, double w, double h){
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
}
void triangle(int x, int y, int width, int height) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + width / 2, y + height);
	glVertex2i(x + width, y);
	glEnd();
}
void nGon(double x, double y, double r, double n){
	double inc = (2*PI) / n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2*PI + inc; theta += inc){
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	}
	glEnd();
}
void sun(double x, double y, double r, double n){
	double inc = (2*PI) / n;
	glColor3ub(255,41,4);
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2*PI + inc; theta += inc){
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	}
	glEnd();
}
void moon(double x, double y, double r, double n){
	double inc = (2*PI) / n;
	glColor3ub(189,193,9);
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2*PI + inc; theta += inc){
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
		glColor3ub(255,128,0);
	}
	glEnd();
}
void sky(){
	glColor3ub(40,148,255);
	glBegin(GL_POLYGON);
		glVertex2i(0,300);
		glVertex2i(0,700);
		glVertex2i(0,700);
		glColor3ub(191,255,255);
		glVertex2i(1200,700);
		glVertex2i(1200,700);
		glColor3ub(191,255,255);
		glVertex2i(1200,300);
		glVertex2i(1200,300);
		glVertex2i(1100,500);
		glVertex2i(1100,500);
		glVertex2i(950,400);
		glVertex2i(950,400);
		glVertex2i(800,550);
		glVertex2i(800,550);
		glVertex2i(550,450);
		glVertex2i(550,450);
		glVertex2i(500,500);
		glVertex2i(500,500);
		glVertex2i(0,300);
	glEnd();
}
//sky for final scene
void sky1(){
	glColor3ub(82,82,82);
	glBegin(GL_POLYGON);
		glVertex2i(0,300);
		glVertex2i(0,700);
		glVertex2i(0,700);
		glColor3ub(191,255,255);
		glVertex2i(1200,700);
		glVertex2i(1200,700);
		glColor3ub(191,255,255);
		glVertex2i(1200,300);
		glVertex2i(1200,300);
		glVertex2i(1100,500);
		glVertex2i(1100,500);
		glVertex2i(950,400);
		glVertex2i(950,400);
		glVertex2i(800,550);
		glVertex2i(800,550);
		glVertex2i(550,450);
		glVertex2i(550,450);
		glVertex2i(500,500);
		glVertex2i(500,500);
		glVertex2i(0,300);
	glEnd();
}
void background(){
	//mountain
	glColor3ub(0,64,0);
	glBegin(GL_POLYGON);
		glVertex2i(0,300);
		glVertex2i(1200,300);
		glVertex2i(0,300);
		glVertex2i(500,500);
		glVertex2i(500,500);
		glVertex2i(550,450);
		glVertex2i(550,450);
		glColor3ub(0,200,0);
		glVertex2i(800,550);
		glVertex2i(800,550);
		glVertex2i(950,400);
		glColor3ub(0,200,0);
		glVertex2i(950,400);
		glVertex2i(1100,500);
		glVertex2i(1100,500);
		glVertex2i(1200,300);
	glEnd();

	//road1
	glColor3ub(79,79,79);
	glBegin(GL_POLYGON);
		glVertex2i(0,100);
		glVertex2i(0,190);
		glVertex2i(0,190);
		glVertex2i(1200,190);
		glVertex2i(1200,190);
		glVertex2i(1200,100);
		glVertex2i(1200,100);
		glVertex2i(0,100);
	glEnd();
	
	//road2
	glColor3ub(79,79,79);
	glBegin(GL_POLYGON);
		glVertex2i(0,300);
		glVertex2i(0,210);
		glVertex2i(0,210);
		glVertex2i(1200,210);
		glVertex2i(1200,210);
		glVertex2i(1200,300);
		glVertex2i(1200,300);
		glVertex2i(0,300);
	glEnd();

	//line
	glColor3ub(252,250,224);
	glBegin(GL_POLYGON);
		glVertex2i(0,190);
		glVertex2i(0,210);
		glVertex2i(0,210);
		glVertex2i(1200,210);
		glVertex2i(1200,210);
		glVertex2i(1200,190);
		glVertex2i(1200,190);
		glVertex2i(0,190);
	glEnd();

	//grass
	glColor3ub(0,200,0);
	glBegin(GL_POLYGON);
		glVertex2i(0,100);
		glVertex2i(0,0);
		glVertex2i(0,0);
		glVertex2i(1200,0);
		glVertex2i(1200,0);
		glVertex2i(1200,100);
		glVertex2i(0,100);
		glVertex2i(1200,100);
	glEnd();
}
//background for scene 2
void background1(){
	//land1
	glColor3ub(151,75,0);
	glBegin(GL_POLYGON);
		glVertex2i(0,430);
		glVertex2i(0,300);
		glVertex2i(0,300);
		glVertex2i(1200,300);
		glVertex2i(1200,300);
		glVertex2i(1200,430);
		glVertex2i(0,430);
		glVertex2i(1200,430);
	glEnd();
	//road1
	glColor3ub(79,79,79);
	glBegin(GL_POLYGON);
		glVertex2i(0,100);
		glVertex2i(0,190);
		glVertex2i(0,190);
		glVertex2i(1200,190);
		glVertex2i(1200,190);
		glVertex2i(1200,100);
		glVertex2i(1200,100);
		glVertex2i(0,100);
	glEnd();
	
	//road2
	glColor3ub(79,79,79);
	glBegin(GL_POLYGON);
		glVertex2i(0,300);
		glVertex2i(0,210);
		glVertex2i(0,210);
		glVertex2i(1200,210);
		glVertex2i(1200,210);
		glVertex2i(1200,300);
		glVertex2i(1200,300);
		glVertex2i(0,300);
	glEnd();

	//line
	glColor3ub(252,250,224);
	glBegin(GL_POLYGON);
		glVertex2i(0,190);
		glVertex2i(0,210);
		glVertex2i(0,210);
		glVertex2i(1200,210);
		glVertex2i(1200,210);
		glVertex2i(1200,190);
		glVertex2i(1200,190);
		glVertex2i(0,190);
	glEnd();

	//land2
	glColor3ub(151,75,0);
	glBegin(GL_POLYGON);
		glVertex2i(0,100);
		glVertex2i(0,0);
		glVertex2i(0,0);
		glVertex2i(1200,0);
		glVertex2i(1200,0);
		glVertex2i(1200,100);
		glVertex2i(0,100);
		glVertex2i(1200,100);
	glEnd();
}
//background for final scene
void background2(){
	//grass
	glColor3ub(128,64,0);
	glBegin(GL_POLYGON);
		glVertex2i(0,0);
		glVertex2i(0,300);
		glVertex2i(0,300);
		glVertex2i(1200,300);
		glVertex2i(1200,300);
		glVertex2i(1200,0);
		glVertex2i(1200,0);
		glVertex2i(0,0);
	glEnd(); 

	//patio
	glColor3ub(37,37,37);
	glBegin(GL_POLYGON);
		glVertex2i(450,0);
		glVertex2i(560,300);
		glVertex2i(560,300);
		glVertex2i(640,300);
		glVertex2i(640,300);
		glVertex2i(750,0);
		glVertex2i(750,0);
		glVertex2i(450,0);
	glEnd();
}
void house(double x, double y, double w){
	//body
	glColor3ub(255,203,151);
	rectangle(x,y,w,w*0.6);

	//door
	glColor3ub(255,128,0);
	rectangle(x+w/2 - (w*0.1), y, w*0.2, w*0.3);

	//left window
	glColor3ub(255,255,0);
	rectangle(x+w*0.1, y+w*0.3, w*0.2, w*0.2);

	//right window
	glColor3ub(255,255,0);
	rectangle(x+w - (w*0.1 + w*0.2), y+w*0.3, w*0.2, w*0.2);

	//roof
	glColor3ub(0,64,0);
	glBegin(GL_POLYGON);
		glVertex2i(x-w*0.1, y+w*0.6);
		glVertex2i(x+w*1.1, y+w*0.6);
		glVertex2i(x+w, y+w*0.9);
		glVertex2i(x, y+w*0.9);
	glEnd();

	//chimney
	glColor3ub(0,64,64);
	rectangle(680,520,60,70);

	//doorknob
	glColor3ub(128,64,0);
	nGon(624,300,8,8);
}
void tree(){
	//stemfirst
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(65,60);
		glVertex2i(60,10);
		glVertex2i(60,10);
		glVertex2i(80,10);
		glVertex2i(80,10);
		glVertex2i(75,60);
		glVertex2i(75,60);
		glVertex2i(65,60);
	glEnd();

	//greenfirst
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(40,50);
		glVertex2i(00,50);
		glVertex2i(40,50);
		glVertex2i(70,90);
		glVertex2i(100,50);
		glVertex2i(70,90);
	glEnd();

	//stems
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(265,60);
		glVertex2i(260,10);
		glVertex2i(260,10);
		glVertex2i(280,10);
		glVertex2i(280,10);
		glVertex2i(275,60);
		glVertex2i(275,60);
		glVertex2i(265,60);
	glEnd();

	//greens
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(240,50);
		glVertex2i(200,50);
		glVertex2i(240,50);
		glVertex2i(270,90);
		glVertex2i(300,50);
		glVertex2i(270,90);
	glEnd();

	//stem
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(95,60);
		glVertex2i(90,10);
		glVertex2i(90,10);
		glVertex2i(110,10);
		glVertex2i(110,10);
		glVertex2i(105,60);
		glVertex2i(105,60);
		glVertex2i(95,60);
	glEnd();

	//green
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(80,60);
		glVertex2i(120,60);
		glVertex2i(80,60);
		glVertex2i(100,90);
		glVertex2i(120,60);
		glVertex2i(100,90);
	glEnd();

	//stem1
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(195,60);
		glVertex2i(190,10);
		glVertex2i(190,10);
		glVertex2i(210,10);
		glVertex2i(210,10);
		glVertex2i(205,60);
		glVertex2i(205,60);
		glVertex2i(195,60);
	glEnd();

	//green1
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(180,50);
		glVertex2i(220,50);
		glVertex2i(180,50);
		glVertex2i(200,90);
		glVertex2i(220,50);
		glVertex2i(200,90);
	glEnd();

	//stem2
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(265,60);
		glVertex2i(260,10);
		glVertex2i(260,10);
		glVertex2i(280,10);
		glVertex2i(280,10);
		glVertex2i(275,60);
		glVertex2i(275,60);
		glVertex2i(265,60);
	glEnd();

	//green2
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(240,50);
		glVertex2i(300,50);
		glVertex2i(240,50);
		glVertex2i(270,90);
		glVertex2i(300,50);
		glVertex2i(270,90);
	glEnd();

	//stem3
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(355,60);
		glVertex2i(350,10);
		glVertex2i(350,10);
		glVertex2i(370,10);
		glVertex2i(370,10);
		glVertex2i(365,60);
		glVertex2i(365,60);
		glVertex2i(355,60);
	glEnd();

	//green3
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(330,50);
		glVertex2i(390,50);
		glVertex2i(330,50);
		glVertex2i(360,90);
		glVertex2i(390,50);
		glVertex2i(360,90);
	glEnd();
	
	//stem4
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(445,60);
		glVertex2i(440,10);
		glVertex2i(440,10);
		glVertex2i(460,10);
		glVertex2i(460,10);
		glVertex2i(455,60);
		glVertex2i(455,60);
		glVertex2i(445,60);
	glEnd();

	//green4
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(420,50);
		glVertex2i(480,50);
		glVertex2i(420,50);
		glVertex2i(450,90);
		glVertex2i(480,50);
		glVertex2i(450,90);
	glEnd();

	//stem5
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(535,60);
		glVertex2i(530,10);
		glVertex2i(530,10);
		glVertex2i(550,10);
		glVertex2i(550,10);
		glVertex2i(545,60);
		glVertex2i(545,60);
		glVertex2i(535,60);
	glEnd();

	//green5
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(510,50);
		glVertex2i(570,50);
		glVertex2i(510,50);
		glVertex2i(540,90);
		glVertex2i(570,50);
		glVertex2i(540,90);
	glEnd();

	//stem6
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(625,60);
		glVertex2i(620,10);
		glVertex2i(620,10);
		glVertex2i(640,10);
		glVertex2i(640,10);
		glVertex2i(635,60);
		glVertex2i(635,60);
		glVertex2i(625,60);
	glEnd();

	//green6
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(600,50);
		glVertex2i(660,50);
		glVertex2i(600,50);
		glVertex2i(630,90);
		glVertex2i(660,50);
		glVertex2i(630,90);
	glEnd();

	//stem7
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(715,60);
		glVertex2i(710,10);
		glVertex2i(710,10);
		glVertex2i(730,10);
		glVertex2i(730,10);
		glVertex2i(725,60);
		glVertex2i(725,60);
		glVertex2i(715,60);
	glEnd();

	//green7
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(690,50);
		glVertex2i(750,50);
		glVertex2i(690,50);
		glVertex2i(720,90);
		glVertex2i(750,50);
		glVertex2i(720,90);
	glEnd();

	//stem8
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(805,60);
		glVertex2i(800,10);
		glVertex2i(800,10);
		glVertex2i(820,10);
		glVertex2i(820,10);
		glVertex2i(815,60);
		glVertex2i(815,60);
		glVertex2i(805,60);
	glEnd();

	//green8
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(780,50);
		glVertex2i(840,50);
		glVertex2i(780,50);
		glVertex2i(810,90);
		glVertex2i(840,50);
		glVertex2i(810,90);
	glEnd();

	//stem9
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(895,60);
		glVertex2i(890,10);
		glVertex2i(890,10);
		glVertex2i(910,10);
		glVertex2i(910,10);
		glVertex2i(905,60);
		glVertex2i(905,60);
		glVertex2i(895,60);
	glEnd();

	//green9
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(870,50);
		glVertex2i(930,50);
		glVertex2i(870,50);
		glVertex2i(900,90);
		glVertex2i(930,50);
		glVertex2i(900,90);
	glEnd();

	//stem10
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
		glVertex2i(985,60);
		glVertex2i(980,10);
		glVertex2i(980,10);
		glVertex2i(1000,10);
		glVertex2i(1000,10);
		glVertex2i(995,60);
		glVertex2i(995,60);
		glVertex2i(985,60);
	glEnd();

	//green10
	glColor3ub(19,90,12);
	glBegin(GL_POLYGON);
		glVertex2i(960,50);
		glVertex2i(1020,50);
		glVertex2i(960,50);
		glVertex2i(990,90);
		glVertex2i(1020,50);
		glVertex2i(990,90);
	glEnd();
}
void grass(double x, double y, double s){
	glBegin(GL_POLYGON);
	glColor3ub(1, 166, 17);
	glVertex2f(x,y);
	glVertex2f(x-20, y+30);
	glVertex2f(x+10, y+15);
	glColor3ub(128,255,128);
	glVertex2f(x+30, y+40);
	glVertex2f(x+40, y+20);
	glVertex2f(x+50, y+30);
	glVertex2f(x+45, y);
	glEnd();
}
void cloud(double dx, double dy, double s){
	glColor3ub(237, 237, 237);
	nGon(dx, dy, s / 20, 20);
	nGon(dx + s / 10, dy + s / 55, s / 16, 50);
	nGon(dx + s / 20, dy + s / 55, s / 16, 50);
	nGon(dx + s / 14, dy + s / 65, s / 16, 50);
	nGon(dx + s / 9 + s / 20, dy, s / 20, 20);
}
void john(double dx, double dy, double w, double h){
	//body
	glColor3ub(26, 26, 26);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(26, 26, 26);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(26, 26, 26);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(255, 224, 193);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
//dark skin yellowshirt bluepants
void pedestrian(double dx, double dy, double w, double h){
	//body
	glColor3ub(216, 210, 14);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(9, 23, 159);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(9, 23, 159);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(9, 23, 159);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(81, 40, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(216, 210, 14);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(81, 40, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(216, 210, 14);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(81, 40, 0);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
//dark skin blueshirt blackpants
void pedestrian1(double dx, double dy, double w, double h){
	//body
	glColor3ub(9, 23, 159);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(81, 40, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(9, 23, 159);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(81, 40, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(9, 23, 159);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(81, 40, 0);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
//fair skin brownshirt bluepants
void pedestrian2(double dx, double dy, double w, double h){
	//body
	glColor3ub(198, 99, 0);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(198, 99, 0);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(198, 99, 0);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(255, 224, 193);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
//chocolate redshirt bluepants
void pedestrian3(double dx, double dy, double w, double h){
	//body
	glColor3ub(255, 0, 0);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(81, 40, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(255, 0, 0);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(81, 40, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(255, 0, 0);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(81, 40, 0);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
//fair skin greenshirt blackpants
void pedestrian4(double dx, double dy, double w, double h){
	//body
	glColor3ub(32, 213, 46);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(32, 213, 46);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(32, 213, 46);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(255, 224, 193);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
//fair skin blueshirt greenpants
void pedestrian5(double dx, double dy, double w, double h){
	//body
	glColor3ub(15, 54, 189);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(22, 107, 20);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(22, 107, 20);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(22, 107, 20);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(15, 54, 189);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(255, 224, 193);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(15, 54, 189);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(255, 224, 193);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
//dark skin purpleshirt bluepants
void pedestrian6(double dx, double dy, double w, double h){
	//body
	glColor3ub(255, 255, 255);
	rectangle(dx, dy, w, h);
	//pant
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w, dy - h*0.4);
	glVertex2f(dx + w / 2, dy - h*0.6);
	glVertex2f(dx, dy - h*0.4);
	glEnd();
	//left leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.4, dy - h*1.5);
	glVertex2f(dx + w*0.4, dy - h * 2);
	glVertex2f(dx, dy - h * 2);
	glEnd();
	//right leg
	glColor3ub(6, 9, 111);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w, dy);
	glVertex2f(dx + w / 2, dy - h*0.4);
	glVertex2f(dx + w*0.6, dy - h * 1.5);
	glVertex2f(dx + w*0.6, dy - h * 2);
	glVertex2f(dx + w, dy - h * 2);
	glEnd();
	//left hand
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx - w*0.1, dy + h*0.8);
	glVertex2f(dx - w*0.1, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy - h*0.1);
	glVertex2f(dx - w*0.3, dy + h*0.8);
	glEnd();
	//left shoulder
	glColor3ub(26, 26, 26);
	nGon(dx - w*0.2, dy + h - h*0.2, w / 5, 20);
	//right hand
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dx + w + w*0.1, dy + h*0.8);
	glVertex2f(dx + w + w*0.1, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy - h*0.1);
	glVertex2f(dx + w + w*0.3, dy + h*0.8);
	glEnd();
	//right shoulder
	glColor3ub(26, 26, 26);
	nGon(dx + w + w*0.2, dy + h - h*0.2, w / 5, 20);
	//head
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.5, dy + h + h*0.5, w / 2, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 20);
	//left eye
	glColor3ub(250, 250, 250);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 20);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.3, dy + h + h*0.6, w / 10, 4);
	//left pupil
	glColor3ub(0, 0, 0);
	nGon(dx + w*0.7, dy + h + h*0.6, w / 10, 4);
	//mouth
	glColor3ub(255, 0, 0);
	triangle(dx +w*0.35, dy+h+h*0.1, w/3, h/4);
}
void school(double x){
	//schoolland
	glColor3ub(128,64,0);
	glBegin(GL_POLYGON);
		glVertex2i(0,280);
		glVertex2i(0,300);
		glVertex2i(0,300);
		glVertex2i(1200,300);
		glVertex2i(1200,300);
		glVertex2i(1200,280);
		glVertex2i(1200,280);
		glVertex2i(0,280);
	glEnd();

	//schoolbuilding
	glColor3ub(255,255,0);
	glBegin(GL_POLYGON);
		glVertex2i(660,290);
		glVertex2i(660,350);
		glVertex2i(660,350);
		glVertex2i(940,350);
		glVertex2i(940,350);
		glVertex2i(940,290);
		glVertex2i(940,290);
		glVertex2i(660,290);
	glEnd();

	//schoolroof
	glColor3ub(255,0,0);
	glBegin(GL_POLYGON);
		glVertex2i(660,350);
		glVertex2i(700,400);
		glVertex2i(700,400);
		glVertex2i(900,400);
		glVertex2i(900,400);
		glVertex2i(940,350);
		glVertex2i(940,350);
		glVertex2i(660,350);
	glEnd();

	//schoolinside
	glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
		glVertex2i(785,290);
		glVertex2i(785,320);
		glVertex2i(785,320);
		glVertex2i(815,320);
		glVertex2i(815,320);
		glVertex2i(815,290);
		glVertex2i(815,290);
		glVertex2i(785,290);
	glEnd();

	//schooldoor1
	glColor3ub(0,0,255);
	glBegin(GL_POLYGON);
		glVertex2i(785-x,290);
		glVertex2i(785-x,320);
		glVertex2i(785-x,320);
		glVertex2i(800-x,320);
		glVertex2i(800-x,320);
		glVertex2i(800-x,290);
		glVertex2i(800-x,290);
		glVertex2i(785-x,290);
	glEnd();

	//schooldoor2
	glColor3ub(0,0,255);
	glBegin(GL_POLYGON);
		glVertex2i(x+800,290);
		glVertex2i(x+800,320);
		glVertex2i(x+800,320);
		glVertex2i(x+815,320);
		glVertex2i(x+815,320);
		glVertex2i(x+815,290);
		glVertex2i(x+815,290);
		glVertex2i(x+800,290);
	glEnd();
}
void textSchool(double x, double y, double s){
	char string[] = "SCHOOL";
	void *font = GLUT_BITMAP_HELVETICA_18;
	int k;
	glColor3ub(0, 0, 0);
	glRasterPos3f(x / 2, y *0.6, 0);
	for (k = 0; k < strlen(string); k++)
		glutBitmapCharacter(font, string[k]);
}
void textHome(double x, double y, double s){
	char string[] = "Home Sweet Home";
	void *font = GLUT_BITMAP_HELVETICA_18;
	int k;
	glColor3ub(0, 0, 0);
	glRasterPos3f(x / 2, y *0.6, 0);
	for (k = 0; k < strlen(string); k++)
		glutBitmapCharacter(font, string[k]);
}
void car(double x){
	glColor3ub(245,16,79);//body
	glBegin(GL_POLYGON);
	glVertex2f(x+285,295);
	glVertex2f(x+350,295);
	glVertex2f(x+400,270);
	glColor3ub(17,47,18);
	glVertex2f(x+400,230);
	glVertex2f(x+285,230);
	glEnd();
	glColor3ub(200,0,0); //wheel
	nGon(x+310,235,20,20);
	nGon(x+370,235,20,20);

	glColor3ub(128,255,255);//body2
	glBegin(GL_POLYGON);
	glVertex2f(x+30,295);
	glVertex2f(x+80,295);
	glVertex2f(x+100,270);
	glVertex2f(x+130,270);
	glColor3ub(5,40,48);
	glVertex2f(x+130,230);
	glVertex2f(x+0,230);
	glVertex2f(x+0,270);
	glEnd();
	glColor3ub(0,0,0); //whee2
	nGon(x+30,235,20,20);
	nGon(x+90,235,20,20);

	glColor3ub(255,128,64);//body3
	glBegin(GL_POLYGON);
	glVertex2f(1165-x,130);
	glVertex2f(1165-x,160);
	glVertex2f(1200-x,195);
	glVertex2f(1280-x,195);
	glColor3ub(128,64,0);
	glVertex2f(1280-x,130);
	glEnd();
	glColor3ub(0,0,0); //wheel3
	nGon(1195-x,135,20,20);
	nGon(1250-x,135,20,20);

	glColor3ub(128,0,0);//body4
	glBegin(GL_POLYGON);
	glVertex2f(865-x,130);
	glVertex2f(865-x,160);
	glVertex2f(900-x,170);
	glVertex2f(910-x,195);
	glColor3ub(64,0,0);
	glVertex2f(960-x,195);
	glVertex2f(980-x,160);
	glVertex2f(990-x,160);
	glVertex2f(990-x,130);
	glEnd();
	glColor3ub(0,0,0); //wheel4
	nGon(900-x,135,20,20);
	nGon(959-x,135,20,20);
}
void carFinal(double x){
	glColor3ub(255,128,64);//body3
	glBegin(GL_POLYGON);
	glVertex2f(550,30+x);
	glVertex2f(550,100+x);
	glVertex2f(650,100+x);
	glVertex2f(650,30+x);
	glEnd();

	glColor3ub(0,0,64);//car window
	glBegin(GL_POLYGON);
	glVertex2f(555,60+x);
	glVertex2f(555,90+x);
	glVertex2f(645,90+x);
	glVertex2f(645,60+x);
	glEnd();

	glColor3ub(255,255,255);//car plate
	glBegin(GL_POLYGON);
	glVertex2f(585,25+x);
	glVertex2f(585,35+x);
	glVertex2f(615,35+x);
	glVertex2f(615,25+x);
	glEnd();

	glColor3ub(255,255,0);//lightcar
	nGon(565,45+x,10,10);
	nGon(635,45+x,10,10);

	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(550,10+x);
	glVertex2f(550,30+x);//left wheel
	glVertex2f(580,30+x);
	glVertex2f(580,10+x);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(620,30+x);
	glVertex2f(620,10+x);
	glVertex2f(650,10+x);
	glVertex2f(650,30+x);//right wheel
	glEnd();

}
void carfetch(double x){
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
	glVertex2f(x+(-170),295);
	glVertex2f(x+(-120),295);
	glVertex2f(x+(-100),270);
	glVertex2f(x+(-70),270);
	glColor3ub(255,128,64);
	glVertex2f(x+(-70),230);
	glVertex2f(x+(-200),230);
	glVertex2f(x+(-200),270);
	glEnd();
	glColor3ub(0,0,0); //whee2
	nGon(x+(-170),235,20,20);
	nGon(x+(-110),235,20,20);
}
void star(){
	glColor3ub(255,255,0);
	nGon(300,610,4,4);
	nGon(100,670,4,4);
	nGon(190,640,4,4);
	nGon(390,665,4,4);
	nGon(590,675,4,4);
	nGon(550,605,4,4);
	nGon(1090,560,4,4);
	nGon(930,650,4,4);
	nGon(850,620,4,4);
	nGon(800,655,4,4);
	nGon(460,630,4,4);
	nGon(720,690,4,4);
}

void idle(){
	DWORD start = GetTickCount();
	while(GetTickCount()-start < 1000/FPS) ;
	count += 1;
	
	if (count >= 0 && count < 1300){ //first scene move
		if (count >= 975){
			walk += 1;
		}
		cmove += 1;
		dx += 0.3;
		dy += 0.1;
		if(op <= 10){
			op += 0.1;}
		if(op == 10){
			op;}
	}

	if (count >= 1300 && count < 2500){ //second scene move
		walk1 += 0.4;
		cmove1 += 1;
		dxa += 0.3;
		dya += 0.1;
	}

	if (count >= 2500 && count < 3500){	//final scene move
		if(count >= 2500 && count < 3000){
			cmoveup += 0.2;
		}
		dxb += 0.3;
	}

	glutPostRedisplay();
}
void scene1(){
	sky();
	background();
	tree();
	sun(1100,700,100,100);
	school(op);
	textSchool(1400,600,100);
	grass(600,290,5);
	grass(970,290,5);
	cloud(dx, 600, 600);
	cloud(dx+300, 550, 600);
	cloud(600-dx, 600, 600);
	cloud(dx+900, 570, 600);
	cloud(880-dx, 570, 600);
	cloud(dx+1100, 600, 600);
	if (count >= 200 && count < 975 ){
		john(830,320,15,15);
	}
	if(count >= 975 && count < 1300){
		john(walk+830,280,15,15);
	}
	car(cmove);
	carfetch(cmove);
}
void scene2(){
	sky();
	sun(1100,700+dya,100,100);
	background1();
	cloud(dxa, 600, 600);
	cloud(dxa+300, 550, 600);
	cloud(600-dxa, 600, 600);
	cloud(dxa+900, 570, 600);
	cloud(880-dxa, 570, 600);
	cloud(dxa+1100, 600, 600);
	pedestrian2(500,80,20,20);
	grass(5,5,5);
	grass(250,25,5);
	grass(350,5,5);
	grass(500,35,5);
	grass(750,55,5);
	grass(900,65,5);
	grass(1100,65,5);
	pedestrian(walk1+100,50,20,20);
	pedestrian1(walk1+300,50,20,20);
	pedestrian3(700-walk1,50,20,20);
	pedestrian4(walk1+900,50,20,20);
	pedestrian5(1000-walk1,50,20,20);
	pedestrian6(1100-walk1,50,20,20);
	grass(5,325,5);
	grass(250,345,5);
	grass(350,325,5);
	grass(500,355,5);
	grass(750,375,5);
	grass(900,385,5);
	grass(1100,385,5);
	pedestrian(walk1+100,400,20,20);
	pedestrian5(walk1+300,400,20,20);
	pedestrian6(700-walk1,400,20,20);
	pedestrian4(walk1+900,400,20,20);
	pedestrian1(1000-walk1,400,20,20);
	pedestrian3(1100-walk1,400,20,20);
	john(cmove1+(-150),280,15,15);
	car(cmove1);
	carfetch(cmove1);
}
void finalScene(){
	sky1();
	background2();
	moon(1100,700,100,100);
	star();
	cloud(dxb, 600, 600);
	cloud(dxb+300, 550, 600);
	cloud(600-dxb, 600, 600);
	cloud(dxb+900, 570, 600);
	cloud(880-dxb, 570, 600);
	cloud(dxb+1100, 600, 600);
	house(425,250,350);
	grass(300,100,5);
	grass(400,200,5);
	grass(720,150,5);
	grass(800,250,5);
	grass(200,250,5);
	grass(930,130,5);
	grass(1100,210,5);
	grass(80,200,5);
	textHome(1050,730,100);
	carFinal(cmoveup);
	if(count >= 3000 ){
		john(600,250,15,15);
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glutIdleFunc(idle);
	
	if(count >= 0 && count < 1300){	//(0-650: 15-16 seconds) !0-1100: 27-28 seconds
		scene1();
	}
	if(count >= 1300 && count < 2500){
		scene2();
	}
	if(count >= 2500 ){
		finalScene();
	}
	
	glFlush();
	glutSwapBuffers();
}

void initGL(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,SCREEN_WIDTH,0,SCREEN_HEIGHT);
	glPointSize(5.0);
}
int main(int argc, char** argv){
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("2DProject");
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	initGL();

	glutMainLoop();
}