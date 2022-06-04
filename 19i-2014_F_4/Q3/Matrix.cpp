//============================================================================
// Name        : Matrix.cpp
// Author      : Danyal Faheem
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix():ROWS(0),COLS(0) {
	matrix=NULL;
}
Matrix::Matrix(int i, int j):ROWS(i),COLS(j){
	matrix=new float*[i];
	for(int counter=0; counter<i; counter++){
		matrix[counter]=new float[j];
	}
}
Matrix::Matrix(const Matrix& mat):ROWS(mat.ROWS),COLS(mat.COLS){
	if(ROWS>0 && COLS>0){
	matrix=new float*[ROWS];
	for(int counter=0; counter<ROWS; counter++){
	matrix[counter]=new float[COLS];
	for(int count=0; count<COLS; count++){
		matrix[counter][count]=mat.matrix[counter][count];
	}
	}
	}
	else
	{
		matrix=NULL;
	}
}
float&	Matrix::operator()(int i, int j) //set value at (i,j)
{
	return matrix[i][j];
}
float&	Matrix::operator()(int i, int j)const//set value at (i,j)
{
	return matrix[i][j];
}
Matrix& Matrix::operator=(const Matrix & mat) //assigns (copies) a Matrix. Returns the	same
{
	if(this->ROWS>0 && this->COLS>0){
		this->matrix=new float*[this->ROWS];
		for(int counter=0; counter< this->ROWS; counter++){
		this->matrix[counter]=new float[this->COLS];
		for(int count=0; count<this->COLS; count++){
			this->matrix[counter][count]=mat.matrix[counter][count];
		}
		}
		}
		else
		{
			matrix=NULL;
		}
	return *this;
}
bool Matrix::operator ==(const Matrix& mat){
	if(this->COLS != mat.COLS || this->ROWS != mat.ROWS){
		return false;
	}
	for(int counter = 0; counter < ROWS; counter ++){
		for(int count = 0; count < COLS; count++){
			if(this->matrix[counter][count] != mat.matrix[counter][count]){
				return false;
			}
		}
	}
	return true;
}
Matrix Matrix::operator +(const Matrix& mat){
	Matrix mat2(mat.ROWS,mat.COLS);
		Matrix null;
		if (mat.ROWS != mat.COLS || mat.ROWS!= this->ROWS || this->ROWS!=this->COLS || mat.COLS!= this->COLS){
			cout<<"Please enter same sized matrices for additon\n";
			return null;
		}
		else{
			for(int counter=0; counter<mat.ROWS; counter++){
				for(int count=0; count<mat.COLS; count++){
					mat2.matrix[counter][count] = this->matrix[counter][count]+mat.matrix[counter][count];
				}
			}
		}
		return mat2;
}
Matrix Matrix::operator -(const Matrix& mat){
	Matrix mat2(mat.ROWS,mat.COLS);
			Matrix null;
			if (mat.ROWS != mat.COLS || mat.ROWS!= this->ROWS || this->ROWS != this->COLS || mat.COLS!=this->COLS){
				cout<<"Please enter same sized matrices for additon\n";
				return null;
			}
			else{
				for(int counter=0; counter<mat.ROWS; counter++){
					for(int count=0; count<mat.COLS; count++){
						mat2.matrix[counter][count]= this->matrix[counter][count] - mat.matrix[counter][count];
					}
				}
			}
			return mat2;
}
Matrix Matrix::operator *(const Matrix& mat){
	if(this->COLS!=mat.ROWS){
				cout<<"Invalid input. Please enter matrices with same number of rows and columns\n";
				Matrix null;
				return null;
			}
			Matrix Answer(mat.ROWS,this->COLS);
			for(int counter=0; counter<this->ROWS; counter++){
				for(int count=0; count<mat.COLS;count++){
					for(int count2=0; count2<mat.COLS; count2++){
						Answer.matrix[counter][count]+=(this->matrix[counter][count2])*(mat.matrix[count2][count]);
					}
				}
			}
			return Answer;
}
Matrix& Matrix::operator ++(int){
	for(int counter=0; counter<this->ROWS; counter++){
				for(int count=0; count<this->COLS; count++){
					this->matrix[counter][count]+= 1;
				}
			}
			return *this;
}
void Matrix::operator +=(const Matrix& mat){
			if (mat.ROWS != mat.COLS || mat.ROWS!= this->ROWS || this->ROWS!=this->COLS || mat.COLS!= this->COLS){
				cout<<"Please enter same sized matrices for additon\n";
				return;
			}
			else{
				for(int counter=0; counter<mat.ROWS; counter++){
					for(int count=0; count<mat.COLS; count++){
						this->matrix[counter][count] += mat.matrix[counter][count];
					}
				}
			}
}
void Matrix::operator -=(const Matrix& mat){
				if (mat.ROWS != mat.COLS || mat.ROWS!= this->ROWS || this->ROWS != this->COLS || mat.COLS!=this->COLS){
					cout<<"Please enter same sized matrices for additon\n";
					return;
				}
				else{
					for(int counter=0; counter<mat.ROWS; counter++){
						for(int count=0; count<mat.COLS; count++){
							this->matrix[counter][count] -= mat.matrix[counter][count];
						}
					}
				}
}
int Matrix::get(int i, int j)const{
	return matrix[i][j];
}
void Matrix::set(int i , int j, int value){
	matrix[i][j] = value;
}
int Matrix::getR()const{
	return ROWS;
}
int Matrix::getC()const{
	return COLS;
}
ostream& operator<<(ostream& input, const Matrix& M1) //Outputs the Matrix
{
	for(int counter = 0; counter < M1.getR(); counter++){
		for(int count = 0; count < M1.getC(); count++){
		input << M1.get(counter,count) << endl;
		}
		}
	return input;
}
istream& operator>>(istream& ouput, Matrix& M1) //Inputs the Matrix
{
	int i;
	for(int counter = 0; counter < M1.getR(); counter++){
		for(int count = 0; count <M1.getC(); count++){
			cout<<"Enter value at counter,count : ";
			ouput >> i;
			M1.set(counter, count, i);
		}
	}
	return ouput;
}
Matrix::~Matrix() {
	if(matrix != NULL){
			for(int counter=0; counter<ROWS; counter++){
				delete []matrix[counter];
			}
			delete []matrix;
		}
}


