/*
 * attributedNode1.cpp
 *
 *  Created on: Apr 15, 2020
 *      Author: danyal-faheem
 */

#include "attributedNode1.h"
#include<iostream>
using namespace std;

attributedNode1::attributedNode1(){
	gender = 0;
	age = -1;
	cout << "attributedNode1 object created through default constructor\n";
}

attributedNode1::attributedNode1(char g, int a){
	gender = g;
	age = a;
	cout << "attributedNode1 object created through parameterized constructor\n";
}

int attributedNode1::getAge(){
	return age;
}

void attributedNode1::setAge(int a){
	age = a;
}

char attributedNode1::getGender(){
	return gender;
}

void attributedNode1::setGender(char g){
	gender = g;
}

attributedNode1::~attributedNode1(){
	cout << "attributedNode1 object destructor called\n";
}
