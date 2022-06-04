//============================================================================
// Name        : q7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {
	Matrix m(2,2);//Calling Constructor
	m.input();
	cout<<"Value at index (1,1) of matrix is " <<m.get(1, 1)<<endl;
	m.set(1, 1, 3.0);
	cout<<"New Value at index (1,1) of matrix is 3.0 "<<endl;
	Matrix m2;
	m2.assign(m);//assigning value to new matrix
	Matrix display=m.add(m2);//adding 2 matrices
	cout<<"The contents of the newly made matrix are: \n";
	display.display();//displaying content
	display.assign(m.add(2.0));//adding constant to matrix
	m.multiply(m2);//multiplying two matrixes
	m.multiply(2.0);//multiplying constant to matrix
	display.assign(m2.multiplyElement(m));//multiplying element wise
	cout<<"The contents of the resulting matrix are\n";
	display.display();
	return 0;
}
