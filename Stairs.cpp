#define _USE_MATH_DEFINES
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

#include "Stairs.h"
#include "Point.h"
#include "PrimitiveDrawer.h"

Stairs::Stairs(){}

Stairs::Stairs(int stairsNo, double stairsHeight, double stairsWidth, double stairsDepth){
	Stairs::stairsNo = stairsNo;
	Stairs::stairsHeight = stairsHeight;
	Stairs::stairsWidth = stairsWidth;
	Stairs::stairsDepth = stairsDepth;
}

void Stairs::draw(Point point, int stairsTex, int handrailTex){
	PrimitiveDrawer drawer = PrimitiveDrawer();
	for(int i = 0 ; i < stairsNo ; i++){
		drawer.DrawCubeCenter(
			Point(point.x,point.y + stairsHeight*i,point.z - i*stairsDepth),
			stairsWidth,
			stairsHeight,
			stairsDepth,
			stairsTex);
	}
	drawRightHandrail(point,0.5,1.5,handrailTex);
	drawLeftHandrail(point,0.5,1.5,handrailTex);
}

void Stairs::drawRightHandrail(Point point, double width, double height, int handrailTex){
	PrimitiveDrawer drawer = PrimitiveDrawer();
	double halfWidth = stairsWidth/2;
	double halfHeight = stairsHeight/2;
	double halfDepth = stairsDepth/2;
	Point A = Point(point.x + halfWidth, point.y-halfHeight, point.z + halfDepth);
	Point B = Point(point.x + halfWidth + width, point.y -halfHeight, point.z + halfDepth);
	Point C = Point(point.x + halfWidth + width,point.y + stairsNo * stairsHeight - stairsHeight, point.z  -(stairsNo * stairsDepth - stairsDepth));
	Point D = Point(point.x + halfWidth,point.y + stairsNo * stairsHeight - stairsHeight,point.z -(stairsNo * stairsDepth -stairsDepth));
	Point E = Point(point.x + halfWidth,point.y -halfHeight + height,point.z + halfDepth);
	Point F = Point(point.x + halfWidth + width,point.y -halfHeight + height,point.z + halfDepth);
	Point G = Point(point.x + halfWidth + width,point.y + (stairsNo * stairsHeight) - stairsHeight + height,point.z  -(stairsNo * stairsDepth - stairsDepth));
	Point H = Point(point.x + halfWidth,point.y + (stairsNo * stairsHeight) - stairsHeight + height,point.z -(stairsNo * stairsDepth - stairsDepth));
	drawer.DrawQuad3(C,D,G,H, handrailTex, 1, 1); // back face
	drawer.DrawQuad3(A,B,F,E, handrailTex,1, 1); // forward face
	drawer.DrawQuad3(A,B,C,D, handrailTex,1, 1); // down face
	drawer.DrawQuad3(E,F,G,H, handrailTex,1, 1); // up face
	drawer.DrawQuad3(B,C,G,F, handrailTex,1, 1); // right face
	drawer.DrawQuad3(D,A,E,H, handrailTex,1, 1); // left face
}


void Stairs::drawLeftHandrail(Point point,double width, double height, int handrailTex){
  glPushMatrix();
  PrimitiveDrawer drawer = PrimitiveDrawer();
  double halfWidth = stairsWidth/2;
  double halfHeight = stairsHeight/2;
  double halfDepth = stairsDepth/2;
  Point A = Point(point.x - halfWidth - width, point.y-halfHeight, point.z + halfDepth);
  Point B = Point(point.x - halfWidth, point.y -halfHeight, point.z + halfDepth);
  Point C = Point(point.x - halfWidth,point.y + stairsNo * stairsHeight - stairsHeight, point.z  -(stairsNo * stairsDepth - stairsDepth));
  Point D = Point(point.x - halfWidth - width,point.y + stairsNo * stairsHeight - stairsHeight,point.z -(stairsNo * stairsDepth -stairsDepth));
  Point E = Point(point.x - halfWidth - width ,point.y -halfHeight + height,point.z + halfDepth);
  Point F = Point(point.x - halfWidth ,point.y -halfHeight + height,point.z + halfDepth);
  Point G = Point(point.x - halfWidth,point.y + (stairsNo * stairsHeight) - stairsHeight + height,point.z  -(stairsNo * stairsDepth - stairsDepth));
  Point H = Point(point.x - halfWidth - width,point.y + (stairsNo * stairsHeight) - stairsHeight + height,point.z -(stairsNo * stairsDepth - stairsDepth));
  drawer.DrawQuad3(C,D,G,H, handrailTex, 1, 1); // back face
  drawer.DrawQuad3(A,B,F,E, handrailTex ,1, 1); // forward face
  drawer.DrawQuad3(A,B,C,D, handrailTex ,1, 1); // down face
  drawer.DrawQuad3(E,F,G,H, handrailTex ,1, 1); // up face
  drawer.DrawQuad3(B,C,G,F, handrailTex ,1, 1); // right face
  drawer.DrawQuad3(D,A,E,H, handrailTex ,1, 1); // left face

  glPopMatrix();
}




