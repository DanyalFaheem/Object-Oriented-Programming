//============================================================================
// Name        : Q5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "String.h"
#include <iostream>
using namespace std;

int main() {
	String s("abc");//calling constructor
	cout<<"Character at index 1 is "<<s.getAt(1)<<endl;
	s.setAt(1, 'B');
	cout<<"New Character at index 1 is B \n";
	cout<<"Substring at position 0 of length 2 is "<<s.substr(0, 2);
	cout<<"Appending character d at end of string\n";
	s.append('d');
	cout<<"Length of string ";
	s.display();
	cout<<" is "<<s.length()<<endl;
	cout<<"String is not empty as "<<s.isEmpty()<<endl;
	cout<<"copying string dbca to string\n";
	s.copy("dbca");
	cout<<"Character c is present at index "<<s.find('c')<<endl;
	cout<<"String abcd is not equal to string as "<<s.equal("abcd")<<endl;
	return 0;
}
