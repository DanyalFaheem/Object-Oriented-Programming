/*
 * SimpleGraph.h
 *
 *  Created on: Apr 14, 2020
 *      Author: danyal-faheem
 */

#ifndef SIMPLEGRAPH_H_
#define SIMPLEGRAPH_H_
#include"SimpleNode.h"
#include<iostream>
using namespace std;

class SimpleGraph {
protected:
	int numNodes,numEdges;
    SimpleNode *allnodes;
public:
	SimpleGraph(int n=5); // overloaded constructor to create the array of Node
    /*this will initialize the SimpleNode array of
    size=n in SimpleNode class against each of the
    object of allnode of SimpleGraph class*/

	void addnode(int nodeid);        //Nodeid is added to the allNode array
	void addEdge(int n1, int n2);
        /* 1.this function will find the index of the nodeid1 and nodeid2
           2. check both the id's are present in allnode array
           3. if its true than call the SimpleNode addEdge function
              by calling from one of the index1 and passing the other index2.
              index1.addEdge(index2); // this will create the edge index1-index2
	    4.Increment the edgecount
        */
	virtual void printneighbor(int id);
         /* 1. First of all find the index using the id
            2. Getneighborcount against the id
            3. getneighbor array against the index.
            4. iterate the loop to print all neighbor in a given array
          */
	virtual void printdata(); // print all node data
	virtual ~SimpleGraph();

};

#endif /* SIMPLEGRAPH_H_ */
