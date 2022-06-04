//============================================================================
// Name        : q2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"Array.h"
#include <iostream>
using namespace std;

int main() {
	int arr[] = {1,2,3,4};
	int* parr = arr;
	Array obj(parr,4);
	cout<<"\nInitializing object with size 4 and values 1,2,3,4\n";
	Array obj2(obj);//Calling copy constructor
	cout<<"\nCreating obj2 with copying obj\n";
	Array obj3;
	cout<<"\nAdding obj2 and obj to obj3\n";
	obj3 = obj2 + obj;
	cout <<"Current values of obj3\n" << obj3;
	if(obj == obj2){
	cout<<"\nobj is equals to obj2 as bool returns 1\n";
	}
	cout<<"\nAdding ++ to obj3\n";
	++obj3;
	cout<<"\nNow subtracting -- from obj3\n";
	cout<<"\nobj is not empty as bool returns "<<!obj <<endl;
	cout<<"\nAdding obj2 to obj3\n";
	obj3 += obj2;
	cout<<"\nNow subtracting obj from obj3\n";
	obj3 -= obj;
	cout <<"Current values of obj3\n" << obj3;
	cout<<"\nRemoving value at 2nd index\n";
	obj3(2,6);
	cout<<"\nNow showing final values of obj3\n";
	cout<< obj3;
	return 0;
}
