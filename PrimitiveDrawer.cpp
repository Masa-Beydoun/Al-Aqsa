
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Colomn.h"
#include "Point.h"
#include "PrimitiveDrawer.h"
#define M_PI 3.14159265358979323846


PrimitiveDrawer primitiveDrawer;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PrimitiveDrawer::PrimitiveDrawer() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawPoint(Point point) {
    glBegin(GL_POINTS);
    glVertex3f(point.x, point.y, point.z);
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrimitiveDrawer::DrawQuad2(Point v1, double l, double h, int image = 0, double rx = 1, double ry = 1) {
	Point v2 = Point(v1.x + l, v1.y, v1.z);
	Point v3 = Point(v1.x + l, v1.y+h, v1.z);
	Point v4 = Point(v1.x, v1.y+h, v1.z);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image);    
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);  glVertex3f(v1.x, v1.y, v1.z);
				glTexCoord2f(rx,0);  glVertex3f(v2.x, v2.y, v2.z);
				glTexCoord2f(rx,ry);  glVertex3f(v3.x, v3.y, v3.z);
				glTexCoord2f(0,ry);  glVertex3f(v4.x, v4.y, v4.z);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
    glEnd();
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawLine(Point start, Point end) {
    glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawTriangle(Point v1, Point v2, Point v3) {
    glBegin(GL_TRIANGLES);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void PrimitiveDrawer::DrawQuad(Point v1, Point v2, Point v3, Point v4,int index) {
	if(index!=-1){
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, index);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0xFFFF);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0xFFFF);
		glBegin(GL_QUADS);
		
		glVertex3f(v1.x, v1.y, v1.z);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(v2.x, v2.y, v2.z);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(v3.x, v3.y, v3.z);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(v4.x, v4.y, v4.z);
		glTexCoord2f(1.0f, 0.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
	}
	else{
		glBegin(GL_QUADS);
		glVertex3f(v1.x, v1.y, v1.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v3.x, v3.y, v3.z);
		glVertex3f(v4.x, v4.y, v4.z);
		glEnd();
	}
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void PrimitiveDrawer::DrawCylinderWIthTwoTextures(Point p,float radius,float r2, float height, int slices,int index1,int index2){
  
    glPushMatrix();
    glTranslated(p.x,p.y,p.z);

    float angleStep = (2.0f * M_PI) / slices;
        int cnt=0;

      
      
      for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
        glEnable(GL_TEXTURE_2D);
        if(cnt%2==0)
          glBindTexture(GL_TEXTURE_2D, index1);
        else
          glBindTexture(GL_TEXTURE_2D, index2);
        glBegin(GL_QUADS);
          glTexCoord2f(1.0f, 1.0f); glVertex3f(r2 * cosf(angle-angleStep), height, r2 * sinf(angle-angleStep));
          glTexCoord2f(0.0f, 1.0f); glVertex3f(radius * cosf(angle-angleStep), 0.0f, radius * sinf(angle-angleStep));
          glTexCoord2f(0.0f, 0.0f); glVertex3f(radius * cosf(angle), 0.0f, radius * sinf(angle));
          glTexCoord2f(1.0f, 0.0f); glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
        glEnd();
        glDisable(GL_TEXTURE_2D);
        cnt++;
      }
      glEnable(GL_TEXTURE_2D);
      // Connect the last to the first
      if(cnt%2==0)
          glBindTexture(GL_TEXTURE_2D, index1);
        else
          glBindTexture(GL_TEXTURE_2D, index2);
        glBegin(GL_QUADS);
          glTexCoord2f(1.0f, 1.0f); glVertex3f(radius * cosf(2.0f * M_PI), height, radius * sinf(2.0f * M_PI));
          glTexCoord2f(0.0f, 1.0f); glVertex3f(radius * cosf(2.0f * M_PI), 0.0f, radius * sinf(2.0f * M_PI));
          glTexCoord2f(0.0f, 0.0f); glVertex3f(radius * cosf(0), height, radius * sinf(0));
          glTexCoord2f(1.0f, 0.0f); glVertex3f(radius * cosf(0), 0.0f, radius * sinf(0));
        glEnd();
      glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
  }
 ///////////////////////////////////////////////////////////////////////////////////////
