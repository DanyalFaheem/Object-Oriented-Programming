/*
 * attributeWeightedGraph.cpp
 *
 *  Created on: Apr 17, 2020
 *      Author: danyal-faheem
 */

#include "attributeWeightedGraph.h"
#include "SimpleGraph.h"
#include<iostream>
using namespace std;

attributeWeightedGraph::attributeWeightedGraph(){
	index = 0;
	weights = new int*[5];
	for(int counter = 0; counter < 5; counter++){
		weights[counter] = new int[attributeGraph1::allnodes[counter].getneighborcount()];
		for(int count = 0; count < attributeGraph1::allnodes[counter].getneighborcount(); count++){
			weights[counter][count] = 0;
		}
	}
	cout << "AttributeWeightedGraph object created through default constructor\n";
}

void attributeWeightedGraph::appendWeight(int n1, int n2, int weight){
	int index1 = 0, index2 = 0;
	bool check1 = false, check2 = false;
	for(int counter = 0; counter < attributeGraph1::numNodes; counter++){
		if(attributeGraph1::allnodes[counter].getid() == n1){
			index1 = counter;
			check1 = true;
		}
		if(attributeGraph1::allnodes[counter].getid() == n2){
			index2 = counter;
			check2 = true;
		}
	}
	if(check1 == false or check2 == false){
		cout << "\nInvalid Indexes\n" << index1 << index2 << n1 << n2 << endl;
		return;
	}
	else{
		bool chck = false;
		SimpleNode* temp_ptr = attributeGraph1::allnodes[index1].getneighbor();
		int counter = 0;
		for(; counter < attributeGraph1::allnodes[index1].getneighborcount(); counter++){
			if(temp_ptr[counter].getid() == n2){
				chck = true;
				break;
			}
		}
		int count = 0;
		for(; count < attributeGraph1::allnodes[index2].getneighborcount(); count++){
			if(temp_ptr[count].getid() == n1){
				chck = true;
				break;
			}
		}
		if(chck == true ){
			weights[index1][counter] = weight;
			weights[index2][count] = weight;
		}
		else{
			cout << "Edge does not exist between nodeid " << n1 << " and nodeid " << n2 << endl;
			return;
		}
	}
}

void attributeWeightedGraph::printneighbor(int id){
	int index = 0;
	bool check = false;
	for(int counter = 0; counter < attributeGraph1::numNodes; counter++){
		if(attributeGraph1::allnodes[counter].getid() == id){
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
		SimpleNode* ptr = attributeGraph1::allnodes[index].getneighbor();
		cout << "Node with id " << id << " has following:\n";
		cout << "Number of neighbors: " << attributeGraph1::allnodes[index].getneighborcount() << endl;
			for(int counter = 0; counter < attributeGraph1::allnodes[index].getneighborcount(); counter++){
				cout << "Neighbor " << counter + 1 << " has Node id: " << ptr[counter].getid() << endl;
				cout << "Neighbor " << counter + 1 << " has Age: " << arrNode[ptr[counter].getid() - 1].getAge() << endl;
				cout << "Neighbor " << counter + 1 << " has Gender: " << arrNode[ptr[counter].getid() - 1].getGender() << endl;
				cout << "Neighbor " << counter + 1 << " has Profession: " << arrnodes[ptr[counter].getid() - 1].getprof() << endl;
				cout << "Neighbor " << counter + 1 << " has Location: " << arrnodes[ptr[counter].getid() - 1].getloc() << endl;
				if(weights[id - 1][counter] != 0){
					cout << "Weight on edge between nodeid " << id << " and Neighbor " << counter + 1 << " is: " << weights[id - 1][counter] << endl;
				}
			}
	}
}

void attributeWeightedGraph::printdata(){
	cout << "Printing all nodes data\n";
	for(int counter = 0; counter < attributeGraph1::numNodes; counter++){
		cout << "\nNode with id " << attributeGraph1::allnodes[counter].getid() << " has following:\n";
		cout << "Age: " << arrNode[counter].getAge() << endl;
		cout << "Gender: " << arrNode[counter].getGender() << endl;
		cout << "Profession: " << arrnodes[counter].getprof() << endl;
		cout << "Location: " << arrnodes[counter].getloc() << endl;
		printneighbor(attributeGraph1::allnodes[counter].getid());
	}
}

attributeWeightedGraph::~attributeWeightedGraph(){
	if(weights != NULL){
		cout << "AttributedWeightGraph Object Destructor called\n";
		for(int counter = 0; counter < 5; counter++){
			delete []weights[counter];
		}
		delete[]weights;
	}
}
