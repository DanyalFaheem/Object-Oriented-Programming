/*
 * String.h
 *
 *  Created on: Mar 3, 2020
 *      Author: root
 */
#include<iostream>
using namespace std;

#ifndef STRING_H_
#define STRING_H_

class String {
private:
	 char* s;
	int SIZE;
public:
	String();// default constructor
	String(char *str);// initializes the string with constant cstring
	String(const String &);// copy constructor
	String(int x);// initializes a string of pre-defined size
	char getAt(int );// returns the character at index [x]
	void setAt(int , char );// set the character at index [x]
	string substr(int , int );// returns a substring of length len from ‘pos’
	string substr(int );// returns substring from the given position to the end.
	void append(char );// append a char at the end of string
	void append(String );// append a String at the end of string
	void append(char * );// append a constant c string at the end of string
	int length();// returns the length of string
	char* tocstring();// converts a String to c-string
	void display();// displays the string ..
	bool isEmpty();// returns true if string is empty..
	void copy(const String&);// Copy one string to another ...
	void copy(const char *);// copy cstring to String...
	int find(char);// returns the index of character being searched.
	bool equal(String);// should return true if both strings are same
	int stoi();// function for converting a string to integer.
	int strlen(const char*);//for own use in program
	~String();
};

#endif /* STRING_H_ */
