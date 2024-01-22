#include "QibliMosque.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "PrimitiveDrawer.h";
#include "Colomn.h";

/////////////////////////////////////////////////////////////////////////////////////////////////
void QibliMosque::drawBase(int stoneWall, int rug, int qibliDome, int qibliWithWindow) {
	PrimitiveDrawer helper = PrimitiveDrawer();
	Colomn column = Colomn();
	//right (dome back)
	glPushMatrix();
		glTranslated(20,0,0);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),20,3,stoneWall,5,1.5);	
	glPopMatrix();
	// back 1
	glPushMatrix();
		glTranslated(0,0,-20);
		helper.DrawQuad2(Point(0,0,0),16,8,stoneWall,3,3);	
	glPopMatrix();
	// back 2
	glPushMatrix();
		glTranslated(16,0,-20);
		helper.DrawQuad2(Point(0,0,0),4,6,stoneWall,1,2);	
	glPopMatrix();
	//left (dome back)
	glPushMatrix();
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),10,8, stoneWall,4,4);	
	glPopMatrix();
	//left2 (dome back)
	glPushMatrix();
		glTranslated(0,0,-11.5);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),8.5,8, stoneWall,4,4);
	glPopMatrix();
	//left3 (dome back)
	glPushMatrix();
		glTranslated(0,2,-10);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),1.5,6, stoneWall,0.75,4);	
	glPopMatrix();
	//front1 (dome back)
	glPushMatrix();
		helper.DrawQuad2(Point(0,0,0),9,6,stoneWall,3,3);	
	glPopMatrix();
	//front2 (dome back)
	glPushMatrix();
		glTranslated(11,0,0);
		helper.DrawQuad2(Point(0,0,0),9,6,stoneWall,3,3);	
	glPopMatrix();
	//front3 (dome back)
	glPushMatrix();
		glTranslated(9,2.5,0);
		helper.DrawQuad2(Point(0,0,0),2,3.5,stoneWall,0.5,2);	
	glPopMatrix();
	//front4 (dome back)
	glPushMatrix();
		glTranslated(0,6,0);
		helper.DrawQuad2(Point(0,0,0),5,2,stoneWall,1,0.75);	
	glPopMatrix();
	//front5 (dome back)
	glPushMatrix();
		glTranslated(5,6,0);
		helper.DrawQuad2(Point(0,0,0),8,2.5,qibliWithWindow,1.7,1);	
	glPopMatrix();
	//ground
	glPushMatrix();
		//glTranslated(0,0,0);
		glRotated(-90,1,0,0);
		helper.DrawQuad2(Point(0,0,0),20,20,rug,10,20);	
	glPopMatrix();
	//ceiling
	glPushMatrix();
		glTranslated(0,8,-20);
		glRotated(90,1,0,0);
		helper.DrawQuad2(Point(0,0,0),16,20,stoneWall,5,5);	
	glPopMatrix();
	glPushMatrix();
		glTranslated(16,6,0);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),20,2,stoneWall,3,1);	
	glPopMatrix();
	glPushMatrix();
		glTranslated(16,6,-20);
		glRotated(90,1,0,0);
		helper.DrawQuad2(Point(0,0,0),4,20,stoneWall,1,3);	
	glPopMatrix();
	glPushMatrix();
		glTranslated(13,6,0);
		helper.DrawQuad2(Point(0,0,0),5,2,stoneWall,1,1);	
	glPopMatrix();
	glPushMatrix();
		//up back
		helper.DrawParallel(Point(5,8,-12.6),8,0.5,12.5,stoneWall, stoneWall);
		// dome
		helper.DrawUpperHalfBallWithTexture(Point(9,9,-16.5) , 4.25, qibliDome);
		// dome base
		helper.DrawOctagonal(Point(7.5,8,-20),2,1,stoneWall,stoneWall,stoneWall);
	glPopMatrix();
	glPushMatrix();
		column.make_n_colomns(Point(0,0,3),3,0.5,0.25,20,0.25,0.25,qibliDome);
		column.make_n_colomns(Point(14,0,3),3,0.5,0.25,20,0.25,0.25,qibliDome);
	glPopMatrix();
	glPushMatrix();
		column.make_n_colomns(Point(8.5,0,3),2,0.6,0.25,25,0.25,0.25,qibliDome);
	glPopMatrix();
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void QibliMosque::drawFrontSide(int stoneWall, int greenDoor) {
	PrimitiveDrawer helper = PrimitiveDrawer();
	glPushMatrix();
		for(double i = 0.5 ; i < 8 ; i+=3) {
			helper.DrawQuad2(Point(i,0,0.1),1.5,2,greenDoor,1,1);	
		}
		for(double i = 12 ; i < 20 ; i+=3) {
			helper.DrawQuad2(Point(i,0,0.1),1.5,2,greenDoor,1,1);	
		}
	glPopMatrix();
	// ceiling with lamps
	glPushMatrix();
		glRotated(90,1,0,0);
		glTranslated(0,0,-6);
		helper.DrawQuad2(Point(0,0,0),20,3,stoneWall,3,1);
		for(double i = 1.25 ; i < 8 ; i+=3) {
			glPushMatrix();
				glRotated(90,1,0,0);
				glTranslated(i,1,-2);
				helper.DrawCylinderVerically(Point(0,0,0), 0.1, 2);
				glTranslated(0,1,0);
				helper.DrawBall(Point(0,0,0), 0.3, 2,30);
			glPopMatrix();
		} 
		for(double i = 12.75 ; i < 20 ; i+=3) {
			glPushMatrix();
				glRotated(90,1,0,0);
				glTranslated(i,1,-2);
				helper.DrawCylinderVerically(Point(0,0,0), 0.1, 2);
				glTranslated(0,1,0);
				helper.DrawBall(Point(0,0,0), 0.3, 2,30);
			glPopMatrix();
		} 
	glPopMatrix();
	// sides
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslated(-3,0,0);
		helper.DrawQuad2(Point(0,0,0),3,6,stoneWall,1,3);
	glPopMatrix();
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslated(-3,0,20);
		helper.DrawQuad2(Point(0,0,0),3,6,stoneWall,1,3);
	glPopMatrix();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void QibliMosque::drawLeftSide(int stoneWall, int qibliWithWindow) {
	PrimitiveDrawer helper = PrimitiveDrawer();
	glPushMatrix();
		glTranslated(-7,0,-20);
		helper.DrawQuad2(Point(0,0,0),7,3,stoneWall,1,1);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-7,0,-16);
		helper.DrawQuad2(Point(0,0,0),7,3,stoneWall,1,1);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-7,0,-16);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),4,3,stoneWall,1,1);
	glPopMatrix();
	//Windows
	glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(-2,6,0);
		for(int i = 0 ; i <= 9 ; i++) {
			glTranslated(2,0,0);
			helper.DrawQuad2(Point(0,0,0),2,2,qibliWithWindow,1,1);
		}
		
	glPopMatrix();
	//Pillars
	glPushMatrix();
		glTranslated(-3,0,-12);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),1.5,7,stoneWall,0.5,4);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,0,-12);
		helper.DrawQuad2(Point(0,0,0),3,7,stoneWall,0.5,4);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,0,-14.5);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),1.5,7,stoneWall,0.5,4);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,0,-14.5);
		helper.DrawQuad2(Point(0,0,0),3,7,stoneWall,0.25,4);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,0,-13);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),1,4,stoneWall,0.5,2);
		helper.DrawQuad2(Point(0,0,0),2,4,stoneWall,1,2);
		helper.DrawQuad2(Point(0,4,0),2,2,qibliWithWindow,1,1);
	glPopMatrix();
	// Fence
	glPushMatrix();
		glTranslated(-3,0,0.75);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),10,1,stoneWall,10,0.5);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-2.7,0,0.75);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),10,1,stoneWall,10,0.5);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,0,0.75);
		helper.DrawQuad2(Point(0,0,0),0.3,1,stoneWall,0.3,0.5);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,0,-9.25);
		helper.DrawQuad2(Point(0,0,0),0.3,1,stoneWall,0.3,0.5);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,1,-9.25);
		glRotated(90,1,0,0);
		helper.DrawQuad2(Point(0,0,0),0.3,10,stoneWall,0.15,5);
	glPopMatrix();
	// lonely
	glPushMatrix();
		glTranslated(-3,0,-11.5);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),0.5,3,stoneWall,0.5,2);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-2.7,0,-11.5);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,0,0),0.5,3,stoneWall,0.5,2);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-3,0,-11.5);
		helper.DrawQuad2(Point(0,0,0),0.3,3,stoneWall,0.3,2);
	glPopMatrix();
	glPushMatrix();
		// Pillars in Fence 
		for(int i = 0 ; i < 7 ; i++) {
			glTranslated(0,0,1.5);
			drawLeftSidePillars(stoneWall);
		}
	glPopMatrix();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void QibliMosque::drawLeftSidePillars(int stoneWall) {
	PrimitiveDrawer helper = PrimitiveDrawer();
	glPushMatrix();
			glTranslated(-3,0,-10.2);
			helper.DrawQuad2(Point(0,0,0),0.3,3,stoneWall,0.15,2);
		glPopMatrix();
		glPushMatrix();
			glTranslated(-3,0,-10.5);
			helper.DrawQuad2(Point(0,0,0),0.3,3,stoneWall,0.15,2);
		glPopMatrix();
		glPushMatrix();
			glTranslated(-3,0,-10.2);
			glRotated(90,0,1,0);
			helper.DrawQuad2(Point(0,0,0),0.3,3,stoneWall,0.15,2);
		glPopMatrix();
		glPushMatrix();
			glTranslated(-2.7,0,-10.2);
			glRotated(90,0,1,0);
			helper.DrawQuad2(Point(0,0,0),0.3,3,stoneWall,0.15,2);
		glPopMatrix();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void QibliMosque::drawRightSide(int greenDoor, int stoneWall, int qibliWithWindow) {
	PrimitiveDrawer helper = PrimitiveDrawer();
	glPushMatrix();
		glTranslated(20,0,0);
		glRotated(90,0,1,0);
		for(int i = 2 ; i < 17 ; i+=7) {
			helper.DrawQuad2(Point(i,0,0.1),1.5,2,greenDoor,1,1);	
		}
	glPopMatrix();
	// bottom
	glPushMatrix();
		glTranslated(20,0,0);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,3,0),20,1,stoneWall,5,0.5);	
	glPopMatrix();
	// top
	glPushMatrix();
		glTranslated(20,0,0);
		glRotated(90,0,1,0);
		helper.DrawQuad2(Point(0,5,0),20,1,stoneWall,5,0.5);	
	glPopMatrix();
	// middle
	glPushMatrix();
		glTranslated(20,0,0);
		glRotated(90,0,1,0);
		for(int i = 0 ; i < 20 ; i+=3) {
			helper.DrawQuad2(Point(i,4,0),2,1,stoneWall,0.5,0.5);	
			if(i <= 17) {
				helper.DrawQuad2(Point(i+1,4,0),2,2,qibliWithWindow,0.7,1);	
			}
		}
	glPopMatrix();
}