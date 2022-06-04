/*
 * SimpleNode.h
 *
 *  Created on: Apr 14, 2020
 *      Author: danyal-faheem
 */

#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_
#include<iostream>
using namespace std;
class SimpleNode {
private:
	int nodeid,NeighborCount;
	SimpleNode* arrNeighbors;
public:
	SimpleNode();
	SimpleNode(int n);
	void setid(int id);//set Nodeid
	int getid();//return the nodeid
	int getneighborcount();//return neighborCount
	SimpleNode* getneighbor();//return the array of neighbor
	void addEdge(const SimpleNode& n);//add the edge from caller to the node
	~SimpleNode();
};

#endif /* SIMPLENODE_H_ */
