#include "Color.h"

Color::Color(double r, double g,double b) : r(r), g(g), b(b) {}

double Color::getR() { return r; }

double Color::getG() { return g; }

double Color::getB() { return b; }

void Color::setR(double x) { this->r = r; }

void Color::setG(double  y) { this->g = g; }

void Color::setB(double  z) { this->b = b; }