// Draw a cube using the DrawQuad function
void PrimitiveDrawer::DrawCube(Point p,double w,double h,double l,int index){
	
	DrawQuad(p,Point(p.x+w,p.y,p.z),Point(p.x+w,p.y+h,p.z),Point(p.x,p.y+h,p.z),index);
	DrawQuad(Point(p.x+w,p.y,p.z+l),Point(p.x+w,p.y+h,p.z+l),Point(p.x+w,p.y+h,p.z),Point(p.x+w,p.y,p.z),index);
	DrawQuad(Point(p.x,p.y,p.z+l),Point(p.x,p.y+h,p.z+l),Point(p.x,p.y+h,p.z),p,index);
	DrawQuad(Point(p.x+w,p.y+h,p.z),Point(p.x+w,p.y+h,p.z+l),Point(p.x,p.y+h,p.z+l),Point(p.x,p.y+h,p.z),index);
	DrawQuad(Point(p.x+w,p.y,p.z+l),Point(p.x+w,p.y+h,p.z+l),Point(p.x,p.y+h,p.z+l),Point(p.x,p.y,p.z+l),index);
	DrawQuad(Point(p.x+w,p.y,p.z),Point(p.x+w,p.y,p.z+l),Point(p.x,p.y,p.z+l),p,index);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrimitiveDrawer::DrawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.14 * float(i) / float(numSegments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawHalfCircle(float cx, float cy, float cz, float r, int numSegments) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numSegments / 2; i++) { // Only loop for half of the segments
        float theta = 3.14 * float(i) / float(numSegments / 2); // Range from 0 to pi
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex3f(x + cx, y + cy, cz);
    }
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void PrimitiveDrawer::DrawFilledHalfCircle(float cx, float cy, float cz, float r, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx, cy, cz); // Center of the half circle

    for (int i = 0; i <= numSegments / 2; i++) {
        float theta = 3.14 * float(i) / float(numSegments / 2);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex3f(x + cx, y + cy, cz);
    }

    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawFilledHalfCircleWithZ(float cx, float cy, float cz, float r, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx, cy, cz); // Center of the half circle

    for (int i = 0; i <= numSegments / 2; i++) {
        float theta = 3.14 * float(i) / float(numSegments / 2);
        float z = r * cosf(theta); // Use the radius for z
        float y = r * sinf(theta);
        glVertex3f(cx, y + cy, z + cz); // Adjust z-coordinate here
    }

    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawFilledCircle(Point center, float radius) {
	int numSegments = 30;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center.x, center.y, center.z); // Center of the circle

    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.14159265358979323846 * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex3f(x + center.x, y + center.y, center.z);
    }

    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawBottomHalfCircle(float cx, float cy, float cz, float r, int numSegments) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numSegments / 2; i++) { // Loop for half of the segments
        float theta = 2.5 + (3.14 * float(i) / float(numSegments / 2)); // Range from pi to 2*pi
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex3f(x + cx, y + cy, cz); // Include the z-coordinate
    }
    glEnd();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawDashedLine(float x1, float y1, float z1, float x2, float y2, float z2, float dashLength, float lineWidth) {
    glLineWidth(lineWidth); // Set the line width
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;
    float lineLength = sqrt(dx * dx + dy * dy + dz * dz);
    int numSegments = lineLength / dashLength;
    
    dx /= numSegments;
    dy /= numSegments;
    dz /= numSegments;
    
    bool drawingLine = true;

    glBegin(GL_LINES);
    for (int i = 0; i < numSegments; ++i) {
        if (drawingLine) {
            glVertex3f(x1, y1, z1);
            x1 += dx;
            y1 += dy;
            z1 += dz;
            glVertex3f(x1, y1, z1);
        } else {
            // Skip the gap
            x1 += dx;
            y1 += dy;
            z1 += dz;
        }
        drawingLine = !drawingLine;
    }
    glEnd();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to draw a window (quad with a half-filled circle at the top)
void PrimitiveDrawer::DrawWindow(float x, float y, float z, float width, float height, float circleRadius, int circleSegments) {
    // Draw the quad for the window
    glBegin(GL_QUADS);
    glVertex3f(x, y, z);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x, y + height, z);
    glEnd();

    // Calculate the center of the half-circle
    float circleCenterX = x + width / 2.0;
    float circleCenterY = y + height;
    float circleCenterZ = z;

    // Draw the half-filled circle at the top
    DrawFilledHalfCircle(circleCenterX, circleCenterY, circleCenterZ, circleRadius, circleSegments);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawWindowWithZ(float x, float y, float z, float width, float height, float circleRadius, int circleSegments) {
    // Draw the quad for the window
    glBegin(GL_QUADS);
    glVertex3f(x, y, z);
    glVertex3f(x , y, z+ width);
    glVertex3f(x , y + height, z+ width);
    glVertex3f(x, y + height, z);
    glEnd();

    // Calculate the center of the half-circle
    float circleCenterX = x ;
    float circleCenterY = y + height;
    float circleCenterZ = z+ width / 2.0;

    // Draw the half-filled circle at the top
    DrawFilledHalfCircleWithZ(circleCenterX, circleCenterY, circleCenterZ, circleRadius, circleSegments);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawPalastineFlag(Point center, float length, float height ,float rotationAngle) {
    float halfLength = length * 0.5;
    float subHeight = height / 3;
    Point p1(center.x - halfLength, center.y - subHeight, center.z);
    Point p2(center.x + halfLength, center.y - subHeight, center.z);
    Point p3(center.x + halfLength, center.y, center.z);
    Point p4(center.x - halfLength, center.y, center.z);
    Point p5(center.x + halfLength, center.y + subHeight, center.z);
    Point p6(center.x - halfLength, center.y + subHeight, center.z);
    Point p7(center.x + halfLength, center.y + 2 * subHeight, center.z);
    Point p8(center.x - halfLength, center.y + 2 * subHeight, center.z);
    Point p9(center.x - (halfLength / 2), center.y + 1, center.z);

	// Apply the rotation transformation
    glPushMatrix();
    glTranslatef(p1.x, p1.y, p1.z);  // Translate to the center of the flag
    glRotatef(rotationAngle, 0, 1, 0);    // Rotate around the Y-axis
    glTranslatef(-p1.x, -p1.y, -p1.z);  // Translate back to the original position


    glColor3f(0.18f, 0.75f, 0.0f); // Green color
    DrawQuadMain(p1, p2, p3, p4);

    glColor3f(1.0f, 1.0f, 1.0f); // White color
    DrawQuadMain(p4, p3, p5, p6);

    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    DrawQuadMain(p6, p5, p7, p8);

    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    DrawTriangle(p1, p9, p8);
	glPopMatrix();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawOctagonal(Point center, float side, float height ,GLuint frontTexture , GLuint sideTexture , GLuint roofTexture) {
	//front
    Point p1 = Point (center.x , center.y , center.z );
	Point p2 = Point (center.x + side * 1.5 , center.y , center.z);
	Point p3 = Point (center.x + side * 1.5, center.y + height , center.z);
	Point p4 = Point(center.x , center.y + height, center.z);

	//right front
	Point p5 = Point (p2.x  , center.y , center.z );
	Point p6 = Point (p2.x +side , center.y, center.z+side);
	Point p7 = Point (p2.x +side , center.y + height , center.z +side);
	Point p8 = Point (p2.x  , center.y + height , center.z );

	//left front
	Point p9 = Point (p1.x  , center.y , center.z );
	Point p10 = Point (p1.x -side , center.y, center.z+side);
	Point p11 = Point (p1.x -side , center.y + height , center.z +side);
	Point p12 = Point (p1.x  , center.y + height , center.z );

	//right
	Point p13 = Point (p6.x, center.y , p7.z);
	Point p14 = Point (p6.x , center.y, p7.z + side * 1.5);
	Point p15 = Point (p6.x , center.y + height , p7.z + side * 1.5);
	Point p16 = Point (p6.x , center.y +height , p7.z);

	//left
	Point p17 = Point (p10.x, center.y , p7.z);
	Point p18 = Point (p10.x , center.y, p7.z + side * 1.5);
	Point p19 = Point (p10.x , center.y + height , p7.z + side * 1.5);
	Point p20 = Point (p10.x , center.y +height , p7.z);

	//left back
	Point p21 = Point (p20.x, center.y , p19.z);
	Point p22 = Point (p20.x +side, center.y, p19.z + side);
	Point p23 = Point (p20.x +side, center.y + height , p19.z + side);
	Point p24 = Point (p20.x , center.y +height , p19.z);

	//right back
	Point p25 = Point (p6.x, center.y , p15.z);
	Point p26 = Point (p6.x -side, center.y, p15.z + side);
	Point p27 = Point (p6.x -side, center.y + height , p15.z + side);
	Point p28 = Point (p6.x , center.y +height , p15.z);

	float centerX = (p1.x + p2.x) * 0.5f;
	float centerY  = p1.y + height * 0.5f;
	float centerZ = (p1.z + p27.z) * 0.5f;
	Point centerOfOctanogal( centerX , centerY , centerZ );

	//front
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, frontTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p1.x , p1.y , p1.z);
				glTexCoord2f(1, 0);       glVertex3f(p2.x , p2.y , p2.z);
				glTexCoord2f(1, 1);       glVertex3f(p3.x , p3.y , p3.z);
				glTexCoord2f(0, 1);       glVertex3f(p4.x , p4.y , p4.z );
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//right front
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sideTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p5.x , p5.y , p5.z);
				glTexCoord2f(1, 0);       glVertex3f(p6.x , p6.y , p6.z);
				glTexCoord2f(1.6, 1);       glVertex3f(p7.x , p7.y , p7.z);
				glTexCoord2f(0.6, 1);       glVertex3f(p8.x , p8.y , p8.z );
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//left front
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sideTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p9.x , p9.y , p9.z);
				glTexCoord2f(1, 0);       glVertex3f(p10.x , p10.y , p10.z);
				glTexCoord2f(1.6, 1);       glVertex3f(p11.x , p11.y , p11.z);
				glTexCoord2f(0.6, 1);       glVertex3f(p12.x , p12.y , p12.z );
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//right
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, frontTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p13.x , p13.y , p13.z);
				glTexCoord2f(1, 0);       glVertex3f(p14.x , p14.y , p14.z);
				glTexCoord2f(1, 1);       glVertex3f(p15.x , p15.y , p15.z);
				glTexCoord2f(0, 1);       glVertex3f(p16.x , p16.y , p16.z );
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//left
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, frontTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p17.x , p17.y , p17.z);
				glTexCoord2f(1, 0);       glVertex3f(p18.x , p18.y , p18.z);
				glTexCoord2f(1, 1);       glVertex3f(p19.x , p19.y , p19.z);
				glTexCoord2f(0, 1);       glVertex3f(p20.x , p20.y , p20.z );
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//left back
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sideTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p21.x , p21.y , p21.z);
				glTexCoord2f(1, 0);       glVertex3f(p22.x , p22.y , p22.z);
				glTexCoord2f(1.6, 1);       glVertex3f(p23.x , p23.y , p23.z);
				glTexCoord2f(0.6, 1);       glVertex3f(p24.x , p24.y , p24.z );
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//right back
	DrawQuadMain(p25,p26,p27,p28);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sideTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p25.x , p25.y , p25.z);
				glTexCoord2f(1, 0);       glVertex3f(p26.x , p26.y , p26.z);
				glTexCoord2f(1.6, 1);       glVertex3f(p27.x , p27.y , p27.z);
				glTexCoord2f(0.6, 1);       glVertex3f(p28.x , p28.y , p28.z );
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//back
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, frontTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p26.x , p26.y , p26.z );
				glTexCoord2f(1, 0);			glVertex3f(p22.x , p22.y , p22.z);
				glTexCoord2f(1, 1);       glVertex3f(p23.x , p23.y , p23.z);
				glTexCoord2f(0, 1);       glVertex3f(p27.x , p27.y , p27.z);
			glEnd();
	glDisable(GL_TEXTURE_2D);


	//top
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, roofTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p3.x , p3.y - height * 0.1 , p3.z );
				glTexCoord2f(2, 0);			glVertex3f(p4.x , p4.y - height * 0.1, p4.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p27.x , p27.y - height * 0.1, p27.z );
				glTexCoord2f(2, 0);			glVertex3f(p28.x , p28.y - height * 0.1, p28.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p23.x , p23.y - height * 0.1, p23.z );
				glTexCoord2f(2, 0);			glVertex3f(p24.x , p24.y - height * 0.1, p24.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p7.x , p7.y - height * 0.1, p7.z );
				glTexCoord2f(2, 0);			glVertex3f(p8.x , p8.y - height * 0.1, p8.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p27.x , p27.y - height * 0.1, p27.z );
				glTexCoord2f(2, 0);			glVertex3f(p23.x , p23.y - height * 0.1, p23.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p15.x , p15.y - height * 0.1, p15.z );
				glTexCoord2f(2, 0);			glVertex3f(p16.x , p16.y - height * 0.1, p16.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p19.x , p19.y - height * 0.1, p19.z );
				glTexCoord2f(2, 0);			glVertex3f(p20.x , p20.y - height * 0.1, p20.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

			glBegin(GL_QUADS);
				glTexCoord2f(0,0);			glVertex3f(p11.x , p11.y - height * 0.1, p11.z );
				glTexCoord2f(2, 0);			glVertex3f(p12.x , p12.y - height * 0.1, p12.z);
				glTexCoord2f(2, 2);       glVertex3f(centerX  , centerY + height * 0.8 , centerZ);
				glTexCoord2f(0, 2);       glVertex3f(centerX , centerY + height * 0.8, centerZ);
			glEnd();

	glDisable(GL_TEXTURE_2D);
	
	//bottom
	glColor3f(0,0,0);
	DrawQuadMain(p1,p2,p26,p22);
	DrawQuadMain(p21,p22,p5,p6);
	DrawQuadMain(p13,p14,p17,p18);
	DrawQuadMain(p25,p26,p9,p10);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawBall(Point center, float radius, int stacks, int slices) {
    for (int i = 0; i < stacks; i++) {
        float phi1 = 3.14 * static_cast<float>(i) / stacks;
        float phi2 = 3.14 * static_cast<float>(i + 1) / stacks;

        for (int j = 0; j < slices; j++) {
            float theta1 = 2.0f * 3.14 * static_cast<float>(j) / slices;
            float theta2 = 2.0f * 3.14 * static_cast<float>(j + 1) / slices;

            // Calculate vertices
            float x1 = center.getX() + radius * sin(phi1) * cos(theta1);
            float y1 = center.getY() + radius * sin(phi1) * sin(theta1);
            float z1 = center.getZ() + radius * cos(phi1);

            float x2 = center.getX() + radius * sin(phi1) * cos(theta2);
            float y2 = center.getY() + radius * sin(phi1) * sin(theta2);
            float z2 = center.getZ() + radius * cos(phi1);

            float x3 = center.getX() + radius * sin(phi2) * cos(theta2);
            float y3 = center.getY() + radius * sin(phi2) * sin(theta2);
            float z3 = center.getZ() + radius * cos(phi2);

            float x4 = center.getX() + radius * sin(phi2) * cos(theta1);
            float y4 = center.getY() + radius * sin(phi2) * sin(theta1);
            float z4 = center.getZ() + radius * cos(phi2);

            // Draw each triangle
            DrawTriangle(Point(x1, y1, z1), Point(x2, y2, z2), Point(x3, y3, z3));
            DrawTriangle(Point(x1, y1, z1), Point(x3, y3, z3), Point(x4, y4, z4));
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawHalfBall(Point center, float radius) {
    int stacks = 100;
	int slices = 20;
    for (int i = 0; i < stacks; i++) {
        float phi1 = 3.14 * static_cast<float>(i) / stacks;
        float phi2 = 3.14 * static_cast<float>(i + 1) / stacks;

        for (int j = 0; j < slices; j++) {
            float theta1 =  3.14 * static_cast<float>(j) / slices;
            float theta2 = 3.14 * static_cast<float>(j + 1) / slices;

            // Calculate vertices
            float x1 = center.getX() + radius * sin(phi1) * cos(theta1);
            float y1 = center.getY() + radius * sin(phi1) * sin(theta1);
            float z1 = center.getZ() + radius * cos(phi1);

            float x2 = center.getX() + radius * sin(phi1) * cos(theta2);
            float y2 = center.getY() + radius * sin(phi1) * sin(theta2);
            float z2 = center.getZ() + radius * cos(phi1);

            float x3 = center.getX() + radius * sin(phi2) * cos(theta2);
            float y3 = center.getY() + radius * sin(phi2) * sin(theta2);
            float z3 = center.getZ() + radius * cos(phi2);

            float x4 = center.getX() + radius * sin(phi2) * cos(theta1);
            float y4 = center.getY() + radius * sin(phi2) * sin(theta1);
            float z4 = center.getZ() + radius * cos(phi2);

            // Draw each triangle
            DrawTriangle(Point(x1, y1, z1), Point(x2, y2, z2), Point(x3, y3, z3));
            DrawTriangle(Point(x1, y1, z1), Point(x3, y3, z3), Point(x4, y4, z4));
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawCircleWithHeight(Point center, float radius, float height) {
	int segments = 1500;
    glBegin(GL_LINES);
    for (int i = 0; i < segments; ++i) {
        float angle1 = 2.0f * 3.14 * i / segments;
        float angle2 = 2.0f * 3.14 * (i + 1) / segments;

        // Calculate the points on the two circles
        float x1 = center.getX() + radius * cos(angle1);
        float y1 = center.getY() ;
        float z1 = center.getZ()+ radius * sin(angle1);
        float x2 = center.getX() + radius * cos(angle2);
        float y2 = center.getY() + height;
        float z2 = center.getZ() + radius * sin(angle2); // Increase the y-coordinate

        // Draw lines connecting the two circles
        glVertex3f(x1, y1, z1);  // Swap y and z coordinates
        glVertex3f(x2, y2, z2);  // Swap y and z coordinates
    }
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawParallel(Point center, float lenght , float width , float height, GLuint frontTexture, GLuint sidesTextures){
    Point p1 = Point (center.x , center.y , center.z );
	Point p2 = Point (center.x + lenght , center.y, center.z);
	Point p3 = Point (center.x + lenght , center.y + width, center.z);
	Point p4 = Point(center.x , center.y + width, center.z);
	Point p5 = Point (center.x, center.y , center.z +height);
	Point p6 = Point (center.x + lenght , center.y, center.z+height);
	Point p7 = Point (center.x + lenght , center.y + width , center.z +height);
	Point p8 = Point (center.x , center.y +width , center.z +height);
	 
	//front
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, frontTexture);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p1.x,p1.y,p1.z);
				glTexCoord2f(1, 0);       glVertex3f(p2.x,p2.y,p2.z );
				glTexCoord2f(1, 1);       glVertex3f(p3.x,p3.y,p3.z);
				glTexCoord2f(0, 1);       glVertex3f(p4.x,p4.y,p4.z);
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//back
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sidesTextures);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p5.x,p5.y,p5.z);
				glTexCoord2f(1, 0);       glVertex3f(p6.x,p6.y,p6.z );
				glTexCoord2f(1, 1);       glVertex3f(p7.x,p7.y,p7.z);
				glTexCoord2f(0, 1);       glVertex3f(p8.x,p8.y,p8.z);
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//bottom
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sidesTextures);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p1.x,p1.y,p1.z);
				glTexCoord2f(1, 0);       glVertex3f(p2.x,p2.y,p2.z );
				glTexCoord2f(1, 1);       glVertex3f(p6.x,p6.y,p6.z);
				glTexCoord2f(0, 1);       glVertex3f(p5.x,p5.y,p5.z);
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//roof
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sidesTextures);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p4.x,p4.y,p4.z);
				glTexCoord2f(1, 0);       glVertex3f(p3.x,p3.y,p3.z );
				glTexCoord2f(1, 1);       glVertex3f(p7.x,p7.y,p7.z);
				glTexCoord2f(0, 1);       glVertex3f(p8.x,p8.y,p8.z);
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//right
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sidesTextures);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p2.x,p2.y,p2.z);
				glTexCoord2f(1, 0);       glVertex3f(p6.x,p6.y,p6.z );
				glTexCoord2f(1, 1);       glVertex3f(p7.x,p7.y,p7.z);
				glTexCoord2f(0, 1);       glVertex3f(p3.x,p3.y,p3.z);
			glEnd();
	glDisable(GL_TEXTURE_2D);

	//left
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sidesTextures);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);       glVertex3f(p1.x,p1.y,p1.z);
				glTexCoord2f(0, 1);       glVertex3f(p4.x,p4.y,p4.z );
				glTexCoord2f(1, 1);       glVertex3f(p8.x,p8.y,p8.z);
				glTexCoord2f(1, 0);       glVertex3f(p5.x,p5.y,p5.z);
			glEnd();
	glDisable(GL_TEXTURE_2D);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawCylinderHorizontally(Point center, float radius, float height) {
	int segments = 100;
    const float PI = 3.14159265358979323846f;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float theta = (2.0f * PI * i) / segments;
        float y = center.y + radius * cos(theta);
        float z = center.z + radius * sin(theta);

        // Bottom point
        glVertex3f(center.x - height / 2.0f, y, z);

        // Top point
        glVertex3f(center.x + height / 2.0f, y, z);
    }
    glEnd();

    // Draw the bottom and top circles
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center.x - height / 2.0f, center.y, center.z); // Bottom center
    for (int i = 0; i <= segments; ++i) {
        float theta = (2.0f * PI * i) / segments;
        float y = center.y + radius * cos(theta);
        float z = center.z + radius * sin(theta);
        glVertex3f(center.x - height / 2.0f, y, z);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center.x + height / 2.0f, center.y, center.z); // Top center
    for (int i = 0; i <= segments; ++i) {
        float theta = (2.0f * PI * i) / segments;
        float y = center.y + radius * cos(theta);
        float z = center.z + radius * sin(theta);
        glVertex3f(center.x + height / 2.0f, y, z);
    }
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawCylinderVerically(Point center, float radius, float height) {
	int segments = 30;
    const float PI = 3.14159265358979323846f;

     glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float theta = (2.0f * PI * i) / segments;
        float x = center.x + radius * cos(theta);
        float z = center.z + radius * sin(theta);

        // Bottom point
        glVertex3f(x, center.y - height / 2.0f, z);

        // Top point
        glVertex3f(x, center.y + height / 2.0f, z);
    }
    glEnd();

    // Draw the bottom and top circles
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center.x, center.y - height / 2.0f, center.z); // Bottom center
    for (int i = 0; i <= segments; ++i) {
        float theta = (2.0f * PI * i) / segments;
        float x = center.x + radius * cos(theta);
        float z = center.z + radius * sin(theta);
        glVertex3f(x, center.y - height / 2.0f, z);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center.x, center.y + height / 2.0f, center.z); // Top center
    for (int i = 0; i <= segments; ++i) {
        float theta = (2.0f * PI * i) / segments;
        float x = center.x + radius * cos(theta);
        float z = center.z + radius * sin(theta);
        glVertex3f(x, center.y + height / 2.0f, z);
    }
    glEnd();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveDrawer::DrawCylinderWithTexture(Point center, float radius, float widthMultiplier, GLuint texture) {
     const int segments = 30;

    glColor3f(1, 1, 1);  // Set color to white

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * (2.0f * 3.14159265358979323846 / segments);
        float x = center.x + radius * cos(angle);
        float z = center.z + radius * sin(angle);

        float u = i / static_cast<float>(segments/10);  // Scale u based on the segment index

        glTexCoord2f(u, 0.0);
        glVertex3f(x, center.y, z);  // Bottom point

        glTexCoord2f(u, 1.0);
        glVertex3f(x, center.y + widthMultiplier, z);  // Top point
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrimitiveDrawer::DrawUpperHalfBallWithTexture(Point center, float radius, GLuint texture) {
    const int slices = 30;
    const int stacks = 30; // Adjust this value for the desired resolution

    glColor3f(1, 1, 1);  // Set color to white

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    for (int i = stacks / 2; i <= stacks; ++i) {
        float theta1 = (i * 3.14159265358979323846 / stacks) - (3.14159265358979323846 / 2);
        float theta2 = ((i + 1) * 3.14159265358979323846 / stacks) - (3.14159265358979323846 / 2);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float phi = j * (2.0f * 3.14159265358979323846 / slices);

            float x1 = center.x + radius * cos(theta1) * cos(phi);
            float y1 = center.y + radius * sin(theta1);
            float z1 = center.z + radius * cos(theta1) * sin(phi);

            float x2 = center.x + radius * cos(theta2) * cos(phi);
            float y2 = center.y + radius * sin(theta2);
            float z2 = center.z + radius * cos(theta2) * sin(phi);

            float u = static_cast<float>(j) / slices*2;
            float v1 = static_cast<float>(i) / stacks*2;
            float v2 = static_cast<float>(i + 1) / stacks*2;

            glTexCoord2f(u, v1);
            glVertex3f(x1, y1, z1);

            glTexCoord2f(u, v2);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }

    // Draw a circle at the bottom
	glPushMatrix();
	glTranslatef(center.x, center.y, center.z);  // Translate to the center
    glRotatef(90, 1, 0, 0);    // Rotate around the X-axis
    glTranslatef(-center.x, -center.y, -center.z);  // Translate back to the original position

	DrawFilledCircle(center , radius);
	glPopMatrix();


    glDisable(GL_TEXTURE_2D);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrimitiveDrawer::DrawCylinder(Point p,float radius, float height, int slices,int index){
  
    glPushMatrix();
    glTranslated(p.x,p.y,p.z);

    float angleStep = (2.0f * M_PI) / slices;
  
    //// Draw the top circle
    //glBegin(GL_TRIANGLE_FAN);
    //glVertex3f(0.0f, height, 0.0f); // center point
    //for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
    //    glVertex3f(radius * cosf(angle), height, radius * sinf(angle));
    //}
    //glEnd();
  

    //// Draw the bottom circle
    //glBegin(GL_TRIANGLE_FAN);
    //glVertex3f(0.0f, 0.0f, 0.0f); // center point
    //for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
    //    glVertex3f(radius * cosf(angle), 0.0f, radius * sinf(angle));
    //}
    //glEnd();
      
    if(index!=-1){
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, index);
      int cnt=0;
      // Draw the side
      glBegin(GL_QUAD_STRIP);
      for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {

        if(cnt%2==0){
      
          glTexCoord2f(1.0f, 1.0f); glVertex3f(radius * cosf(angle), height, radius * sinf(angle));
          glTexCoord2f(0.0f, 1.0f); glVertex3f(radius * cosf(angle), 0.0f, radius * sinf(angle));
      
        }
        else {
          glTexCoord2f(1.0f, 0.0f); glVertex3f(radius * cosf(angle), height, radius * sinf(angle));
          glTexCoord2f(0.0f, 0.0f); glVertex3f(radius * cosf(angle), 0.0f, radius * sinf(angle));
        }
        cnt++;
      }

      // Connect the last to the first
      glTexCoord2f(1.0f, 1.0f); glVertex3f(radius, height, 0.0f);
      glTexCoord2f(0.0f, 1.0f); glVertex3f(radius, 0.0f, 0.0f);
      glEnd();
      glDisable(GL_TEXTURE_2D);
    }
    else{
      glBegin(GL_QUAD_STRIP);
      for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
        glVertex3f(radius * cosf(angle), height, radius * sinf(angle));
        glVertex3f(radius * cosf(angle), 0.0f, radius * sinf(angle));
      
      }
      // Connect the last to the first
      glVertex3f(radius, height, 0.0f);
      glVertex3f(radius, 0.0f, 0.0f);
      glEnd();
    }
    glPopMatrix();
  
  }
