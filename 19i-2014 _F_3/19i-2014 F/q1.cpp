//============================================================================
// Name        : q1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"Vehicle.h"
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
	Vehicle obj;
	cout<<"age of vehicle: "<<obj.ageOfVehicle()<<endl;
	obj.setcheck();
	int size = 5;
	Vehicle* v = new Vehicle[size];
	cout<<"object does not match as "<<obj.isMatching(v[2])<<endl;
	obj.getVehicleDetails();
	obj.returnByMake(v, size);
	obj.returnByValue(v, size);
	obj.returnByYear(v, size);
	return 0;
}
