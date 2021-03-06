//============================================================================
// Name        : q4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Polynomial.h"
#include <iostream>
using namespace std;

int main() {
	Polynomial obj(2);
	cout<<"Initializing object with degree 2\n";
	cin>>obj;
	cout<<"Current polynomial is "<< obj << endl;
	Polynomial obj2(obj);//Calling copy constructor
	cout << "Creating obj2 by copying obj\n";
	cout << "obj and obj2 are equal as bool returns ";
	if(obj == obj2){
		cout << "1\n";
	}
	Polynomial obj3;
	cout<<"\nAdding obj2 and obj to obj 3\n";
	obj3 = obj2 + obj;
	cout<<"\nNew values of obj3 are\n";
	cout<< obj3;
	cout<<"\nCurrent values of obj are " << obj << endl;
	cout<<"Subtracting obj from obj3\n";
	obj3 -= obj;
	cout<<"New values of obj3 are\n";
	cout<< obj3;
	return 0;
}
