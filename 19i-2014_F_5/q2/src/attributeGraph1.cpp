/*
 * attributeGraph1.cpp
 *
 *  Created on: Apr 15, 2020
 *      Author: danyal-faheem
 */

#include "attributeGraph1.h"
#include "SimpleGraph.h"
#include<iostream>
using namespace std;

attributeGraph1::attributeGraph1(){
	arrNode = new attributedNode1[5];
	for(int counter = 1; counter < 6; counter++){
		addnode(counter);
	}
	cout << "AttributeGraph1 Object created through default constructor\nnodeids have been initialized with 1,2,3,4,5 respectively\n";
}

void attributeGraph1::appendAttribute(){
	int temp = 0;
	char mid;
	bool check;
	for(int counter = 0; counter < numNodes; counter++){
		check = false;
		cout << "Enter age for nodeid" << allnodes[counter].getid() << ": ";
		cin >> temp;
		arrNode[counter].setAge(temp);
		cout << "Enter gender(either F or M) for nodeid" << allnodes[counter].getid() << ": ";
		cin >> mid;
		if(mid == 'f' or mid == 'm' or mid == 'F' or mid == 'M'){
			arrNode[counter].setGender(mid);
		}
		else{
			for(;check != true;){
				cout << "Please only choose either f or m\nEnter gender again: ";
				cin >> mid;
				if(mid == 'f' or mid == 'm'){
					check = true;
				}
			}
		}
	}
}

void attributeGraph1::printneighbor(int id){
	int index = 0;
		bool check = false;
		for(int counter = 0; counter < numNodes; counter++){
			if(allnodes[counter].getid() == id){
				index = counter;
				check = true;
				break;
			}
		}
		if(check == false){
			cout << "\nInvalid Index\n";
			return;
		}
		else{
			SimpleNode* ptr = allnodes[index].getneighbor();
			cout << "Node with id " << id << " has following:\n";
			cout << "Number of neighbors: " << allnodes[index].getneighborcount() << endl;
			for(int counter = 0; counter < allnodes[index].getneighborcount(); counter++){
				cout << "Neighbor " << counter + 1 << " has Node id: " << ptr[counter].getid() << endl;
				cout << "Neighbor " << counter + 1 << " has Age: " << arrNode[ptr[counter].getid() - 1].getAge() << endl;
				cout << "Neighbor " << counter + 1 << " has Gender: " << arrNode[ptr[counter].getid() - 1].getGender() << endl;
			}
		}
}

void attributeGraph1::printdata(){
	cout << "Printing all nodes data\n";
		for(int counter = 0; counter < numNodes; counter++){
			cout << "\nNode with id " << allnodes[counter].getid() << " has following:\n";
			cout << "Age: " << arrNode[counter].getAge() << endl;
			cout << "Gender: " << arrNode[counter].getGender() << endl;
			printneighbor(allnodes[counter].getid());
		}
}

attributeGraph1::~attributeGraph1(){
	if (arrNode != NULL){
		cout << "attributeGraph1 object destructor called\n";
		delete []arrNode;
	}
}
