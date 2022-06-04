/*
 * Polynomial.h
 *
 *  Created on: Mar 27, 2020
 *      Author: danyal-faheem
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include<iostream>
using namespace std;
class Polynomial {
private:
	int degree;
	int* arr;
public:
	Polynomial();
	Polynomial(int);
	Polynomial(const Polynomial&);
	void set(int,int);
	int get(int)const;
	int getD()const;
	Polynomial& operator =(const Polynomial&);
	Polynomial operator +(const Polynomial&);
	Polynomial operator -(const Polynomial&);
	bool operator ==(const Polynomial&);
	void operator +=(const Polynomial&);
	void operator -=(const Polynomial&);
	~Polynomial();
};
ostream& operator<<(ostream& input, const Polynomial&);
istream& operator>>(istream& ouput, Polynomial&);
#endif /* POLYNOMIAL_H_ */
