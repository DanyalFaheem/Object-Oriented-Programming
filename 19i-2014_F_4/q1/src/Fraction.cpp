/*
 * Fraction.cpp
 *
 *  Created on: Mar 31, 2020
 *      Author: danyal-faheem
 */

#include "Fraction.h"
#include<iostream>
using namespace std;
Fraction::Fraction() {
	numer = 0;
	denom = 1;

}

Fraction::Fraction(int n){
	numer = n;
	denom = 1;
}

Fraction::Fraction(int n, int d){
	if(d == 0){
		cout << "\n!!!Denominator cannot be zero!!!\n";
		exit(0);
	}
	numer = n;
	denom = d;
	if(n < 0){
		n *= -1;
	}
	if(d < 0){
			d *= -1;
		}
	int divisor = 1;
	for(int counter = 2; counter < n or counter < d; counter++){
		if(n % counter == 0 and d % counter == 0){
			divisor = counter;
		}
	}
	if(n == d){
		numer = 1;
		denom = 1;
	}
	else{
		numer /= divisor;
		denom /= divisor;
	}
	if(denom < 0 and numer > 0){
		numer *= -1;
		denom *= -1;
	}
	if(denom < 0 and numer < 0){
		numer *= -1;
		denom *= -1;
	}
}

Fraction::Fraction(const Fraction &other) {
	numer = other.numer;
	denom = other.denom;
}

void Fraction::display()const{
	cout << numer << "/" << denom << endl;
}

int Fraction::getDenominator()const{
	return denom;
}

int Fraction::getNumerator()const{
	return numer;
}

void Fraction::normalize(){
	int divisor = 1;
	for(int counter = 2; counter < numer or counter < denom; counter++){
			if(numer % counter == 0 and denom % counter == 0){
				divisor = counter;
			}
		}
	if(numer == denom){
		numer = 1;
		denom = 1;
	}
	else{
		numer = numer/divisor;
		denom = denom/divisor;
	}
	if(denom < 0 and numer > 0){
			numer *= -1;
			denom *= -1;
		}
		if(denom < 0 and numer < 0){
			numer *= -1;
			denom *= -1;
		}
}

Fraction Fraction::operator +(const Fraction& other){
	Fraction answer;
	int common = 1;
	if(denom != other.denom){
		if(denom < other.denom){
	for(int counter = denom;;counter++){
		//cout << counter << endl;
		if(counter % denom == 0 and counter % other.denom == 0){
			common = counter;
			break;
		}
	}
	}
		if(denom > other.denom){
		for(int counter = other.denom;;counter++){
			if(counter % denom == 0 and counter % other.denom == 0){
				common = counter;
				break;
			}
		}
		}
		answer.denom = common;
		answer.numer = ((common/denom)*numer) + ((common/other.denom)*other.numer);
		answer.normalize();
		return answer;
	}
	answer.denom = denom;
	answer.numer = numer + other.numer;
	answer.normalize();
	return answer;
}

Fraction Fraction::operator -(const Fraction& other){
	Fraction answer;
	int common = 1;
	if(denom != other.denom){
		if(denom < other.denom){
	for(int counter = denom;;counter++){
		if(counter % denom == 0 and counter % other.denom == 0){
			common = counter;
			break;
		}
	}
	}
		if(denom > other.denom){
		for(int counter = other.denom;;counter++){
			if(counter % denom == 0 and counter % other.denom == 0){
				common = counter;
				break;
			}
		}
		}
		answer.denom = common;
		answer.numer = ((common/denom)*numer) - ((common/other.denom)*other.numer);
		answer.normalize();
		return answer;
	}
	answer.denom = denom;
	answer.numer = numer - other.numer;
	answer.normalize();
	return answer;
}

Fraction Fraction::operator *(const Fraction& f){
	Fraction Answer(numer*f.numer, denom*f.denom);
	Answer.normalize();
	return Answer;
}

Fraction Fraction::operator *(int f){
	Fraction Answer(numer*f, denom*f);
	Answer.normalize();
	return Answer;
}

