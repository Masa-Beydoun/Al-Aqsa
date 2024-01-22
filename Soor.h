#ifndef SOOR_H
#define SOOR_H

#include "Point.h"
#include "Color.h"
#include "PrimitiveSoor.h"
#include "Colomn.h"

class Soor
{
public:
	Soor();
	void Wall1(int x1, int h1, int z1, int index);
	void Wall2(int x2,int h2, int z2, int index);
	void WallX(int x, int z, int h, int l, int num, int index);
	void WallZ(int x, int z, int h, int l, int num, int index);
	void Boraq(Point w, int num, Point p, int index, int index1, int index2, int index3);
	void Enterance(Point w, int num, Point p, int index, int index1);
	void Minaret1(Point w, float num, int index2, int index3);
	void Minaret2(Point w, float dis, int num, int index2, int index3);
	void Magharba(Point w, Point p, int index);
	void Gate(Point w, Point p, int index);
};

#endif