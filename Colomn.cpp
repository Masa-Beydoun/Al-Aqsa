#include "Colomn.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Point.h"
#include "PrimitiveDrawer.h"

Colomn::Colomn(void){}
Colomn::~Colomn(void){}

int Colomn::makeColomn(Point p,float r,float disx,float h,float hForBlock,float h2,bool start,bool end,int index,int index2){
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	PrimitiveDrawer primitiveDrawer=PrimitiveDrawer();
		primitiveDrawer.DrawCube(Point(-r,0,-r),r+0.5,r,r+0.5,index2);

	float fullDistanse=0;
	float mnY=h*hForBlock;
	glPushMatrix();
	glRotated(20,0,1,0);
	for(float i=0;i<=h*hForBlock;i+=hForBlock)
	{
		primitiveDrawer.DrawCylinder3(Point(0,i,0),r,r,hForBlock,8,index);
	}
	
	for(float i=mnY;i<=mnY+3*h2;i+=h2){
		
		primitiveDrawer.DrawCylinder3(Point(0,i,0),r,r,h2,8,index);
	}
	glPopMatrix();
	double mndisx=-1.5;
	
	if(end==0){
		float disx1=disx;
		//f
		Point p11=Point(r/2.0-0.05,mnY,r);
		Point p12=Point(r/2.0-0.05,mnY+h2,r/2);
		Point p13=Point(r-0.05,mnY,r/2.0);
		Point p14=Point(r+disx1,mnY+h2,r/2.0);
		primitiveDrawer.DrawQuad(p11,p12,p14,p13,index);
		Point p15=Point(r-0.05,mnY,r/2.0-r);
		Point p16=Point(r+disx1,mnY+h2,r/2.0-r);
		primitiveDrawer.DrawQuad(p13,p14,p16,p15,index);
		Point p17=Point(r-0.05,mnY,-r/2.0);
		Point p18=Point(r-0.05,mnY+h2,-r/2.0);;	
		primitiveDrawer.DrawQuad(p15,p16,p18,p17,index);
		fullDistanse+=disx1;
		disx1+=0.1;

		//s
		Point p21=p12;
		Point p22=Point(p12.x,p12.y+h2,p12.z);
		Point p23=p14;
		Point p24=Point(p14.x+disx1,p14.y+h2,p14.z);
		primitiveDrawer.DrawQuad(p21,p22,p24,p23,index);
		Point p25=p16;
		Point p26=Point(p16.x+disx1,p16.y+h2,p16.z);
		primitiveDrawer.DrawQuad(p23,p24,p26,p25,index);
		Point p27=p18;
		Point p28=Point(p18.x+disx1,p18.y+h2,p18.z);
		primitiveDrawer.DrawQuad(p25,p26,p28,p27,index);
		fullDistanse+=disx1;
		disx1+=0.1;

		//3
		Point p31=p22;
		Point p32=Point(p22.x,p22.y+h2,p22.z);
		Point p33=p24;
		Point p34=Point(p24.x+disx1,p24.y+h2,p24.z);
		primitiveDrawer.DrawQuad(p31,p32,p34,p33,index);
		Point p35=p26;
		Point p36=Point(p26.x+disx1,p26.y+h2,p26.z);
		primitiveDrawer.DrawQuad(p33,p34,p36,p35,index);
		Point p37=p28;
		Point p38=Point(p28.x+disx1,p28.y+h2,p28.z);
		primitiveDrawer.DrawQuad(p35,p36,p38,p37,index);
		fullDistanse+=disx1;
		disx1+=0.1;
		//4
		Point p41=p32;
		Point p42=Point(p32.x,p32.y+h2,p32.z);
		Point p43=p34;
		Point p44=Point(p34.x+disx1,p34.y+h2,p34.z);
		primitiveDrawer.DrawQuad(p41,p42,p44,p43,index);
		Point p45=p36;
		Point p46=Point(p36.x+disx1,p36.y+h2,p36.z);
		primitiveDrawer.DrawQuad(p43,p44,p46,p45,index);
		Point p47=p38;
		Point p48=Point(p38.x+disx1,p38.y+h2,p38.z);
		primitiveDrawer.DrawQuad(p45,p46,p48,p47,index);
		fullDistanse=p48.x;
		disx1+=0.1;
	}

	if(start==0){
		float disx1=disx;
		Point p11=Point(-r/2.0+0.05,mnY,r);
		Point p12=Point(-r/2.0+0.05,mnY+h2,r/2.0);
		Point p13=Point(-r+0.05,mnY,r/2.0);
		Point p14=Point(-r-disx1,mnY+h2,r/2.0);
		primitiveDrawer.DrawQuad(p11,p12,p14,p13,index);
		Point p15=Point(-r+0.05,mnY,r/2.0-r);
		Point p16=Point(-r-disx1,mnY+h2,r/2.0-r);
		primitiveDrawer.DrawQuad(p13,p14,p16,p15,index);
		Point p17=Point(-r+0.05,mnY,r/2.0);
		Point p18=Point(-r+0.05,mnY+h2,r/2.0);;	
		primitiveDrawer.DrawQuad(p15,p16,p18,p17,index);
		disx1+=0.1;

		
		//s
		Point p21=p12;
		Point p22=Point(p12.x,p12.y+h2,p12.z);
		Point p23=p14;
		Point p24=Point(p14.x-disx1,p14.y+h2,p14.z);
		primitiveDrawer.DrawQuad(p21,p22,p24,p23,index);
		Point p25=p16;
		Point p26=Point(p16.x-disx1,p16.y+h2,p16.z);
		primitiveDrawer.DrawQuad(p23,p24,p26,p25,index);
		Point p27=p18;
		Point p28=Point(p18.x-disx1,p18.y+h2,p18.z);
		primitiveDrawer.DrawQuad(p25,p26,p28,p27,index);
		disx1+=0.1;

		//3
		Point p31=p22;
		Point p32=Point(p22.x,p22.y+h2,p22.z);
		Point p33=p24;
		Point p34=Point(p24.x-disx1,p24.y+h2,p24.z);
		primitiveDrawer.DrawQuad(p31,p32,p34,p33,index);
		Point p35=p26;
		Point p36=Point(p26.x-disx1,p26.y+h2,p26.z);
		primitiveDrawer.DrawQuad(p33,p34,p36,p35,index);
		Point p37=p28;
		Point p38=Point(p28.x-disx1,p28.y+h2,p28.z);
		primitiveDrawer.DrawQuad(p35,p36,p38,p37,index);
		disx1+=0.1;
		//4
		Point p41=p32;
		Point p42=Point(p32.x,p32.y+h2,p32.z);
		Point p43=p34;
		Point p44=Point(p34.x-disx1,p34.y+h2,p34.z);
		primitiveDrawer.DrawQuad(p41,p42,p44,p43,index);
		Point p45=p36;
		Point p46=Point(p36.x-disx1,p36.y+h2,p36.z);
		primitiveDrawer.DrawQuad(p43,p44,p46,p45,index);
		Point p47=p38;
		Point p48=Point(p38.x-disx1,p38.y+h2,p38.z);
		primitiveDrawer.DrawQuad(p45,p46,p48,p47,index);
		disx1+=0.1;
	}
	
	glPopMatrix();
	return fullDistanse;
}

