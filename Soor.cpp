#include "soor.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Point.h"
#include "Color.h"
#include "PrimitiveSoor.h"
#include "Colomn.h"

  Soor::Soor(){}
  PrimitiveSoor helper = PrimitiveSoor();
  Colomn colomn_helper = Colomn();

  //soor lenghth = 89num-14

  void Soor::Wall1( int x1, int h1, int z1, int index)
	{
	  Color(0,0,0);
	  helper.DrawQuad(Point(x1,0,z1),Point(x1+2,0,z1),Point(x1+2,h1,z1),Point(x1,h1,z1),index); //front
	  helper.DrawQuad(Point(x1,0,z1+1),Point(x1+2,0,z1+1),Point(x1+2,h1,z1+1),Point(x1,h1,z1+1),index); //back
	  helper.DrawQuad(Point(x1+2,0,z1),Point(x1+2,0,z1+1),Point(x1+2,h1,z1+1),Point(x1+2,h1,z1),index); //right
	  helper.DrawQuad(Point(x1,0,z1),Point(x1,0,z1+1),Point(x1,h1,z1+1),Point(x1,h1,z1),index); //left
	  helper.DrawQuad(Point(x1,0,z1),Point(x1+2,0,z1),Point(x1+2,0,z1+1),Point(x1,0,z1+1),index); //bottom
	  helper.DrawQuad(Point(x1,h1,z1),Point(x1+2,h1,z1),Point(x1+2,h1,z1+1),Point(x1,h1,z1+1),index); //top
	}
  void Soor::Wall2(int x2,int h2, int z2, int index)
	{

	  Color(0,0,0);
	  helper.DrawQuad(Point(x2,0,z2),Point(x2+1,0,z2),Point(x2+1,h2,z2),Point(x2,h2,z2),index); //front
	  helper.DrawQuad(Point(x2,0,z2+1),Point(x2+1,0,z2+1),Point(x2+1,h2,z2+1),Point(x2,h2,z2+1),index); //back
	  helper.DrawQuad(Point(x2+1,0,z2),Point(x2+1,0,z2+1),Point(x2+1,h2,z2+1),Point(x2+1,h2,z2),index); //right
	  helper.DrawQuad(Point(x2,0,z2),Point(x2,0,z2+1),Point(x2,h2,z2+1),Point(x2,h2,z2),index); //left
	  helper.DrawQuad(Point(x2,0,z2),Point(x2+1,0,z2),Point(x2+1,0,z2+1),Point(x2,0,z2+1),index); //bottom
	  helper.DrawQuad(Point(x2,h2,z2),Point(x2+1,h2,z2),Point(x2+1,h2,z2+1),Point(x2,h2,z2+1),index); //top
	}
  void Soor::WallX(int x, int z, int h, int l, int num, int index)
	{
	 glPushMatrix();
	    for(int i=0 ; i<num ; i++)
		{
		 Wall1(x,h,z,index);	
		 Wall2(x+2,l,z, index);	
		 glTranslated(3,0,0);
		}
		Wall1(x,h,z, index);	
	 glPopMatrix();
	}
  void Soor::WallZ(int x, int z, int h, int l, int num, int index)
  {
	  glPushMatrix();
	  glRotated(90,0,1,0);
	  WallX(x, z, h, l, num, index);
	  glPopMatrix();
  }
  void Soor::Enterance(Point w, int num, Point p, int index, int index1)
  {
	  glPushMatrix();
	  glRotated(90,0,1,0);
	  glTranslated(p.x,p.y,p.z);
	  WallX(w.x, w.z, w.y, w.y-1, num+14,index);
	  WallX(w.x+42, w.z+50, w.y, w.y-1, num,index);
	  helper.DrawCube(Point(w.x+1,w.y-2,w.z),41+num*3,50,1,index); //roof
	  glPopMatrix();
  }
  void Soor::Minaret1(Point w, float dis, int index2, int index3)
  {

	  helper.DrawCubeCenter(Point(dis,w.y-1,w.z+11),8,8,20, index2); 
      helper.DrawCubeCenter(Point(dis,w.y-1+20,w.z+11),6,6,4,index2);
	  helper.DrawQuadCenter(Point(dis,w.y-1+24,w.z+11),9,9, index2);
	  helper.DrawCylinder2(Point(dis,w.y-1+24,w.z+11),2,2,4,20,index2);
	  helper.DrawHalfBall(Point(dis,w.y-1+28,w.z+11),2,index3);
	  helper.DrawLine(Point(dis,w.y-1+28,w.z+11),Point(dis,w.y-1+31,w.z+11));
  }
  void Soor::Minaret2(Point w, float dis, int num, int index2, int index3)
  {

	  helper.DrawCubeCenter(Point(2*dis-56+3*(num+20)-2,0,w.z+5),8,8,w.y-1+20, index2); 
      helper.DrawCubeCenter(Point(2*dis-56+3*(num+20)-2,w.y-1+20,w.z+5),6,6,4, index2);
	  helper.DrawQuadCenter(Point(2*dis-56+3*(num+20)-2,w.y-1+24,w.z+5),9,9, index2);
	  helper.DrawCylinder2(Point(2*dis-56+3*(num+20)-2,w.y-1+24,w.z+5),2,2,4,20,index2);
	  helper.DrawHalfBall(Point(2*dis-56+3*(num+20)-2,w.y-1+28,w.z+5),2,index3);
	  helper.DrawLine(Point(2*dis-56+3*(num+20)-2,w.y-1+28,w.z+5),Point(2*dis-56+3*(num+20)-2,w.y-1+31,w.z+5));
  }
  void Soor::Magharba(Point w, Point p, int index)
  {

	  glPushMatrix();
	  glTranslated(p.x,p.y,p.z);
	  glPushMatrix();
	  glTranslated(0,20,0);
	  WallX(w.x-50, w.z-31, w.y-20, w.y-20-1, 16,index);
	  WallX(w.x-50, w.z-30, w.y-20, w.y-20-1, 16,index);
	  glPopMatrix();
	  helper.DrawCubeCenter(Point(w.x-8,0,w.z-31),16,2,20,index);
	  helper.DrawCubeCenter(Point(w.x-42,0,w.z-31),16,2,20,index);
	  glPopMatrix();
  }
  void Soor::Boraq(Point w, int num, Point p, int index, int index1, int index2, int index3)
  {

	  glPushMatrix();
	  glTranslated(p.x,p.y,p.z);
	  float dis = 6*num+37*(num-1);

	  //boraq  	  
	  WallX(w.x, w.z, w.y, w.y-1, (dis-52)/3,index);
	  colomn_helper.make_n_colomns(Point(w.x-47,0,w.z+41),num,3,6,20,2,4,index1);
	  glPushMatrix();
	  glTranslated(0,55,0);
	  WallX(w.x-50, w.z+41, w.y-55, w.y-55-1, (dis-3)/3,index); 
	  glPopMatrix();
	  helper.DrawCube(Point(w.x-49,w.y-2,w.z),dis-1,41,1,index); //roof
	  helper.DrawCube(Point(dis-53,0,w.z),3,42,w.y-1.1,index); //end
	  
	  //wall of doors
	  WallX(dis-52, w.z, w.y, w.y-1, (dis-3)/3,index);
	  colomn_helper.make_n_colomns(Point(dis-49,0,w.z+21),num,3,6,20,2,4,index1);
	  glPushMatrix();
	  glTranslated(0,55,0);
	  WallX(dis-52, w.z+21, w.y-55, w.y-55-1, (dis-3)/3,index);
	  glPopMatrix();
	  helper.DrawCube(Point(2*dis-55,0,w.z ),3,22,w.y-1.1,index); //end
	  helper.DrawCube(Point(dis-53,w.y-2,w.z),dis-1,21,1,index); //roof
	  Minaret1(w, dis, index2, index3);
	  Minaret2(w, dis, num, index2, index3);
	  
	  //last peace
	  WallX(2*dis-56, w.z, w.y, w.y-1, num+20,index);
	  
	  //enterance
	  Magharba(Point(w.x, w.y, w.z), Point(0,0,0),index);
	  Enterance(Point(w.x, w.y, w.z), 10, Point(-42,0,-50),index,index);
	  
	  glPopMatrix();
  }
  void Soor::Gate(Point w, Point p, int index)
  {

	   glPushMatrix();
	  glTranslated(p.x,p.y,p.z);
	  glPushMatrix();
	  glTranslated(0,27,0);
	  WallX(w.x, w.z, w.y-27, w.y-27-1, 17, index);
	  WallX(w.x, w.z+1, w.y-27, w.y-27-1, 17, index);
	  WallX(w.x, w.z+2, w.y-27, w.y-27-1, 17, index);
	  glPopMatrix();
	  colomn_helper.make_n_colomns(Point(w.x+12,0,w.z+1),2,2,4,8,2,3,index);
	  helper.DrawCubeCenter(Point(w.x+6,0,w.z+1.5),12,3,28,index);
	  helper.DrawCubeCenter(Point(w.x+47,0,w.z+1.5),12,3,28,index);
	  glPopMatrix();
  }