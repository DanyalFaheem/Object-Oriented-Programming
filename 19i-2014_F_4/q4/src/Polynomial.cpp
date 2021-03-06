/*
 * Polynomial.cpp
 *
 *  Created on: Mar 27, 2020
 *      Author: danyal-faheem
 */

#include "Polynomial.h"

Polynomial::Polynomial():degree(0) {
	arr = NULL;
}
Polynomial::Polynomial(int d): degree(d){
	if(d > 0){
		arr = new int[d+1];
	}
	else{
		arr = NULL;
	}
}
Polynomial::Polynomial(const Polynomial& copy): degree(copy.degree) {
	if(degree > 0){
		arr = new int[degree+1];
		for(int counter = 0; counter <= degree; counter++){
			arr[counter] = copy.arr[counter];
		}
	}
	else{
		arr = NULL;
	}
}
int Polynomial::get(int index)const{
	if(index <= degree and index >= 0){
		return arr[index];
	}
}
void Polynomial::set(int value, int index){
	if(index <= degree and index >= 0){
		arr[index] = value;
	}
}
int Polynomial::getD()const{
	return degree;
}
Polynomial& Polynomial::operator =(const Polynomial& other){
	this->degree = other.degree;
		this->arr = new int[other.degree + 1];
	for(int counter = 0; counter <= this->degree; counter++){
		this->arr[counter] = other.arr[counter];
	}
	return *this;
}
Polynomial Polynomial::operator +(const Polynomial& other){
	if(other.degree >=  this->degree){
		Polynomial answer(other.degree);
		for(int counter = 0; counter <= this->degree; counter++){
			answer.arr[counter] = this->arr[counter] + other.arr[counter];
		}
		for(int counter = this->degree; counter <= other.degree; counter++){
			answer.arr[counter] = other.arr[counter];
		}
		return answer;
	}
	else {
		Polynomial answer(this->degree);
				for(int counter = 0; counter <= other.degree; counter++){
					answer.arr[counter] = this->arr[counter] + other.arr[counter];
				}
				for(int counter = other.degree; counter <= this->degree; counter++){
					answer.arr[counter] = other.arr[counter];
				}
				return answer;
	}
}
Polynomial Polynomial::operator -(const Polynomial& other){
	if(other.degree >=  this->degree){
			Polynomial answer(other.degree);
			for(int counter = 0; counter <= this->degree; counter++){
				answer.arr[counter] = this->arr[counter] - other.arr[counter];
			}
			for(int counter = this->degree; counter <= other.degree; counter++){
				answer.arr[counter] = other.arr[counter];
			}
			return answer;
		}
		else {
			Polynomial answer(this->degree);
					for(int counter = 0; counter <= other.degree; counter++){
						answer.arr[counter] = this->arr[counter] - other.arr[counter];
					}
					for(int counter = other.degree; counter <= this->degree; counter++){
						answer.arr[counter] = other.arr[counter];
					}
					return answer;
		}
}
bool Polynomial::operator ==(const Polynomial& other){
	if (this->degree != other.degree){
		return false;
	}
	for(int counter = 0; counter <= this->degree; counter++){
		if(this->arr[counter] != other.arr[counter]){
			return false;
		}
	}
	return true;
}
void Polynomial::operator +=(const Polynomial& other){
	if(this->degree >= other.degree){
		for(int counter = 0; counter <= other.degree; counter++){
			this->arr[counter] += other.arr[counter];
		}
	}
	else{
		for(int counter = 0; counter <= this->degree; counter++){
					this->arr[counter] += other.arr[counter];
			}
	}
}
void Polynomial::operator -=(const Polynomial& other){
	if(this->degree >= other.degree){
			for(int counter = 0; counter <= other.degree; counter++){
				this->arr[counter] -= other.arr[counter];
			}
		}
		else{
			for(int counter = 0; counter <= this->degree; counter++){
						this->arr[counter] -= other.arr[counter];
				}
		}
}
Polynomial::~Polynomial() {
	if(arr != NULL){
		delete []arr;
	}
}
ostream& operator<<(ostream& input, const Polynomial& P){
	input << P.get(P.getD()) << "x^" << P.getD();
	for(int counter = P.getD() - 1; counter >= 0; counter--){
		if(P.get(counter) > 0){
			input << " + " <<  P.get(counter) << "x^" << counter;
		}
		else{
			input << " " << P.get(counter) << "x^" << counter;
		}
	}
	input << endl;
	return input;
}
istream& operator>>(istream& ouput, Polynomial& P){
	int value;
	for(int counter = 0; counter <= P.getD(); counter++){
		cout << "Enter coefficient for degree "<<counter<<endl;
		ouput >> value;
		P.set(value,counter);
	}
	return ouput;
}