void Colomn::makeArch(Point p,int h,bool dir,bool start,bool end){
	PrimitiveDrawer primitiveDrawer=PrimitiveDrawer();
	glPushMatrix();
	if(dir==1){
		glRotated(90,0,1,0);
	}

	double disx=0.25,mndisx=-1.5;
	for(int i=h+1;i<=h+4;i++){
		primitiveDrawer.DrawQuad(Point(p.x,p.y+i,p.z+2),Point(p.x-1,p.y+i,p.z+2),Point(p.x-1,p.y+i+1,p.z+2),Point(p.x,p.y+i+1,p.z+2),0);
		primitiveDrawer.DrawQuad(Point(p.x,p.y+i,p.z),Point(p.x-1,p.y+i,p.z),Point(p.x-1,p.y+i+1,p.z),Point(p.x,p.y+i+1,p.z),0);
	}


	if((start==1 && dir==0)||(end==1 && dir==1)){
		//f
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+1,p.z+2),Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-1.5,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-1.5,p.y+h+2,p.z+0.5),Point(p.x-1.5,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-1,p.y+h+1,p.z),Point(p.x-1,p.y+h+2,p.z),Point(p.x-1.5,p.y+h+2,p.z+0.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+2,p.z+0.5),Point(p.x-1,p.y+h+2,p.z),Point(p.x-1,p.y+h+3,p.z),Point(p.x-1.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+2,p.z+0.5),Point(p.x-1.5,p.y+h+3,p.z+0.5),Point(p.x-1.5,p.y+h+3,p.z+1.5),Point(p.x-1.5,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-1.5,p.y+h+3,p.z+1.5),Point(p.x-1.5,p.y+h+2,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+3,p.z+1.5),Point(p.x-1.5,p.y+h+4,p.z+1.5),Point(p.x-1.5,p.y+h+4,p.z+0.5),Point(p.x-1.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+3,p.z+0.5),Point(p.x-1,p.y+h+3,p.z),Point(p.x-1,p.y+h+4,p.z),Point(p.x-1.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-1.5,p.y+h+4,p.z+1.5),Point(p.x-1.5,p.y+h+3,p.z+1.5),0);
		//f
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+4,p.z+1.5),Point(p.x-1.5,p.y+h+5,p.z+1.5),Point(p.x-1.5,p.y+h+5,p.z+0.5),Point(p.x-1.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+4,p.z+0.5),Point(p.x-1,p.y+h+4,p.z),Point(p.x-1,p.y+h+5,p.z),Point(p.x-1.5,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-1,p.y+h+5,p.z+2),Point(p.x-1.5,p.y+h+5,p.z+1.5),Point(p.x-1.5,p.y+h+4,p.z+1.5),0);
	
	}
	else{	
		//f
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+1,p.z+2),Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-5*disx,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-5*disx,p.y+h+2,p.z+0.5),Point(p.x-5*disx,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-1,p.y+h+1,p.z),Point(p.x-1,p.y+h+2,p.z),Point(p.x-5*disx,p.y+h+2,p.z+0.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x-5*disx,p.y+h+2,p.z+0.5),Point(p.x-7*disx,p.y+h+3,p.z+0.5),Point(p.x-7*disx,p.y+h+3,p.z+1.5),Point(p.x-5*disx,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-5*disx,p.y+h+2,p.z+0.5),Point(p.x-1,p.y+h+2,p.z),Point(p.x-1,p.y+h+3,p.z),Point(p.x-7*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-7*disx,p.y+h+3,p.z+1.5),Point(p.x-5*disx,p.y+h+2,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x-7*disx,p.y+h+3,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-7*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-7*disx,p.y+h+3,p.z+0.5),Point(p.x-1,p.y+h+3,p.z),Point(p.x-1,p.y+h+4,p.z),Point(p.x-9*disx,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-7*disx,p.y+h+3,p.z+1.5),0);
		//f
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-9*disx,p.y+h+5,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-9*disx,p.y+h+5,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-9*disx-0.5,p.y+h+4,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+0.5),0);
		
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-1,p.y+h+4,p.z),Point(p.x-1,p.y+h+5,p.z),Point(p.x-9*disx,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-1,p.y+h+5,p.z+2),Point(p.x-9*disx,p.y+h+5,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+1.5),0);

	}
	if((end==1 && dir==0) || (start==1 && dir==1)){
		//f
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x+0.5,p.y+h+2,p.z+0.5),Point(p.x+0.5,p.y+h+2,p.z+1.5),Point(p.x+0.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+1.5),Point(p.x,p.y+h+1,p.z+2),Point(p.x,p.y+h+2,p.z+2),Point(p.x+0.5,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x,p.y+h+1,p.z),Point(p.x,p.y+h+2,p.z),Point(p.x+0.5,p.y+h+2,p.z+0.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+2,p.z+0.5),Point(p.x+0.5,p.y+h+3,p.z+0.5),Point(p.x+0.5,p.y+h+3,p.z+1.5),Point(p.x+0.5,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+2,p.z+0.5),Point(p.x,p.y+h+2,p.z),Point(p.x,p.y+h+3,p.z),Point(p.x+0.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+2,p.z+1.5),Point(p.x,p.y+h+2,p.z+2),Point(p.x,p.y+h+3,p.z+2),Point(p.x+0.5,p.y+h+3,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+3,p.z+1.5),Point(p.x+0.5,p.y+h+4,p.z+1.5),Point(p.x+0.5,p.y+h+4,p.z+0.5),Point(p.x+0.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+3,p.z+0.5),Point(p.x,p.y+h+3,p.z),Point(p.x,p.y+h+4,p.z),Point(p.x+0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+3,p.z+1.5),Point(p.x,p.y+h+3,p.z+2),Point(p.x,p.y+h+4,p.z+2),Point(p.x+0.5,p.y+h+4,p.z+1.5),0);
		//f
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+4,p.z+1.5),Point(p.x+0.5,p.y+h+5,p.z+1.5),Point(p.x+0.5,p.y+h+5,p.z+0.5),Point(p.x+0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+4,p.z+0.5),Point(p.x,p.y+h+4,p.z),Point(p.x,p.y+h+5,p.z),Point(p.x+0.5,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+4,p.z+1.5),Point(p.x,p.y+h+4,p.z+2),Point(p.x,p.y+h+5,p.z+2),Point(p.x+0.5,p.y+h+5,p.z+1.5),0);
	}
	else{
		//f
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+1.5),Point(p.x,p.y+h+1,p.z+2),Point(p.x,p.y+h+2,p.z+2),Point(p.x+3*disx,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x,p.y+h+1,p.z),Point(p.x,p.y+h+2,p.z),Point(p.x+3*disx,p.y+h+2,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x+3*disx,p.y+h+2,p.z+0.5),Point(p.x+3*disx,p.y+h+2,p.z+1.5),Point(p.x+0.5,p.y+h+1,p.z+1.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x+3*disx,p.y+h+2,p.z+0.5),Point(p.x+5*disx,p.y+h+3,p.z+0.5),Point(p.x+5*disx,p.y+h+3,p.z+1.5),Point(p.x+3*disx,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+3*disx,p.y+h+2,p.z+0.5),Point(p.x,p.y+h+2,p.z),Point(p.x,p.y+h+3,p.z),Point(p.x+5*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+3*disx,p.y+h+2,p.z+1.5),Point(p.x,p.y+h+2,p.z+2),Point(p.x,p.y+h+3,p.z+2),Point(p.x+5*disx,p.y+h+3,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x+5*disx,p.y+h+3,p.z+1.5),Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x+5*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+5*disx,p.y+h+3,p.z+0.5),Point(p.x,p.y+h+3,p.z),Point(p.x,p.y+h+4,p.z),Point(p.x+7*disx,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+5*disx,p.y+h+3,p.z+1.5),Point(p.x,p.y+h+3,p.z+2),Point(p.x,p.y+h+4,p.z+2),Point(p.x+7*disx,p.y+h+4,p.z+1.5),0);
		//f

		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x+7*disx,p.y+h+5,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+5,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx+0.5,p.y+h+4,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+0.5),0);
	
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+5,p.z+1.5),Point(p.x+7*disx,p.y+h+5,p.z+0.5),Point(p.x+7*disx,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x,p.y+h+4,p.z),Point(p.x,p.y+h+5,p.z),Point(p.x+7*disx,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x,p.y+h+4,p.z+2),Point(p.x,p.y+h+5,p.z+2),Point(p.x+7*disx,p.y+h+5,p.z+1.5),0);
	}
	
	glPopMatrix();
	
}

