#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <fstream>
#include <iostream>
int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;
#include "Point.h" // Header File For Point
#include "PrimitiveDrawer.h" // // Header File For PrimitiveDrawer
#include "texture.h"
#include "Model_3DS.h"
#include"math3d.h"
#include "sound.h"
#include "Stairs.h"
#include "QibliMosque.h"
#include "IslamicMusuem.h"
#include "Mosque.h"
#include "Garden.h"
#include "camera.h"
#include "Colomn.h"
#include "AhmadiyyaSchool.h"
#include "DomesofAlAqsa.h"
#include "Soor.h"
#include "Collision.h"
#include "CollisionWall.h"

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 2000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

float ch=0;


GLfloat LightDir[] = { 0.0f,0.0f, 0.0f,1.0f };

GLfloat LightPos[] = { 12.0f ,10.0f, -10.0f,1.0f };
GLfloat LightAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat LightDiff[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat LightSpec[] = { 0.2f,0.2f,0.2f,1.0f };


GLfloat MosqueLightAmb[] = { 0.9f,0.8f,0.6f,1.0f };
GLfloat MosqueLightDiff[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MosqueLightSpec[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat mosqueLightPos [5][4];
GLfloat qibaliLightPos[4]={0,0,0,1.0f};



GLfloat MatAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f };

GLfloat MatShn[] = { 120 };

double movX = 0, movY, movZ;
double lX, lY;
bool view = false; //true => first -- false => third
int pov = 0;

int x = 0, angle = 0;
double k = 0 , l=0 , h=0;
int textureMasa[60];

void mouse(int mouseX, int mouseY, bool isClicked, bool isRClicked)
{
       if (mouseX){
		    k = float((mouseX-520)*10)/640;
			l = float((mouseY-520)*10)/640;
			glTranslated(k,l,0);
	       
	      } 
	   if(isClicked){
	      h+=0.1f;
	   }
	    if(isRClicked){
	      h-=0.1f;
	   
	   }

}

// Textures
int qibliMosqueWall, greenDoor, rug, qibliDome, qibliWithWindow, islamicDoor, flat, mainFloor, musuemLabel;
int skyboxDay[6], skyboxNight[6], skybox[6];
int school_building, school_door2, school_door, school_window, school_window2;
int handrail,stairsTex,stone7[6];
int domesoule1, domesoule2, domesoule3, death, dome2, dome3;
int column, wall,  minaret, ball;
int alselsleh1,alselsleh2,alselsleh3,alselsleh4,grass;


GLTexture gullTexture,doveTexture;

//Sound
DirectSoundBuffer Sound, DoorOpen;
DirectSoundManager SoundManager;

//Models
Model_3DS *tank, *character;
Model_3DS *dove[5], *gull[5];

//
M3DMatrix44f shadowMat;
M3DVector4f vPlaneEquation;

//Objects
QibliMosque qibli = QibliMosque();
IslamicMusuem islamic = IslamicMusuem();
Mosque mosque = Mosque();
Garden garden = Garden(0);
PrimitiveDrawer helper = PrimitiveDrawer();
AhmadiyyaSchool school = AhmadiyyaSchool();
DomesofAlAqsa domes = DomesofAlAqsa();
Soor soor = Soor();
Collision sakhraCollision=Collision();

// Display Lists
const int list = 1;
Camera MyCamera; 
void day()
{
	LightAmb[0]=0.7f;
	LightAmb[1]=0.7f;
	LightAmb[2]=0.7f;
	LightAmb[3]=1.0f;
}


void night()
{
	LightAmb[0]=0.0f;
	LightAmb[1]=0.0f;
	LightAmb[2]=0.0f;
	LightAmb[3]=1.0f;
}
void alSakhraCollsion(){
	primitiveDrawer.DrawCubeCenter(Point(-5*3+4,30-8,55),5*3,1,2*8,5);
	CollisionWall c1=CollisionWall(Point(-5*3+4,30-8,55),5*3,1,2*8);
	sakhraCollision.addWall(c1);	
}
void initBirds(int x, int y, int z, int scale) {
		for(int i = 0 ; i < 5 ; i++) {

		dove[i]=new Model_3DS();
		gull[i]=new Model_3DS();
		dove[i]->Load("DOVE.3DS");
		gull[i]->Load("GULL.3DS");
		doveTexture.LoadBMP("DOVE.bmp");
		gullTexture.LoadBMP("GULL.bmp");
		for(int j = 0 ; j < dove[i]->numMaterials-1 ; j++) {
			dove[i]->Materials[j].tex = doveTexture;
		}
		for(int j = 0 ; j < gull[i]->numMaterials-1 ; j++) {
			gull[i]->Materials[j].tex = gullTexture;
		}
		gull[i]->pos.x=20 + i*10;
		gull[i]->pos.y=y+100;
		gull[i]->pos.z=150;
		gull[i]->scale=20;

		dove[i]->pos.x=20+ i*10;
		dove[i]->pos.y=y+100;
		dove[i]->pos.z=-150;
		dove[i]->scale=20;
	}

}
int index=0;
void LoadingTexture(){
	grass=LoadTexture("grass.bmp", 255);
	alselsleh1=LoadTexture("doomSelsleh1.bmp", 255);
	alselsleh2=LoadTexture("doomSelsleh2.bmp", 255);
	alselsleh3=LoadTexture("doomSelsleh3.bmp", 255);
	alselsleh4=LoadTexture("doomSelsleh4.bmp", 255);
	textureMasa[index++]=LoadTexture("stone6.bmp",255);//0
	textureMasa[index++]=LoadTexture("mosque.bmp",255); // 1    in outside walls  in mosque
	textureMasa[index++]=LoadTexture("stone2.bmp",255); 
	textureMasa[index++]=LoadTexture("mos2.bmp",255); // 3       in outside walls  in mosque
	textureMasa[index++]=LoadTexture("carpet.bmp",255);
	textureMasa[index++]=LoadTexture("mosque3.bmp",255);//5
	textureMasa[index++]=LoadTexture("doom2.bmp",255);//6
	textureMasa[index++]=LoadTexture("doom.bmp",255);//7
	textureMasa[index++]=LoadTexture("roof.bmp",255);//8
	textureMasa[index++]=LoadTexture("stone3.bmp",255); //9   insideColomn in mosque
	textureMasa[index++]=LoadTexture("stone5.bmp",255); //10  head of colomn  +   insideColomns in Mosque
	textureMasa[index++]=LoadTexture("door.bmp",255); //11   in enternce in mosque
	textureMasa[index++]=LoadTexture("door2.bmp",255); //12   in enternce in mosque
	textureMasa[index++]=LoadTexture("insideRoof.bmp",255); //13  in inside roof
	textureMasa[index++]=LoadTexture("doom3.bmp",255); //14  in doom
	textureMasa[index++]=LoadTexture("rock.bmp",255); //15  
	textureMasa[index++]=LoadTexture("arch.bmp",255); //16 
	textureMasa[index++]=LoadTexture("arch2.bmp",255); //17  
	textureMasa[index++]=LoadTexture("enter.bmp",70); //18 
	textureMasa[index++]=LoadTexture("enterfloor.bmp",255); //19 
	textureMasa[index++]=LoadTexture("door3.bmp",255); //20 enterence doors
	textureMasa[index++]=LoadTexture("doom4.bmp",255); //21 first doom
	textureMasa[index++]=LoadTexture("doom5.bmp",255); //22 second doom
	textureMasa[index++]=LoadTexture("doom6.bmp",255); //23 second doom
	textureMasa[index++]=LoadTexture("doom7.bmp",255); //24 second doom
	textureMasa[index++]=LoadTexture("doom8.bmp",150); //25 second doom
	textureMasa[index++]=LoadTexture("doom9.bmp",255); //26 second doom
	textureMasa[index++]=LoadTexture("doom10.bmp",255); //27 second doom
	textureMasa[index++]=LoadTexture("doom11.bmp",255); //28 second doom
	textureMasa[index++]=LoadTexture("doom12.bmp",255); //29 second doom
	textureMasa[index++]=LoadTexture("doom13.bmp",255); //30 second doom
	textureMasa[index++]=LoadTexture("colomn3.bmp",255); //31 second doom
	textureMasa[index++]=LoadTexture("doom14.bmp",255); //32 second doom
	textureMasa[index++]=LoadTexture("doom15.bmp",255); //33 second doom
	textureMasa[index++]=LoadTexture("doom16.bmp",255); //34 second doom
	textureMasa[index++]=LoadTexture("doom17.bmp",255); //35 
	textureMasa[index++]=LoadTexture("inWall.bmp",255); //36  
	textureMasa[index++]=LoadTexture("inWall.bmp",255); //37  
	textureMasa[index++]=LoadTexture("mainColomn.bmp",255); //38  
	textureMasa[index++]=LoadTexture("circle1.bmp",255); //39  
	textureMasa[index++]=LoadTexture("arch3.bmp",255); //40 
	textureMasa[index++]=LoadTexture("arch4.bmp",255); //41 
	textureMasa[index++]=LoadTexture("mosque4.bmp",255); //42
	textureMasa[index++]=LoadTexture("window.bmp",255); //43 window
	textureMasa[index++]=LoadTexture("roof1.bmp",255); //44 roof
	textureMasa[index++]=LoadTexture("outDoom.bmp",120); //45 roof
	textureMasa[index++]=LoadTexture("mosque5.bmp",255); //46 roof
	textureMasa[index++]=LoadTexture("outWall.bmp",255); //47 roof
	textureMasa[index++]=LoadTexture("outWall2.bmp",255); //48 roof
	textureMasa[index++]=LoadTexture("middle.bmp",255); //49 roof
	textureMasa[index++]=LoadTexture("outWall3.bmp",255); //50 roof
	textureMasa[index++]=LoadTexture("makeRock.bmp",255); //51 rock
	textureMasa[index++]=LoadTexture("colomn2.bmp",255); //52 rock
	textureMasa[index++]=LoadTexture("stairs3.bmp",255); //53 rock
	textureMasa[index++]=LoadTexture("colomn4.bmp",255); //54 rock
	textureMasa[index++]=LoadTexture("stone4.bmp",255); //55 rock
}
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	/*glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	*/


	glEnable(GL_TEXTURE_2D);

	SoundManager.Initialize(hWnd);
	SoundManager.CreateSound("footsteps.wav", Sound);
	SoundManager.CreateSound("stone_door.wav",DoorOpen);

	// Qibli & Musuem
	qibliMosqueWall = LoadTexture("qibliTexture.bmp", 255);
	greenDoor = LoadTexture("greenDoor.bmp", 255);
	rug = LoadTexture("rug.bmp",255);
	qibliDome = LoadTexture("qibliDome.bmp",255);
	qibliWithWindow = LoadTexture("qibliWithWindow.bmp",255);
	islamicDoor = LoadTexture("woodDoor.bmp",255);
	musuemLabel = LoadTexture("musuemLabel.bmp",255);

	// School
	school_building=LoadTexture("schoolBuilding.bmp", 255);
	school_door=LoadTexture("doorbuild.bmp",255);
	school_window=LoadTexture("window2.bmp",255);
	school_window2=LoadTexture("window3.bmp",255);
	school_door2=LoadTexture("doorold.bmp",255);
	
	//to delete
	islamicDoor = LoadTexture("woodDoor.bmp",255);
	//end delete


	//Day
	skyboxDay[0] = LoadTexture("skybox/Daylight Box_Back.bmp");
	skyboxDay[1] = LoadTexture("skybox/Daylight Box_Front.bmp");
	skyboxDay[2] = LoadTexture("skybox/Daylight Box_Bottom.bmp");
	skyboxDay[3] = LoadTexture("skybox/Daylight Box_Top.bmp");
	skyboxDay[4] = LoadTexture("skybox/Daylight Box_Right.bmp");
	skyboxDay[5] = LoadTexture("skybox/Daylight Box_Left.bmp");
	for(int i = 0 ; i < 6 ; i++) {
		skybox[i] = skyboxDay[i];
	}
	//Night
	skyboxNight[0] = LoadTexture("skybox/Night Box_Back.bmp");
	skyboxNight[1] = LoadTexture("skybox/Night Box_Front.bmp");
	skyboxNight[2] = LoadTexture("skybox/Night Box_Bottom.bmp");
	skyboxNight[3] = LoadTexture("skybox/Night Box_Top.bmp");
	skyboxNight[4] = LoadTexture("skybox/Night Box_Right.bmp");
	skyboxNight[5] = LoadTexture("skybox/Night Box_Left.bmp");
	//masa's
	LoadingTexture();
	for(int i=0;i<6;i++)
	stone7[i] = LoadTexture("stone7.bmp");



	handrail = LoadTexture("handrail.bmp");
	stairsTex = LoadTexture("stone2.bmp");

	mainFloor = LoadTexture("mainFloor.bmp");

	domesoule1=LoadTexture("stone8.bmp");
	domesoule2=LoadTexture("domesoul2.bmp");
	domesoule3=LoadTexture("texdome.bmp");

	death=LoadTexture("death.bmp",255);
	dome2=LoadTexture("domesoul2.bmp",255);
	dome3=LoadTexture("domesoul3.bmp",255);

	column = LoadTexture("wall.bmp", 255);
	wall = LoadTexture("surface.bmp", 255);
	minaret = LoadTexture("minaret.bmp", 255);
	ball = LoadTexture("top.bmp",255);

	flat = LoadTexture("garden_flat.bmp");
	garden.load();
	// note if you load a image the opengl while on the GL_Texture_2D himself
	glDisable(GL_TEXTURE_2D);
	//Display List
	glNewList(list, GL_COMPILE);
		glPushMatrix();
			garden.drawSmallGarden(flat);
		glPopMatrix();
	glEndList();
	initBirds(0,0,0,7);
	//alSakhraCollsion();

	MyCamera = Camera();
	MyCamera.Position.x = 0;
	MyCamera.Position.y = +1;
	MyCamera.Position.z = +30;

	//Models
	/*character = new Model_3DS();
	character->Load("character.3DS");
	character->pos.x = -40;
	character->pos.y = 0;
	character->pos.z = 0;
	character->scale = 10;*/
	
		 
	  //glEnable(GL_LIGHT0);
	  //glEnable(GL_LIGHT1);
	  //glEnable(GL_LIGHT2);
	  glEnable(GL_LIGHT7);
	  glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, mosqueLightPos[0]);
  glLightfv(GL_LIGHT0, GL_AMBIENT, MosqueLightAmb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, MosqueLightDiff);
  glLightfv(GL_LIGHT0, GL_SPECULAR, MosqueLightSpec);

  glLightfv(GL_LIGHT1, GL_POSITION, mosqueLightPos[1]);
  glLightfv(GL_LIGHT1, GL_AMBIENT, MosqueLightAmb);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, MosqueLightDiff);
  glLightfv(GL_LIGHT1, GL_SPECULAR, MosqueLightSpec);

  glLightfv(GL_LIGHT2, GL_POSITION, qibaliLightPos);
  glLightfv(GL_LIGHT2, GL_AMBIENT, MosqueLightAmb);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, MosqueLightDiff);
  glLightfv(GL_LIGHT2, GL_SPECULAR, MosqueLightSpec);

  glLightfv(GL_LIGHT7, GL_POSITION, LightPos);
  glLightfv(GL_LIGHT7, GL_AMBIENT, LightAmb);
  glLightfv(GL_LIGHT7, GL_DIFFUSE, LightDiff);
  glLightfv(GL_LIGHT7, GL_SPECULAR, LightSpec);
  /*
	glLightfv(GL_LIGHT3, GL_POSITION, mosqueLightPos[3]);
	glLightfv(GL_LIGHT3, GL_AMBIENT, MosqueLightAmb);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, MosqueLightDiff);
	glLightfv(GL_LIGHT3, GL_SPECULAR, MosqueLightSpec);
	
	glLightfv(GL_LIGHT4, GL_POSITION, mosqueLightPos[4]);
	glLightfv(GL_LIGHT4, GL_AMBIENT, MosqueLightAmb);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, MosqueLightDiff);
	glLightfv(GL_LIGHT4, GL_SPECULAR, MosqueLightSpec);

	glLightfv(GL_LIGHT5, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT5, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT5, GL_SPECULAR, LightSpec);

	glLightfv(GL_LIGHT6, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT6, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT6, GL_SPECULAR, LightSpec);
*/
	
	
	/*glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);*/
	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);
	glEnable(GL_COLOR_MATERIAL);

	//M3DVector3f points[3] = { { -30.0f, -2.0f, -20.0f },{ -30.0f, -2.0f,
	//	20.0f },
	//	{ 40.0f, -2.0f, 20.0f } };
	//m3dGetPlaneEquation(vPlaneEquation, points[0], points[1],points[2]);
	//// Calculate projection matrix to draw shadow on the ground
	//m3dMakePlanarShadowMatrix(shadowMat, vPlaneEquation, LightPos);


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);


	return TRUE;										// Initialization Went OK
}