//////////////////////////////////////////////////////////////
void PrimitiveDrawer::DrawCylinder3(Point p,float r1,float r2, float height, int slices,int index){
  
  glPushMatrix();
  glTranslated(p.x,p.y,p.z);

    float angleStep = (2.0f * M_PI) / slices;
      
  if(index!=-1){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index);
    int cnt=0;
    // Draw the side
    glBegin(GL_QUAD_STRIP);
    for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {

      if(cnt%2==0){
      
        glTexCoord2f(1.0f, 1.0f); glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
        glTexCoord2f(0.0f, 1.0f); glVertex3f(r1 * cosf(angle), 0.0f, r1 * sinf(angle));
      
      }
      else {
        glTexCoord2f(1.0f, 0.0f); glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
        glTexCoord2f(0.0f, 0.0f); glVertex3f(r1 * cosf(angle), 0.0f, r1 * sinf(angle));
      }
      cnt++;
    }

    // Connect the last to the first
    glTexCoord2f(1.0f, 1.0f); glVertex3f(r2, height, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(r1, 0.0f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
  }
  else{
    glBegin(GL_QUAD_STRIP);
    for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
      glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
      glVertex3f(r1 * cosf(angle), 0.0f, r1 * sinf(angle));
      
    }
    // Connect the last to the first
    glVertex3f(r2, height, 0.0f);
    glVertex3f(r1, 0.0f, 0.0f);
    glEnd();
  }
  glPopMatrix();
  
  }

