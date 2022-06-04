//============================================================================
// Name        : Q4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Integer.h"
#include <iostream>
using namespace std;

int main() {
	Integer i(5);//calling constructor
	cout<<"Integer present is "<<i.get()<<endl;
	cout<<"New integer is 4";
	i.set(4);
	cout<<"There are "<<i.bitCount()<<" bits in the Integer\n";
	Integer i2(6);
	cout<<"i2 and i are not same as "<<i.compareTo(i2);
	cout<<"Value of integer as a double is "<<i.doubleValue()<<endl;
	cout<<"Value of integer as a float is "<<i.floatValue()<<endl;
	cout<<"Adding integer i and i2 gives "<<(i.plus(i2)).get()<<endl;
	cout<<"Subtracting integer i and i2 gives "<<(i2.minus(i)).get()<<endl;
	cout<<"Multiplying integer i and i2 gives "<<(i.multiple(i2)).get()<<endl;
	cout<<"Dividing integer i and i2 gives "<<(i2.divide(i)).get()<<endl;
	cout<<"Number of leading zeroes in 2s complement of 110101 are "<<i.numberOfLeadingZeros(110101)<<endl;
	cout<<"Number of trailing zeroes in 2s complement of  100100 are "<<i.numberOfTrailingZeros(1001000)<<endl;
	return 0;
}
