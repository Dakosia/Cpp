#pragma once
#include <string>
#include <iostream>
class Rectangle
{
private:
	float length;
	float width;
public:
	Rectangle();
	Rectangle(float, float);
	~Rectangle();

	float getLength();
	void setLength(float);
	float getWidth();
	void setWidth(float);
	double getArea();
	double getPerimeter();
	std::string toString();
};

