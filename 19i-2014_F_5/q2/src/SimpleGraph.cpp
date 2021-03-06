/*
 * SimpleGraph.cpp
 *
 *  Created on: Apr 14, 2020
 *      Author: danyal-faheem
 */

#include "SimpleGraph.h"
#include<iostream>
using namespace std;

SimpleGraph::SimpleGraph(int n){
	allnodes = new SimpleNode[5]{{5},{5},{5},{5},{5}};
	numNodes = 0;
	numEdges = 0;
	cout << "Object of type Simple Graph created successfully with constructor\n";
}

void SimpleGraph::addnode(int nodeid){
		allnodes[numNodes].setid(nodeid);
		numNodes++;
}

void SimpleGraph::addEdge(int n1, int n2){
	int index1 = 0, index2 = 0;
	bool check1 = false, check2 = false;
	for(int counter = 0; counter < numNodes; counter++){
		if(allnodes[counter].getid() == n1){
			index1 = counter;
			check1 = true;
		}
		if(allnodes[counter].getid() == n2){
			index2 = counter;
			check2 = true;
		}
	}
	if(check1 == false or check2 == false){
		cout << "\nInvalid Indexes\n" << index1 << index2 << n1 << n2 << endl;
		return;
	}
	else{
		allnodes[index1].addEdge(allnodes[index2]);
		numEdges++;
	}
}

void SimpleGraph::printneighbor(int id){
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
		}
	}
}

void SimpleGraph::printdata(){
	cout << "Printing all nodes data\n";
	for(int counter = 0; counter < numNodes; counter++){
		cout << "\nNode id: " << allnodes[counter].getid() << endl;
		printneighbor(allnodes[counter].getid());
	}
}
SimpleGraph::~SimpleGraph(){
	if(allnodes != NULL){
		cout << "SimpleGraph object destructor called\n";
		delete []allnodes;
	}
}
