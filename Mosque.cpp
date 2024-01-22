#include "Colomn.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Point.h"
#include "PrimitiveDrawer.h"
#include "Mosque.h"
#include "texture.h"
#include "Stairs.h"
#include <iostream>

PrimitiveDrawer prim;
Colomn colomn;


Mosque::Mosque(void){  doorAngle=0; doorOpen=0; prim=PrimitiveDrawer(); colomn=Colomn();}
Mosque::~Mosque(void){doorAngle=0; doorOpen=0; prim=PrimitiveDrawer(); colomn=Colomn();}

/*
       5
   6       4
 7             3
    8      2
       1
*/






void Mosque::makeMosque(Point p,float t1,float t2,float doomHeight){
	makeOutsideWalls(p,t1,t2,doomHeight);
	makeFullCarpet(p,t1);
	top(Point(p.x,p.y+2*t2,p.z),5*t1,t1);
	makeEnterence(Point(p.x,p.y,p.z),5,t1,t2,0);
	makeEnterence(Point(p.x-7*t1+3,p.y,p.z-(7+7/2.0)*t1),5,t1,t2,1);
	makeEnterence(Point(p.x+4*t1,p.y,p.z-21*t1),5,t1,t2,2);
	makeEnterence(Point(p.x-7*t1+3,p.y,p.z-(7+7/2.0)*t1),5,t1,t2,3);
	insideRoof(Point(p.x,p.y+2*t2,p.z),t1);
	insideColomns(Point(p.x,p.y,p.z),t1,t2);
	makeRock(Point(p.x+7*t1/2.0+t1+2,p.y,p.z-7*t1-7*t1/2.0),t1);
	insideDoom(Point(p.x+7/2.0*t1,p.y,p.z-7*t1-7/2.0*t1),5*t1-0.5,t1,t2);
	makeLights(Point(p.x,p.y+2*t2,p.z),t1);
}



// 0 : x
// 1 : y
// 2 : z
//3 
void Mosque::makeLights(Point p,float t1){
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);

	float r=0.5,h=6,slices=10,hB=0.5,rB=2;

	Point p1=Point(-2*t1-1,-h,-7*t1-7/2.0*t1);
	prim.DrawCylinder(p1,r,h,slices,texture[55]);
	prim.DrawBall2(p1,rB,hB,texture[54]);
	light[0][0]= p1.x;
	light[0][1]= p1.y;
	light[0][2]=p1.z;



	p1=Point(7*t1 + 2*t1,-h,-7*t1-7/2.0*t1);
	prim.DrawCylinder(p1,r,h,slices,texture[55]);
	//prim.DrawBall2(p1,rB,hB,texture[54]);
	light[1][0]= p1.x;
	light[1][1]= p1.y;
	light[1][2]=p1.z;

	p1=Point(3.5*t1 ,-h,-4*t1);
	prim.DrawCylinder(p1,r,h,slices,texture[55]);
	//prim.DrawBall2(p1,rB,hB,texture[54]);
	light[2][0]= p1.x;
	light[2][1]= p1.y;
	light[2][2]=p1.z;

	p1=Point(3.5*t1,-h,-21*t1+4*t1);
	prim.DrawCylinder(p1,r,h,slices,texture[55]);
	//prim.DrawBall2(p1,rB,hB,texture[54]);
	glPopMatrix();
	light[3][0]= p1.x;
	light[3][1]= p1.y;
	light[3][2]=p1.z;

}

