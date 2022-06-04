/*
 * TrueDynamicArray.h
 *
 *  Created on: Mar 6, 2020
 *      Author: root
 */
#include<iostream>
using namespace std;

#ifndef TRUEDYNAMICARRAY_H_
#define TRUEDYNAMICARRAY_H_

struct node{
int value;
node* next;
};

class TrueDynamicArray {
private:
	int size;
	node* link;
public:
	TrueDynamicArray();//default constructor
	TrueDynamicArray (int s);// a parametrized constructor initializing an Array
	TrueDynamicArray (int *arr, int s);// initializes the Array with an existing
	TrueDynamicArray (const TrueDynamicArray &);// copy constructor
	int getAt(int );// returns the integer at index [i]
	void setAt(int , int );// set the value at index [i]
	TrueDynamicArray subArr(int pos, int siz);// returns subArray of ‘siz’ from ‘pos’
	TrueDynamicArray subArr(int pos);// returns a sub-Array from ‘pos’ to end
	void push_back(int a);// adds an element to the end of the array
	int pop_back();// removes and returns the last element of the array
	int insert(int , int );// inserts the value val at idx
	int erase(int , int );// erases the value val at idx
	int length();// returns the size of the Array
	void clear();//clears the contents of the Array
	int value(int );//returns the value at idx
	void assign(int , int );//assigns the value val to the element at index idx
	void display();// displays the Array
	bool isEmpty();// returns true if the Array is empty
	bool equal(TrueDynamicArray);// should return true if both Arrays are same
	int sort();// sorts the Array. Returns true if the array is already sorted
	void reverse();// reverses the contents of the array
	~TrueDynamicArray();
};

#endif /* TRUEDYNAMICARRAY_H_ */
