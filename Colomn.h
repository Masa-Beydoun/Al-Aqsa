#pragma once
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Point.h"
#include "PrimitiveDrawer.h"

class Colomn
{
public:
	Colomn(void);
	~Colomn(void);
	int Colomn::makeColomn(Point p,float r,float disx,float h,float hForBlock,float h2,bool start,bool end,int index,int index2=0);
	void Colomn::make_n_colomns(Point p,int n,float r,float disx,float h,float hForBlock,float h2,int index, float correction = 0);
	void makeArch(Point p,int h,bool dir,bool start,bool end); // num for place 
	void make_n_Arch(Point p,int n,int h,bool dir);
	void newColomn(Point p,float r,int height,int index1=0,int index2=10);
	int Colomn::makeColomn2(Point p,float r,float disx,float h,float hForBlock,float h2,bool start,bool end,int index,int index2,float correction=0,int index3=0);
	void Colomn::make_n_colomns2(Point p,int n,float r,float disx,float h,float hForBlock,float h2,int index,int index2,float correction,int index3=0);
	int Colomn::makeColomn3(Point p,float r,float disx,float h,float hForBlock,float h2,bool start,bool end,int index,int index2=0);
	void Colomn::make_n_colomns3(Point p,int n,float r,float disx,float h,float hForBlock,float h2,int index, float correction = 0);
	void make_n_colomns_for_dome(Point p,int n,int h,bool dir);
	void make_colomn_for_dome(Point p,int h,bool dir,bool start,bool end);
	

};

