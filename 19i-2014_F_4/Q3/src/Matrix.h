/*
 * Matrix.h
 *
 *  Created on: Mar 26, 2020
 *      Author: danyal-faheem
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include<iostream>
using namespace std;
class Matrix {
int ROWS;
int COLS;
float** matrix;
public:
	Matrix();
	Matrix(int, int); // a parametrized constructor
	Matrix(const Matrix &); // copy constructor
	int get(int, int)const;
	void set(int, int, int);
	int getR()const;
	int getC()const;
	float& operator()(int i, int j); //set value at (i,j)
	float& operator()(int i, int j)const; //set value at (i,j)
	Matrix& operator=(const Matrix &); //assigns (copies) a Matrix. Returns the	same
	bool operator==(const Matrix &); //Compares two matrices
	Matrix operator+(const Matrix &); //adds two Matrices and returns the result
	Matrix operator-(const Matrix &); //subtracts two Matrices and returns the	result
	Matrix operator *(const Matrix &); //multiplies two Matrices
	Matrix& operator++(int); //add one to every element
	void operator+=(const Matrix&); //adds two Matrices
	void operator-=(const Matrix&); //subtracts two Matrices
	~Matrix();
};
ostream& operator<<(ostream& input, const Matrix& M1);
istream& operator>>(istream& ouput, Matrix& M1);
#endif /* MATRIX_H_ */