void Colomn::make_n_Arch(Point p,int n,int h,bool dir){
	

	for(float i=p.x,cnt=0;cnt<n;i+=5,cnt++){
		glPushMatrix();
		if(dir==1){
			glTranslated(0,0,i);
		}
		else{
			glTranslated(i,0,0);
		}
		if(cnt==0)
			makeArch(p,h,dir,1,0);
		else if(cnt==n-1)
			makeArch(p,h,dir,0,1);
		else 
			makeArch(p,h,dir,0,0);
		glPopMatrix();
	}
	
}

void Colomn::make_n_colomns(Point p,int n,float r,float disx,float h,float hForBlock,float h2,int index, float correction){

	float go=0;
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	for(float i=0,cnt=0;cnt<n;i+=2*go+0.8,cnt++){
		if(cnt==0)
			go=makeColomn(Point(i,0,0),r,disx,h,hForBlock,h2,1,0,index);
		else if(cnt==n-1)
			go=makeColomn(Point(i,0,0),r,disx,h,hForBlock,h2,0,1,index);
		else 
			go=makeColomn(Point(i,0,0),r,disx,h,hForBlock,h2,0,0,index);
	}
	glPopMatrix();
}


void Colomn::newColomn(Point p,float r,int height,int index1,int index2){
	PrimitiveDrawer primitiveDrawer=PrimitiveDrawer();
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	for(int i=0;i<height;i++){
		primitiveDrawer.DrawCylinder(Point(0,i,0),r,1,8,index1);
	}
	primitiveDrawer.DrawCylinder(Point(0,height,0),r,0.5,8,index1);
	primitiveDrawer.DrawCube(Point(-(1.5)*r,0,-(1.5)*r),3*r,height/8.0,3*r,index2);
	primitiveDrawer.DrawCube(Point(-(1.5)*r,height+0.5,-(1.5)*r),3*r,height/8.0,3*r,index2);

	glPopMatrix();	
}

