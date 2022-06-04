//============================================================================
// Name        : q4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "attributeWeightedGraph.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	attributeWeightedGraph obj;
	int arr[5];
	for(int counter = 0; counter < 5; counter++){
			arr[counter] = counter + 1;
		}
		obj.attributeGraph1::addEdge(arr[0], arr[1]);
		obj.attributeGraph1::addEdge(arr[1], arr[0]);
		obj.attributeGraph1::addEdge(arr[1], arr[2]);
		obj.attributeGraph1::addEdge(arr[2], arr[1]);
		obj.attributeGraph1::addEdge(arr[1], arr[3]);
		obj.attributeGraph1::addEdge(arr[3], arr[1]);
		obj.attributeGraph2::appendAttribute();
		obj.attributeGraph1::appendAttribute();
		obj.appendWeight(arr[0], arr[1], 5);
		obj.appendWeight(arr[1], arr[2], 6);
		obj.appendWeight(arr[2], arr[1], 7);
		obj.appendWeight(arr[3], arr[1], 8);
		obj.printneighbor(2);
		obj.printdata();
	return 0;
}
