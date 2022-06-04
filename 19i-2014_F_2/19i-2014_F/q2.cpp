#include<iostream>
using namespace std;
bool equal(int** matrix1, int** matrix2,int** matrix3,int row, int column)
{
	if(row!=column){
		return false;
	}
	if(row>0||column>0){
			return equal( matrix1,matrix2,matrix3,row-1,column-1);
	}
	if(matrix1[row][column]!=matrix2[row][column]||matrix1[row][column]!=matrix3[row][column]||matrix2[row][column]!=matrix3[row][column]){
		return false;
	}
}