int Colomn::makeColomn2(Point p,float r,float disx,float h,float hForBlock,float h2,bool start,bool end,int index,int index2, float correction,int index3){
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	PrimitiveDrawer primitiveDrawer=PrimitiveDrawer();
	float fullDistanse=0;
		primitiveDrawer.DrawCube(Point(-r,0,-r),r+0.5,r,r+0.5,index3);
	float mnY=h*hForBlock;
	glPushMatrix();
	glRotated(20,0,1,0);
	for(float i=0;i<=h*hForBlock;i+=hForBlock)
	{
		primitiveDrawer.DrawCylinder3(Point(0,i,0),r,r,hForBlock,8,index);
	}
	
	for(float i=mnY;i<=mnY+3*h2;i+=h2){
		
		primitiveDrawer.DrawCylinder3(Point(0,i,0),r,r,h2,8,index);
	}
	glPopMatrix();
	double mndisx=-1.5;
	
	if(end==0){
		float disx1=disx;
		//f
		Point p11=Point(r/2.0-0.05,mnY,r);
		Point p12=Point(r/2.0-0.05,mnY+h2,r/2);
		Point p13=Point(r-0.05,mnY,r/2.0);
		Point p14=Point(r+disx1,mnY+h2,r/2.0);
		primitiveDrawer.DrawQuad(p11,p12,p14,p13,index2);
		Point p15=Point(r-0.05,mnY,r/2.0-r);
		Point p16=Point(r+disx1,mnY+h2,r/2.0-r);
		primitiveDrawer.DrawQuad(p13,p14,p16,p15,index2);
		Point p17=Point(r-0.05,mnY,-r/2.0);
		Point p18=Point(r-0.05,mnY+h2,-r/2.0);;	
		primitiveDrawer.DrawQuad(p15,p16,p18,p17,index2);
		fullDistanse+=disx1;
		disx1+=0.2;

		//s
		Point p21=p12;
		Point p22=Point(p12.x,p12.y+h2,p12.z);
		Point p23=p14;
		Point p24=Point(p14.x+disx1,p14.y+h2,p14.z);
		primitiveDrawer.DrawQuad(p21,p22,p24,p23,index2);
		Point p25=p16;
		Point p26=Point(p16.x+disx1,p16.y+h2,p16.z);
		primitiveDrawer.DrawQuad(p23,p24,p26,p25,index2);
		Point p27=p18;
		Point p28=Point(p18.x+disx1,p18.y+h2,p18.z);
		primitiveDrawer.DrawQuad(p25,p26,p28,p27,index2);
		fullDistanse+=disx1;
		disx1+=0.2;

		//3
		Point p31=p22;
		Point p32=Point(p22.x,p22.y+h2,p22.z);
		Point p33=p24;
		Point p34=Point(p24.x+disx1,p24.y+h2,p24.z);
		primitiveDrawer.DrawQuad(p31,p32,p34,p33,index2);
		Point p35=p26;
		Point p36=Point(p26.x+disx1,p26.y+h2,p26.z);
		primitiveDrawer.DrawQuad(p33,p34,p36,p35,index2);
		Point p37=p28;
		Point p38=Point(p28.x+disx1,p28.y+h2,p28.z);
		primitiveDrawer.DrawQuad(p35,p36,p38,p37,index2);
		fullDistanse+=disx1;
		disx1+=0.2;
		//4
		Point p41=p32;
		Point p42=Point(p32.x,p32.y+h2,p32.z);
		Point p43=p34;
		Point p44=Point(p34.x+disx1,p34.y+h2,p34.z);
		primitiveDrawer.DrawQuad(p41,p42,p44,p43,index2);
		Point p45=p36;
		Point p46=Point(p36.x+disx1,p36.y+h2,p36.z);
		primitiveDrawer.DrawQuad(p43,p44,p46,p45,index2);
		Point p47=p38;
		Point p48=Point(p38.x+disx1,p38.y+h2,p38.z);
		primitiveDrawer.DrawQuad(p45,p46,p48,p47,index2);
		fullDistanse=p48.x;
		disx1+=0.2;
	}

	if(start==0){
		float disx1=disx;
		Point p11=Point(-r/2.0+0.05,mnY,r);
		Point p12=Point(-r/2.0+0.05,mnY+h2,r/2.0);
		Point p13=Point(-r+0.05,mnY,r/2.0);
		Point p14=Point(-r-disx1,mnY+h2,r/2.0);
		primitiveDrawer.DrawQuad(p11,p12,p14,p13,index2);
		Point p15=Point(-r+0.05,mnY,r/2.0-r);
		Point p16=Point(-r-disx1,mnY+h2,r/2.0-r);
		primitiveDrawer.DrawQuad(p13,p14,p16,p15,index2);
		Point p17=Point(-r+0.05,mnY,r/2.0);
		Point p18=Point(-r+0.05,mnY+h2,r/2.0);;	
		primitiveDrawer.DrawQuad(p15,p16,p18,p17,index2);
		disx1+=0.2;

		
		//s
		Point p21=p12;
		Point p22=Point(p12.x,p12.y+h2,p12.z);
		Point p23=p14;
		Point p24=Point(p14.x-disx1,p14.y+h2,p14.z);
		primitiveDrawer.DrawQuad(p21,p22,p24,p23,index2);
		Point p25=p16;
		Point p26=Point(p16.x-disx1,p16.y+h2,p16.z);
		primitiveDrawer.DrawQuad(p23,p24,p26,p25,index2);
		Point p27=p18;
		Point p28=Point(p18.x-disx1,p18.y+h2,p18.z);
		primitiveDrawer.DrawQuad(p25,p26,p28,p27,index2);
		disx1+=0.2;

		//3
		Point p31=p22;
		Point p32=Point(p22.x,p22.y+h2,p22.z);
		Point p33=p24;
		Point p34=Point(p24.x-disx1,p24.y+h2,p24.z);
		primitiveDrawer.DrawQuad(p31,p32,p34,p33,index2);
		Point p35=p26;
		Point p36=Point(p26.x-disx1,p26.y+h2,p26.z);
		primitiveDrawer.DrawQuad(p33,p34,p36,p35,index2);
		Point p37=p28;
		Point p38=Point(p28.x-disx1,p28.y+h2,p28.z);
		primitiveDrawer.DrawQuad(p35,p36,p38,p37,index2);
		disx1+=0.2;
		//4
		Point p41=p32;
		Point p42=Point(p32.x,p32.y+h2,p32.z);
		Point p43=p34;
		Point p44=Point(p34.x-disx1,p34.y+h2,p34.z);
		primitiveDrawer.DrawQuad(p41,p42,p44,p43,index2);
		Point p45=p36;
		Point p46=Point(p36.x-disx1,p36.y+h2,p36.z);
		primitiveDrawer.DrawQuad(p43,p44,p46,p45,index2);
		Point p47=p38;
		Point p48=Point(p38.x-disx1,p38.y+h2,p38.z);
		primitiveDrawer.DrawQuad(p45,p46,p48,p47,index2);
		disx1+=0.2;
	}
	
	glPopMatrix();
	return fullDistanse;
}

