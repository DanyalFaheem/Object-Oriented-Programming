//============================================================================
// Name        : q2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"attributeGraph1.h"
#include <iostream>
using namespace std;

int main() {
	attributeGraph1 obj;
	int arr[5];
	for(int counter = 0; counter < 5; counter++){
			arr[counter] = counter + 1;
		}
		obj.addEdge(arr[0], arr[1]);
		obj.addEdge(arr[1], arr[0]);
		obj.addEdge(arr[1], arr[2]);
		obj.addEdge(arr[2], arr[1]);
		obj.addEdge(arr[1], arr[3]);
		obj.addEdge(arr[3], arr[1]);
		obj.appendAttribute();
		SimpleGraph* ptr = &obj;
		ptr->printdata();
		cout << endl;
	return 0;
}
