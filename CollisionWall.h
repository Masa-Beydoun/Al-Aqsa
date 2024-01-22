#ifndef COLLISIONWALL_H
#define COLLISIONWALL_H
#include "Point.h"

class CollisionWall{
public:
	double xMin,xMax,yMin,yMax,zMin,zMax;
	Point center;
	double w,h,d;
	bool isActive;
	CollisionWall(Point center, double w, double h, double d);
	CollisionWall();
	bool isCollided(Point position);
	void debug();
	void enable();
	void disable();
};

#endif