void Mosque::insideDoom(Point p,float r,float t1,float t2){
	float temp=3,dec=0,h=4,hBaseDoom=4,hDoom=2*t2;

	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	//delete comment
	
	float t=0;
	r-=0.5;
	glPushMatrix();
	glTranslated(0,hDoom,0);
	prim.DrawCylinder(Point(0,t,0),r,2,100,texture[21]); t+=2;
	prim.DrawCylinder(Point(0,t,0),r,1,100,texture[22]); t+=1;
	glPushMatrix();
	//glColor3ub(0,0,0);
	prim.DrawCylinder(Point(0,t,0),r,0.3,100,texture[35]); t+=0.3;
	glPopMatrix();
	float dee=0.5;
	float r1=r,r2=r-dee;
	prim.DrawCylinder3(Point(0,t,0),r1,r2,3,100,texture[23]); t+=3; 
	r1=r2; 
	r2-=dee;
	dee+=0.5;
	prim.DrawCylinder3(Point(0,t,0),r1,r2,0.3,100,texture[35]); t+=0.3;
	r1=r2; 
	r2-=dee;
	dee+=0.5;

	prim.DrawCylinder3(Point(0,t,0),r1,r2,1,100,texture[24]); t+=1;
	r1=r2; 
	r2-=dee;
	prim.DrawCylinderWIthTwoTextures(Point(0,t,0),r+0.5,r+0.5,6,16,texture[45],texture[45]);
	prim.DrawCylinder2(Point(0,t+4,0),r-0.5,r-0.5,1,16,texture[30]);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	prim.DrawCylinderWIthTwoTextures(Point(0,t,0),r1,r2,6,50,texture[25],texture[30]); t+=6;
	glDisable(GL_BLEND);
	r1=r2; 
	r2-=dee;
	dee+=0.5;
	prim.DrawDoom(Point(0,t,0),r+1,2,0.2,100,texture[14]);

	prim.DrawCylinder3(Point(0,t,0),r1,r2,2,100,texture[26]); t+=2;
	r1=r2; 
	r2-=dee;
		dee+=0.5;

	prim.DrawCylinder3(Point(0,t,0),r1,r2,4,60,texture[27]); t+=4;
	r1=r2; 
	r2-=dee;
		dee-=0.5;

	prim.DrawCylinder3(Point(0,t,0),r1,r2,4,100,texture[28]); t+=4;
	r1=r2; 
	r2-=dee;
		dee+=0.5;

	
		int slices=40,cnt=1;
		float dis=0;
		float hd=3;
		
		prim.DrawCylinder3(Point(0,t,0),r1,r2,hd,30,texture[29]);
		dis+=hd;
		r1=r2; 
		r2-=dee;
		while(cnt<3){
			prim.DrawCylinder3(Point(0,t+dis,0),r1,r2,hd,30,texture[29]);
			r1=r2; 
			r2-=dee;
			dis+=hd;
			cnt++;
		}
		hd=2;
		while(cnt<4){
			prim.DrawCylinder3(Point(0,t+dis,0),r1,r2,hd,15,texture[32]);
			r1=r2; 
			r2-=dee;
			dee+=0.6;
			dis+=hd;
			cnt++;
		}
		while(cnt<5){
			prim.DrawCylinder3(Point(0,t+dis,0),r1,r2,hd,slices,texture[33]);
			r1=r2; 
			r2-=dee;
			dis+=hd;
			cnt++;
		}
		while(cnt<6){
			prim.DrawCylinder3(Point(0,t+dis,0),r1,max(0,r2),hd,slices,texture[34]);
			r1=r2; 
			r2-=dee;
			dis+=hd;
			cnt++;
		}
		prim.DrawReq(Point(-0.5,t+dis-1,-0.5),1,1,2,texture[35]);

		prim.DrawCylinder3(Point(0,t+dis+6,0),0.4,0.4,10,5,texture[14]);

		prim.DrawBall2(Point(0,t+dis+6+2,0),1,0.4,texture[14]);
		prim.DrawBall2(Point(0,t+dis+6+5,0),1.5,0.4,texture[14]);
		prim.DrawBall2(Point(0,t+dis+6+8,0),1,0.4,texture[14]);
		glPushMatrix();
		glTranslated(0,t+dis+6+10+2.5,0);
		glRotated(90,1,0,0);
		prim.DrawCylinder3(Point(0,0,0),2.5,2.5,1,24,texture[14]);
		prim.DrawWhat2(Point(0,0,0),2.5,2,24,0.5,texture[14]);
		prim.DrawCylinder3(Point(0,0,0),2,2,1,24,texture[39]);
		glPopMatrix();

	prim.DrawCylinder(Point(0,-2,0),r,3,150,texture[0]); t+=2;
	//gold
	prim.DrawCylinder(Point(0,-6,0),r-1,1,100,texture[14]); t+=2;
	prim.DrawCylinder(Point(0,-6,0),r-0.5,1,100,texture[14]); t+=2;
	glPopMatrix();

	//
	
	float l=8;
	float wid=4;
	float newR=0.5;
	float rForArch=1.5;
	
	//under doom cololmn
	glPushMatrix();
	glTranslatef(r/2.0-wid+4,0,-r+wid+4);
	glRotated(40,0,1,0);
	prim.DrawCube(Point(0,0,0),wid,2*t2-2,l,texture[31]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-r/2.0-wid-5,0,r/2.0+wid-1);
	glRotated(50,0,1,0);
	prim.DrawCube(Point(0,0,0),wid,2*t2-2,l,texture[31]);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-r/2.0-1,0,-r+wid/2+2);
	glRotated(-50,0,1,0);
	prim.DrawCube(Point(0,0,0),wid,2*t2-2,l,texture[31]);
	glPopMatrix();

	float disX=0.8;
	glPushMatrix();
	glTranslated(r/2.0+wid,0,r/2.0);
	glRotated(-50,0,1,0);
	prim.DrawCube(Point(0,0,0),wid,2*t2-2,l,texture[31]);
	glRotated(110,0,1,0);
	colomn.make_n_colomns(Point(-1,0,1.5),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(disX*3+1,t2+2,2);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.5,20,rForArch,texture[0],texture[40]);
	glPopMatrix();



	glPopMatrix();
	//second 1
	glPushMatrix();
	glTranslated(r-2,0,6);
	glRotated(100,0,1,0);
		colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],4);
		glPushMatrix();
		glTranslated(3*disX+2,t2+2,0.8);
		glRotated(-90,1,0,0);
		glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
		glPopMatrix();
	glPopMatrix();
	//third 1
	glPushMatrix();
	glTranslated(r-4,0,-2);
	glRotated(100,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-20,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslated(-r+11,0,r-5);
	glRotated(-20,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//second 2
	glPushMatrix();
	glTranslated(-5,0,r-2);
	//glRotated(0,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//third 2
	glPushMatrix();
	glTranslated(4,0,r-2);
	glRotated(20,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslated(-r+13,0,-r+5);
	glRotated(20,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//second 3
	glPushMatrix();
	glTranslated(-3,0,-r+3);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//third 3
	glPushMatrix();
	glTranslated(5.5,0,-r+3);
	glRotated(-20,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//first 4
	glPushMatrix();
	glTranslated(-r+6,0,-r/2.0-1);
	glRotated(-110,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//second 4
	glPushMatrix();
	glTranslated(-r+3,0,-5);
	glRotated(-90,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();
	//third 4
	glPushMatrix();
	glTranslated(-r+6,0,r/2.0);
	glRotated(110,0,1,0);
	colomn.make_n_colomns3(Point(0,0,0),2,newR,disX,2*t2,0.7,1,texture[0],2.5);
	glPushMatrix();
	glTranslated(3*disX+2,t2+2,0.8);
	glRotated(-90,1,0,0);
	glRotated(-18,0,1,0);
	prim.DrawArch(Point(0,0,0),disX*3+2,disX*3+0.8,20,rForArch,texture[0],texture[40]);
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

}

void Mosque::makeRock(Point p,float t1){
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);

	float x=-4*t1-2,width=0.5,h=3;
	prim.DrawCube(Point(x,-0.4,-t1+2),6*t1-3,2,3*t1,texture[52]);
	prim.DrawCube(Point(x+5*t1,-0.4,-t1+2),2*t1-3,2,t1+4,texture[52]);
	prim.DrawCube(Point(x+4*t1,-0.4,-3*t1),2*t1-3,2,t1,texture[52]);
	prim.DrawCube(Point(x+3*t1,-0.4,-3*t1),2*t1-3,2,2*t1+2,texture[52]);
	glPushMatrix();
	glTranslated(-2*t1+3,0,-2*t1-5);
	glRotated(-60,0,1,0);
	prim.DrawCube(Point(0,0,0),2*t1-3,2,2*t1+6,texture[52]);
	glPopMatrix();
	//edit
	prim.DrawBall2(Point(-t1-4,0.5,-4),1,0.5,texture[0]);

	light[4][0]=-t1-4;
	light[4][1]=0.5;
	light[4][2]=-4;

	for(float i=0,cnt=0;cnt<12;i+=t1/2.0-0.2,cnt++){
		prim.DrawCube(Point(x+i,0,3*t1-3),t1/2.0,h,width,texture[15]);
	}
	prim.DrawCube(Point(t1,0,2*t1-5),width,h,t1+3,texture[51]);

	for(int i=-2*t1+3,cnt=0;cnt<4;cnt++,i+=t1){
		prim.DrawCube(Point(x,0,i),width,h,t1,texture[15]);
	}
	///////////////////////////////////////
	prim.DrawCube(Point(t1,0,t1),t1+2,h,width,texture[15]);
	prim.DrawCube(Point(2*t1+2,0,0),width,h,t1,texture[15]);
	glPopMatrix();
	////////////////////////////////////////////

	glPushMatrix();
	glTranslated(p.x+2*t1+1,p.y,p.z-3);
	glRotated(10,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,t1+1,texture[15]);
	glPopMatrix();

////////////////////////////////////////////////////
	//stairs	
	int sNo=5;
	int sH=0;
	int sW=7,cnt=0;
	glPushMatrix();
	glTranslated(p.x-10,p.y,p.z-t1-5);
	/*glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);*/
	prim.DrawCube(Point(10,0,1),0.3,h,t1+1,texture[18]);
	//glDisable(GL_BLEND);
	prim.DrawCube(Point(10,0,1),t1+1,h,0.2,texture[15]);
	prim.DrawCube(Point(10,0,1+1+t1),t1+1,h,0.2,texture[15]);

	while(sH<=10.3){
		if(sH==10) sH=10.3;
			prim.DrawCube(Point(cnt-12,-10.3,0),4,sH,sW,texture[53]);
		sH+=2;
		cnt+=4;
	}
	glPopMatrix();

////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(p.x+2*t1+2,p.y,p.z-t1+1);
	glRotated(90,0,1,0);
	colomn.make_n_colomns(Point(0,0,0),2,0.4,0.4,10,0.4,0.5,texture[54],1);
	glPopMatrix();

	////////////////////////////
	glPushMatrix();
	glTranslated(p.x+1,p.y,p.z-3*t1-1);
	glRotated(80,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,t1,texture[15]);
	glPopMatrix();


	glPushMatrix();
	glTranslated(p.x-t1-1,p.y,p.z-3*t1-1);
	glRotated(90,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,t1+2,texture[15]);
	glPopMatrix();


	glPushMatrix();
	glTranslated(p.x-2*t1-0.5,p.y,p.z-3*t1+0.5);
	glRotated(110,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,t1,texture[15]);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslated(p.x-3*t1+2,p.y,p.z-3*t1+2);
	glRotated(120,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,4,texture[15]);
	glPopMatrix();

	glPushMatrix();
	glTranslated(p.x-4*t1+1,p.y,p.z-2*t1+0.5);
	glRotated(-50,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,4,texture[15]);
	glPopMatrix();

	glPushMatrix();
	glTranslated(p.x-4*t1+4,p.y,p.z-2*t1-1);
	glRotated(120,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,t1,texture[15]);
	glPopMatrix();


	glPushMatrix();
	glTranslated(p.x-4*t1+1,p.y,p.z-2*t1+1);
	glRotated(130,0,1,0);
	prim.DrawCube(Point(0,0,0),width,h,4,texture[15]);
	glPopMatrix();

	glPushMatrix();
	glTranslated(p.x,p.y,p.z);

	Point p =Point(-30,-10.4,-30);
	float w=40,hh=10,l=30;
	prim.DrawQuad(Point(p.x+w,p.y,p.z),Point(p.x+w,p.y+hh,p.z),Point(p.x,p.y+hh,p.z),p,texture[52]);
	prim.DrawQuad(Point(p.x+w,p.y,p.z+l),Point(p.x+w,p.y+hh,p.z+l),Point(p.x+w,p.y+hh,p.z),Point(p.x+w,p.y,p.z),texture[52]);
	prim.DrawQuad(Point(p.x,p.y+hh,p.z),p,Point(p.x,p.y,p.z+l),Point(p.x,p.y+hh,p.z+l),texture[52]);
	prim.DrawQuad(Point(p.x+w,p.y,p.z+l),Point(p.x+w,p.y+hh,p.z+l),Point(p.x,p.y+hh,p.z+l),Point(p.x,p.y,p.z+l),texture[52]);
	//down
	prim.DrawQuad(Point(p.x+w,p.y,p.z),Point(p.x+w,p.y,p.z+l),Point(p.x,p.y,p.z+l),p,texture[52]);
	//top
	prim.DrawQuad(Point(p.x+10*t1,p.y+hh-0.4,p.z),Point(p.x+10*t1,p.y+hh-0.4,p.z+l/2.0+4),Point(p.x,p.y+hh-0.4,p.z+l/2+4),Point(p.x,p.y+hh-0.4,p.z),texture[52]);
	prim.DrawQuad(Point(p.x+4*t1,p.y+hh-0.4,p.z),Point(p.x+4*t1,p.y+hh-0.4,p.z+l),Point(p.x,p.y+hh-0.4,p.z+l),Point(p.x,p.y+hh-0.4,p.z),texture[52]);

	prim.DrawCube(Point(0,-10.4,-30),10,4,10,texture[0]);
	prim.DrawCube(Point(0,-6.4,-20),1,4,1,texture[0]);
	prim.DrawCube(Point(0,-6.4,-29),1,4,1,texture[0]);
	prim.DrawCube(Point(9,-6.4,-20),1,4,1,texture[0]);
	glPopMatrix();

	
}

void Mosque::insideColomns(Point p,float t1,float t2){
	float dis=2;
	float h=1;
	float hh=t2;
	float z1=-3*t1;

	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	//1 
	float beginXLeft=t1-2;
	Point p1=Point(beginXLeft,hh,z1);
	Point p2=Point(beginXLeft,hh+h,z1);
	Point p3=Point(beginXLeft,hh,z1+dis);
	Point p4=Point(beginXLeft,hh+h,z1+dis);
	prim.DrawQuad3(p1,p3,p4,p2,texture[1],39,10);

	float beginXRight=6*t1+2;
	Point p5=Point(beginXRight,hh,z1);
	Point p6=Point(beginXRight,hh+h,z1);
	Point p7=Point(beginXRight,hh,z1+dis);
	Point p8=Point(beginXRight,hh+h,z1+dis);

	prim.DrawQuad3(p7,p8,p6,p5,texture[39],1,1);
	prim.DrawQuad3(p2,p1,p5,p6,texture[39],1,1);
	prim.DrawQuad3(p7,p8,p4,p3,texture[39],1,1);
	prim.DrawQuad3(p4,p2,p6,p8,texture[39],1,1);
	prim.DrawQuad3(p3,p1,p5,p7,texture[39],1,1);
	float wid=4;

	prim.DrawCube(Point(p1.x-2,p1.y-hh,p1.z-1),wid,hh, dis+1,texture[38]);
	prim.DrawCube(Point(p1.x-2,p1.y-hh,p1.z-dis-1),dis,hh, wid,texture[38]);

	prim.DrawCube(Point(p5.x-dis-1,p5.y-hh,p5.z-1),wid,hh, dis+1,texture[38]);
	prim.DrawCube(Point(p5.x-0.2-1,p5.y-hh,p5.z-dis-1),dis,hh, wid,texture[38]);
		
	
	////5
	float leftX=-4*t1;
	float leftZBegin=-8*t1+2;
	float leftZEnd=-13*t1;
	//7
	//
	glPushMatrix();
	glTranslated(leftX-1,0,leftZBegin-dis-1);
	glRotated(40,0,1,0);
	prim.DrawCube(Point(0,0,0),wid,hh,dis+1,texture[38]);
	glPopMatrix();
	glPushMatrix();
	glTranslated(leftX-0.5,0,leftZBegin-1);
	glRotated(40,0,1,0);
	prim.DrawCube(Point(0,0,0),dis,hh,wid,texture[38]);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(leftX-2,0,leftZEnd-dis-1);
	glRotated(20,0,1,0);
	prim.DrawCube(Point(0,0,0),wid,hh,dis,texture[38]);
	glPopMatrix();
	glPushMatrix();
	glTranslated(leftX-1,0,leftZEnd-dis-1);
	glRotated(20,0,1,0);
	prim.DrawCube(Point(0,0,0),dis,hh,wid,texture[38]);
	glPopMatrix();
	//

	Point p9=Point(leftX,hh,leftZBegin);
	Point p10=Point(leftX+2,hh+h,leftZBegin);
	Point p11=Point(leftX,hh+h,leftZBegin);
	Point p12=Point(leftX+2,hh,leftZBegin);
	prim.DrawQuad(p10,p11,p9,p12,texture[39]);
	//sides
	prim.DrawQuad(p1,p2,p10,p12,texture[39]);
	prim.DrawQuad(p4,p3,p9,p11,texture[39]);
	//top and buttom
	prim.DrawQuad(p4,p2,p10,p11,texture[39]);
	prim.DrawQuad(p1,p12,p3,p9,texture[39]);
			

	Point p13=Point(leftX,hh,leftZEnd-dis);
	Point p14=Point(leftX+dis,hh,leftZEnd-dis);
	Point p15=Point(leftX,hh+h,leftZEnd-dis);
	Point p16=Point(leftX+dis,hh+h,leftZEnd-dis);
	prim.DrawQuad(p14,p13,p15,p16,texture[39]);
	//top and buttom
	prim.DrawQuad(p14,p13,p9,p12,texture[39]);
	prim.DrawQuad(p15,p16,p11,p10,texture[39]);
	//sides
	prim.DrawQuad(p15,p13,p9,p11,texture[39]);
	prim.DrawQuad(p14,p16,p10,p12,texture[39]);

	//13,14,    ,15,16
	float downZBegin=-21*t1+3*t1;
	//
	prim.DrawCube(Point(beginXRight-1,0,downZBegin-1),wid,hh,dis+1,texture[38]);
	prim.DrawCube(Point(beginXRight+dis-1,0,downZBegin+0.2-1),dis+1,hh,wid,texture[38]);
	//
	prim.DrawCube(Point(beginXLeft-1,0,downZBegin-1),wid,hh,dis+1,texture[38]);
	prim.DrawCube(Point(beginXLeft-dis,0,downZBegin+0.2-1),dis+1,hh,wid,texture[38]);
	//////////////////////////////////////////////////////////

	Point p17=Point(beginXLeft,hh,downZBegin);
	Point p18=Point(beginXLeft,hh+h,downZBegin);
	Point p19=Point(beginXLeft,hh,downZBegin+dis);
	Point p20=Point(beginXLeft,hh+h,downZBegin+dis);
	prim.DrawQuad(p18,p17,p19,p20,texture[39]);
	prim.DrawQuad(p19,p17,p13,p14,texture[39]);
	prim.DrawQuad(p18,p20,p16,p15,texture[39]);
	prim.DrawQuad(p18,p17,p13,p15,texture[39]);
	prim.DrawQuad(p19,p20,p16,p14,texture[39]);
		

	Point p21=Point(beginXRight+dis,hh,downZBegin);
	Point p22=Point(beginXRight+dis,hh+h,downZBegin);
	Point p23=Point(beginXRight+dis,hh,downZBegin+dis);
	Point p24=Point(beginXRight+dis,hh+h,downZBegin+dis);
	prim.DrawQuad(p22,p21,p23,p24,texture[39]);
	prim.DrawQuad(p24,p22,p18,p20,texture[39]);
	prim.DrawQuad(p21,p23,p19,p17,texture[39]);
	prim.DrawQuad(p24,p23,p19,p20,texture[39]);
	prim.DrawQuad(p22,p21,p17,p18,texture[39]);


		

	float rightX=10*t1;
	//
	glPushMatrix();
	glTranslated(rightX-1,0,leftZBegin-dis-2.5);
	glRotated(-40,0,1,0);
		prim.DrawCube(Point(0,0,0),wid,hh,dis,texture[38]);
	glPopMatrix();
	glPushMatrix();
	glTranslated(rightX+dis,0,leftZBegin-1);
	glRotated(-80,0,1,0);
		prim.DrawCube(Point(0,0,0),dis,hh,wid,texture[38]);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(rightX-3,0,leftZEnd-dis-2.5);
	glRotated(-20,0,1,0);
		prim.DrawCube(Point(0,0,0),wid,hh,dis,texture[38]);
	glPopMatrix();
	glPushMatrix();
	glTranslated(rightX+dis-2,0,leftZEnd-1);
	glRotated(-50,0,1,0);
		prim.DrawCube(Point(0,0,0),dis,hh,wid,texture[38]);
	glPopMatrix();
	//
	Point p25=Point(rightX,hh,leftZEnd-dis);
	Point p26=Point(rightX+dis,hh+h,leftZEnd-dis);
	Point p27=Point(rightX,hh+h,leftZEnd-dis);
	Point p28=Point(rightX+dis,hh,leftZEnd-dis);

	prim.DrawQuad(p26,p27,p25,p28,texture[39]);
	//sides
	prim.DrawQuad(p21,p22,p26,p28,texture[39]);
	prim.DrawQuad(p24,p23,p25,p27,texture[39]);
	//top and buttom
	prim.DrawQuad(p24,p22,p26,p27,texture[39]);
	prim.DrawQuad(p21,p28,p23,p25,texture[39]);


	Point p29=Point(rightX,hh,leftZBegin);
	Point p30=Point(rightX+dis,hh+h,leftZBegin);
	Point p31=Point(rightX,hh+h,leftZBegin);
	Point p32=Point(rightX+dis,hh,leftZBegin);
	prim.DrawQuad(p30,p31,p29,p32,texture[39]);
	//sides
	prim.DrawQuad(p5,p6,p30,p32,texture[39]);
	prim.DrawQuad(p8,p7,p29,p31,texture[39]);
	//top and buttom
	prim.DrawQuad(p8,p6,p30,p31,texture[39]);
	prim.DrawQuad(p5,p32,p7,p29,texture[39]);

	prim.DrawQuad(p29,p32,p28,p25,texture[39]);
	prim.DrawQuad(p30,p31,p27,p26,texture[39]);
	prim.DrawQuad(p29,p31,p27,p25,texture[39]);
	prim.DrawQuad(p30,p32,p28,p26,texture[39]);

	/////////////////////////////////////////////////////////////////////////////////////////
		float rC=0.5,disx=0.95,hhh=t2+4,hF=t2/8.0-0.2,h2=1;
		//1
		colomn.make_n_colomns2(Point(beginXLeft+1,0,z1+1),4,rC,disx,hhh,hF,h2,texture[0],texture[44],1.1);
		//5
		colomn.make_n_colomns2(Point(beginXLeft+1,0,downZBegin+1),4,rC,disx,hhh,hF,h2,texture[0],texture[44],1.5);
		//5 and 7
		for(float i=beginXLeft + disx*6,cnt=0; cnt<3 ;i+=disx*6+cnt+3,cnt++){
			glPushMatrix();
			glTranslated(i,hh+h,z1+1.5);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.3,3*disx-0.4,20,2,texture[44],texture[44]);
			glPopMatrix();

			glPushMatrix();
			glTranslated(i+0.4,hh+h,downZBegin+2);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.3,3*disx-0.4,20,2,texture[44],texture[44]);
			glPopMatrix();
		}
		//7
		glPushMatrix();
		glTranslated(leftX+1,0,leftZEnd-1);
		glRotated(-90,0,1,0);
			colomn.make_n_colomns2(Point(0,0,0),4,rC,disx,hhh,hF,h2,texture[0],texture[44],1);
		glPopMatrix();

		//3
		glPushMatrix();
		glTranslated(rightX+1,0,leftZEnd-1);
		glRotated(-90,0,1,0);
			colomn.make_n_colomns2(Point(0,0,0),4,rC,disx,hhh,hF,h2,texture[0],texture[44],1);
		glPopMatrix();

		// 7 and 3
		glPushMatrix();
		glTranslated(leftX,0,leftZBegin-1);
		glRotated(-90,0,1,0);
		for(float i=-(leftZBegin-leftZEnd)+disx*6-0.3,cnt=0; cnt<3 ;i+=disx*6+3,cnt++){
			glPushMatrix();
			glTranslated( i,hh+h,0);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.4,3*disx-0.4,20,2,texture[44],texture[44]);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslated(rightX,0,leftZBegin-1);
		glRotated(-90,0,1,0);
		for(float i=-(leftZBegin-leftZEnd)+disx*6-0.3,cnt=0; cnt<3 ;i+=disx*6+3,cnt++){
			glPushMatrix();
			glTranslated( i,hh+h,0);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.4,3*disx-0.4,20,2,texture[44],texture[44]);
			glPopMatrix();
		}
		glPopMatrix();
		
		//2
		glPushMatrix();
		glTranslated(beginXRight,0,z1);
		glRotated(53,0,1,0);
			colomn.make_n_colomns2(Point(0,0,0),4,rC,disx,hhh,hF,h2,texture[0],texture[44],2);
		glPopMatrix();

		glPushMatrix();
		glTranslated(rightX,0,leftZBegin);
		glRotated(53,0,1,0);
		for(float i=-(z1-leftZBegin)-disx,cnt=0; cnt<3 ;i+=disx*6+4,cnt++){
			glPushMatrix();
			glTranslated( i,hh+h,0);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.4,3*disx-0.4,20,2,texture[44],texture[44]);
			glPopMatrix();
		}
		glPopMatrix();


		//4
		glPushMatrix();
		glTranslated(beginXRight+1,0,downZBegin+1);
		glRotated(-53,0,1,0);
			colomn.make_n_colomns2(Point(0,0,0),4,rC,disx,hhh,hF,h2,texture[0],texture[44],1.5);
		glPopMatrix();
		glPushMatrix();
		glTranslated(beginXRight,0,downZBegin+1);
		glRotated(-53,0,1,0);
		for(float i=-(downZBegin-leftZEnd),cnt=0; cnt<3 ;i-=disx*6+4,cnt++){
			glPushMatrix();
			glTranslated( i,hh+h,0);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.4,3*disx-0.4,20,2,texture[44],texture[44]);
			glPopMatrix();
		}
		glPopMatrix();


		//6
		glPushMatrix();
		glTranslated(leftX,0,leftZEnd-1);
		glRotated(45,0,1,0);
			colomn.make_n_colomns2(Point(0,0,0),4,rC,disx+0.25,hhh,hF,h2,texture[0],texture[44],2.6);
		glPopMatrix();
		glPushMatrix();
		glTranslated(beginXLeft+1,0,downZBegin+1);
		glRotated(45,0,1,0);
		for(float i=(downZBegin-leftZEnd)-2*disx-0.4,cnt=0; cnt<3 ;i+=disx*6+4.3,cnt++){
			glPushMatrix();
			glTranslated( i,hh+h,0);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.7,3*disx,20,2,texture[44],texture[44]);
			glPopMatrix();
		}
		glPopMatrix();

		//8
		glPushMatrix();
		glTranslated(leftX+1,0,leftZBegin);
		glRotated(-47,0,1,0);
			colomn.make_n_colomns2(Point(0,0,0),4,rC,disx,hhh,hF,h2,texture[0],texture[44],2.7);
		glPopMatrix();
		glPushMatrix();
		glTranslated(leftX+1,0,leftZBegin+1);
		glRotated(-47,0,1,0);
		for(float i=-(downZBegin-leftZEnd)+disx,cnt=0; cnt<3 ;i-=disx*6+4.6,cnt++){
			glPushMatrix();
			glTranslated( i,hh+h,0);
			glRotated(-90,1,0,0);
			glRotated(-18,0,1,0);
			prim.DrawArch(Point(0,0,0),3*disx+1.7,3*disx,20,2,texture[44],texture[44]);
			glPopMatrix();
		}
		glPopMatrix();



	glPopMatrix();

}

