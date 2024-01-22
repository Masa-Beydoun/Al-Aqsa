#include <windows.h>    // Header File For Windows
#include <gl.h>      // Header File For The OpenGL32 Library
#include <glu.h>      // Header File For The GLu32 Library
#include <glaux.h>    // Header File For The Glaux Library
#include <cmath>
#include "Point.h"
#include "Color.h"
#include "PrimitiveSoor.h"
#define M_PI 3.14159265358979323846

PrimitiveSoor::PrimitiveSoor(void)
{
}


PrimitiveSoor::~PrimitiveSoor(void)
{
}



  void PrimitiveSoor::DrawPoint(Point point) {
  glPointSize(10);
    glBegin(GL_POINTS);
  glVertex3f(point.x,point.y,point.z);
    glEnd();
  }
  void PrimitiveSoor::DrawLine(Point start, Point end) {
  glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
  }
  void PrimitiveSoor::DrawTriangle(Point v1, Point v2, Point v3, Color c = Color(0,0,0)) {
    glBegin(GL_TRIANGLES);
  glColor3ub(c.r,c.g,c.b);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
  }
 /* void PrimitiveSoor::DrawQuad1(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }*/
  void PrimitiveSoor::DrawQuad(Point v1, Point v2, Point v3, Point v4,int index,float a,float b) {
  if(index!=-1){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 255);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 255);
    glBegin(GL_QUADS);
    
    glVertex3f(v1.x, v1.y, v1.z);
  glTexCoord2f(0.0f, 0.0f);
    glVertex3f(v2.x, v2.y, v2.z);
  glTexCoord2f(a, 0.0f);
    glVertex3f(v3.x, v3.y, v3.z);
    glTexCoord2f(a, b);
    glVertex3f(v4.x, v4.y, v4.z);
    glTexCoord2f(0.0f, b);
    glEnd();
    glDisable(GL_TEXTURE_2D);
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
  void PrimitiveSoor::DrawQuadColor(Point v1, Point v2, Point v3, Point v4, Color c) {
    glBegin(GL_QUADS);
  glColor3ub(c.r,c.g,c.b);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }
  void PrimitiveSoor::DrawQuadCenter(Point v1, double l, double h, int index) {
      double l1 = l/2;
    double h1 = h/2;
    Point v2 = Point(v1.x -l1, v1.y , v1.z - h1);
    Point v3 = Point(v1.x + l1, v1.y, v1.z - h1);
    Point v4 = Point(v1.x + l1, v1.y, v1.z + h1);
    Point v5 = Point(v1.x - l1, v1.y, v1.z + h1);
    DrawQuad(v2,v3,v4,v5,index);
  }
  void PrimitiveSoor::DrawCube(Point s, double l, double w, double h, int index) {
    Point B = Point(s.x + l, s.y, s.z);
    Point C = Point(s.x + l, s.y, s.z + w);
    Point D = Point(s.x, s.y, s.z + w);

    Point E = Point(s.x, s.y + h, s.z);
    Point F = Point(s.x + l, s.y + h, s.z);
    Point H = Point(s.x, s.y + h, s.z + w);
    Point G = Point(s.x + l, s.y + h, s.z + w);
    DrawQuad(s,B,C,D,index);
    DrawQuad(E,F,G,H,index);
    DrawQuad(s,D,H,E,index);
    DrawQuad(B,C,G,F,index);
    DrawQuad(s,B,F,E,index);
    DrawQuad(D,C,G,H,index);
  }
  void PrimitiveSoor::DrawCubeCenter(Point s, double l, double w, double h, int index) {
    double l1 = l/2;
    double w1 = w/2;
    Point A = Point(s.x -l1, s.y , s.z - w1);
    Point B = Point(s.x + l1, s.y, s.z - w1);
    Point C = Point(s.x + l1, s.y, s.z + w1);
    Point D = Point(s.x - l1, s.y, s.z + w1);
	Point E = Point(s.x -l1, s.y + h, s.z-w1);
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
  void PrimitiveSoor::DrawPyramid(Point v1, Point v2, Point v3, Point v4, Point v5, Color c = Color(0,0,0)) {
    DrawTriangle(v1,v2,v3,c);
    DrawTriangle(v1,v3,v4,c);
    DrawTriangle(v1,v4,v5,c);
    DrawTriangle(v1,v5,v2,c);
  }
  void PrimitiveSoor::DrawHalfBall(Point center, float radius, int index) {
 //   int stacks = 100;
  //int slices = 20;
 //   for (int i = 0; i < stacks; i++) {
 //       float phi1 = 3.14 * static_cast<float>(i) / stacks;
 //       float phi2 = 3.14 * static_cast<float>(i + 1) / stacks;
 //       for (int j = 0; j < slices; j++) {
 //           float theta1 =  3.14 * static_cast<float>(j) / slices;
 //           float theta2 = 3.14 * static_cast<float>(j + 1) / slices;
 //           // Calculate vertices
 //           float x1 = center.getX() + radius * sin(phi1) * cos(theta1);
 //           float y1 = center.getY() + radius * sin(phi1) * sin(theta1);
 //           float z1 = center.getZ() + radius * cos(phi1);
 //           float x2 = center.getX() + radius * sin(phi1) * cos(theta2);
 //           float y2 = center.getY() + radius * sin(phi1) * sin(theta2);
 //           float z2 = center.getZ() + radius * cos(phi1);
 //           float x3 = center.getX() + radius * sin(phi2) * cos(theta2);
 //           float y3 = center.getY() + radius * sin(phi2) * sin(theta2);
 //           float z3 = center.getZ() + radius * cos(phi2);
 //           float x4 = center.getX() + radius * sin(phi2) * cos(theta1);
 //           float y4 = center.getY() + radius * sin(phi2) * sin(theta1);
 //           float z4 = center.getZ() + radius * cos(phi2);
 //           // Draw each triangle
 //           DrawTriangle(Point(x1, y1, z1), Point(x2, y2, z2), Point(x3, y3, z3));
 //           DrawTriangle(Point(x1, y1, z1), Point(x3, y3, z3), Point(x4, y4, z4));
 //       }
  //  void PrimitiveSoor::DrawUpperHalfBallWithTexture(Point center, float radius, GLuint texture) {
    const int slices = 10;
    const int stacks = 20; // Adjust this value for the desired resolution

    glColor3f(1, 1, 1);  // Set color to white

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, index);

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

  //DrawFilledCircle(center , radius);
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}
  void PrimitiveSoor::DrawCylinderVerically(Point center, float radius, float height) {
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
  void PrimitiveSoor::DrawCylinder2(Point p,float r1,float r2, float height, int slices,int index){
  
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
  void PrimitiveSoor::DrawCylinder(Point p,float radius, float height, int slices,int index){
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