Fraction Fraction::operator /(const Fraction& f){
	Fraction Answer(numer*f.denom, denom*f.numer);
	Answer.normalize();
	return Answer;
}

Fraction& Fraction::operator =(const Fraction& f){
	this->denom = f.denom;
	this->numer = f.numer;
	return *this;
}

void Fraction::operator +=(const Fraction& f){
	*this = *this + f;
	this->normalize();
}

void Fraction::operator -=(const Fraction& f){
	*this = *this - f;
	this->normalize();
}

void Fraction::operator *=(const Fraction& f){
	*this = *this * f;
	this->normalize();
}

void Fraction::operator /=(const Fraction& f){
	*this = *this / f;
	this->normalize();
}

bool Fraction::operator ==(const Fraction& f)const{
	if(this->denom == f.denom and this->numer == f.numer){
		return true;
	}
	return false;
}

bool Fraction::operator !=(const Fraction& f)const{
	if(this->denom == f.denom and this->numer == f.numer){
		return false;
	}
	return true;
}

bool Fraction::operator <(const Fraction& f)const{
	double temp = numer/denom;
	double temp2 = f.numer/f.denom;
	if(temp < temp2){
		return true;
	}
	return false;
}

bool Fraction::operator >(const Fraction& f)const{
	double temp = numer/denom;
	double temp2 = f.numer/f.denom;
	if(temp > temp2){
		return true;
	}
	return false;
}

bool Fraction::operator <=(const Fraction& f)const{
	double temp = numer/denom;
	double temp2 = f.numer/f.denom;
	if(temp <= temp2){
		return true;
	}
	return false;
}

bool Fraction::operator >=(const Fraction& f)const{
	double temp = numer/denom;
	double temp2 = f.numer/f.denom;
	if(temp >= temp2){
		return true;
	}
	return false;
}

int& Fraction::operator [](const char ch){
	if(ch == 'n'){
		return numer;
	}
	else if(ch == 'd'){
		return denom;
	}
	else{
		cout << "\n!!!Please enter the correct options!!!\n";
		int* wrong = new int;
		*wrong = -1;
		return *wrong;
	}
}

int& Fraction::operator ()(const char ch){
	if(ch == 'n'){
		return numer;
	}
	else if(ch == 'd'){
		return denom;
	}
	else{
		cout << "\n!!!Please enter the correct options!!!\n";
		int* wrong = new int;
		*wrong = -1;
		return *wrong;
	}
}

Fraction Fraction::operator ++(){
	Fraction adder(1,1);
	*this = *this + adder;
	return *this;
}

Fraction Fraction::operator --(){
	Fraction adder(1,1);
	*this = *this - adder;
	return *this;
}

Fraction* Fraction::operator &(){
	Fraction* p = this;
	return p;
}

bool Fraction::operator &&(const Fraction& other)const{
	if(this->numer == 0 || other.numer == 0){
		return false;
	}
	return true;
}

bool Fraction::operator ||(const Fraction& other)const{
	if(this->numer != 0 || other.numer != 0){
		return true;
	}
	return false;
}

Fraction* Fraction::operator ->(){
	Fraction *p = this;
	return p;
}

Fraction* Fraction::operator ->*(Fraction* ptr){
	ptr = this;
	return ptr;
}

ostream& operator<<(ostream& input, const Fraction& f){
	input << f.getNumerator() << "/" << f.getDenominator() << endl;
	return input;
}

istream& operator>>(istream& ouput, Fraction& f){
	int input = 0;
	bool check = false;
	cout << "Enter value for numerator: \n";
	ouput >> input;
	f['n'] = input;
	cout << "Enter value for denominator: \n";
	ouput >> input;
	if(input == 0){
		for(;check != true;){
		cout << "Denominator cannot be zero. Please enter correct value\n";
		ouput >> input;
		if(input != 0){
			check = true;
		}
	}
	}
	f['d'] = input;
	f.normalize();
	return ouput;
}