///////////////////////////
void PrimitiveDrawer::DrawQuadMain(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
}
/////////////////

	void PrimitiveDrawer::Draw8(Point p,double l,double h,int ind){
		Point p1=Point(p.x,p.y,p.z);
		Point p2=Point(p.x-l,p.y,p.z);
		Point p3=Point(p.x-l,p.y+h,p.z);
		Point p4=Point(p.x,p.y+h,p.z);
		DrawQuad(p1,p2,p3,p4,ind);
		Point p5=Point(p.x+l/2,p.y,p.z+l/2);
		Point p6=Point(p.x+l/2,p.y+h,p.z+l/2);
		DrawQuad(p1,p5,p6,p4,ind);
		Point p7=Point(p.x-l-0.5,p.y,p.z+l/2);
		Point p8=Point(p.x-l-0.5,p.y+h,p.z+l/2);
		DrawQuad(p2,p7,p8,p3,ind);
		Point p9=Point(p.x-l-0.5,p.y,p.z+l+0.5);
		Point p10=Point(p.x-l-0.5,p.y+h,p.z+l+0.5);
		DrawQuad(p7,p9,p10,p8,ind);
		Point p11=Point(p.x+l/2,p.y+h,p.z+l+0.5);
		Point p12=Point(p.x+l/2,p.y,p.z+l+0.5);
		DrawQuad(p5,p6,p11,p12,ind);
		Point p13=Point(p.x-l,p.y,p.z+l+1);
		Point p14=Point(p.x-l,p.y+h,p.z+l+1);
		DrawQuad(p9,p13,p14,p10,ind);
		Point p15=Point(p.x,p.y,p.z+l+1);
		Point p16=Point(p.x,p.y+h,p.z+l+1);
		DrawQuad(p12,p15,p16,p11,ind);
		DrawQuad(p15,p13,p14,p16,ind);
		
		//top
		DrawQuad(p3,p4,p6,p8,ind);
		DrawQuad(p6,p8,p10,p11,ind);
		DrawQuad(p10,p11,p16,p14,ind);
		//down
		DrawQuad(p1,p2,p7,p5,ind);
		DrawQuad(p7,p5,p12,p9,ind);
		DrawQuad(p12,p9,p13,p15,ind);

	}

	// added fom masa

 void PrimitiveDrawer::DrawReq(Point p,double a,double b,int dir,int ind) {
	 if(dir==1)
		 DrawQuad(p,Point(p.x, p.y + b, p.z),Point(p.x , p.y + b, p.z + a),Point(p.x , p.y, p.z + a),ind);
	 else if(dir==0)
		DrawQuad(p,Point(p.x, p.y + b, p.z),Point(p.x + a, p.y + b, p.z),Point(p.x + a, p.y, p.z),ind);
	 else
		DrawQuad(p,Point(p.x + a, p.y, p.z),Point(p.x + a, p.y, p.z+b),Point(p.x, p.y, p.z + b),ind);
  }


	  void PrimitiveDrawer::DrawCubeCenter(Point s, double l, double w, double h, int index) {
		double l1 = l/2;
		double w1 = w/2;
		Point A = Point(s.x - l1, s.y , s.z - w1);
		Point B = Point(s.x + l1, s.y, s.z - w1);
		Point C = Point(s.x + l1, s.y, s.z + w1);
		Point D = Point(s.x - l1, s.y, s.z + w1);
		Point E = Point(s.x - l1, s.y + h, s.z-w1);
		Point F = Point(s.x + l1, s.y + h, s.z-w1);
		Point H = Point(s.x - l1, s.y + h, s.z + w1);
		Point G = Point(s.x + l1, s.y + h, s.z + w1);
		DrawQuad(A,B,C,D,index);
		DrawQuad(E,F,G,H,index);
		DrawQuad(A,D,H,E,index);
		DrawQuad(B,C,G,F,index);
		DrawQuad(A,B,F,E,index);
		DrawQuad(D,C,G,H,index);
  }

	
	void PrimitiveDrawer::DrawCylinder2(Point p,float r1,float r2, float height, int slices,int index){
	
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);

    float angleStep = (2.0f * M_PI) / slices;
			
	if(index!=-1){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, index);
		int cnt=0;
		// Draw the side
		glBegin(GL_QUAD_STRIP);
		for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {

			if(cnt%2==0){
			
				glTexCoord2f(1.0f, 1.0f); glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
				glTexCoord2f(0.0f, 1.0f); glVertex3f(r1 * cosf(angle), 0.0f, r1 * sinf(angle));
			
			}
			else {
				glTexCoord2f(1.0f, 0.0f); glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
				glTexCoord2f(0.0f, 0.0f); glVertex3f(r1 * cosf(angle), 0.0f, r1 * sinf(angle));
			}
			cnt++;
		}

		// Connect the last to the first
		glTexCoord2f(1.0f, 1.0f); glVertex3f(r2, height, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(r1, 0.0f, 0.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else{
		glBegin(GL_QUAD_STRIP);
		for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
			glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
			glVertex3f(r1 * cosf(angle), 0.0f, r1 * sinf(angle));
			
		}
		// Connect the last to the first
		glVertex3f(r2, height, 0.0f);
		glVertex3f(r1, 0.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();
	
	}

	void PrimitiveDrawer::DrawCell(Point p,float r,float slices,float height,int index){
		
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	//glRotated(90,1,0,0);
    float angleStep = (2.0f * M_PI) / slices;			
	if(index!=-1){
		for (float angle = 0.0f; angle <= M_PI; angle += angleStep) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, index);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(r * cosf(angle-angleStep), 0, r * sinf(angle-angleStep));
			glTexCoord2f(0.0f, 1.0f); glVertex3f(r * cosf(angle-angleStep), height, r * sinf(angle-angleStep));
			glTexCoord2f(0.0f, 0.0f); glVertex3f(r * cosf(angle), height, r * sinf(angle));
			glTexCoord2f(1.0f, 0.0f); glVertex3f(r * cosf(angle), 0, r * sinf(angle));
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}

	}
	else{
		glBegin(GL_QUAD_STRIP);
		for (float angle = 0.0f; angle <=  M_PI; angle += angleStep) {
			glVertex3f(r * cosf(angle), height, r * sinf(angle));
			glVertex3f(r * cosf(angle), 0.0f, r * sinf(angle));
			
		}
		glEnd();
	}
	glPopMatrix();
	
	}

	void PrimitiveDrawer::DrawWhat(Point p,float r1,float r2,float slices,float height,int index){	
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	//glRotated(90,1,0,0);
    float angleStep = (2.0f * M_PI) / slices;
			
	if(index!=-1){		
		for (float angle = 0.0f; angle <= M_PI; angle += angleStep) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, index);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(r1 * cosf(angle-angleStep), height, r1 * sinf(angle-angleStep));
			glTexCoord2f(0.0f, 1.0f); glVertex3f(r2 * cosf(angle-angleStep), height, r2 * sinf(angle-angleStep));
			glTexCoord2f(0.0f, 0.0f); glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
			glTexCoord2f(1.0f, 0.0f); glVertex3f(r1 * cosf(angle), height, r1 * sinf(angle));
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		
	}
	else{
		glBegin(GL_QUAD_STRIP);
		for (float angle = 0.0f; angle <=  M_PI; angle += angleStep) {
			glVertex3f(r1 * cosf(angle), height, r1 * sinf(angle));
			glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
			
		}
		glEnd();
	}
	glPopMatrix();
	
	}


	void PrimitiveDrawer::DrawArch(Point p,float r1,float r2,float slices,float height,int index1,int index2){
		DrawCell(p,r1,slices,height,index1);
		DrawCell(p,r2,slices,height,index1);
		DrawWhat(p,r1,r2,slices,0,index2);
		DrawWhat(p,r1,r2,slices,+height,index2);
	}
	void PrimitiveDrawer::DrawCircle(Point p,float r){
		//9
		int slices=20;
		float height=0;
		glPushMatrix();
		glTranslated(p.x,p.y,p.z);

		float angleStep = (2.0f * M_PI) / slices;


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 9);
		glBegin(GL_TRIANGLE_FAN);

		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, height, 0.0f); // center point
		int cnt=1;
		for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
		    if(cnt%3==0) glTexCoord2f(1.0f, 0.0f);
			else if(cnt%3==1) glTexCoord2f(1.0f, 1.0f);
			else glTexCoord2f(0.0f, 0.0f);
			cnt++;
			glVertex3f(r * cosf(angle), height, r * sinf(angle));
		}
		glTexCoord2f(0.0f,0.0f); glVertex3f(r, height, 0.0f);
		glEnd();
		glEnable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void PrimitiveDrawer::DrawBall2(Point p,GLfloat r,float h,int index){
		float r1=r,r2=r,decrease=0.2,slices=20,cnt=h;
		glPushMatrix();
		glTranslated(p.x,p.y,p.z);
		DrawCylinder2(Point(0,0,0),r2,r1,h,slices,index);
		r1-=decrease;
		while(r1>=0){
			DrawCylinder2(Point(0,cnt,0),r2,r1,h,slices,index);
			DrawCylinder2(Point(0,-cnt,0),r1,r2,h,slices,index);
			r2-=decrease;
			if(r1>2*r/3 )decrease+=0.2;
			else decrease+=0.1;
			r1-=decrease;
			cnt+=h;
		}
		glPopMatrix();
	}

	void PrimitiveDrawer::DrawDoom(Point p,float r,float h,float decrease,int slices,int index){
		float r1=r,r2=r,cnt=h;
		glPushMatrix();
		glTranslated(p.x,p.y,p.z);
		DrawCylinder2(Point(0,0,0),r2,r1,h,slices,index);
		r1-=decrease;
		while(r1>=0){
			DrawCylinder2(Point(0,cnt,0),r2,r1,h,slices,index);
			r2-=decrease;
			decrease+=0.2;
			
			r1-=decrease;
			cnt+=h;
		}
		glPopMatrix();
	}
	////////////////////////////////////
	void PrimitiveDrawer::DrawFlat(Point center, GLdouble w, GLdouble h, int texture){
  glPushMatrix();
  glTranslated(center.x,center.y,center.z);
  Point A = Point(-w,0,h);
  Point B = Point(w,0,h);
  Point C = Point(w,0,-h);
  Point D = Point(-w,0,-h);
  PrimitiveDrawer::DrawQuad3(A,B,C,D,texture,1,1);
  glPopMatrix();
}
	//////////////////////////
	void PrimitiveDrawer::DrawQuad3(Point v1, Point v2, Point v3, Point v4,int texture, double w, double h) {
  glBindTexture(GL_TEXTURE_2D,texture);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glBegin(GL_QUADS);
  glTexCoord2d(0,0);
    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2d(w,0);
    glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2d(w,h);
    glVertex3f(v3.x, v3.y, v3.z);
  glTexCoord2d(0,h);
    glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }
