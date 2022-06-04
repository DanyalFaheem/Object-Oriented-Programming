/*
 * Vehicle.cpp
 *
 *  Created on: Mar 10, 2020
 *      Author: root
 */

#include "Vehicle.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

Vehicle::Vehicle() {
	if(check == true){
	cout<<"Enter the registration number of car: ";
	getline(cin,reg_no);
	cin.clear();
	cout<<"Enter the manufacturing year of car: ";
	cin>>man_year;
	cout<<"Enter the current financial value of car: ";
	cin>>fin_val;
	cin.clear();
	cout<<"Enter the make of car: ";
	getline(cin,make);
	}
	else if(check == false){
		man_year = fin_val  = 0;
			reg_no = make = "0";
			size = 0;
	}
}
Vehicle::Vehicle(int s){
	size = s;
	man_year = fin_val  = 0;
	reg_no = make = "0";
}
Vehicle::Vehicle(char* s){
	for(int counter = 0; counter < strlen(s); counter++){
		make += s[counter];
	}
	man_year = fin_val = size = 0;
	reg_no = "0";
}
Vehicle::Vehicle(double v){
	fin_val = v;
	man_year = size = 0;
	reg_no = make = "0";
}
Vehicle::Vehicle(const Vehicle& v): size(v.size){
	make = v.make;
	reg_no = v.reg_no;
	man_year = v.man_year;
	fin_val = v.fin_val;
}
double Vehicle::getfinval(){
	return fin_val;
}
string Vehicle::getmake(){
	return make;
}
string Vehicle::getregno(){
	return reg_no;
}
int Vehicle::getsize(){
	return size;
}
int Vehicle::getmanyear(){
	return man_year;
}
void Vehicle::setfinval(double v){
	fin_val = v;
}
void Vehicle::setmake(string s){
	make = s;
}
void Vehicle::setmanyear(int y){
	man_year = y;
}
void Vehicle::setregno(string r){
	reg_no = r;
}
void Vehicle::setcheck(){
	check = false;
}
void Vehicle::addVehicle(Vehicle*& v, int s){
	s++;
	size = s;
		cout<<"Enter the registration number of car: ";
		getline(cin,reg_no);
		cin.clear();
		cout<<"Enter the manufacturing year of car: ";
		cin>>man_year;
		cout<<"Enter the current financial value of car: ";
		cin>>fin_val;
		cin.clear();
		cout<<"Enter the make of car: ";
		getline(cin,make);
}
int Vehicle::ageOfVehicle(){
	int curr_year = 0;
	cout << "Enter the current year: ";
	cin >> curr_year;
	return curr_year - man_year;
}
void Vehicle::getVehicleDetails(){
	cout<<"The vehicle has registration number "<<reg_no<<endl;
	cout<<"The vehicle has manufacturing year "<<man_year<<endl;
	cout<<"The vehicle has current financial value "<<fin_val<<endl;
	cout<<"The vehicle has make "<<make<<endl;
}
void Vehicle::getVehicleDetailsAtIndex(Vehicle*& v, int index){
	cout<<"The vehicle has registration number "<<v[index].reg_no<<endl;
		cout<<"The vehicle has manufacturing year "<<v[index].man_year<<endl;
		cout<<"The vehicle has current financial value "<<v[index].fin_val<<endl;
		cout<<"The vehicle has make "<<v[index].make<<endl;
}
bool Vehicle::isMatching(Vehicle& v){
	if(v.fin_val != fin_val || v.make != make || v.man_year != man_year || v.reg_no != reg_no){
		return false;
	}
	else{
		return true;
	}
}
Vehicle* Vehicle::returnByMake(Vehicle*& v, int s){
	int same = 0;
	check = false;
	Vehicle* obj = new Vehicle[same];
	for(int counter = 0; counter < size; counter++){
		if(v[counter].make == make){
			same++;
			obj[same-1] = v[counter];
		}
	}
	return obj;
}
Vehicle* Vehicle::returnByValue(Vehicle*& v, int s){
	int same = 0;
	check = false;
	Vehicle* obj = new Vehicle[same];
	for(int counter = 0; counter < size; counter++){
		if(v[counter].fin_val == fin_val){
			same++;
			obj[same-1] = v[counter];
		}
	}
	return obj;
}
Vehicle* Vehicle::returnByYear(Vehicle*& v, int s){
	int same = 0;
	check = false;
	Vehicle* obj = new Vehicle[same];
	for(int counter = 0; counter < size; counter++){
		if(v[counter].man_year == man_year){
			same++;
			obj[same-1] = v[counter];
		}
	}
	return obj;
}
void Vehicle::vehicleSold(Vehicle*&v, int index){
	v[index].fin_val = 0;
	v[index].size = 0;
	v[index].reg_no = "0";
	v[index].man_year = 0;
	v[index].make = "0";
}
Vehicle::~Vehicle() {
	fin_val = 0;
	size = 0;
	reg_no = "0";
	man_year = 0;
	make = "0";
}

