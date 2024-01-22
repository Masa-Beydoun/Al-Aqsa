#pragma once


#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>	
#include "Color.h"
#include "Point.h"
#include "PrimitiveDrawer.h"

class AhmadiyyaSchool
{
public:
	AhmadiyyaSchool(void);
	~AhmadiyyaSchool(void);
	//void DrawConstruction(Point p1 , double high ,double length, double width,int image);
	void DrawDoor(Point v1, Point v2, Point v3, Point v4, int img);
	void DrawSphereAlhmadiyyaSchool(double r,int t);
	void DrawAlhmadiyyaSchool(int buildingimg,int doorimg, int n,int z, int c);
	void DrawQuad(Point v1, double l, double h, int img);
	void DrawQuad2(Point v1, Point v2, Point v3, Point v4, int img, int repetx,int repety);
	void DrawCube(Point s, double l, double w, double h, int img,int door1,int n, int z, int c);
	void DrawQuad2d(Point a, double l,double high,int img);
 
	
};

