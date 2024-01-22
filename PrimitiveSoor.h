#include "Color.h"
#include "Point.h"
#pragma once
class PrimitiveSoor
{
public:
	PrimitiveSoor(void);
	~PrimitiveSoor(void);

	public:
  void DrawPoint(Point point);
  void DrawLine(Point start, Point end);
  void DrawTriangle(Point v1, Point v2, Point v3, Color c);
  void DrawQuad1(Point v1, Point v2, Point v3, Point v4);
  void DrawQuadColor(Point v1, Point v2, Point v3, Point v4, Color c);
  void DrawQuadCenter(Point v1, double l, double h, int index);
  void DrawQuad(Point v1, Point v2, Point v3, Point v4,int index,float a=1,float b=1);
  void DrawCube(Point s, double l, double w, double h, int index);
  void DrawCubeCenter(Point s, double l, double w, double h, int index);
  void DrawPyramid(Point v1, Point v2, Point v3, Point v4, Point v5, Color c);
  void DrawHalfBall(Point center, float radius, int index);
  void DrawCylinderVerically(Point center, float radius, float height);
  void DrawCylinder2(Point p,float r1,float r2, float height, int slices,int index);
  void DrawCylinder(Point p,float radius, float height, int slices,int index);
};

