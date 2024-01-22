#include "Point.h"
#include "CollisionWall.h"
#include "PrimitiveDrawer.h"
CollisionWall::CollisionWall(Point center, double w, double h, double d){
	CollisionWall::xMin = (center.x) - (w/2);
	CollisionWall::xMax = (center.x) + (w/2);
	CollisionWall::yMin = (center.y) - (h/2);
	CollisionWall::yMax = (center.y) + (h/2);
	CollisionWall::zMin = (center.z) - (d/2);
	CollisionWall::zMax = (center.z) + (d/2);
	CollisionWall::center = center;
	CollisionWall::w = w;
	CollisionWall::h = h;
	CollisionWall::d = d;
	isActive = true;
}
CollisionWall::CollisionWall(){
	isActive = true;
}


void CollisionWall::enable(){
	isActive = true;
}

void CollisionWall::disable(){
	isActive = false;
}

bool CollisionWall::isCollided(Point position){
	double per = 0.5;
	if(!isActive) return false;
	return position.x >= (xMin - per) && 
		position.x <= (xMax + per) &&
		position.y >= (yMin - per) &&
		position.y <= (yMax + per) &&
		position.z >= (zMin - per) &&
		position.z <= (zMax + per);
}

void CollisionWall::debug(){
	PrimitiveDrawer drawer = PrimitiveDrawer();
	drawer.DrawCube(center,w,h,d, -1);
}


