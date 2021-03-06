/*
 * String.h
 *
 *  Created on: Mar 28, 2020
 *      Author: danyal-faheem
 */

#ifndef STRING_H_
#define STRING_H_
#include<iostream>
#include<cstring>
using namespace std;
class String {
private:
	char* str;
	int size;
public:
	String();
	String(char* str);
	String(const String &other);
	String(int x);
	void set(char*);
	char* get()const;
	int gets()const;
	char& operator[](int i);
	char& operator[](int i)const;
	String& operator+(const String&);
	String& operator+(const char& str);
	String& operator+(char* str);
	String& operator-(const String&);
	bool operator!();
	String& operator=(const String&);
	String& operator=(char*);
	String& operator=(const string&);
	bool operator==(const String&)const;
	bool operator==(char*)const;
	int& operator()(char);
	int& operator()(const String&);
	int& operator()(const string&);
	int& operator()(char*);
	String operator*(int a);
	int length();
	int length()const;
	int slen(char*)const;//for own use in program
	~String();
};
ostream& operator<<(ostream& input, const String&);
istream& operator>>(istream& ouput, String&);
#endif /* STRING_H_ */
