#include "Garden.h"
#include "PrimitiveDrawer.h"
Garden::Garden(){}
Garden::Garden(int type){
	Garden::type = type;
}

void Garden::load(){
	switch(type){
	case 0: Garden::initializeTrees(4);
		return;
	case 1: Garden::initializeTrees(8);
		return;
	case 2: Garden::initializeTrees(15);
		return;
	}
	glGetError();

}

void Garden::initializeTrees(int n){
	for(int i = 0 ; i < n; i++){
		trees[i].load();
	}
	glGetError();

}

void Garden::draw(Point point, int texture){
	 glPushMatrix();
	 glTranslated(point.x,point.y,point.z);
	 if(type == 0){
		 Garden::drawSmallGarden(texture);
	 }else if(type == 1){
		 Garden::drawMediumGarden(texture);
	 }else{
		 Garden::drawLargeGarden(texture);
	 }
	 glPopMatrix();
	glGetError();

}

void Garden::drawWithRepeatX(Point point, int times, int texture){
	for(int i = 0;i<times;i++){
		Garden::draw(point,texture);
		if(type == 0) point.x += 4;
		else if(type == 1) point.x += 5;
		else point.x += 7;
	}
}

void Garden::drawWithRepeatY(Point point, int times, int texture){
	for(int i = 0;i<times;i++){
		Garden::draw(point,texture);
		if(type == 0) point.z -= 4;
		else if(type == 1) point.z -= 5;
		else point.z -= 7;
	}
}

void Garden::drawSmallGarden(int texture){
	PrimitiveDrawer drawer = PrimitiveDrawer();
	drawer.DrawFlat(Point(0,0,0),10,10,texture);
	trees[0].draw(Point(6,0,-8),1);
	trees[1].draw(Point(6,0,8),1);
	trees[2].draw(Point(-6,0,5),1);
	trees[3].draw(Point(-6,0,-5),1);
	glGetError();

}

void Garden::drawMediumGarden(int texture){
	PrimitiveDrawer drawer = PrimitiveDrawer();
	drawer.DrawFlat(Point(0,0,0),2.5,2.5,texture);
	trees[0].draw(Point(0,0,0),0.2);
	trees[1].draw(Point(1.5,0,-1.5),0.2);
	trees[2].draw(Point(0.5,0,-1.2),0.2);
	trees[3].draw(Point(-1.5,0,1.5),0.2);
	trees[4].draw(Point(2,0,2),0.2);
	trees[5].draw(Point(-1,0,-0.6),0.2);
	trees[6].draw(Point(1,0,1.6),0.2);
	trees[7].draw(Point(-1.7,0,-0.3),0.2);
}

void Garden::drawLargeGarden(int texture){
	PrimitiveDrawer drawer = PrimitiveDrawer();
	drawer.DrawFlat(Point(0,0,0),3.5,3.5,texture);
	trees[0].draw(Point(0,0,0),0.2);
	trees[1].draw(Point(1.5,0,-1.5),0.2);
	trees[2].draw(Point(0.5,0,-1.2),0.2);
	trees[3].draw(Point(-1.5,0,1.5),0.2);
	trees[4].draw(Point(2,0,2),0.2);
	trees[5].draw(Point(-1,0,-0.6),0.2);
	trees[6].draw(Point(1,0,1.6),0.2);
	trees[7].draw(Point(-1.7,0,-0.3),0.2);
	trees[8].draw(Point(-3,0,-3),0.2);
	trees[9].draw(Point(-2.7,0,2.7),0.2);
	trees[10].draw(Point(3,0,-2.5),0.2);
	trees[11].draw(Point(2,0,3),0.2);
	trees[12].draw(Point(-0.7,0,-2),0.2);
	trees[13].draw(Point(2.5,0,-1),0.2);
	trees[14].draw(Point(-1.2,0,0.3),0.2);
}

void Garden::drawGarden(int texture){
	int treeDL = trees[0].createDL();
	PrimitiveDrawer drawer = PrimitiveDrawer();
	drawer.DrawFlat(Point(0,0,0),2,2,texture);
	glPushMatrix();
		glTranslated(0.5,0,0);
		glCallList(treeDL);
	glPopMatrix();
	glPushMatrix();
		glTranslated(1,0,1);
		glCallList(treeDL);
	glPopMatrix();
	glPushMatrix();
		glTranslated(1,0,1);
		glCallList(treeDL);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-0.6,0,-1.4);
		glCallList(treeDL);
	glPopMatrix();
	glGetError();

}