double angle1 = 0;
//double x = 0.005;
double sliding = 0.0005;

void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{
  // Center the Skybox around the given x,y,z position
  x = x - width / 2;
  y = y - height / 2;
  z = z - length / 2;
  glEnable(GL_TEXTURE_2D);

  // Draw Front side
  glBindTexture(GL_TEXTURE_2D, skybox[1]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
  glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
  glEnd();

  // Draw Back side
  glBindTexture(GL_TEXTURE_2D, skybox[0]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
  glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
  glEnd();

  // Draw Left side
  glBindTexture(GL_TEXTURE_2D, skybox[5]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
  glBegin(GL_QUADS);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
  glEnd();

  // Draw Right side
  glBindTexture(GL_TEXTURE_2D, skybox[4]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
  glEnd();

  // Draw Up side
  glBindTexture(GL_TEXTURE_2D, skybox[3]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
  glEnd();

  // Draw Down side
  glBindTexture(GL_TEXTURE_2D, skybox[2]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
  glEnd();

  glColor3f(1, 1, 1);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}


double birdX = 0;
void drawBirds(Point p) {
glPushMatrix();
		glRotatef(birdX*5, 0.0, -1.0, 0.0);   
		glTranslatef(10, 0.0, 0.0);
		for(int i = 0 ; i < 5 ; i++) {
			dove[i]->Draw();
			//gull[i]->Draw();
		}
		birdX+=0.1;
	glPopMatrix();

}
bool light = false;
void changeLight() {
	if(!light) day();
	else night();
	if(keys['P'] && light) {
		for(int i = 0 ; i < 6 ; i++) skybox[i] = skyboxDay[i];
		light = false;
	}
	if(keys['O'] && !light) {
		for(int i = 0 ; i < 6 ; i++) skybox[i] = skyboxNight[i];
		light = true;
	}
	Draw_Skybox(0,0,0,500,300,1000);
}

void changePOV(){
	if(keys['M'] && view) {
		pov += 4;
		view = false;
	}
	if(keys['N'] && !view) {
		pov -= 3;
		view = true;
	}
}

void walkingSound() {
	if(!keys['W']) Sound.Stop();
	if(keys['W']){
		Sound.Play(0);
	}
	if(keys['S']) {
		Sound.Play(0);
	}
	if(keys['A']) {
		Sound.Play(0);
	}
	if(keys['D']) {
		Sound.Play(0);
	}
}

void drawQibliMosque() {
	qibli.drawBase(qibliMosqueWall, rug, qibliDome, qibliWithWindow);
	qibli.drawFrontSide(qibliMosqueWall, greenDoor);
	qibli.drawRightSide(greenDoor,qibliMosqueWall, qibliWithWindow);
	qibli.drawLeftSide(qibliMosqueWall, qibliWithWindow);
}

void AqsaGarden() {
	glTranslated(-70, 0, 0);
	glCallList(list);
}

void drawGardens() {
	//Left Aqsa
	for(int i = 0 ; i < 1 ; i++) {
		glPushMatrix();
		glTranslated(-60, 0, 150 + i*20);
		glCallList(list);
		glTranslated(120, 0, 0);
		glCallList(list);
		glPopMatrix();
	}
	//Back Aqsa
	glPushMatrix();
		glTranslated(-100,0,240);
		glRotated(90,1,0,0);
		helper.DrawQuad2(Point(0,0,0),200,60,flat,10,3);
	glPopMatrix();

}

void drawMainGround(){
	glPushMatrix();
	glRotated(90,1,0,0);
	helper.DrawQuad2(Point(-250,-500,0.1),500,1000, mainFloor, 50, 150);
	glPopMatrix();
}

void drawIslamicMusuem() {
	islamic.drawBase(qibliMosqueWall);
	islamic.drawDome(qibliDome);
	islamic.drawManara(qibliMosqueWall,qibliWithWindow, greenDoor,stairsTex,handrail);
	islamic.drawDecorations(islamicDoor,musuemLabel,musuemLabel);
}

void drawAhmadiyyaSchool() {
	school.DrawAlhmadiyyaSchool(school_building,school_door,school_window,school_door2,school_window2);
}

void drawStairs(){
Colomn column = Colomn();
	Stairs stairs1 = Stairs(12,2,50,2);
	column.make_n_colomns(Point(-60,25,95),4,2,2,25,0.5,1,textureMasa[0],1);
	stairs1.draw(Point(-35,0,122.5),stairsTex,handrail);
	Stairs stairs2 = Stairs(12,2,50,2);
	column.make_n_colomns(Point(10,25,95),4,2,2,25,0.5,1,textureMasa[0],1);
	stairs2.draw(Point(35,0,122.5),stairsTex,handrail);
	glPushMatrix();
		glTranslated(-35,0,-122.5);
		glRotated(180,0,1,0);
		Stairs stairs3 = Stairs(12,2,50,2);
		stairs3.draw(Point(0,0,0),stairsTex,handrail);
	glPopMatrix();
	glPushMatrix();
		glTranslated(35,0,-122.5);
		glRotated(180,0,1,0);
		Stairs stairs4 = Stairs(12,2,50,2);
		stairs4.draw(Point(0,0,0),stairsTex,handrail);
	glPopMatrix();
	column.make_n_colomns(Point(10,25,-95),4,2,2,25,0.5,1,textureMasa[0],1);
	column.make_n_colomns(Point(-60,25,-95),4,2,2,25,0.5,1,textureMasa[0],1);

}

void drawGarden2(){
		
	glPushMatrix();
	primitiveDrawer.DrawCube(Point(-150,0,180),50,1,50,grass);
	primitiveDrawer.DrawCube(Point(-70,0,180),50,1,50,grass);
	primitiveDrawer.DrawCube(Point(0,0,180),50,1,50,grass);
	primitiveDrawer.DrawCube(Point(20,0,180),50,1,50,grass);
	primitiveDrawer.DrawCube(Point(30,0,180),50,1,50,grass);

	primitiveDrawer.DrawCube(Point(-150,0,-70),50,1,50,grass);
	primitiveDrawer.DrawCube(Point(-150,0,0),50,1,50,grass);
	primitiveDrawer.DrawCube(Point(-150,0,70),50,1,50,grass);
	primitiveDrawer.DrawCube(Point(-150,0,150),50,1,50,grass);
	


	glPopMatrix();
}
//edit
void drawDomes() {
	glPushMatrix();
		glTranslated(70,30,50);
		glScaled(3,3,3);
		glRotated(180,1,0,0);
		domes.DrawDomeOfSouls(domesoule1,domesoule2,domesoule3);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-60,0,-200);
		glScaled(3,3,3);
		glRotated(180,1,0,0);
		glRotated(90,0,1,0);
		domes.DrawDomeOfProphet(death,dome2,dome3);
	glPopMatrix();

	glPushMatrix();
		glTranslated(300,100,-200);
		glScaled(3,3,3);
		domes.DrawDomeOfProphet(death,dome2,dome3);
	glPopMatrix();

		glPushMatrix();
			glTranslated(-70,30,10);
			domes.DrawDomeOfAlselsileh(alselsleh1,alselsleh2,alselsleh3,alselsleh4,domesoule1,dome3);
		glPopMatrix();


	
}

void drawMap(){
	PrimitiveDrawer drawer = PrimitiveDrawer();
	// School
	glPushMatrix();
		glTranslated(75,25,75);
		glScaled(4,4,4);
		drawAhmadiyyaSchool();
	glPopMatrix();
	// Aqsa
	glPushMatrix();
		mosque.setTex(textureMasa);
		glEnable(GL_LIGHT0);
				mosque.makeMosque(Point(-3.5*5,26,10.5*5));

		//edit here
		for(int i=0;i<5;i++){
			for(int j=0;j<3;j++){
				mosqueLightPos[i][j]= mosque.light[i][j];
			}
		}
		mosque.makeMosque(Point(-3.5*5,26,10.5*5));

				glLightfv(GL_LIGHT0, GL_POSITION, mosqueLightPos[0]);

		glDisable(GL_LIGHT0);
		drawer.DrawCubeCenter(Point(0,0,0),200,200,25 ,textureMasa [55]);
	glPopMatrix();
		drawStairs();
	////Qibli
	glPushMatrix();
		glTranslated(-35,0,-300);
		qibaliLightPos[0]=0;
		qibaliLightPos[1]=30;
		qibaliLightPos[2]=0;
		primitiveDrawer.DrawBall2(Point(0,30,0),1,1,0);
		glScaled(3,3,3);
		glLightfv(GL_LIGHT2, GL_POSITION, qibaliLightPos);
		drawQibliMosque();

	glPopMatrix();
	////Musuem
	glPushMatrix();
		glTranslated(70,0,-385);
		glRotated(-90,0,1,0);
		glScaled(2,2,2);
		drawIslamicMusuem();
	glPopMatrix();
	
	//Extra
	glPushMatrix();
		drawMainGround();
		drawGardens();
	glPopMatrix();

	drawDomes();
}

void doorOpening(){
	if(keys['G']) DoorOpen.Play(0);
}

void sounds(){
	walkingSound();
	doorOpening();
}

void Key(bool* keys, float speed)
{
	sakhraCollision.isAnyCollided(Point(MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z ));

	if (keys[VK_DOWN])
	MyCamera.RotateX(-1 * speed);
	if (keys[VK_UP])
	MyCamera.RotateX(1 * speed);
	if (keys[VK_RIGHT])
	MyCamera.RotateY(-1 * speed);
	if (keys['Z'])
	MyCamera.RotateZ(1 * speed);
	if (keys['X'])
	MyCamera.RotateZ(-1 * speed);
	if (keys[VK_LEFT])
	MyCamera.RotateY(1 * speed);
	if (keys['W'])
	MyCamera.MoveForward(1 * speed);
	if (keys['S'])
	MyCamera.MoveForward(-1 * speed);
	if (keys['D'])
	MyCamera.MoveRight(1 * speed);
	if (keys['A'])
	MyCamera.MoveRight(-1 * speed);
	if (keys['O'])
	MyCamera.MoveUpward(1 * speed);
	if (keys['L'])
	MyCamera.MoveUpward(-1 * speed);
	if(keys['G']){
		mosque.doorOpen=1;
	}
}

int temp = 0;
void characterControl(){
	character->Draw();
}

void dome() {
	Colomn column = Colomn();
	helper.DrawQuad2(Point(0,0,0),3.5,5,qibliMosqueWall, 1,2.5);
	helper.DrawQuad2(Point(0,0,0.2),3.5,5,qibliMosqueWall, 1,2.5);
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslated(-5,0,0);
		column.make_n_colomns(Point(0,0,0),2,0.2,0.6,20,0.2,0.2,qibliMosqueWall);
		glTranslated(0,0,3.2);
		column.make_n_colomns(Point(0,0,0),2,0.2,0.6,20,0.2,0.2,qibliMosqueWall);
	glPopMatrix();
	//column.makeArch(Point(10,0,0),10,1,1,1);
}

void drawSoor() {
	glPushMatrix();
		glTranslated(150,0,-350);
		glRotated(-90,0,1,0);
		soor.Boraq(Point(0,70,0), 9, Point(0,0,0),wall,column,minaret,ball);
	glPopMatrix();
	//
	soor.WallX(-160,382.5,70,69,30,wall);
	soor.Gate(Point(-70,70,382.5),Point(0,0,0),wall);
	soor.WallX(-20,382.5,70,69,15,wall);
	soor.Gate(Point(25,70,382.5),Point(0,0,0),wall);
	soor.WallX(75,382.5,70,69,30,wall);
	//
	glPushMatrix();
		glRotated(90,0,1,0);
		soor.WallX(-382.5,-160,70,69,30,wall);
		soor.Gate(Point(-292.5,70,-160),Point(0,0,0),wall);
		soor.WallX(-242.5,-160,70,69,15,wall);
		soor.Gate(Point(-197.5,70,-160),Point(0,0,0),wall);
		soor.WallX(-152.5,-160,70,69,15,wall);
		soor.Gate(Point(-107.5,70,-160),Point(0,0,0),wall);
		soor.WallX(-62.5,-160,70,69,15,wall);
		soor.Gate(Point(-17.5,70,-160),Point(0,0,0),wall);
		soor.WallX(27.5,-160,70,69,15,wall);
		soor.Gate(Point(72.5,70,-160),Point(0,0,0),wall);
		soor.WallX(117.5,-160,70,69,15,wall);
		soor.Gate(Point(72.5,70,-160),Point(0,0,0),wall);
		soor.WallX(117.5,-160,70,69,15,wall);
		soor.Gate(Point(162.5,70,-160),Point(0,0,0),wall);
		soor.WallX(117.5,-160,70,69,15,wall);
		soor.Gate(Point(162.5,70,-160),Point(0,0,0),wall);
		soor.WallX(207.5,-160,70,69,15,wall);
		soor.Gate(Point(252.5,70,-160),Point(0,0,0),wall);
		soor.WallX(297.5,-160,70,69,35,wall);
	glPopMatrix();
	//
	soor.WallX(-160,-400,70,69,100,wall);
	//
	
}



int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{   
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	glClearColor(0.7,0.7,0.7,1);

	MyCamera.Render();
	glPushMatrix();
	glTranslated(0,-2,pov);
	
	Key(keys, 8);
	drawMap();
	sounds();
	drawGarden2();
	drawSoor();
	//drawBirds(Point(0,0,0));
	//// [M] & [N] for POV
	changePOV();
	////characterControl();
	////[P] & [O] for light
	changeLight();
	////glPopMatrix();
	//	
	glPopMatrix();
	LightPos[0]=-20;
	LightPos[1]=50;
	LightPos[2]=20;
	primitiveDrawer.DrawBall2(Point(-20,50,20),1,0.5,textureMasa[0]);
	primitiveDrawer.DrawBall2(Point(-20,50,-20),1,0.5,textureMasa[0]);
	primitiveDrawer.DrawBall2(Point(20,50,-15),1,0.5,textureMasa[0]);
	primitiveDrawer.DrawBall2(Point(20,50,15),1,0.5,textureMasa[0]);

		glLightfv(GL_LIGHT7, GL_AMBIENT, LightAmb);
		glLightfv(GL_LIGHT7, GL_POSITION, LightPos);
	//primitiveDrawer.DrawQuad2(Point(-5*3,30,30),5*3,3*8,5,5,5);
	return TRUE;
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}
	case WM_LBUTTONUP:
		isClicked = false; 	 break;
	case WM_RBUTTONUP:
		isRClicked = false;   break;
	case WM_LBUTTONDOWN:
		isClicked = true; 	break;
	case WM_RBUTTONDOWN:
		isRClicked = true;	break;
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
													if (!HIWORD(wParam))					// Check Minimization State
													{
														active = TRUE;						// Program Is Active
													}
													else
													{
														active = FALSE;						// Program Is No Longer Active
													}

													return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
													switch (wParam)							// Check System Calls
													{
													case SC_SCREENSAVE:					// Screensaver Trying To Start?
													case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
														return 0;							// Prevent From Happening
													}
													break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
													PostQuitMessage(0);						// Send A Quit Message
													return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
													keys[wParam] = TRUE;					// If So, Mark It As TRUE
													return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
													keys[wParam] = FALSE;					// If So, Mark It As FALSE
													return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
													ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
													return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Example", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

