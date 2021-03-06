/*
 * Fraction.h
 *
 *  Created on: Mar 31, 2020
 *      Author: danyal-faheem
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include<iostream>
using namespace std;
class Fraction {
private:
	int numer,denom;
	Fraction* ptr;
public:
	Fraction();
	Fraction(int);
	Fraction(int,int);
	int getNumerator()const;
	int getDenominator()const;
	void display()const;
	void normalize();
	Fraction(const Fraction &other);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator*(int);
	Fraction operator/(const Fraction&);
	Fraction& operator=(const Fraction&);
	void operator+=(const Fraction&);
	void operator-=(const Fraction&);
	void operator*=(const Fraction&);
	void operator/=(const Fraction&);
	bool operator==(const Fraction&)const;
	bool operator!=(const Fraction&)const;
	bool operator<(const Fraction&)const;
	bool operator>(const Fraction&)const;
	bool operator<=(const Fraction&)const;
	bool operator>=(const Fraction&)const;
	int& operator[](const char);
	int& operator()(const char);
	Fraction* operator&();
	bool operator&&(const Fraction&)const;
	bool operator||(const Fraction&)const;
	Fraction operator++();
	Fraction operator--();
	Fraction* operator->();
	Fraction* operator->*(Fraction*);
};
ostream& operator<<(ostream& input, const Fraction&);
istream& operator>>(istream& ouput, Fraction&);
#endif /* FRACTION_H_ */
