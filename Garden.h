#ifndef GARDEN_H
#define GARDEN_H
#include "Point.h"
#include "Model_3DS.h"
#include "Tree.h"
#include "3DTexture.h"
class Garden{
public:
	Tree trees[20];
	int type;
	Garden(int type);
	Garden();
	void load();
	void initializeTrees(int n);
	void draw(Point point, int texture);
	void drawWithRepeatX(Point point, int times, int texture);
	void drawWithRepeatY(Point point, int times, int texture);
	void drawSmallGarden(int texture);
	void drawMediumGarden(int texture);
	void drawLargeGarden(int texture);
	void drawGarden(int texture);
};

#endif
