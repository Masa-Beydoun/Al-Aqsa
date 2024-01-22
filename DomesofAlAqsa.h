#pragma once

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

#include "Point.h"
#include "Color.h"
#include "PrimitiveDrawer.h"
#include "Colomn.h"
#define M_PI 3.14159265358979323846
class DomesofAlAqsa
{
public:
	DomesofAlAqsa(void);
	~DomesofAlAqsa(void);


	void DrawDomeOfSouls(int domesoule1, int index, int index2);
	void DrawDomeOfProphet(int index1, int index2, int index3);

	
void DomesofAlAqsa::DrawDomeOfAlselsileh(int alselsleh1,int alselsleh2,int alselsleh3,int alselsleh4,int domesoule1,int doomTexture);




};

