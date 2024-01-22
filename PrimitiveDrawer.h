#ifndef PRIMITIVEDRAWER_H
#define PRIMITIVEDRAWER_H


#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Point.h"
class PrimitiveDrawer {
public:
	PrimitiveDrawer();
	void DrawPoint(Point point);
	void DrawLine(Point start, Point end);
	void DrawTriangle(Point v1, Point v2, Point v3);
	void DrawQuadMain(Point v1, Point v2, Point v3, Point v4);
	void DrawQuad2(Point v1, double l, double h, int image, double rx, double ry);
	//void DrawCube(Point center, float size);
	void DrawCircle(float cx, float cy, float r, int numSegments);
	void DrawHalfCircle(float cx, float cy, float cz, float r, int numSegments);
	void DrawFilledHalfCircle(float cx, float cy, float cz, float r, int numSegments);
	void DrawPalastineFlag(Point center, float lenght, float height, float rotationAngle);
	void DrawFilledCircle(Point center, float radius);
	void DrawBottomHalfCircle(float cx, float cy, float cz, float r, int numSegments) ;
	void DrawDashedLine(float x1, float y1, float z1, float x2, float y2, float z2, float dashLength, float lineWidth);
	void DrawWindow(float x, float y, float z, float width, float height, float circleRadius, int circleSegments);
	void DrawOctagonal(Point center, float side, float height,GLuint frontTexture , GLuint sideTexture, GLuint roofTexture);
	void DrawBall(Point center, float radius, int stacks, int slices);
	void DrawHalfBall(Point center, float radius);
	void DrawCircleWithHeight(Point center, float radius, float height);
	void DrawWindowWithZ(float x, float y, float z, float width, float height, float circleRadius, int circleSegments);
	void DrawFilledHalfCircleWithZ(float cx, float cy, float cz, float r, int numSegments);
	void DrawSkyBox(Point center, float side);
	void DrawParallel(Point center, float lenght , float width , float height , GLuint frontTexture, GLuint sidesTextures);
	void DrawCylinderHorizontally(Point center, float radius, float height);
	void DrawCylinderVerically(Point center, float radius, float height);
	void DrawCylinderWithTexture(Point center, float radius, float widthMultiplier, GLuint texture);
	void DrawUpperHalfBallWithTexture(Point center , float rad, GLuint texture);
	void Draw8(Point p,double l,double h,int ind);
	void DrawQuad(Point v1, Point v2, Point v3, Point v4,int index);
	void DrawCylinder(Point p,float radius, float height, int slices,int index);
	void DrawCylinder3(Point p,float r1,float r2, float height, int slices,int index);
	void DrawCube(Point p,double w,double h,double l,int index);
	void DrawSkyBoxSides(Point v1, Point v2, Point v3, Point v4,int index);


	void DrawWhat2(Point p,float r1,float r2,float slices,float height,int index);
	void DrawReq(Point p,double a,double b,int dir,int ind);
	void DrawCylinderWIthTwoTextures(Point p,float radius,float r2, float height, int slices,int index1,int index2);
	void DrawCylinder2(Point p,float r2,float r1, float height, int slices,int index);
	void DrawBall2(Point p,GLfloat radius,float h,int index);
	void DrawDoom(Point p,float r,float h,float decrease,int slices,int index);
	void DrawCell(Point p,float r,float slices,float height,int index);
	void DrawWhat(Point p,float r1,float r2,float slices,float height,int index);
	void DrawArch(Point p,float r1,float r2,float slices,float height,int index1,int index2);
	void DrawCubeCenter(Point s, double l, double w, double h, int index);
	void DrawCubeCenter2(Point s, double l, double w, double h, int texture[],double w2, double h2);
	void DrawCircle(Point p,float r);
	void DrawFlat(Point center, GLdouble w, GLdouble h, int texture);
	void DrawQuad3(Point v1, Point v2, Point v3, Point v4,int texture, double w, double h);
	void DrawCube2(Point start, GLdouble w, GLdouble h, GLdouble d,int texture[],double w2, double h2);
	void DrawCubeCenterimg(Point v1,double high, double length,double width, int img);



	 void PrimitiveDrawer::makeBaseWithColomn(Point p,float r,float h ,int slices,int index,int doomSelsleh2);
	 

};
extern PrimitiveDrawer primitiveDrawer;
#endif