void Colomn::make_n_colomns2(Point p,int n,float r,float disx,float h,float hForBlock,float h2,int index,int index2,float correction,int index3){

	float go=0;
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	for(float i=0,cnt=0;cnt<n;i+=2*go+correction,cnt++){
		if(cnt==0)
			go=makeColomn2(Point(i,0,0),r,disx,h,hForBlock,h2,1,0,index,index2);
		else if(cnt==n-1)
			go=makeColomn2(Point(i,0,0),r,disx,h,hForBlock,h2,0,1,index,index2);
		else 
			go=makeColomn2(Point(i,0,0),r,disx,h,hForBlock,h2,0,0,index,index2);
	}
	glPopMatrix();
}

int Colomn::makeColomn3(Point p,float r,float disx,float h,float hForBlock,float h2,bool start,bool end,int index,int index2){
	int text[] = {index2, index2,index2, index2,index2, index2};
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	PrimitiveDrawer primitiveDrawer=PrimitiveDrawer();
		primitiveDrawer.DrawCube2(Point(-r,0,-r),r+0.5,r,r+0.5,text,1,1);

	float fullDistanse=0;
	float mnY=h*hForBlock;
	glPushMatrix();
	glRotated(20,0,1,0);
	for(float i=0;i<=h*hForBlock;i+=hForBlock)
	{
		primitiveDrawer.DrawCylinder3(Point(0,i,0),r,r,hForBlock,8,index);
	}
	
	for(float i=mnY;i<=mnY+3*h2;i+=h2){
		
		primitiveDrawer.DrawCylinder3(Point(0,i,0),r,r,h2,8,index);
	}
	glPopMatrix();
	double mndisx=-1.5;
	
	if(end==0){
		float disx1=disx;
		//f
		Point p11=Point(r/2.0-0.05,mnY,r);
		Point p12=Point(r/2.0-0.05,mnY+h2,r/2);
		Point p13=Point(r-0.05,mnY,r/2.0);
		Point p14=Point(r+disx1,mnY+h2,r/2.0);
		primitiveDrawer.DrawQuad(p11,p12,p14,p13,index);
		Point p15=Point(r-0.05,mnY,r/2.0-r);
		Point p16=Point(r+disx1,mnY+h2,r/2.0-r);
		primitiveDrawer.DrawQuad(p13,p14,p16,p15,index);
		Point p17=Point(r-0.05,mnY,-r/2.0);
		Point p18=Point(r-0.05,mnY+h2,-r/2.0);;	
		primitiveDrawer.DrawQuad(p15,p16,p18,p17,index);
		fullDistanse+=disx1;
		disx1+=0.2;

		//s
		Point p21=p12;
		Point p22=Point(p12.x,p12.y+h2,p12.z);
		Point p23=p14;
		Point p24=Point(p14.x+disx1,p14.y+h2,p14.z);
		primitiveDrawer.DrawQuad(p21,p22,p24,p23,index);
		Point p25=p16;
		Point p26=Point(p16.x+disx1,p16.y+h2,p16.z);
		primitiveDrawer.DrawQuad(p23,p24,p26,p25,index);
		Point p27=p18;
		Point p28=Point(p18.x+disx1,p18.y+h2,p18.z);
		primitiveDrawer.DrawQuad(p25,p26,p28,p27,index);
		fullDistanse+=disx1;
		disx1+=0.2;

		//3
		Point p31=p22;
		Point p32=Point(p22.x,p22.y+h2,p22.z);
		Point p33=p24;
		Point p34=Point(p24.x+disx1,p24.y+h2,p24.z);
		primitiveDrawer.DrawQuad(p31,p32,p34,p33,index);
		Point p35=p26;
		Point p36=Point(p26.x+disx1,p26.y+h2,p26.z);
		primitiveDrawer.DrawQuad(p33,p34,p36,p35,index);
		Point p37=p28;
		Point p38=Point(p28.x+disx1,p28.y+h2,p28.z);
		primitiveDrawer.DrawQuad(p35,p36,p38,p37,index);
		fullDistanse+=disx1;
		disx1+=0.2;
		//4
		Point p41=p32;
		Point p42=Point(p32.x,p32.y+h2,p32.z);
		Point p43=p34;
		Point p44=Point(p34.x+disx1,p34.y+h2,p34.z);
		primitiveDrawer.DrawQuad(p41,p42,p44,p43,index);
		Point p45=p36;
		Point p46=Point(p36.x+disx1,p36.y+h2,p36.z);
		primitiveDrawer.DrawQuad(p43,p44,p46,p45,index);
		Point p47=p38;
		Point p48=Point(p38.x+disx1,p38.y+h2,p38.z);
		primitiveDrawer.DrawQuad(p45,p46,p48,p47,index);
		fullDistanse=p48.x;
		disx1+=0.2;
	}

	if(start==0){
		float disx1=disx;
		Point p11=Point(-r/2.0+0.05,mnY,r);
		Point p12=Point(-r/2.0+0.05,mnY+h2,r/2.0);
		Point p13=Point(-r+0.05,mnY,r/2.0);
		Point p14=Point(-r-disx1,mnY+h2,r/2.0);
		primitiveDrawer.DrawQuad(p11,p12,p14,p13,index);
		Point p15=Point(-r+0.05,mnY,r/2.0-r);
		Point p16=Point(-r-disx1,mnY+h2,r/2.0-r);
		primitiveDrawer.DrawQuad(p13,p14,p16,p15,index);
		Point p17=Point(-r+0.05,mnY,r/2.0);
		Point p18=Point(-r+0.05,mnY+h2,r/2.0);;	
		primitiveDrawer.DrawQuad(p15,p16,p18,p17,index);
		disx1+=0.2;

		
		//s
		Point p21=p12;
		Point p22=Point(p12.x,p12.y+h2,p12.z);
		Point p23=p14;
		Point p24=Point(p14.x-disx1,p14.y+h2,p14.z);
		primitiveDrawer.DrawQuad(p21,p22,p24,p23,index);
		Point p25=p16;
		Point p26=Point(p16.x-disx1,p16.y+h2,p16.z);
		primitiveDrawer.DrawQuad(p23,p24,p26,p25,index);
		Point p27=p18;
		Point p28=Point(p18.x-disx1,p18.y+h2,p18.z);
		primitiveDrawer.DrawQuad(p25,p26,p28,p27,index);
		disx1+=0.2;

		//3
		Point p31=p22;
		Point p32=Point(p22.x,p22.y+h2,p22.z);
		Point p33=p24;
		Point p34=Point(p24.x-disx1,p24.y+h2,p24.z);
		primitiveDrawer.DrawQuad(p31,p32,p34,p33,index);
		Point p35=p26;
		Point p36=Point(p26.x-disx1,p26.y+h2,p26.z);
		primitiveDrawer.DrawQuad(p33,p34,p36,p35,index);
		Point p37=p28;
		Point p38=Point(p28.x-disx1,p28.y+h2,p28.z);
		primitiveDrawer.DrawQuad(p35,p36,p38,p37,index);
		disx1+=0.2;
		//4
		Point p41=p32;
		Point p42=Point(p32.x,p32.y+h2,p32.z);
		Point p43=p34;
		Point p44=Point(p34.x-disx1,p34.y+h2,p34.z);
		primitiveDrawer.DrawQuad(p41,p42,p44,p43,index);
		Point p45=p36;
		Point p46=Point(p36.x-disx1,p36.y+h2,p36.z);
		primitiveDrawer.DrawQuad(p43,p44,p46,p45,index);
		Point p47=p38;
		Point p48=Point(p38.x-disx1,p38.y+h2,p38.z);
		primitiveDrawer.DrawQuad(p45,p46,p48,p47,index);
		disx1+=0.2;
	}
	
	glPopMatrix();
	return fullDistanse;
}

