/*
 * attributeWeightedGraph.h
 *
 *  Created on: Apr 17, 2020
 *      Author: danyal-faheem
 */

#ifndef ATTRIBUTEWEIGHTEDGRAPH_H_
#define ATTRIBUTEWEIGHTEDGRAPH_H_
#include"SimpleGraph.h"
#include"attributeGraph1.h"
#include"attributeGraph2.h"
#include<iostream>
using namespace std;
class attributeWeightedGraph: public attributeGraph1, public attributeGraph2 {
protected:
	int** weights;
	int index;
public:
	attributeWeightedGraph();//default constructor
	void appendWeight(int n1,int n2, int weight);
	   /*1. iterate a loop over array of SimpleNode "allnode" to read the Node Index of n1 and n2
		 2. If both the nodes are present then check if both have an edge.
		 3. if the edge also exist then  add the weight using indexes of a Nodes and maintain 2D Array of weightedvalues.
		   id's N1-N2 have weight of 5 then indexes of N2-N1 must have the same weight.
	   */
	virtual void printdata();
	  /* 1. Apply the run-time polymorphism to override the SimpleGraph function by
			this derived the function.
		 2. print all the attributes and their neighbor
			(for neighbor use same functionality as in Printneighbor() of SimpleNode class)
	   */
	virtual void printneighbor(int id);  //Runtime polymorphism to override the SimpleGraph function of printNeighbor()
			   /* 1. First of all find the index using the id
				 2. Getneighborcount against the id
				 3. getneighbor array against the index.
				 4. iterate the loop to print all neighbor in a given array
			   */
	virtual ~attributeWeightedGraph(); // handle the memory leakage by using virtual destructor both for based & derived class.

};

#endif /* ATTRIBUTEWEIGHTEDGRAPH_H_ */
