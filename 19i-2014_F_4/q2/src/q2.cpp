//============================================================================
// Name        : q2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"String.h"
#include <iostream>
#include<cstring>
using namespace std;

int main() {
	char p[] = "hello";
	char q[] = "world";
	String obj(p);
	cout<<"\nInitializing obj with hello\n";
	String obj2(q);
	cout<<"\nInitializing obj2 with world\n";
	String obj3;
	cout<<"\nAdding obj and obj2 to obj3\n";
	obj3 = obj + obj2;
	cout<<"Current string in obj3 is " << obj3;
	cout<<"\nobj is not empty as bool returns " << !obj <<endl;
	cout<<"\ncreating obj4 with copy constructor and same as obj\n";
	String obj4(obj);
	cout<<"Current string in obj4 is " << obj4 <<endl;
	cout<<"Current string in obj is "<<obj<<endl;
	if(obj == obj4){
		cout<<"\nobj and obj4 are equal as bool returns 1\n";
	}
	cout<<"Current string in obj3 is " << obj3 <<endl;
	cout<<"character at 1st index of obj3 is "<< obj3[1]<<endl;
	cout<<"Character r is present at index "<< obj3('r') <<endl;
	cout<<"\nLength of string in obj3 is "<<obj3.length()<<endl;
	cout<<"Current string in obj is "<<obj<<endl;
	obj = obj * 3;
	cout<<"Multiplying obj by 3 times\n";
	cout<<"New string in obj is "<<obj<<endl;
	cout<<"\nCurrent string in obj3 is "<<obj3<<endl;
	cout<<"Current string in obj2 is "<<obj2<<endl;
	cout<<"\nSubtracting obj3 from obj2 \n";
	obj3 = obj3 - obj2;
	cout<<"New string in obj3 is "<<obj3<<endl;
	return 0;
}
