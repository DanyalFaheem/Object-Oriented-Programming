/*
 * attributedNode1.h
 *
 *  Created on: Apr 15, 2020
 *      Author: danyal-faheem
 */

#ifndef ATTRIBUTEDNODE1_H_
#define ATTRIBUTEDNODE1_H_
#include<iostream>
using namespace std;
class attributedNode1 {
private:
	char gender;
	int age;
public:
	attributedNode1();
	attributedNode1(char,int);
	char getGender();
	void setGender(char);
	int getAge();
	void setAge(int);
	~attributedNode1();
};

#endif /* ATTRIBUTEDNODE1_H_ */