void Colomn::make_n_colomns3(Point p,int n,float r,float disx,float h,float hForBlock,float h2,int index, float correction){

	float go=0;
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	for(float i=0,cnt=0;cnt<n;i+=2*go+0.8,cnt++){
		if(cnt==0)
			go=makeColomn3(Point(i,0,0),r,disx,h,hForBlock,h2,1,0,index);
		else if(cnt==n-1)
			go=makeColomn3(Point(i,0,0),r,disx,h,hForBlock,h2,0,1,index);
		else 
			go=makeColomn3(Point(i,0,0),r,disx,h,hForBlock,h2,0,0,index);
	}
	glPopMatrix();
}


// for Domes
void Colomn::make_n_colomns_for_dome(Point p,int n,int h,bool dir){
	for(float i=p.x,cnt=0;cnt<n;i+=5,cnt++){
		if(dir==1){
			glTranslated(0,0,i);
		}
		else{
			glTranslated(i,0,0);
		}
		if(cnt==0)
			make_colomn_for_dome(p,h,dir,1,0);
		else if(cnt==n-1)
			make_colomn_for_dome(p,h,dir,0,1);
		else 
			make_colomn_for_dome(p,h,dir,0,0);
		if(dir==1){
			glTranslated(0,0,-i);
		}
		else{
			glTranslated(-i,0,0);
		}
	}
}

