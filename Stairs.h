#ifndef STAIRS_H
#define STAIRS_H
#include "Point.h"

class Stairs{
public:
	int stairsNo,texture[6];
	double stairsHeight, stairsWidth, stairsDepth;
	Stairs();
	Stairs(int stairsNo, double stairsHeight, double stairsWidth, double stairsDepth);
	void draw(Point point, int stairsTex, int handrailTex);
	void drawLeftHandrail(Point point, double width, double height, int handrailTex);
	void drawRightHandrail(Point point, double widht, double height, int handrailTex);
};

#endif
