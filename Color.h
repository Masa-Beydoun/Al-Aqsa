#ifndef COLOR_H
#define COLOR_H

class Color {
public:
	Color(double r, double g, double b);
	double getR();
	double getG();
	double getB();
	void setR(double r);
	void setG(double g);
	void setB(double b);
	double r;
	double g;
	double b;
};

#endif
