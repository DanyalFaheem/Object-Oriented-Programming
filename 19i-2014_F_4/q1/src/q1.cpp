//============================================================================
// Name        : q1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"Fraction.h"
#include <iostream>
using namespace std;

int main() {
	Fraction obj(12,8);
	cout << "Initiliazing obj with values 12/8 and obj2 with values 10/4\n";
	Fraction obj2(10,4);
	cout << "After normalizing, obj and obj2 have values respectively: \n" << obj << obj2 << endl;
	Fraction obj3;
	cout << "Creating obj3 by adding obj+obj2 and assigning to it\n";
	obj3 = obj + obj2;
	cout << "obj3 has current normalized values: " << obj3 << endl;
	cout << "Creating obj4 by subtracting obj2 - obj \n";
	Fraction obj4 = obj2 - obj;
	cout << "obj4 has current normalized values: " << obj4 << endl;
	cout << "Dividing obj3 by obj\n";
	obj3 /= obj;
	cout << "obj3: " << obj3;
	cout << "Multiplying obj4 by obj2 \n";
	obj4 *= obj2;
	cout << "obj4: " << obj4;
	cout << "obj: " << obj << "obj2: " << obj2;
	cout << "obj and obj2 are not equal as bool returns ";
	if(obj == obj2){
		cout << "1\n";
	}
	else if(obj != obj2){
		cout << "0\n";
	}
	cout << "obj4 is either lesser than or equal to obj3 as bool returns ";
	if(obj4 <= obj3){
		cout << "1\n";
	}
	else if(obj4 >= obj3){
		cout << "0\n";
	}
	cout << "Value at numerator of obj3 is " << obj3['n'] << endl;
	cout << "Value at denominator of obj4 is " << obj4('d') << endl;
	cout << "obj3: " << obj3;
	cout << "Adding ++ to obj3\nobj3: ";
	++obj3;
	cout << obj3;
	cout << "obj4: " << obj4;
	cout << "Subtracting -- from obj4\nobj4: ";
	--obj4;
	cout << obj4;
	cout << "Address of obj2 is: " << &obj2 << endl;
	Fraction* f_ptr = NULL;
	cout << "Address of obj is: " << obj->*f_ptr << endl;
	cout << "obj: " << obj << "obj2: " << obj2;
	cout << "obj and obj2 have atleast one non zero value as obj || obj2 returns ";
	if(obj || obj2){
		cout << "1\n";
	}
	cout << "Setting obj to zero \n";
	obj['n'] = 0;
	cout << "obj: ";
	obj->display();
	cout << "obj2: ";
	obj2->display();
	cout << "obj or obj2 has atleast one zero value as obj && obj2 returns ";
	if(obj && obj2){
		cout << "1\n";
	}
	else{
		cout << "0\n";
	}
	return 0;
}