void Mosque::insideRoof(Point p,int t1){

	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	
	for(int i=0;i<7;i++){
		prim.DrawReq(Point(i*t1,-1,-0.2),t1,1,0,texture[39]);
		prim.DrawReq(Point(i*t1,-1,-21*t1+0.2),t1,1,0,texture[39]);
		prim.DrawReq(Point(-7*t1+0.2,-1,-8*t1-i*t1),t1,1,1,texture[39]);
		prim.DrawReq(Point(14*t1-0.2,-1,-8*t1-i*t1),t1,1,1,texture[39]);
		for(int j=0;j<5;j++){
			if(j<4){
				prim.DrawReq(Point(i*t1,0,-j*t1-t1),t1,t1,2,texture[41]);
				prim.DrawReq(Point(i*t1,0,-21*t1+j*t1),t1,t1,2,texture[41]);
			}
			

			prim.DrawReq(Point(-7*t1+j*t1,0,-8*t1-i*t1),t1,t1,2,texture[41]);
			prim.DrawReq(Point(13*t1-j*t1,0,-8*t1-i*t1),t1,t1,2,texture[41]);
			
		}
	}
	////////////////////////////////
	glPushMatrix();
	glTranslated(7*t1,0,0);
	glRotated(45,0,1,0);
	for(int i=0;i<10;i++){
		prim.DrawReq(Point(t1*i,-1,-0.2),t1,1,0,texture[39]);
		prim.DrawReq(Point(t1*i,-1,-20*t1+1),t1,1,0,texture[39]);
		for(int j=0;j<4;j++){
			float newT1=t1+1;
			prim.DrawReq(Point(i*t1,0,-j*t1-t1),t1,t1,2,texture[41]);
			prim.DrawReq(Point(i*t1,0,+j*t1-20*t1+1),t1,t1,2,texture[41]);
		}
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,0);
	glRotated(135,0,1,0);
	for(int i=0;i<10;i++){
		prim.DrawReq(Point(t1*i,-1,+0.2),t1,1,0,texture[39]);
		prim.DrawReq(Point(t1*i,-1,19*t1),t1,1,0,texture[39]);
		for(int j=0;j<5;j++){
			float newT1=t1+1;
			prim.DrawReq(Point(i*t1,0,+j*t1),t1,t1,2,texture[41]);
			prim.DrawReq(Point(i*t1,0,-j*t1+19*t1-1),t1,t1,2,texture[41]);
		}
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(7/2.0*t1,0,-7*t1-7/2.0*t1);
	prim.DrawWhat2(Point(0,-30,0),24.2,33,30,texture[0],texture[41]);
	glPopMatrix();


	glPopMatrix();

}



void Mosque::makeEnterence(Point p,int l,int t1,int t2,int num){
	float r=0.3;
	glPushMatrix();
	glTranslated(p.x-0.1,p.y,p.z);
	if(num==0){
		
		for(int i=0;i<5;i++)
			prim.DrawCube(Point(t1-1+i*(l+0.5),0,0),l+0.5,0.2,l+1,texture[19]);
		glPushMatrix();
		glTranslated(t1,t2,0);
		prim.DrawCube(Point(0,0,0),2*t1-1,1,l,texture[10]);
		prim.DrawCube(Point(3*t1+1,0,0),2*t1-1,1,l,texture[10]);
		prim.DrawCube(Point(2*t1-1,0,0),1,1,l+1,texture[0]);
		prim.DrawCube(Point(3*t1,0,0),1,1,l+1,texture[0]);
		glPopMatrix();

		
		glPushMatrix();
		glTranslated(t1,0,l-2*r+0.3);
		colomn.newColomn(Point(2*r,0,0),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(9*r,0,0),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(2*t1-7*r,0,0),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(2*t1-2*r,0,0.5),r,t2-0.5,texture[0],texture[10]);
		glPopMatrix();

		glPushMatrix();
		glTranslated(4*t1+1,0,l-2*r+0.3);
		colomn.newColomn(Point(-2*r,0,0.5),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(6*r,0,0),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(2*t1-5*r,0,0),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(2*t1-10*r,0,0),r,t2-0.5,texture[0],texture[10]);
		glPopMatrix();


		glPushMatrix();
		glTranslated(3*t1,0,0);
		prim.DrawReq(Point(0,2*t2/(3.0),0),t1,t2/(3.0),0,texture[11]);
		prim.DrawReq(Point(0,2*t2/(3.0),0),t1,t2/(3.0),0,texture[11]);
		glPopMatrix();

		glPushMatrix();
		glTranslated(3*t1,0,0);
		movementOfTheDoor(t1,t2,1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(4*t1,0,0);
		glRotated(180,0,1,0);
		movementOfTheDoor(t1,t2,0);
		glPopMatrix();


		glPushMatrix();
		glTranslated(3*t1+t1/2.0,t2+1,l+1);
		glRotated(-90,1,0,0);
		glRotated(-18,0,1,0);
		prim.DrawArch(Point(0,0,0),t1/2.0,t1/2.0+1,20,l+1,texture[16],texture[17]);
		glPopMatrix();
		
	}
	else if(num==1){
		
		float beg=-2*l+0.5;
		float dep=l/5.0+0.3;
		float wid=3;
		prim.DrawCube(Point(beg-1,0,-t1+1),2*wid+2,0.2,t1+3,19);
		for(int i=0;i<5;i++){
			prim.DrawCube(Point(beg+i*dep+0.2,t2,-wid-0.6),dep,1.4,1.3,texture[18]);
			prim.DrawCube(Point(beg+i*dep+0.2,t2,wid-0.6),dep,1.4,1.3,texture[18]);
		}

		colomn.newColomn(Point(beg+0.7,0,-wid),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(beg+0.7,0,wid),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(beg+l+1,0,wid),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(beg+l+1,0,-wid),r,t2-0.5,texture[0],texture[10]);
		

		glPushMatrix();
		glTranslated(beg+l+1,t2+1,0);
		glRotated(90,0,1,0);
		glRotated(-90,1,0,0);
		glRotated(-18,0,1,0);
		prim.DrawArch(Point(0,0,0),t1/2.0,t1/2.0+0.5,20,l+0.6,texture[16],texture[17]);
		glPopMatrix();

		float disTop=0.5;
		float disWid=0.5;
		prim.DrawCube(Point(-t1/2.0-0.5,0,-0.5),0.5,t2-disTop,wid-disWid,texture[20]);
		glPushMatrix();
		glTranslated(-t1/2.0,0,0);
		glRotated(180,0,1,0);
		prim.DrawCube(Point(0,0,0),0.5,t2-disTop,wid-disWid,texture[20]);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-t1/2.0-0.5,0,0);
		prim.DrawCube(Point(0,0,wid-1),0.2,t2,0.5,texture[0]);
		prim.DrawCube(Point(0,0,wid-1-t1),0.2,t2,0.5,texture[0]);
		prim.DrawCube(Point(0,t2-0.5,wid-1-t1),0.2,disTop,t1,texture[0]);
		glPopMatrix();

	}
	else if(num==2){
		
		float beg=-t1-1;
		float dep=l/5.0+0.3;
		float wid=3;
		prim.DrawCube(Point(beg,0,-2*wid-2),t1+3,0.2,2*wid+2,texture[19]);
		for(int i=0;i<5;i++){
			prim.DrawCube(Point(beg+0.2,t2,-i*dep-2),dep,1.4,1.3,texture[18]);
			prim.DrawCube(Point(beg+2*wid+0.2,t2,-i*dep-2),dep,1.4,1.3,texture[18]);
		}

		colomn.newColomn(Point(beg+1,0,-dep),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(beg+1,0,-5*dep),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(beg+2*wid+1,0,-dep),r,t2-0.5,texture[0],texture[10]);
		colomn.newColomn(Point(beg+2*wid+1,0,-5*dep),r,t2-0.5,texture[0],texture[10]);
		

		glPushMatrix();
		glTranslated(-t1/2.0+0.4,t2+1,-1);
		glRotated(-90,1,0,0);
		glRotated(-18,0,1,0);
		prim.DrawArch(Point(0,0,0),t1/2.0,t1/2.0+0.5,20,l+0.6,texture[16],texture[17]);
		glPopMatrix();

		
		prim.DrawCube(Point(0,0,0),0.5,t2,0.2,texture[0]);
		prim.DrawCube(Point(-t1,0,0),0.5,t2,0.2,texture[0]);
		prim.DrawCube(Point(-t1,t2-0.5,0),t1,0.5,0.2,texture[0]);

		prim.DrawCube(Point(-t1/2.0,0,0),t1/2.0,t2-0.5,0.2,texture[20]);

		glPushMatrix();
		glTranslated(-t1,0,0);
		glRotated(180,0,1,0);
		prim.DrawCube(Point(-t1/2.0,0,0),t1/2.0,t2-0.5,0.2,texture[20]);
		glPopMatrix();

	}
	else {
		glPushMatrix();
		glTranslated(21*t1+6,0,0);
		glRotated(180,0,1,0);
		glTranslated(2*t1+2,0,0);
		makeEnterence(Point(0,0,0),l,t1,t2,1);
		glPopMatrix();
	}
	
	glPopMatrix();
}





void Mosque::movementOfTheDoor(double width,double height,int dir){
	PrimitiveDrawer prim=PrimitiveDrawer();
	if(doorOpen==1 && doorAngle<=90){
		doorAngle+=0.4;
	}
	
	glPushMatrix();
	if(dir==1) glRotated(doorAngle,0,1,0);
	else glRotated(-doorAngle,0,1,0);
	prim.DrawReq(Point(0,0,0),width/2.0,2*height/(3.0),0,texture[12]);
	glPopMatrix();
}




void Mosque::makeOutsideWalls(Point p,int t1,int t2,int doomHeight){
	int cnt=0;

	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	for(int i=0;i<=6;i++){
		glPushMatrix();
		glTranslated(i*t1,0,0);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),t1,t2,0,texture[42]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*t1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),t1,doomHeight,0,texture[6]);
		glPopMatrix();

		glPushMatrix();
		glTranslated(i*t1,0,-21*t1);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),t1,t2,0,texture[42]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*t1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),t1,doomHeight,0,texture[6]);
		glPopMatrix();
	}
	int temx=0,endx=7*t1;
	
	glPushMatrix();
	glTranslated(7*t1,0,0);
	glRotated(45,0,1,0);
	float newT1=t1+2.1;
	for(int i=0;i<=6;i++){
		glPushMatrix();
		glTranslated(i*newT1,0,0);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*newT1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[42]);
		if(i==3) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[43]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*newT1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),newT1,doomHeight,0,texture[6]);
		glPopMatrix();
	}
	glPopMatrix();
	///////////////////////////////
	glPushMatrix();
	glTranslated(0,0,0);
	glRotated(135,0,1,0);
	for(int i=0;i<=6;i++){
		glPushMatrix();
		glTranslated(i*newT1,0,0);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*newT1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[42]);
		if(i==3) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[43]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*newT1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),newT1,doomHeight,0,texture[6]);
		glPopMatrix();
	}
	glPopMatrix();

	//////////////////////////////////////////////////////
	glPushMatrix();
	glTranslated(14*t1,0,-7*t1);
	glRotated(90,0,1,0);
	for(int i=0;i<=6;i++){
		glPushMatrix();
		glTranslated(i*t1,0,0);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),t1,t2,0,texture[42]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*t1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),t1,doomHeight,0,texture[6]);
		glPopMatrix();
	}
	glPopMatrix();
	///////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslated(-7*t1,0,-7*t1);
	glRotated(90,0,1,0);
	for(int i=0;i<=6;i++){
		glPushMatrix();
		glTranslated(i*t1,0,0);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*t1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),t1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),t1,t2,0,texture[42]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*t1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),t1,doomHeight,0,texture[6]);
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix();
	glTranslated(7*t1,0,-21*t1);
	glRotated(-45,0,1,0);
	for(int i=0;i<=6;i++){
		glPushMatrix();
		glTranslated(i*newT1,0,0);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*newT1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[42]);
		if(i==3) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[43]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*newT1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),newT1,doomHeight,0,texture[6]);
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix();
	glTranslated(0,0,-21*t1);
	glRotated(-135,0,1,0);
	for(int i=0;i<=6;i++){
		glPushMatrix();
		glTranslated(i*newT1,0,0);
		if(i == 0  || i == 5)prim.DrawReq(Point(0,t2,0),2*newT1,t2,0,texture[48]);
		if(i==3) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[49]);
		if(i==2) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[47]);
		if(i==4) prim.DrawReq(Point(0,t2,0),newT1,t2,0,texture[50]);
		if(i==0 || i==4) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[42]);
		if(i==3) prim.DrawReq(Point(0,0,0),newT1,t2,0,texture[43]);
		if(i==1 || i==5) prim.DrawReq(Point(0,0,0),2*newT1,t2,0,texture[5]);
		prim.DrawReq(Point(0,2*t2,0),newT1,doomHeight,0,texture[6]);
		glPopMatrix();
		
	}
	
	glPopMatrix();

	glPopMatrix();
	

}





