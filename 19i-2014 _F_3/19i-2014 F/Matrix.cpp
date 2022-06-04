/*
 * Matrix.cpp
 *
 *  Created on: Mar 2, 2020
 *      Author: root
 */

#include "Matrix.h"

#include<iostream>
using namespace std;

Matrix::Matrix():ROWS(0),COLS(0) {
	matrix=NULL;
}
Matrix::Matrix(int i, int j):ROWS(i),COLS(j){
	matrix=new int*[i];
	for(int counter=0; counter<i; i++){
		matrix[i]=new int[j];
	}
}
Matrix::Matrix(const Matrix& mat):ROWS(mat.ROWS),COLS(mat.COLS){
	if(ROWS>0 && COLS>0){
	matrix=new int*[ROWS];
	for(int counter=0; counter<ROWS; counter++){
	matrix[counter]=new int[COLS];
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
float Matrix::get(int index_1, int index_2)const{
	return matrix[index_1][index_2];
}
void Matrix::set(int index_1, int index_2,float value){
	matrix[index_1][index_2]=value;
}

Matrix& Matrix::assign(const Matrix& mat ){
	if(ROWS>0 && COLS>0){
		matrix=new int*[ROWS];
		for(int counter=0; counter<ROWS; counter++){
		matrix[counter]=new int[COLS];
		for(int count=0; count<COLS; count++){
			matrix[counter][count]=mat.matrix[counter][count];
		}
		}
		}
		else
		{
			matrix=NULL;
		}
	return *this;
}
Matrix Matrix::add(const Matrix& mat){
	Matrix mat2(ROWS,COLS);
	Matrix null;
	if (mat.ROWS != mat.COLS || mat.ROWS!=ROWS || ROWS!=COLS || mat.COLS!=COLS){
		cout<<"Please enter same sized matrices for additon\n";
		return null;
	}
	else{
		for(int counter=0; counter<ROWS; counter++){
			for(int count=0; count<COLS; count++){
				mat2.matrix[counter][count]=matrix[counter][count]+mat.matrix[counter][count];
			}
		}
	}
	return mat2;
}
Matrix Matrix::subtract(const Matrix& mat){
	Matrix mat2(ROWS,COLS);
		Matrix null;
		if (mat.ROWS != mat.COLS || mat.ROWS!=ROWS || ROWS!=COLS || mat.COLS!=COLS){
			cout<<"Please enter same sized matrices for additon\n";
			return null;
		}
		else{
			for(int counter=0; counter<ROWS; counter++){
				for(int count=0; count<COLS; count++){
					mat2.matrix[counter][count]=matrix[counter][count]-mat.matrix[counter][count];
				}
			}
		}
		return mat2;
}
Matrix Matrix::multiply(const Matrix& mat){
	if(COLS!=mat.ROWS){
			cout<<"Invalid input. Please enter matrices with same number of rows and columns\n";
			Matrix null;
			return null;
		}
		Matrix Answer(mat.ROWS,COLS);
		for(int counter=0; counter<ROWS; counter++){
			for(int count=0; count<mat.COLS;count++){
				for(int count2=0; count2<mat.COLS; count2++){
					Answer.matrix[counter][count]+=(matrix[counter][count2])*(mat.matrix[count2][count]);
				}
			}
		}
		return Answer;
}
Matrix Matrix::multiplyElement(const Matrix& mat){
	Matrix mat2(ROWS,COLS);
			Matrix null;
			if (mat.ROWS != mat.COLS || mat.ROWS!=ROWS || ROWS!=COLS || mat.COLS!=COLS){
				cout<<"Please enter same sized matrices for additon\n";
				return null;
			}
			else{
				for(int counter=0; counter<ROWS; counter++){
					for(int count=0; count<COLS; count++){
						mat2.matrix[counter][count]=matrix[counter][count]*mat.matrix[counter][count];
					}
				}
			}
			return mat2;
}
Matrix Matrix::add(float value){
	for(int counter=0; counter<ROWS; counter++){
			for(int count=0; count<COLS; count++){
				matrix[counter][count]+=value;
			}
		}
		return *this;
}
Matrix Matrix::multiply(float value){
	for(int counter=0; counter<ROWS; counter++){
		for(int count=0; count<COLS; count++){
			matrix[counter][count]*=value;
		}
	}
	return *this;
}
void Matrix::input(){
	if(ROWS<=0 && COLS<=0){
		cout<<"Matrix has no Rows or Columns, please enter correct size matrix\n";
		return;
	}
	else{
		cout<<"Enter following values for the matrix\n";
		for(int counter=0; counter<ROWS; counter++){
			for(int count=0; count<COLS; count++){
				cout<<"Enter value to be inserted at Row "<<ROWS<<" and Column "<<COLS<<" :";
				cin>>matrix[counter][count];
			}
		}
	}
}
void Matrix::display(){
	if(matrix != NULL){
		cout<<"Following are the values of Matrix\n";
		for(int counter=0; counter<ROWS; counter++){
					for(int count=0; count<COLS; count++){
						cout<<"Value at Row "<<ROWS<<" and Column "<<COLS<<" :"<<matrix[counter][count];
					}
				}
	}
}
Matrix::~Matrix() {
	if(matrix != NULL){
		for(int counter=0; counter<ROWS; counter++){
			delete []matrix[counter];
		}
		delete []matrix;
	}
}

