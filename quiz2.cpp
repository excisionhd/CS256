#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;

class Circle {
private:

	float radius;
	float pi = 3.14159;

public:

	Circle() {
		radius = 0;
	}

	Circle(float r) {
		radius = r;
	}

	void setRadius(float r) { radius = r; }

	float getRadius() {
		return radius;
	}
	float getArea() {
		return pi * radius*radius;
	}
	float getDiameter() {
		return radius * 2;
	}
	float getCircumference() {
		return 2 * pi * radius;
	}

};



int main() {
	float input;
	cout << "Enter radius of the circle:" << endl;
	cin >> input;
	Circle c1(input);

	cout << "Area: " << c1.getArea() << endl;
	cout << "Diameter: " << c1.getDiameter() << endl;
	cout << "Circumference: " << c1.getCircumference() << endl;


	return 0;

}
