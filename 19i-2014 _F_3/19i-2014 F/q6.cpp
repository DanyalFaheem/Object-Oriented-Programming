//============================================================================
// Name        : q6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"TrueDynamicArray.h"
#include <iostream>
using namespace std;

int main() {
	int arr[5] = {3,2,4,1,5};
	int* parr = arr;
	TrueDynamicArray obj(parr,5);
	obj.setAt(2, 3);
	cout<<obj.getAt(3)<<endl<<obj.length()<<endl;
	obj.subArr(3);
	obj.sort();
	obj.clear();
	return 0;
}
