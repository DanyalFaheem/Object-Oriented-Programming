#include<iostream>
#include<cstdlib>
using namespace std;
//Part 1
int **MatrixAdd( int **MatrixA , int rowsA , int colsA , int **MatrixB , int rowsB , int colsB ){
	if(rowsA!=rowsB||colsA!=colsB){
		cout<<"Invalid input. Please enter same size matrixes\n";
		int** null_ptr=NULL;
		return null_ptr;
	}
	int** Answer= new int*[rowsA];
	for(int counter=0; counter<rowsA; counter++){
		Answer[counter]=new int;
	}
	for(int counter=0; counter<rowsA; counter++){
		for(int count=0; count<colsB; count++){
			Answer[counter][count]=(MatrixA[counter][count])+MatrixB[counter][count];
		}
	}
	return Answer;
}
//Part 2
int **MatrixSub( int **MatrixA , int rowsA , int colsA , int **MatrixB , int rowsB , int colsB ){
	if(rowsA!=rowsB||colsA!=colsB){
		cout<<"Invalid input. Please enter same size matrixes\n";
		int** null_ptr=NULL;
		return null_ptr;
	}
	int** Answer= new int*[rowsA];
	for(int counter=0; counter<rowsA; counter++){
		Answer[counter]=new int;
	}
	for(int counter=0; counter<rowsA; counter++){
		for(int count=0; count<colsB; count++){
			Answer[counter][count]=(MatrixA[counter][count])-MatrixB[counter][count];
		}
	}
	return Answer;
}
//Part 3
int **MatrixMul( int **MatrixA , int rowsA , int colsA , int **MatrixB , int rowsB , int colsB ){
	if(colsA!=rowsB){
		cout<<"Invalid input. Please enter matrices with same number of rows and columns\n";
		int** null_ptr=NULL;
		return null_ptr;
	}
	int** Answer=new int*[rowsA];
	for(int counter=0; counter<rowsA; counter++){
		Answer[counter]=new int;
	}
	for(int counter=0; counter<rowsA; counter++){
		for(int count=0; count<colsB;count++){
			for(int count2=0; count2<rowsB; count2++){
				Answer[counter][count]+=(MatrixA[counter][count2])*(MatrixB[count2][count]);
			}
		}
	}
	return Answer;
}
//4th part
int** MatrixTranspose(int** Matrix, int rows, int cols){
	if(rows==1&&cols==1){
		return Matrix;
	}
	if(rows!=cols){
		cout<<"Invalid input. Please enter same size matrixes\n";
		int** null_ptr=NULL;
		return null_ptr;
	}
	int* middle=new int[rows+cols];
	for(int counter=0; counter<rows; counter++){
		for(int count=0; count<cols; count++){
				middle[count]=Matrix[count][counter];
		}
	}
			for(int counter=0 ;counter<2; counter++){
		for(int count=0; count<2; count++){
			if(count!=counter){
			Matrix[counter][count]=middle[count];
		}
	}
	}
	return Matrix;
}
//5th part
int** MatrixRotate ( int **Matrix , int rows , int cols ){
		if(rows==1&&cols==1){
		return Matrix;
	}
	if(rows!=cols){
		cout<<"Invalid input. Please enter same size matrixes\n";
		int** null_ptr=NULL;
		return null_ptr;
	}
		int* middle=new int[rows+cols];
	for(int counter=0; counter<rows; counter++){
		for(int count=0; count<cols; count++){
				middle[count]=Matrix[count][counter];
		}
	}
			for(int counter=0 ;counter<2; counter++){
		for(int count=0; count<2; count++){
			if(count!=counter){
			Matrix[counter][count]=middle[count];
		}
	}
	}
	return Matrix;
}
//6th part
int MatrixDet( int **Matrix , int rows , int cols ){
	if(rows==1&&cols==1){
		return Matrix[0][0];
	}
		if(rows!=cols){
		return 0;
	}
	int Answer=0;
	for(int counter=0; counter<rows; counter++){
	for(int count=0; count<cols; count++){
		Answer+=(Matrix[counter][count]*Matrix[count][counter])-(Matrix[count][counter]*Matrix[counter][count]);
		}
	}
	return Answer;
}
//7th part
/*int** MatrixInverse( int **Matrix , int rows , int cols ){
	if(cols!=rows){
		cout<<"Invalid input. Please enter matrices with same number of rows and columns\n";
		int** null_ptr=NULL;
		return null_ptr;
	}
	int Answer=0;
	for(int counter=0; counter<rows; counter++){
	for(int count=0; count<cols; count++){
		Answer+=(Matrix[counter][count]*Matrix[count][counter])-(Matrix[count][counter]*Matrix[counter][count]);
		}
	}
	return Answer;
}*/

