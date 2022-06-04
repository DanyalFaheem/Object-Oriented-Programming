/*
 * Array.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: danyal-faheem
 */

#include "Array.h"
#include<iostream>
using namespace std;
Array::Array() {
	size = 0;
	arr = NULL;
}
Array::Array(int s){
	if(s > 0){
		size = s;
		arr = new int[size];
	}
	else{
			arr = NULL;
	}
}
Array::Array(int* a, int s){
	if(a != NULL and s >= 0){
		size = s;
		arr = new int[size];
		for(int counter = 0; counter < size; counter++){
			arr[counter] = a[counter];
		}
	}
	else{
			arr = NULL;
		}
}
Array::Array(const Array &copy) {
	// TODO Auto-generated constructor stub
	if(copy.arr != NULL){
		size = copy.size;
		arr = new int[size];
		for(int counter = 0; counter < size; counter++){
			arr[counter] = copy.arr[counter];
		}
	}
	else{
		arr = NULL;
	}
}
int& Array::operator [](int index){
	if(index >= 0 and index < size){
		return arr[index];
	}
}
int& Array::operator [](int index)const{
	if(index >= 0 and index < size){
		return arr[index];
	}
}
const Array& Array::operator =(const Array& other){
	this->size = other.size;
	this->arr = new int[size];
	for(int counter = 0; counter < size; counter++){
		this->arr[counter] = other.arr[counter];
	}
	return *this;
}
Array Array::operator +(const Array& other){
	if(this->size >= other.size){
		Array answer(this->arr,this->size);
		for(int counter = 0; counter < other.size; counter++){
			answer.arr[counter] = this->arr[counter] + other.arr[counter];
		}
		return answer;
	}
	else{
		Array answer(other.arr,other.size);
				for(int counter = 0; counter < this->size; counter++){
					answer.arr[counter] = this->arr[counter] + other.arr[counter];
				}
				return answer;
	}
}
Array Array::operator -(const Array& other){
	if(this->size >= other.size){
			Array answer(this->arr,this->size);
			for(int counter = 0; counter < other.size; counter++){
				answer.arr[counter] = this->arr[counter] - other.arr[counter];
			}
			return answer;
		}
		else{
			Array answer(other.arr,other.size);
					for(int counter = 0; counter < this->size; counter++){
						answer.arr[counter] = this->arr[counter] - other.arr[counter];
					}
					return answer;
		}
}
Array Array::operator ++(){
	for(int counter = 0; counter < this->size; counter++){
		this->arr[counter] += 1;
	}
	return *this;
}
Array Array::operator ++(int){
	Array obj(*this);
	for(int counter = 0; counter < this->size; counter++){
		obj.arr[counter] += 1;
		this->arr[counter] += 1;
	}
	return obj;
}
Array Array::operator --(int){
	Array* p = new Array(*this);
	for(int counter = 0; counter < this->size; counter++){
		(*p).arr[counter] -= 1;
		this->arr[counter] -= 1;
	}
	return *p;
}
bool Array::operator ==(const Array& other)const{
	if(this->size != other.size){
		return false;
	}
	for(int counter = 0; counter < this->size; counter++){
		if(this->arr[counter] != other.arr[counter]){
			return false;
		}
	}
	return true;
}
bool Array::operator !(){
	if(arr == NULL){
		return true;
	}
	return false;
}
void Array::operator +=(const Array& other){
	if(this->size >= other.size){
		for(int counter = 0; counter < other.size; counter++){
			this->arr[counter] += other.arr[counter];
		}
	}
}
void Array::operator -=(const Array& other){
	if(this->size >= other.size){
			for(int counter = 0; counter < other.size; counter++){
				this->arr[counter] -= other.arr[counter];
			}
		}
}
int Array::operator ()(int index, int value){
	if(index >= this->size or index < 0){
		return -1;
	}
	for(int counter = 0; counter < this->size; counter++){
		if(counter == index){
			for(int count = counter; count < ((this->size)-1); count++){
				int temp = this->arr[count];
				this->arr[count] = this->arr[count + 1];
				this->arr[count + 1] = temp;
			}
		}
	}
	this->arr[this->size] = 0;
	this->size -= 1;
	return 1;
}
int Array::getS()const{
	return size;
}
ostream& operator<<(ostream& input, const Array& A){
	for(int counter = 0; counter < A.getS(); counter++){
		input << A[counter] <<endl;
	}
	return input;
}
istream& operator>>(istream& ouput, Array& A){
	int temp;
	for(int counter = 0; counter < A.getS(); counter++){
		cout<< "Enter value "<< counter+1 << endl;
		ouput >> temp;
		A[counter] = temp;
	}
	return ouput;
}
Array::~Array() {
	// TODO Auto-generated destructor stub
	if(arr != NULL){
		delete []arr;
	}
}

