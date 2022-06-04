//============================================================================
// Name        : q1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"SimpleGraph.h"
#include <iostream>
using namespace std;
int main() {
	SimpleGraph obj;
	int arr[5];
	for(int counter = 0; counter < 5; counter++){
		cout << "Enter id for nodeid" << counter + 1 << endl;
		cin >> arr[counter];
	}
	obj.addnode(arr[0]);
	obj.addnode(arr[1]);
	obj.addnode(arr[2]);
	obj.addnode(arr[3]);
	obj.addnode(arr[4]);
	obj.addEdge(arr[0], arr[1]);
	obj.addEdge(arr[1], arr[0]);
	obj.addEdge(arr[1], arr[2]);
	obj.addEdge(arr[2], arr[1]);
	obj.addEdge(arr[1], arr[3]);
	obj.addEdge(arr[3], arr[1]);
	obj.printneighbor(arr[1]);
	obj.printdata();
	//cout << "\n!!!Program finishes here!!!\n";
	return 0;
}
