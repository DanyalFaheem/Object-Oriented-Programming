/*
 * Circle.cpp
 *
 *  Created on: Mar 3, 2020
 *      Author: root
 */

#include "Circle.h"
#include<iostream>
using namespace std;
#define PI 3.14159265358979323846
Circle::Circle(){
	x=y=radius=0;
}
Circle::Circle(int x1, int y1){
	x=x1;
	y=y1;
	radius=0;
}
Circle::Circle(int x1, int y1, int r){
	x=x1;
	y=y1;
	radius=r;
}
void Circle::setCenter(int x1, int y1){
	x=x1;
	y=y1;
}
void Circle::setRadius(int r){
	radius=r;
}
double Circle::getArea(){
	double area=0.0;
	area=radius*radius;
	area=PI*area;
	return area;
}
Circle Circle::returnLargestCircle(Circle*& c,int size){
	int index=0;
	double max=0.0;
	for(int counter=0; counter<size; counter++){
		if((c[counter].getArea())>max){
			max=c[counter].getArea();
			index=counter;
		}
	}
	return c[index];
}
bool Circle::overlapping(Circle& c){
	if( x+radius < c.x-c.radius || x-radius < c.x+c.radius || y+radius < c.y-c.radius || y-radius < c.y+c.radius){
		return true;
	}
	else {
		return false;
	}
}
Circle* Circle::overlappingCircles(Circle*& c, int size){
	int c_count=0;
	Circle* overlap=new Circle[c_count];
	Circle largest=Circle::returnLargestCircle(c,size);
	for(int counter=0,index=0; counter<size; counter++){
		if(largest.overlapping(c[counter])==true){
			c_count++;
			overlap[index]=c[counter];
		}
	}
	return overlap;
}
Circle::~Circle(){}

