#include "Tree.h"
#include "3DTexture.h"
#include "Model_3DS.h"

Tree::Tree(){
}
void Tree::load(){
	Tree::tree = new Model_3DS();
	Tree::tree->Load("tree/tree.3DS");
	Tree::bark.LoadBMP("tree/bark_loo.bmp");
	Tree::leaf.LoadBMP("tree/leaf.bmp"); 
	for(int i = 0;i<=2;i++) Tree::tree->Materials[i].tex = Tree::bark;
	for(int i = 3;i<=Tree::tree->numMaterials-1;i++) Tree::tree->Materials[i].tex = Tree::leaf;
	glGetError();

}
void Tree::draw(Point point, float scale){
	Tree::tree->pos.x = point.x;
	Tree::tree->pos.y = point.y;
	Tree::tree->pos.z = point.z;
	Tree::tree->scale = scale;
	Tree::tree->Draw();
	glGetError();

	
}

int Tree::createDL(){
	const int list = 2;

	glNewList(list, GL_COMPILE);
		glPushMatrix();
		Tree::draw(Point(0,0,0),0.2);
		glPopMatrix();
	glEndList();
	return list;
}