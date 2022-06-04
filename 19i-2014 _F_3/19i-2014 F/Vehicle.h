/*
 * Vehicle.h
 *
 *  Created on: Mar 10, 2020
 *      Author: root
 */
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle {
private:
	bool check;
	int size;
	string reg_no;
	string make;
	int man_year;
	double fin_val;
public:
	Vehicle();
	Vehicle(char *str);
	Vehicle(double);
	Vehicle(const Vehicle &);
	Vehicle(int);
	int getsize();
	string getregno();
	string getmake();
	int getmanyear();
	double getfinval();
	void setregno(string);
	void setmake(string);
	void setmanyear(int);
	void setfinval(double);
	void setcheck();
	void addVehicle(Vehicle*&, int);//adds a new vehicle
	int ageOfVehicle();//returns age of vehicle on the basis of year passed
	void getVehicleDetails();//return detail of vehicle
	void getVehicleDetailsAtIndex(Vehicle*&, int);//return detail of vehicle stored at certain index
	bool isMatching(Vehicle&);//returns true if passed vehicle matches with it
	Vehicle* returnByMake(Vehicle*&, int );//returns the array of vehicles of specific make
	Vehicle* returnByValue(Vehicle*&, int);//returns the array of vehicles of specific value
	Vehicle* returnByYear(Vehicle*&, int);//returns the array of vehicles of specific year
	void vehicleSold(Vehicle*&, int);//deletes the specific vehicle once its sold
	~Vehicle();
};

#endif /* VEHICLE_H_ */
