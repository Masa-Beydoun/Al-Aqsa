#include "DomesofAlAqsa.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

#include "Point.h"
#include "Color.h"
#include "PrimitiveDrawer.h"
#define M_PI 3.14159265358979323846

DomesofAlAqsa::DomesofAlAqsa(void)
{
}


DomesofAlAqsa::~DomesofAlAqsa(void)
{
}


void DomesofAlAqsa::DrawDomeOfSouls(int domeofsoul1, int domesoule2, int domesoule3){
PrimitiveDrawer primitiveDrawer =PrimitiveDrawer();
Colomn colomn = Colomn();
//primitiveDrawer.Draw8(Point(0,0,0),2,0.2,domeofsoul1);
primitiveDrawer.DrawCylinder(Point(0,1.2,0),3,0.2,8,domeofsoul1);
glPushMatrix();
glTranslated(0,-1.1,0);
colomn.newColomn(Point(0,-0.3,-2.9),0.1,2,domesoule2,domesoule2);
colomn.newColomn(Point(0,-0.3,2.7),0.1,2,domesoule2,domesoule2);
colomn.newColomn(Point(2,-0.3,1.7),0.1,2,domesoule2,domesoule2);
colomn.newColomn(Point(2.7,-0.3,0.1),0.1,2,domesoule2,domesoule2);
colomn.newColomn(Point(-2.7,-0.3,0.1),0.1,2,domesoule2,domesoule2);
colomn.newColomn(Point(-2.1,-0.3,1.5),0.1,2,domesoule2,domesoule2);
colomn.newColomn(Point(-1.9,-0.3,-1.7),0.1,2,domesoule2,domesoule2);
colomn.newColomn(Point(1.9,-0.3,-1.7),0.1,2,domesoule2,domesoule2);
primitiveDrawer.DrawCylinder(Point(0,-0.2,0),2.7,0.05,8,domesoule2);
glPushMatrix();
glRotated(180,1,0,0);
glRotated(-22.6,0,1,0);
glScaled(0.8,0.9,0.8);
colomn.make_n_colomns(Point(-1.3,0.3,-3),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
////
glPushMatrix();
glRotated(180,1,0,0);
glRotated(22.6,0,1,0);
glScaled(0.8,0.9,0.8);
colomn.make_n_colomns(Point(-1.6,0.3,-3),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
/////
///colomn.make_n_colomns(Point(-2.7,0.3,-2.7),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPushMatrix();
glRotated(180,1,0,0);
glRotated(70.9,0,1,0);
glScaled(0.7,0.9,0.7);
colomn.make_n_colomns(Point(-1.5,0.3,-3.6),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
/////
glPushMatrix();
glRotated(180,1,0,0);
glRotated(-70.9,0,1,0);
glScaled(0.7,0.9,0.7);
colomn.make_n_colomns(Point(-1.5,0.3,-3.6),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
/////
glPushMatrix();
glRotated(180,1,0,0);
glRotated(-22.6,0,1,0);
glScaled(0.8,0.9,-0.8);
colomn.make_n_colomns(Point(-1.5,0.3,-2.9),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
////

glPushMatrix();
glRotated(180,1,0,0);
glRotated(70.9,0,1,0);
glScaled(0.7,0.9,0.7);
colomn.make_n_colomns(Point(-1.6,0.3,3.5),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
/////
glPushMatrix();
glRotated(180,1,0,0);
glRotated(-70.9,0,1,0);
glScaled(0.7,0.9,0.7);
colomn.make_n_colomns(Point(-1.3,0.3,3.5),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
/////
glPushMatrix();
glRotated(180,1,0,0);
glRotated(22.6,0,1,0);
glScaled(0.7,0.9,0.7);
colomn.make_n_colomns(Point(-1.3,0.3,3.5),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
glPopMatrix();
/////


glPopMatrix();
glPushMatrix();
glRotated(180,1,0,0);

primitiveDrawer.DrawDoom(Point(0,2.5,0),2.6,0.4,0.2,100,domesoule3);
glPopMatrix();




}

void DomesofAlAqsa::DrawDomeOfProphet(int death, int domesoule2, int domesoule3){
PrimitiveDrawer primitiveDrawer =PrimitiveDrawer();
Colomn colomn = Colomn();
glPushMatrix();
	glPushMatrix();
		primitiveDrawer.DrawCubeCenterimg(Point(0,1,0),0.7,2.6,0.7,death);
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,-1.1,0);
		colomn.newColomn(Point(0,-0.3,-2.9),0.1,2,domesoule2,domesoule2);
		colomn.newColomn(Point(0,-0.3,2.7),0.1,2,domesoule2,domesoule2);
		colomn.newColomn(Point(2,-0.3,1.7),0.1,2,domesoule2,domesoule2);
		colomn.newColomn(Point(2.7,-0.3,0.1),0.1,2,domesoule2,domesoule2);
		colomn.newColomn(Point(-2.7,-0.3,0.1),0.1,2,domesoule2,domesoule2);
		colomn.newColomn(Point(-2.1,-0.3,1.5),0.1,2,domesoule2,domesoule2);
		colomn.newColomn(Point(-1.9,-0.3,-1.7),0.1,2,domesoule2,domesoule2);
		colomn.newColomn(Point(1.9,-0.3,-1.7),0.1,2,domesoule2,domesoule2);
		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(-22.6,0,1,0);
			glScaled(0.8,0.9,0.8);
			colomn.make_n_colomns(Point(-1.3,0.3,-3),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		////
		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(22.6,0,1,0);
			glScaled(0.8,0.9,0.8);
			colomn.make_n_colomns(Point(-1.6,0.3,-3),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		/////
		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(70.9,0,1,0);
			glScaled(0.7,0.9,0.7);
			colomn.make_n_colomns(Point(-1.5,0.3,-3.6),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		/////
		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(-70.9,0,1,0);
			glScaled(0.7,0.9,0.7);
			colomn.make_n_colomns(Point(-1.5,0.3,-3.6),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		/////
		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(-22.6,0,1,0);
			glScaled(0.8,0.9,-0.8);
			colomn.make_n_colomns(Point(-1.5,0.3,-2.9),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		////

		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(70.9,0,1,0);
			glScaled(0.7,0.9,0.7);
			colomn.make_n_colomns(Point(-1.6,0.3,3.5),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		/////
		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(-70.9,0,1,0);
			glScaled(0.7,0.9,0.7);
			colomn.make_n_colomns3(Point(-1.3,0.3,3.5),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		/////
		glPushMatrix();
			glRotated(180,1,0,0);
			glRotated(22.6,0,1,0);
			glScaled(0.7,0.9,0.7);
			colomn.make_n_colomns(Point(-1.3,0.3,3.5),2,0.1,0.2,0.2,0.2,0.3,domesoule2);
		glPopMatrix();
		/////


	glPopMatrix();
		glPushMatrix();
		glRotated(180,1,0,0);

		primitiveDrawer.DrawDoom(Point(0,2.5,0),2.6,0.4,0.2,100,domesoule3);
		glPopMatrix();
glPopMatrix();
}




void DomesofAlAqsa::DrawDomeOfAlselsileh(int alselsleh1,int alselsleh2,int alselsleh3,int alselsleh4,int domesoule1,int doomTexture){
	PrimitiveDrawer prim=PrimitiveDrawer();

	float rOut=10,rIn=6,h=10,slicesOut=11,slicesIn=6;

	prim.makeBaseWithColomn(Point(0,0,0),rOut,h,slicesOut,domesoule1,alselsleh1);
	prim.DrawCylinder2(Point(0,h-3,0),rOut,rOut,0.3,11,doomTexture);
	prim.DrawCylinder2(Point(0,h,0),rOut,1,3,11,doomTexture);
	////////////////////////////////////////////////////////////
		float angleStep = (2.0f * M_PI) / slicesOut;

		float hh=3;
		prim.DrawCylinder2(Point(0,h,0),rIn,rIn,3,6,alselsleh3);
		prim.DrawCylinder2(Point(0,h,0),rOut+0.2,rOut,0.3,11,doomTexture);
		prim.DrawDoom(Point(0,h+hh,0),rIn,1,0.2,150,doomTexture);

		prim.DrawReq(Point(-rOut,0,-2),5,6,1,alselsleh2);
		prim.DrawCylinder(Point(-rOut-0.5,0,1),1,h/2.0-1,20,alselsleh4);
		prim.DrawDoom(Point(-rOut-0.5,h/2.0-1,1),1,0.4,0.4,20,alselsleh4);
}



