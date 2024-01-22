#ifndef COLLISION_H
#define COLLISION_H
#include "Point.h"
#include "CollisionWall.h"

class Collision{
public:
	double translateX, translateY, translateZ;
	int index;
	bool isActive;
	CollisionWall walls[50];
	Collision(double translateX, double translateY, double translateZ);
	Collision();
	void enable();
	void disable();
	bool isAnyCollided(Point position);
	void addWall(CollisionWall wall);

};

#endif
