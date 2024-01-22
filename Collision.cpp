#include "CollisionWall.h" 
#include "Collision.h"

Collision::Collision(double translateX, double translateY, double translateZ){
	Collision::translateX = translateX;
	Collision::translateY = translateY;
	Collision::translateZ = translateZ;
	Collision::index = 0;
	Collision::isActive = true;
	for(int i = 0;i<30;i++){
		walls[i] = CollisionWall();
	}
}
Collision::Collision(){
	Collision::index = 0;
	Collision::isActive = true;
}

void Collision::enable(){
	isActive = true;
}

void Collision::disable(){
	isActive = false;
}

void Collision::addWall(CollisionWall wall){
	CollisionWall newWall = CollisionWall(
		Point(wall.center.x + translateX, wall.center.y + translateY, wall.center.z + translateZ),
		wall.w,
		wall.h,
		wall.d);
	Collision::walls[index] = newWall;
	index++;
}

bool Collision::isAnyCollided(Point position){
	if(!isActive) return false;
	for(int i = 0 ; i < index ; i++){
		if(walls[i].isCollided(position)){
			return true;
		}
	}
	return false;
}
