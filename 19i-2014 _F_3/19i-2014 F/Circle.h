/*
 * Circle.h
 *
 *  Created on: Mar 3, 2020
 *      Author: root
 */
#include<iostream>
using namespace std;
#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
private:
	int x;
	int y;
	int radius;
public:
	Circle();// default constructor
	Circle(int x, int y);
	Circle(int x, int y, int radius);//you have to implement the following functions
	// think about the parameters required and return type of the following functions
	void setCenter(int,int);//set center of a circle
	void setRadius(int);//set radius of a circle
	double getArea();//prints area of a circle
	Circle returnLargestCircle(Circle*&,int);//return the largest circle from the array of circles
	bool overlapping(Circle&);//determines of two circles are overlapping or not
	Circle* overlappingCircles(Circle*&, int);//returns an array of circles overlapping the largest circle
	~Circle();
};

#endif /* CIRCLE_H_ */
