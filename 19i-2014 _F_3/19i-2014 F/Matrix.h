
/*
 * Matrix.h
 *
 *  Created on: Mar 2, 2020
 *      Author: root
 */
#include<iostream>
using namespace std;
#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix {
private:
	int** matrix;
	const int ROWS;
	const int COLS;
public:
	Matrix();
	Matrix(int, int);// a parametrized constructor
	Matrix(const Matrix&);// copy constructor
	void set(int i, int j, float val);//set value at (i,j)
	float get(int i, int j)const;//get value at (i,j)
	Matrix& assign(const Matrix &);//assigns (copies) a Matrix. Returns the same
	Matrix add(const Matrix &);//adds two Matrices and returns the result
	Matrix subtract(const Matrix &);//subtracts two Matrices and returns the result
	Matrix multiply(const Matrix &);//multiplies two Matrices and returns the result
	Matrix multiplyElement(const Matrix &);//Elementwise multiplies two Matrices and
	//returns the result
	Matrix add(float );//assigns a constant to every element
	Matrix multiply(float);//multiplies every element with a constant
	void input(); // takes input in every element of matrix
	void display(); // prints every element
	~Matrix();
};

#endif /* MATRIX_H_ */
