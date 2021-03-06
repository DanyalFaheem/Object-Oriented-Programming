/*
 * attributeGraph2.cpp
 *
 *  Created on: Apr 17, 2020
 *      Author: danyal-faheem
 */

#include "attributeGraph2.h"
#include<iostream>
#include<string>
using namespace std;

attributeGraph2::attributeGraph2(){
	arrnodes = new attributedNode2[5];
	cout << "AttributeGraph2 Object created through default constructor\nnodeids have been initialized with 1,2,3,4,5 respectively\n";
	for(int counter = 1; counter < 6; counter++){
			addnode(counter);
		}
}

void attributeGraph2::appendAttribute(){
	string temp,mid;
	for(int counter = 0; counter < numNodes; counter++){
		cout << "Enter profession for nodeid" << allnodes[counter].getid() << ": ";
		getline(cin,temp);
		arrnodes[counter].setprof(temp);
		cout << "Enter location (CityName) for nodeid" << allnodes[counter].getid() << ": ";
		getline(cin,mid);
		arrnodes[counter].setloc(mid);
	}
}

void attributeGraph2::printneighbor(int id){
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
			cout << "Neighbor " << counter + 1 << " has Profession: " << arrnodes[ptr[counter].getid() - 1].getprof() << endl;
			cout << "Neighbor " << counter + 1 << " has Location: " << arrnodes[ptr[counter].getid() - 1].getloc() << endl;
		}
	}
}

void attributeGraph2::printdata(){
	cout << "Printing all nodes data\n";
	for(int counter = 0; counter < numNodes; counter++){
		cout << "\nNode with id " << allnodes[counter].getid() << " has following:\n";
		cout << "Profession: " << arrnodes[counter].getprof() << endl;
		cout << "Location: " << arrnodes[counter].getloc() << endl;
		printneighbor(allnodes[counter].getid());
	}
}

attributeGraph2::~attributeGraph2(){
	if(arrnodes != NULL){
		cout << "AttributeGraph2 Object Destructor called\n";
		delete []arrnodes;
	}
}
