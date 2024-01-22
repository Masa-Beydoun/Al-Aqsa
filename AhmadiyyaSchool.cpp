#include "AhmadiyyaSchool.h"

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>	
#include "Point.h"
#include "Color.h"
#include "PrimitiveDrawer.h"

#define M_PI 3.14159265358979323846
AhmadiyyaSchool::AhmadiyyaSchool(void)
{
}


AhmadiyyaSchool::~AhmadiyyaSchool(void)
{
}
void AhmadiyyaSchool::DrawQuad(Point v1, double l, double h, int img) {
	Point v2 = Point(v1.x + l, v1.y, v1.z);
	Point v3 = Point(v1.x + l, v1.y+h, v1.z);
	Point v4 = Point(v1.x, v1.y+h, v1.z);


	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,img);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(v1.x, v1.y, v1.z);
	glTexCoord2d(1,0);
	glVertex3f(v2.x, v2.y, v2.z);
	glTexCoord2d(1,1);
	glVertex3f(v3.x, v3.y, v3.z);
	glTexCoord2d(0,1);
	glVertex3f(v4.x, v4.y, v4.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void AhmadiyyaSchool::DrawQuad2(Point v1, Point v2, Point v3, Point v4,int img,int repetx,int repety){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,img);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(v1.x, v1.y, v1.z);
	glTexCoord2d(repetx,0);
	glVertex3f(v2.x, v2.y, v2.z);
	glTexCoord2d(repetx,repety);
	glVertex3f(v3.x, v3.y, v3.z);
	glTexCoord2d(0,repety);
	glVertex3f(v4.x, v4.y, v4.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void AhmadiyyaSchool:: DrawQuad2d(Point a, double l,double h,int img){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,img);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex2d(a.x,a.y);
	glTexCoord2d(1,0);
	glVertex2d(a.x+l,a.y);
	glTexCoord2d(1,1);
	glVertex2d(a.x+l,a.y+h);
	glTexCoord2d(0,1);
	glVertex2d(a.x,a.y+h);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
void AhmadiyyaSchool::DrawCube(Point s, double l, double w, double h, int img,int door1, int window, int door2, int window2) {
	Point B = Point(s.x + l, s.y, s.z);
	Point C = Point(s.x + l, s.y, s.z + w);
	Point D = Point(s.x, s.y, s.z + w);

	Point E = Point(s.x, s.y + h, s.z);
	Point F = Point(s.x + l, s.y + h, s.z);
	Point H = Point(s.x, s.y + h, s.z + w);
	Point G = Point(s.x + l, s.y + h, s.z + w);
	glPushMatrix();
	DrawQuad2(D,C,G,H,img,3,3);//Front
	DrawQuad(Point(s.x+2.1,s.y+1.3,s.z*-1),1.6,1.2,window);
	DrawQuad(Point(-s.x+0.5,s.y+0.7,s.z*-1),1.4,2.3,door1);//Drawing green Door
	DrawQuad(Point(s.x+0.3,s.y+1,s.z*-1),1,1.8,door2);
	glPushMatrix();
	glRotated(90,0,1,0);
	DrawQuad(Point(s.x+1.5,s.y+1,s.z+0.9),1.6,1.2,window2);
	
	glPopMatrix();
	DrawQuad2(s,D,H,E,img,3,3);
	DrawQuad2(s,B,C,D,img,3,3);
	DrawQuad2(E,F,G,H,img,3,3);
	//-2,-3,-3

	DrawQuad2(B,C,G,F,img,3,3);
	DrawQuad2(s,B,F,E,img,3,3);
	glPopMatrix();

	
}
/*void AhmadiyyaSchool::DrawSphereAlhmadiyyaSchool(double r, int t){
	glEnable(GL_TEXTURE_2D);
	int a,b,stepA=2,stepB=2;
	double pi=3.14159265, stepI=stepA/2,stepJ=stepB/2;
	double i=0;
	double j=0;
	for(b=0;b<180;b+=stepB){
		for(a=0;a<360;a+=stepA){
			glNormal3f(
				cos((a+stepA/2)*pi/180)* sin((b+stepB/2)*pi/180),
				sin((a+stepA/2)*pi/180),
				cos((a+stepA/2)*pi/180)* cos((b+stepB/2)*pi/180));
			glBindTexture(GL_TEXTURE_2D,t);
			glBegin(GL_QUADS);
			//point1
			glTexCoord2d(i,j);
			glVertex3d(
				r*cos(a*pi/180)*sin(b*pi/180),
				r*sin(a*pi/180),
				r*cos(a*pi/180)*cos(b*pi/180));
			//point2
			glTexCoord2d(i+stepI,j);
			glVertex3d(
				r*cos((a+stepA)*pi/180)*sin(b*pi/180),
				r*sin((a+stepA)*pi/180),
				r*cos((a+stepA)*pi/180)*cos(b*pi/180));
			//point3
			glTexCoord2d(i+stepI,j+stepJ);
			glVertex3d(
				r*cos((a+stepA)*pi/180)*sin((b+stepB)*pi/180),
				r*sin((a+stepA)*pi/180),
				r*cos((a+stepA)*pi/180)*cos((b+stepB)*pi/180));
			//point4
			glTexCoord2d(i,j+stepJ);
			glVertex3d(
				r*cos(a*pi/180)*sin(b*pi/180),
				r*sin(a*pi/180),
				r*cos(a*pi/180)*cos((b+stepB)*pi/180));
			glEnd();
			i+=stepI;
		}
		i=0;
		j+=stepJ;
	}
}*/





void AhmadiyyaSchool::DrawAlhmadiyyaSchool(int building,int door,int door2, int window, int window2){
	PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
	glPushMatrix();
	glRotated(-180,1,0,0);
		
	DrawCube(Point(-2,-3,-3),6,6,3,building,door,door2,window, window2);
	glPopMatrix();

	glPushMatrix();
	primitiveDrawer.DrawUpperHalfBallWithTexture(Point(-0.3,3,-1),1.5,building);
	glPopMatrix();

	


}