void PrimitiveDrawer::DrawCubeCenter2(Point s, double l, double w, double h, int texture[],double w2, double h2)
{
		double l1 = l/2;
		double w1 = w/2;
		Point A = Point(s.x - l1, s.y , s.z - w1);
		Point B = Point(s.x + l1, s.y, s.z - w1);
		Point C = Point(s.x + l1, s.y, s.z + w1);
		Point D = Point(s.x - l1, s.y, s.z + w1);
		Point E = Point(s.x - l1, s.y + h, s.z-w1);
		Point F = Point(s.x + l1, s.y + h, s.z-w1);
		Point H = Point(s.x - l1, s.y + h, s.z + w1);
		Point G = Point(s.x + l1, s.y + h, s.z + w1);
		PrimitiveDrawer::DrawQuad(A,B,C,D,texture[0]);
		PrimitiveDrawer::DrawQuad(E,F,G,H,texture[1]);
		PrimitiveDrawer::DrawQuad(A,D,H,E,texture[2]);
		PrimitiveDrawer::DrawQuad(B,C,G,F,texture[3]);
		PrimitiveDrawer::DrawQuad(A,B,F,E,texture[4]);
		PrimitiveDrawer::DrawQuad(D,C,G,H,texture[5]);

}
	///////////////////////////////////
	void PrimitiveDrawer::DrawCube2(Point start, GLdouble w, GLdouble h, GLdouble d,int texture[],double w2, double h2){
    Point B = Point(start.x, start.y,start.z-d);
    Point C = Point(start.x+w,start.y,start.z-d);
    Point D = Point(start.x+w,start.y,start.z);
    Point E = Point(start.x,start.y+h,start.z);
    Point F = Point(start.x,start.y+h,start.z-d);
    Point G = Point(start.x+w,start.y+h,start.z-d);
    Point H = Point(start.x+w,start.y+h,start.z);
    PrimitiveDrawer::DrawQuad(C,B,F,G,texture[0]);// back face
    PrimitiveDrawer::DrawQuad(start,D,H,E,texture[1]); // forward face
    PrimitiveDrawer::DrawQuad(start,D,C,B,texture[2]); // down face
    PrimitiveDrawer::DrawQuad(E,H,G,F,texture[3]); // up face
    PrimitiveDrawer::DrawQuad(D,C,G,H,texture[4]); // right face
    PrimitiveDrawer::DrawQuad(B,start,E,F,texture[5]); // left face
  }

	///////////
		void PrimitiveDrawer::DrawWhat2(Point p,float r1,float r2,float slices,float height,int index){	
	glPushMatrix();
	glTranslated(p.x,p.y,p.z);
	//glRotated(90,1,0,0);
    float angleStep = (2.0f * M_PI) / slices;
			
	if(index!=-1){		
		for (float angle = 0.0f; angle <= 2 * M_PI; angle += angleStep) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, index);
			glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(r1 * cosf(angle-angleStep), height, r1 * sinf(angle-angleStep));
			glTexCoord2f(0.0f, 1.0f); glVertex3f(r2 * cosf(angle-angleStep), height, r2 * sinf(angle-angleStep));
			glTexCoord2f(0.0f, 0.0f); glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
			glTexCoord2f(1.0f, 0.0f); glVertex3f(r1 * cosf(angle), height, r1 * sinf(angle));
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		
	}
	else{
		glBegin(GL_QUAD_STRIP);
		for (float angle = 0.0f; angle <=  M_PI; angle += angleStep) {
			glVertex3f(r1 * cosf(angle), height, r1 * sinf(angle));
			glVertex3f(r2 * cosf(angle), height, r2 * sinf(angle));
			
		}
		glEnd();
	}
	glPopMatrix();
	
	}


		void PrimitiveDrawer ::DrawCubeCenterimg(Point v1,double high, double length,double width, int img){
  
  double half_length = length/2;
  double half_width = width/2;
  double half_high = high/2;
  Point bottom_left = Point(v1.x-half_length,v1.y,v1.z+half_width);
  Point bottom_right=Point(v1.x+half_length,v1.y,v1.z+half_width);
  Point Top_right = Point (v1.x+half_length,v1.y+high,v1.z+half_width);
  Point Top_left =Point(v1.x-half_length,v1.y+high, v1.z+half_width);

  Point bottom_left_behind =Point (v1.x-half_length,v1.y,v1.z-half_width);
  Point bottom_right_behind= Point(v1.x+half_length,v1.y,v1.z-half_width);
  Point Top_right_behind =Point(v1.x+half_length,v1.y+high,v1.z-half_width);
  Point Top_left_behind =Point(v1.x-half_length,v1.y+high,v1.z-half_width);

  DrawQuad(bottom_left,bottom_right,Top_right,Top_left,img);


  

  DrawQuad( bottom_left_behind ,bottom_right_behind,Top_right_behind, Top_left_behind, img);//back
  
  DrawQuad(bottom_left,bottom_left_behind,Top_left_behind,Top_left,img);//leftside

  DrawQuad(bottom_right,bottom_right_behind,Top_right_behind,Top_right,img);//rightside
  
  DrawQuad(Top_left,Top_right,Top_right_behind,Top_left_behind, img);//top
  
  DrawQuad(bottom_left,bottom_right,bottom_right_behind,bottom_left_behind,img);//bottom
}





		 void PrimitiveDrawer::makeBaseWithColomn(Point p,float r,float h ,int slices,int index,int doomSelsleh2){
		glPushMatrix();
		glTranslated(p.x,p.y,p.z);

		Colomn c=Colomn();
		float angleStep = (2.0f * M_PI) / slices;
			for (float angle = 0.0f; angle <= 2.0f * M_PI; angle += angleStep) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, index);
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(r * cosf(angle-angleStep), 0.2, r * sinf(angle-angleStep));
				glTexCoord2f(0.0f, 1.0f); glVertex3f(r * cosf(angle-angleStep), 0.0f, r * sinf(angle-angleStep));
				glTexCoord2f(0.0f, 0.0f); glVertex3f(r * cosf(angle), 0.0f, r * sinf(angle));
				glTexCoord2f(1.0f, 0.0f); glVertex3f(r * cosf(angle), 0.3 , r * sinf(angle));
				glEnd();
				glDisable(GL_TEXTURE_2D);

				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, doomSelsleh2);
				glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(r * cosf(angle-angleStep), h-3 , r * sinf(angle-angleStep));
				glTexCoord2f(0.0f, 1.0f); glVertex3f(r * cosf(angle-angleStep), h, r * sinf(angle-angleStep));
				glTexCoord2f(0.0f, 0.0f); glVertex3f(r * cosf(angle), h, r * sinf(angle));
				glTexCoord2f(1.0f, 0.0f); glVertex3f(r * cosf(angle), h-3 , r * sinf(angle));
				glEnd();
				glDisable(GL_TEXTURE_2D);
				c.newColomn(Point(r * cosf(angle), 0.0f, r * sinf(angle)),0.5,h-1.3,index,index);
				//DrawCylinder(Point(r * cosf(angle), 0.0f, r * sinf(angle)),0.3,0.3,h,10,index);
			}
		
		glPopMatrix();
	
	}

