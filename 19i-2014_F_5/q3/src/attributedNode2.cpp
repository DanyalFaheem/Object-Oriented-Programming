/*
 * attributedNode2.cpp
 *
 *  Created on: Apr 17, 2020
 *      Author: danyal-faheem
 */

#include "attributedNode2.h"
#include<iostream>
#include<string>
using namespace std;

attributedNode2::attributedNode2(){
	profession = location = " ";
	cout << "AttributedNode2 Object created through default constructor\n";
}

attributedNode2::attributedNode2(string p, string l){
	profession = p;
	location = l;
	cout << "AttributedNode2 Object created through paramterized constructor\n";
}

string attributedNode2::getprof(){
	return profession;
}

string attributedNode2::getloc(){
	return location;
}

void attributedNode2::setprof(string p){
	profession = p;
}

void attributedNode2::setloc(string l){
	location = l;
}

attributedNode2::~attributedNode2(){
	cout << "AttribuedNode2 object destructor called\n";
}