void Mosque::makeInsideWalls(Point p,int width,int height){
	PrimitiveDrawer prim = PrimitiveDrawer();
	glPushMatrix();

	glTranslated(p.x,p.y,p.z);
	double temp=width/7;
	glColor3ub(10,10,10);
	prim.DrawReq(Point(0.2,0,-1),temp*3,height,0,-1);
	prim.DrawReq(Point(temp*4+0.2,0,-1),temp*3-0.2,height,0,-1);
	prim.DrawReq(Point(0.2,0,-3*width+1),width-0.2,height,0,-1);
	
	prim.DrawQuad(Point(width-0.2,0,-0.6),Point(width-0.2,height,-0.6),Point(2*width-0.2,height,-width-0.6),Point(2*width-0.2,0,-width-0.6),-1);
	prim.DrawQuad(Point(0.2,0,-0.6),Point(0.2,height,-0.6),Point(-width+0.2,height,-width-0.6),Point(-width+0.2,0,-width-0.6),-1);
	
	prim.DrawReq(Point(-width+1,0,-2*width),width/2.0-2.6,height,1,-1);
	prim.DrawReq(Point(-width+1,0,-2*width+4*temp),width/2.0-2.6,height,1,-1);


	prim.DrawReq(Point(2*width-1,0,-2*width),width,height,1,-1);

	prim.DrawQuad(Point(-width,0,-2*width+0.6),Point(-width,height,-2*width+0.6),Point(0.2,height,-3*width+0.6),Point(0.2,0,-3*width+0.6),-1);
	prim.DrawQuad(Point(width,0,-3*width+0.6),Point(width,height,-3*width+0.6),Point(2*width,height,-2*width+0.6),Point(2*width,0,-2*width+0.6),-1);
	glPopMatrix();
}
	

