/*
 * SimpleNode.cpp
 *
 *  Created on: Apr 14, 2020
 *      Author: danyal-faheem
 */

#include "SimpleNode.h"
#include<iostream>
using namespace std;

SimpleNode::SimpleNode()
{
		arrNeighbors = NULL;
		nodeid = NeighborCount = 0;
		cout << "SimpleNode object created through default constructor\n";
}

SimpleNode::SimpleNode(int n){
	if(n > 0){
		arrNeighbors = new SimpleNode[n];
		NeighborCount = 0;
		nodeid = 0;
		cout << "SimpleNode object created through parameterized constructor\n";
	}
	else{
		arrNeighbors = NULL;
		NeighborCount = nodeid = 0;
	}
}

void SimpleNode::setid(int id){
	nodeid = id;
}

int SimpleNode::getid(){
	return nodeid;
}

int SimpleNode::getneighborcount(){
	return NeighborCount;
}

void SimpleNode::addEdge(const SimpleNode& n){
	arrNeighbors[NeighborCount] = n;
	NeighborCount++;
}

SimpleNode* SimpleNode::getneighbor(){
	return arrNeighbors;
}

SimpleNode::~SimpleNode(){
	cout << "Simple node destructor called\n";
}
