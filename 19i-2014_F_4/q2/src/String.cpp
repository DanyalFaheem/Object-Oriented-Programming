/*
 * String.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: danyal-faheem
 */

#include "String.h"
#include<iostream>
#include<cstring>
using namespace std;
String::String() {
	// TODO Auto-generated constructor stub
	str = NULL;
	size = 0;
}

String::String(int x){
	if(x > 0){
	str = new char[x];
	size = x;
	}
	else{
		size = 0;
		str = NULL;
	}
}

String::String(char* s){
	if(s != NULL){
		size = slen(s);
		str = new char[slen(s)];
		for(int counter = 0; counter < String::slen(s); counter++){
			str[counter] = s[counter];
		}
	}
	else{
		size = 0;
		str = NULL;
	}
}

String::String(const String &other) {
	if(other.str != NULL){
		size = slen(other.str);
		str = new char[slen(other.str)];
		for(int counter = 0; counter < slen(other.str); counter++){
			str[counter] = other.str[counter];
		}
	}
	else{
		size = 0;
		str = NULL;
	}
}

char& String::operator [](int index){
	if(index >= 0 and index < length()){
		return str[index];
	}
}

char& String::operator [](int index)const{
	if(index >= 0 and index < slen(this->str)){
		return str[index];
	}
}

String& String::operator +(const String& s){
	String* p = new String(s.length()+length()+1);
	for(int counter = 0; counter < length(); counter++){
		(*p).str[counter] = str[counter];
	}
	for(int counter = length(),count = 0; counter < s.length()+length(); counter++,count++){
			(*p).str[counter] = s.str[count];
		}
	return *p;
}

String& String::operator +(char* s){
	String* p = new String(slen(s)+length()+1);
	for(int counter = 0; counter < length(); counter++){
		(*p).str[counter] = str[counter];
	}
	for(int counter = length(),count = 0; counter < slen(s)+length(); counter++,count++){
		(*p).str[counter] = s[count];
		}
	return *p;
}

String& String::operator +(const char& s){
	String* p = new String(1+length()+1);
	for(int counter = 0,count = 0; counter < length()+length(); counter++,count++){
		(*p).str[counter] = str[count];
	}
	(*p).str[length()] = s;
	return *p;
}

bool String::operator !(){
	if(str == NULL){
		return true;
	}
	else{
		for(int counter = 0; counter < (length()-1); counter++){
			if(str[counter] != 0){
				return false;
			}
		}
	}
	return true;
}

String& String::operator -(const String& s){
	String* p = new String(length()-s.length()+1);
	bool check = true;
	for(int counter = 0; counter < length(); counter++){
		if(str[counter] == s.str[0]){
			for(int count = 1; count < s.length(); count++){
				if(str[counter+count] != s.str[count]){
					check = false;
				}
			}
		if(check == true){
			int c = 0;
			for(int count2 = 0; count2 < counter; count2++,c++){
				(*p).str[count2] = str[count2];
			}
			for(int count2 = counter+s.length(); count2 < length(); count2++){
				(*p).str[c] = str[count2];
			}
			return *p;
		}
		}
	}
	(*p).str = "SubStr not found";
	return *p;
}

String& String::operator =(const String& s){
	this->str = new char[s.length()+1];
	for(int counter = 0; counter < s.length()+1; counter++){
		this->str[counter] = s.str[counter];
	}
	return *this;
}

String& String::operator =(char* s){
	str = new char[slen(s)+1];
		for(int counter = 0; counter < length(); counter++){
			str[counter] = s[counter];
		}
		return *this;
}

String& String::operator =(const string& s){
	for(int counter = 0; counter < s.length(); counter++){
			str[counter] = s[counter];
		}
	return *this;
}

bool String::operator ==(const String& s)const{
	if(length() != s.length()){
		return false;
	}
	for(int counter = 0; counter < length(); counter++){
		if(str[counter] != s.str[counter]){
			return false;
		}
	}
	return true;
}

bool String::operator ==(char* s)const{
	if(length() != slen(s)){
			return false;
		}
		for(int counter = 0; counter < length(); counter++){
			if(str[counter] != s[counter]){
				return false;
			}
		}
		return true;
}

int& String::operator ()(char s){
	int* p = new int;
	for(int counter = 0; counter < length(); counter++){
		if(str[counter] == s){
			*p = counter;
			return *p;
		}
	}
	*p = -1;
	return *p;
}

int& String::operator ()(const String& s){
	int* p = new int;
	bool check = true;
	for(int counter = 0; counter < length(); counter++){
			if(str[counter] == s.str[0]){
				for(int count = 1; count < s.length(); count++){
					if(str[counter + count] != s[count]){
						check = false;
					}
				}
				if(check == true){
					*p = counter;
								return *p;
				}
			}
		}
		*p = -1;
		return *p;
}

int& String::operator ()(char* s){
	int* p = new int;
	bool check = true;
		for(int counter = 0; counter < length(); counter++){
				if(str[counter] == s[0]){
					for(int count = 1; count < slen(s); count++){
						if(str[counter + count] != s[count]){
							check = false;
						}
					}
					if(check == true){
						*p = counter;
									return *p;
					}
				}
			}
		*p = -1;
				return *p;
}

int& String::operator ()(const string& s){
	int* p = new int;
	bool check = true;
		for(int counter = 0; counter < length(); counter++){
				if(str[counter] == s[0]){
					for(int count = 1; count < s.length(); count++){
						if(str[counter + count] != s[count]){
							check = false;
						}
					}
					if(check == true){
						*p = counter;
									return *p;
					}
				}
			}
		*p = -1;
				return *p;
}

String String::operator *(int a){
	String copy(((length())*a)+1);
	for(int counter = 0, index = 0; counter < a; counter++){
		for(int count = 0; count < length(); count++, index++){
			copy.str[index] = str[count];
		}
	}
	return copy;
}

int String::length(){
	int counter = 0;
	for(; str[counter] != 0; counter++){}
	return counter;
}

int String::length()const{
	int counter = 0;
	for(; str[counter] != 0; counter++){}
	return counter;
}

int String::slen(char* s)const{
	int counter = 0;
	for(; s[counter] != 0; counter++){}
	return counter;
}
String::~String() {
	if(str != NULL){
		delete []str;
	}
}

char* String::get()const{
	return str;
}

int String::gets()const{
	return size;
}

void String::set(char* p){
	str = p;
}
ostream& operator<<(ostream& input, const String& s){
	for(int counter = 0; counter < s.length(); counter++){
		input << s[counter];
	}
	input << endl;
	return input;
}

istream& operator>>(istream& ouput, String& s){
	cout << "Enter your string: ";
	char inp[5];
	ouput >> inp;
	s.set(inp);
	return ouput;
}
