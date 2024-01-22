#include "IslamicMusuem.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "PrimitiveDrawer.h"
#include "Stairs.h"
#include "Colomn.h"

IslamicMusuem::IslamicMusuem(void)
{
}


IslamicMusuem::~IslamicMusuem(void)
{
}

////////////////////////////////////////////////////////////////////////
void IslamicMusuem::drawBase(int stoneWall){
	PrimitiveDrawer helper = PrimitiveDrawer();
	//Front Side
	glPushMatrix();
		helper.DrawQuad2(Point(0,0,0), 30, 5, stoneWall, 10, 2.5);
		glTranslated(0,0,-15);
		helper.DrawQuad2(Point(0,0,0), 30, 5, stoneWall, 10, 2.5);
	glPopMatrix();
	glPushMatrix();
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0), 15, 5, stoneWall, 7.5, 2.5);
		glTranslated(0,0,30);
		helper.DrawQuad2(Point(0,0,0), 15, 5, stoneWall, 7.5, 2.5);
	glPopMatrix();
	glPushMatrix();
		glRotated(90,1,0,0);
		glTranslated(0,-15,0);
		helper.DrawQuad2(Point(0,0,-5), 30, 15, stoneWall, 15, 7.5);
	glPopMatrix();
}
////////////////////////////////////////////////////////////////////////
void IslamicMusuem::drawDome(int domeTexture){
	PrimitiveDrawer helper = PrimitiveDrawer();
	glPushMatrix();
		helper.DrawUpperHalfBallWithTexture(Point(15,5,-7.5) , 4.25, domeTexture);
	glPopMatrix();
}
////////////////////////////////////////////////////////////////////////
void IslamicMusuem::drawDecorations(int door, int window, int label){
	PrimitiveDrawer helper = PrimitiveDrawer();
		helper.DrawQuad2(Point(13,0,0.01),2,3.5,door,1,1);
		helper.DrawQuad2(Point(15,0,0.01),2,3.5,door,1,1);
		helper.DrawQuad2(Point(18,2,0.01),3,1,label,1,1);
}
////////////////////////////////////////////////////////////////////////
void IslamicMusuem::drawManara(int stoneWall, int window, int door, int stairsTex, int handrailTex) {
	PrimitiveDrawer helper = PrimitiveDrawer();
	Stairs stairs = Stairs(10,0.5,4,0.5);
	glPushMatrix();
	glTranslated(0,0,10);
	glRotated(90,0,1,0);
	stairs.draw(Point(0,0,0),stairsTex,handrailTex);
	glPopMatrix();
	Colomn column = Colomn();
	glPushMatrix();
		helper.DrawQuad2(Point(-5,0,5),5,20,stoneWall,1,10);
		helper.DrawQuad2(Point(-5,0,0),5,20,stoneWall,1,10);
	glPopMatrix();
	glPushMatrix();
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(-5,0,-5),5,20,stoneWall,1,10);
		helper.DrawQuad2(Point(-5,0,0),5,20,stoneWall,1,10);
		helper.DrawQuad2(Point(-5,10,0),2,2,window,1,1);
		helper.DrawQuad2(Point(-2,10,0),2,2,window,1,1);
		helper.DrawQuad2(Point(-3,5,0),1.5,3,door,1,1);
	glPopMatrix();
	glPushMatrix();
		glRotated(90,1,0,0);
		helper.DrawQuad2(Point(-5.5,-0.5,-20),6,6,stoneWall,1,3);
	glPopMatrix();
	glPushMatrix();
		helper.DrawCubeCenter(Point(-2.5,20,2.5),5,5,1,stoneWall);
	glPopMatrix();
	glPushMatrix();
		column.make_n_colomns(Point(-5,20,5),2,0.2,0.5,1,0.5,1,stoneWall);
		column.make_n_colomns(Point(-5,20,0),2,0.2,0.5,1,0.5,1,stoneWall);
	glPopMatrix();
	glPushMatrix();
		glRotated(90,0,1,0);
		column.make_n_colomns(Point(-5,20,-5),2,0.2,0.5,1,0.5,1,stoneWall);
		column.make_n_colomns(Point(-5,20,0),2,0.2,0.5,1,0.5,1,stoneWall);
	glPopMatrix();
}