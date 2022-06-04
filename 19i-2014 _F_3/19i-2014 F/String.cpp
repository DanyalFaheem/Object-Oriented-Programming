/*
 * String.cpp
 *
 *  Created on: Mar 3, 2020
 *      Author: root
 */

#include "String.h"

#include<iostream>

String::String() {
	s=NULL;
	*s='\0';
	SIZE=0;
	// TODO Auto-generated constructor stub
}
String::String(char* str):SIZE(strlen(str)+1){
	s=new char[strlen(str)+1];
	s=str;
}
String::String(const String& st):SIZE(st.SIZE){
	*s=*(st.s);
}
String::String(int x){
	s=new char[x];
}
char String::getAt(int index){
	return s[index];
}
void String::setAt(int index, char ch){
	s[index]=ch;
}
string String::substr(int position, int length){
	char* substr=new char[length+1];
	for(int counter=position,index=0; index<length ; counter++,index++){
		substr[index]=s[counter];
	}
	return substr;
}
string String::substr(int position){
	char* substr=new char[strlen(s)-position+1];
	for(int counter=position, index=0; counter<strlen(s); counter++, index++){
		substr[index]=s[counter];
	}
	return substr;
}
void String::append(char ch){
	SIZE++;
	s[SIZE-1]=ch;
	s[SIZE]=0;
}
void String::append(char* str){
	SIZE+=strlen(str);
	for(int counter=strlen(str)-1, index=0; counter<SIZE-1; counter++,index++){
		s[counter]=str[index];
	}
	s[SIZE]=0;
}
void String::append(String st){

}
int String::length(){
	int counter=0;
	for(; *(s+counter)!=0; counter++){
	}
	return counter;
}
char* String::tocstring(){
	return s;
}
bool String::isEmpty(){
	if(*s==0){
		return true;
	}
	else{
		return false;
	}
}
void String::display(){
	cout<<"The string is: ";
	for(int counter=0; counter<SIZE; counter++){
		cout<<s[counter];
	}
}
void String::copy(const String& st){
	if(strlen(st.s) >= strlen(s)){
		cout<<"Invalid conversion. String is larger than original string";
	}
	else{
		for(int counter=0; counter<SIZE; counter++){
			if(counter == strlen(st.s)){
				for(int count=counter; count<SIZE; count++){
					s[count]=0;
				}
			}
			else{
				s[counter]=st.s[counter];
			}
		}
	}
}
void String::copy(const char* st){
	if(strlen(st) >= strlen(s)){
			cout<<"Invalid conversion. String is larger than original string";
		}
		else{
			for(int counter=0; counter<SIZE; counter++){
				if(counter == strlen(st)){
					for(int count=counter; count<SIZE; count++){
						s[count]=0;
					}
				}
				else{
					s[counter]=st[counter];
				}
			}
		}
}
int String::find(char ch){
	int index=0;
	for(int counter=0; *(s+counter)!=0; counter++){
		if(s[counter]==ch){
			index=counter;
			break;
		}
	}
	return index;
}
bool String::equal(String st){
	if(strlen(st.s) != strlen(s)){
				return false;
			}
	for(int counter=0; *(s+counter)!=0; counter++){
		if(s[counter]!=st.s[counter]){
			return false;
		}
	}
	return true;
}
int String::stoi(){
	int num=0,multiplier=1;
	for(int counter=0; *(s+counter)!=0; counter++,multiplier*=10){
		num+=(s[counter]*multiplier);
	}
	return num;
}
int String::strlen(const char* string_1){
	int length=0;
	for(; string_1[length]!=0; length++){
	}
	return length;
}
String::~String() {
	// TODO Auto-generated destructor stub
	if(s != NULL){
		delete []s;
	}
}