void Mosque::makeFullCarpet(Point p,int t1){
	int beg=0;
	for(int i=-7*t1;i<14*t1;i++){
		if(i>=0 && i<7*t1){
				carpet(Point(p.x,p.y,p.z),7*t1,11*t1-1);
				carpet(Point(p.x,p.y,p.z-13*t1),8*t1,8*t1-1);
				carpet(Point(p.x,p.y,p.z),2*t1,21*t1-1);
				i=7*t1-1;
				beg-=2;
		}
		else if(i>=7*t1){
			carpet(Point(p.x+i,p.y,p.z-7*t1+beg/2 - (i%2==0)),1,7*t1+beg);
			beg-=2.0;
		}
		else{
			carpet(Point(p.x+i,p.y,p.z-7*t1+beg/2.0 - (i%2!=0)),1,7*t1+beg);
			beg+=2;
		}
	}
}


void Mosque::carpet(Point p,float width,float hight){
	PrimitiveDrawer prim=PrimitiveDrawer();
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	for(int i=0;i< width;i++){
		for (int j = 0; j < hight; j+=2)
		{
			prim.DrawQuad(Point(i,0,-j),Point(i,0,-j-2),Point(i+1,0,-j-2),Point(i+1,0,-j),texture[4]);
		}
	}
	glPopMatrix();
}

