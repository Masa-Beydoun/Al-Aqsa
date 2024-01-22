#pragma once
class Mosque
{
public:
	double doorAngle;
	int doorOpen;
	int texture[60];
	GLfloat light[5][3];
	Mosque(void);
	~Mosque(void);
	void makeMosque(Point p,float t1=5,float t2=8,float doomHeight=3);
	void carpet(Point p,float width,float hight);
	void top(Point p,float r,int t1);
	void makeFullCarpet(Point p,int t1);
	void makeOutsideWalls(Point p,int t1,int t2,int doomHeight);
	void makeInsideWalls(Point p,int t1,int t2);
	void makeEnterence(Point p,int l,int width,int height,int num);
	void movementOfTheDoor(double width,double height,int dir);
	void insideRoof(Point p,int t1);
	void insideColomns(Point p,float t1,float t2);
	void makeRock(Point p,float t1);
	void insideDoom(Point p,float r,float t1,float t2);
	void makeLights(Point p,float t1);
	void setTex(int t[]);
};