void Colomn::make_colomn_for_dome(Point p,int h,bool dir,bool start,bool end){
	PrimitiveDrawer primitiveDrawer=PrimitiveDrawer();
	if(dir==1){
		glRotated(90,0,1,0);
	}

	glTranslated(0.2,0,-0.4);
	primitiveDrawer.Draw8(Point(p.x,p.y-0.5,p.z),1,0.5,0);
	glTranslated(-0.2,0,+0.4);

	for(int i=p.y;i<=p.y+h;i+=1)
	{
		if(i<=p.y+h-1 || start==1 || end==1) primitiveDrawer.Draw8(Point(p.x,i,p.z),0.5,1,0);
		else primitiveDrawer.Draw8(Point(p.x,i,p.z),0.7,1,0);
	}
	
	for(int i=h;i<=h+4;i++){
		primitiveDrawer.DrawQuad(Point(p.x,p.y+i,p.z+2),Point(p.x-1,p.y+i,p.z+2),Point(p.x-1,p.y+i+1,p.z+2),Point(p.x,p.y+i+1,p.z+2),0);
		primitiveDrawer.DrawQuad(Point(p.x,p.y+i,p.z),Point(p.x-1,p.y+i,p.z),Point(p.x-1,p.y+i+1,p.z),Point(p.x,p.y+i+1,p.z),0);
	}

	double disx=0.25,mndisx=-1.5;



	if((start==1 && dir==0)||(end==1 && dir==1)){
		//f
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+1,p.z+2),Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-1.5,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-1.5,p.y+h+2,p.z+0.5),Point(p.x-1.5,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-1,p.y+h+1,p.z),Point(p.x-1,p.y+h+2,p.z),Point(p.x-1.5,p.y+h+2,p.z+0.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+2,p.z+0.5),Point(p.x-1,p.y+h+2,p.z),Point(p.x-1,p.y+h+3,p.z),Point(p.x-1.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+2,p.z+0.5),Point(p.x-1.5,p.y+h+3,p.z+0.5),Point(p.x-1.5,p.y+h+3,p.z+1.5),Point(p.x-1.5,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-1.5,p.y+h+3,p.z+1.5),Point(p.x-1.5,p.y+h+2,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+3,p.z+1.5),Point(p.x-1.5,p.y+h+4,p.z+1.5),Point(p.x-1.5,p.y+h+4,p.z+0.5),Point(p.x-1.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+3,p.z+0.5),Point(p.x-1,p.y+h+3,p.z),Point(p.x-1,p.y+h+4,p.z),Point(p.x-1.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-1.5,p.y+h+4,p.z+1.5),Point(p.x-1.5,p.y+h+3,p.z+1.5),0);
		//f
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+4,p.z+1.5),Point(p.x-1.5,p.y+h+5,p.z+1.5),Point(p.x-1.5,p.y+h+5,p.z+0.5),Point(p.x-1.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+4,p.z+0.5),Point(p.x-1,p.y+h+4,p.z),Point(p.x-1,p.y+h+5,p.z),Point(p.x-1.5,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-1,p.y+h+5,p.z+2),Point(p.x-1.5,p.y+h+5,p.z+1.5),Point(p.x-1.5,p.y+h+4,p.z+1.5),0);
	
	}
	else{	
		//f
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+1,p.z+2),Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-5*disx,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-5*disx,p.y+h+2,p.z+0.5),Point(p.x-5*disx,p.y+h+2,p.z+1.5),Point(p.x-1.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1.5,p.y+h+1,p.z+0.5),Point(p.x-1,p.y+h+1,p.z),Point(p.x-1,p.y+h+2,p.z),Point(p.x-5*disx,p.y+h+2,p.z+0.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x-5*disx,p.y+h+2,p.z+0.5),Point(p.x-7*disx,p.y+h+3,p.z+0.5),Point(p.x-7*disx,p.y+h+3,p.z+1.5),Point(p.x-5*disx,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-5*disx,p.y+h+2,p.z+0.5),Point(p.x-1,p.y+h+2,p.z),Point(p.x-1,p.y+h+3,p.z),Point(p.x-7*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+2,p.z+2),Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-7*disx,p.y+h+3,p.z+1.5),Point(p.x-5*disx,p.y+h+2,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x-7*disx,p.y+h+3,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-7*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-7*disx,p.y+h+3,p.z+0.5),Point(p.x-1,p.y+h+3,p.z),Point(p.x-1,p.y+h+4,p.z),Point(p.x-9*disx,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+3,p.z+2),Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-7*disx,p.y+h+3,p.z+1.5),0);
		//f
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-9*disx,p.y+h+5,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+1.5),Point(p.x-9*disx,p.y+h+5,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-9*disx-0.5,p.y+h+4,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+1.5),Point(p.x-9*disx-0.5,p.y+h+5,p.z+0.5),Point(p.x-9*disx-0.5,p.y+h+4,p.z+0.5),0);
		
		primitiveDrawer.DrawQuad(Point(p.x-9*disx,p.y+h+4,p.z+0.5),Point(p.x-1,p.y+h+4,p.z),Point(p.x-1,p.y+h+5,p.z),Point(p.x-9*disx,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x-1,p.y+h+4,p.z+2),Point(p.x-1,p.y+h+5,p.z+2),Point(p.x-9*disx,p.y+h+5,p.z+1.5),Point(p.x-9*disx,p.y+h+4,p.z+1.5),0);

	}
	if((end==1 && dir==0) || (start==1 && dir==1)){
		//f
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x+0.5,p.y+h+2,p.z+0.5),Point(p.x+0.5,p.y+h+2,p.z+1.5),Point(p.x+0.5,p.y+h+1,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+1.5),Point(p.x,p.y+h+1,p.z+2),Point(p.x,p.y+h+2,p.z+2),Point(p.x+0.5,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x,p.y+h+1,p.z),Point(p.x,p.y+h+2,p.z),Point(p.x+0.5,p.y+h+2,p.z+0.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+2,p.z+0.5),Point(p.x+0.5,p.y+h+3,p.z+0.5),Point(p.x+0.5,p.y+h+3,p.z+1.5),Point(p.x+0.5,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+2,p.z+0.5),Point(p.x,p.y+h+2,p.z),Point(p.x,p.y+h+3,p.z),Point(p.x+0.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+2,p.z+1.5),Point(p.x,p.y+h+2,p.z+2),Point(p.x,p.y+h+3,p.z+2),Point(p.x+0.5,p.y+h+3,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+3,p.z+1.5),Point(p.x+0.5,p.y+h+4,p.z+1.5),Point(p.x+0.5,p.y+h+4,p.z+0.5),Point(p.x+0.5,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+3,p.z+0.5),Point(p.x,p.y+h+3,p.z),Point(p.x,p.y+h+4,p.z),Point(p.x+0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+3,p.z+1.5),Point(p.x,p.y+h+3,p.z+2),Point(p.x,p.y+h+4,p.z+2),Point(p.x+0.5,p.y+h+4,p.z+1.5),0);
		//f
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+4,p.z+1.5),Point(p.x+0.5,p.y+h+5,p.z+1.5),Point(p.x+0.5,p.y+h+5,p.z+0.5),Point(p.x+0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+4,p.z+0.5),Point(p.x,p.y+h+4,p.z),Point(p.x,p.y+h+5,p.z),Point(p.x+0.5,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+4,p.z+1.5),Point(p.x,p.y+h+4,p.z+2),Point(p.x,p.y+h+5,p.z+2),Point(p.x+0.5,p.y+h+5,p.z+1.5),0);
	}
	else{
		//f
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+1.5),Point(p.x,p.y+h+1,p.z+2),Point(p.x,p.y+h+2,p.z+2),Point(p.x+3*disx,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x,p.y+h+1,p.z),Point(p.x,p.y+h+2,p.z),Point(p.x+3*disx,p.y+h+2,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+0.5,p.y+h+1,p.z+0.5),Point(p.x+3*disx,p.y+h+2,p.z+0.5),Point(p.x+3*disx,p.y+h+2,p.z+1.5),Point(p.x+0.5,p.y+h+1,p.z+1.5),0);
		//s
		primitiveDrawer.DrawQuad(Point(p.x+3*disx,p.y+h+2,p.z+0.5),Point(p.x+5*disx,p.y+h+3,p.z+0.5),Point(p.x+5*disx,p.y+h+3,p.z+1.5),Point(p.x+3*disx,p.y+h+2,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+3*disx,p.y+h+2,p.z+0.5),Point(p.x,p.y+h+2,p.z),Point(p.x,p.y+h+3,p.z),Point(p.x+5*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+3*disx,p.y+h+2,p.z+1.5),Point(p.x,p.y+h+2,p.z+2),Point(p.x,p.y+h+3,p.z+2),Point(p.x+5*disx,p.y+h+3,p.z+1.5),0);
		//t
		primitiveDrawer.DrawQuad(Point(p.x+5*disx,p.y+h+3,p.z+1.5),Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x+5*disx,p.y+h+3,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+5*disx,p.y+h+3,p.z+0.5),Point(p.x,p.y+h+3,p.z),Point(p.x,p.y+h+4,p.z),Point(p.x+7*disx,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+5*disx,p.y+h+3,p.z+1.5),Point(p.x,p.y+h+3,p.z+2),Point(p.x,p.y+h+4,p.z+2),Point(p.x+7*disx,p.y+h+4,p.z+1.5),0);
		//f

		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x+7*disx,p.y+h+5,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+5,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+1.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx+0.5,p.y+h+4,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+1.5),Point(p.x+7*disx+0.5,p.y+h+5,p.z+0.5),Point(p.x+7*disx+0.5,p.y+h+4,p.z+0.5),0);
	
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x+7*disx,p.y+h+5,p.z+1.5),Point(p.x+7*disx,p.y+h+5,p.z+0.5),Point(p.x+7*disx,p.y+h+4,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+0.5),Point(p.x,p.y+h+4,p.z),Point(p.x,p.y+h+5,p.z),Point(p.x+7*disx,p.y+h+5,p.z+0.5),0);
		primitiveDrawer.DrawQuad(Point(p.x+7*disx,p.y+h+4,p.z+1.5),Point(p.x,p.y+h+4,p.z+2),Point(p.x,p.y+h+5,p.z+2),Point(p.x+7*disx,p.y+h+5,p.z+1.5),0);
	}
	
	if(dir==1){
		glRotated(-90,0,1,0);
	}
	
}