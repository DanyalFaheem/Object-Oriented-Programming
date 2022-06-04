/*
 * TrueDynamicArray.cpp
 *
 *  Created on: Mar 6, 2020
 *      Author: root
 */

#include "TrueDynamicArray.h"
#include<iostream>
using namespace std;

TrueDynamicArray::TrueDynamicArray() {
	link->value=size=0;
	link->next=NULL;
}
TrueDynamicArray::TrueDynamicArray(int* arr, int s){
	size=s;
	node* temp;
	for(int counter = 0; counter < size; counter++){
		if(counter == size-1){
			temp->next = NULL;
		}
		//cout<<temp<<endl;
		temp = temp->next;
		temp = new node;
		if(counter == 0 ){
			link = temp;
		}
		temp->value = arr[counter];
	}
	display();
}
TrueDynamicArray::TrueDynamicArray(int s){
	size=s;
	node* temp;
	for(int counter=0; counter<size; counter++){
	temp->next=new node;
	if(counter == size-1){
	temp->next=NULL;
			}
	if(counter == 0){
		link=temp;
			}
	}
}
TrueDynamicArray::TrueDynamicArray(const TrueDynamicArray& t){
	size=t.size;
	link=t.link;
}
int TrueDynamicArray::getAt(int index){
	node* temp;
	temp=link;
	for(int counter=0; counter<index; counter++){
		temp=temp->next;
	}
	return temp->value;
}
void TrueDynamicArray::setAt(int index, int val){
	node* temp;
		temp=link;
		for(int counter=0; counter<index; counter++){
			temp=temp->next;
		}
		temp->value=val;
}
TrueDynamicArray TrueDynamicArray::subArr(int p, int s){
	TrueDynamicArray obj(s);
	node* temp = link;
	node* temp2 = obj.link;
	for(int counter=0; counter<s; counter++){
		if(counter == p){
			for(int count = counter; count < s; count++){
				temp2->value = temp->value;
				temp2 = temp2->next;
				temp = temp->next;
			}
		}
	}
	return obj;
}
TrueDynamicArray TrueDynamicArray::subArr(int p){
	TrueDynamicArray obj(size-p);
	node* temp = link;
	node* temp2 = obj.link;
	for(int counter=0; counter<size; counter++){
		if(counter == p){
			for(int count = counter; count < size; count++){
				temp2->value = temp->value;
				temp2 = temp2->next;
				temp = temp->next;
			}
		}
	}
	return obj;
}
void TrueDynamicArray::push_back(int a){
	size++;
	node* temp = link;
	for(int counter = 0; counter < size; counter++){
		if(counter == size-1){
			temp->next=new node;
			temp->next->value = a;
			temp->next->next = NULL;
		}
		else{
		temp = temp->next;
		}
	}
}
int TrueDynamicArray::pop_back(){
	int val = 0;
	node* temp = link;
	for(int counter = 0; counter < size-2; counter++){
		if(counter == size-2){
			val = temp->next->value;
			temp->next=NULL;
		}
		else{
			temp = temp->next;
		}
	}
	return val;
}
int TrueDynamicArray::insert(int index, int val){
	node* temp;
	temp=link;
	for(int counter=0; counter<index; counter++){
		temp=temp->next;
	}
	temp->value=val;
	return val;
}
int TrueDynamicArray::erase(int i, int v){
	node* temp = link;
	bool check = false;
	for(int counter = 0; counter < size-2; counter++){
			if(counter == size-2){
				temp->next=NULL;
				check = true;
			}
			else{
				temp = temp->next;
			}
		}
	return check;
}
int TrueDynamicArray::length(){
	return size;
}
void TrueDynamicArray::clear(){
	node* temp = link;
	for(int counter = 0; counter < size; counter++){
		temp->value=0;
		temp = temp->next;
	}
}
int TrueDynamicArray::value(int index){
	node* temp;
		temp=link;
		for(int counter=0; counter<index; counter++){
			temp=temp->next;
		}
		return temp->value;
}
void TrueDynamicArray::assign(int index, int val){
	node* temp;
	temp=link;
	for(int counter=0; counter<index; counter++){
		temp=temp->next;
	}
	temp->value = val;
}
void TrueDynamicArray::display(){
	node* temp = link;
	cout<<"Following are the values of the array\n";
	for(int counter = 0; counter < size; counter++){
		cout<<temp->value<<endl;
		temp = temp->next;
	}
}
bool TrueDynamicArray::isEmpty(){
	node* temp = link;
	for(int counter = 0; counter < size; counter++){
		if(temp->value != 0){
			return false;
		}
		temp = temp->next;
	}
	return true;
}
bool TrueDynamicArray::equal(TrueDynamicArray t){
	if(size != t.size){
		return false;
	}
	node* temp = link;
	node* temp2 = t.link;
	for(int counter = 0; counter < size; counter++){
		if(temp->value != temp2->value){
			return false;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	return true;
}
int TrueDynamicArray::sort(){
	bool check = true;
	node* temp = link;
	for(int counter = 0; counter < size; counter++){
		for(int count = 0; count < counter; count++){
			if( temp->value > temp->next->value ){
				int temperary = temp->value;
				temp->value = temp->next->value;
				temp->next->value = temperary;
				check = false;
			}
		}
	}
	return check;
}
void TrueDynamicArray::reverse(){

}
TrueDynamicArray::~TrueDynamicArray() {
	if(link != NULL){
		node* temp;
		for(int counter = 0; counter < size; counter++){
			temp = link;
			for(int count = 0; count < size - counter+1; count++){
				temp = temp->next;
			}
			delete temp;
		}
	}
}

