/*
 * attributedNode2.h
 *
 *  Created on: Apr 17, 2020
 *      Author: danyal-faheem
 */

#ifndef ATTRIBUTEDNODE2_H_
#define ATTRIBUTEDNODE2_H_
#include<iostream>
#include<string>
using namespace std;
class attributedNode2 {
private:
	string profession,location;
public:
	attributedNode2();
	attributedNode2(string, string);
	string getprof();
	string getloc();
	void setprof(string p);
	void setloc(string l);
	virtual ~attributedNode2();
};

#endif /* ATTRIBUTEDNODE2_H_ */
