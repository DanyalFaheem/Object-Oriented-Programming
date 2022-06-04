/*
 * Integer.cpp
 *
 *  Created on: Mar 1, 2020
 *      Author: root
 */

#include "Integer.h"

#include <iostream>
#include<cstring>
using namespace std;

Integer::Integer(){
	integ=0;

}
Integer::Integer(int i){
	integ=i;
}
Integer::Integer(string str){
	integ=0;
	binary=str;
}
void Integer::set(int i){
	integ=i;
}
int Integer::get()const{
	return integ;
}
int Integer::compareTo(Integer i){
	return integ-i.integ;
}
double Integer::doubleValue(){
	return static_cast<double>(integ);
}
float Integer::floatValue(){
	return static_cast<float>(integ);
}
Integer Integer::plus(const Integer& i){
	Integer i2;
	i2.integ=i.integ+integ;
	return i2;
}
Integer Integer::minus(const Integer& i){
	Integer i2;
	i2.integ=i.integ-integ;
	return i2;
}
Integer Integer::multiple(const Integer& i){
	Integer i2;
	i2.integ=i.integ*integ;
	return i2;
}
Integer Integer::divide(const Integer& i){
	Integer i2;
	i2.integ=i.integ/integ;
	return i2;
}
int Integer::bitCount(){
	int count=0;
	for(int counter=0; integ>0; counter++){
		if(integ%2==1){
			count++;
		}
		integ=integ/10;
	}
	return count;
}
int Integer::numberOfTrailingZeros(int i){
	int count=0;
	if(i%10 == 1){ 
	i/=10;
	}
	for(count=0; i>0; count++){
		if(i%2==1){
			break;
		}
		i=i/10;
	}
	return count+1;
}
int Integer::numberOfLeadingZeros(int i){
	int count=0,copy=i;

	for(int counter=0; i>0; counter++){
		if(i%2==1){
			int count2=0;
			bool check=false;
			copy=i;
			for(; copy>0; count2++){
				if(copy%2 == 0){
					check=true;
				}
				copy/=10;
			}
			if(check==false){
				count=count2;
				break;
			}
		}
		i=i/10;
	}
	return count;
}
 string Integer::toBinaryString(int i){

}
 string Integer::toHexString(int i){

}
 string Integer::toOctString(int i){

}