void Mosque::top(Point p,float r,int t1){
	
	float temp=8,dec=0,h=4;
	
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	

	Point p1=Point(0,0,0);
	Point p2=Point(7*t1,0,0);
	Point p3=Point(6*t1,temp,-6*t1);	
	Point p4=Point(1*t1,temp,-6*t1);
	prim.DrawQuad(p2,p3,p4,p1,texture[8]);


	Point p5=Point(-4,temp,-9*t1);
	Point p6=Point(-7*t1,0,-7*t1);
	Point p7=Point(-7*t1,0,-14*t1);
	Point p8=Point(-4,temp,-12*t1);
	prim.DrawQuad(p7,p8,p5,p6,texture[8]);

	prim.DrawQuad(p1,p4,p5,p6,texture[8]);
	
	Point p9=Point(0,0,-21*t1);
	Point p10=Point(7*t1,0,-21*t1);
	Point p11=Point(6*t1,temp,-15*t1);
	Point p12=Point(1*t1,temp,-15*t1);
	prim.DrawQuad(p9,p10,p11,p12,texture[8]);
	prim.DrawQuad(p7,p8,p12,p9,texture[8]);

	Point p13=Point(14*t1,0,-14*t1);
	Point p14=Point(8*t1,temp,-12*t1);
	Point p15=Point(14*t1,0,-7*t1);
	Point p16=Point(8*t1,temp,-9*t1);
	prim.DrawQuad(p13,p14,p16,p15,texture[8]);

	prim.DrawQuad(p13,p14,p11,p10,texture[8]);
	prim.DrawQuad(p2,p3,p16,p15,texture[8]);

	glPopMatrix();


}


void Mosque::setTex(int t[]){
	for(int i=0;i<60;i++){
		texture[i]=t[i];
	}
}