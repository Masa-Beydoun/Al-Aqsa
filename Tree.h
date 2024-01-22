#ifndef TREE_H
#define TREE_H
#include "Point.h"
#include "Model_3DS.h"
#include "3DTexture.h"
class Tree {
public:
	Model_3DS *tree;
	GLTexture bark,leaf;
	Tree();
	void draw(Point point, float scale);
	int createDL();
	void load();
};

#endif
