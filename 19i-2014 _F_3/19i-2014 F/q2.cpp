/*
 * Q3.cpp
 *
 *  Created on: Mar 5, 2020
 *      Author: root
 */

#include"Circle.h"
#include<iostream>
using namespace std;
int main(){
	Circle c(5,5);
	c.setRadius(7);
	Circle c1(4,6,8);
	cout<<"Area of Circle c1 is" <<c1.getArea()<<endl;
	Circle* cptr=new Circle[5];
	for(int counter=0; counter<5; counter++){
		cptr[counter].setCenter(counter+1,counter+1);
		cptr[counter].setRadius(counter+2);
	}
	Circle large=c.returnLargestCircle(cptr,5);
	cout<<"Largest Circle has area "<<large.getArea()<<endl;
	if(c.overlapping(c1)==true){
		cout<<"Circle c1 is overlapping with c\n";
	}
	else{
		cout<<"Circle c1 is not overlapping with c\n";
	}
	return 0;

}


