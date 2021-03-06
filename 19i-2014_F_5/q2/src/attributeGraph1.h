/*
 * attributeGraph1.h
 *
 *  Created on: Apr 15, 2020
 *      Author: danyal-faheem
 */

#ifndef ATTRIBUTEGRAPH1_H_
#define ATTRIBUTEGRAPH1_H_
#include"SimpleGraph.h"
#include"attributedNode1.h"
#include<iostream>
using namespace std;
class attributeGraph1: public SimpleGraph {
protected:
	attributedNode1* arrNode;
public:
	attributeGraph1();//default constructor
	void appendAttribute();
	   /*iterate a loop over array of SimpleNode "allnode" to read the NodeID's
	     and ask user to add attributes (Gender, Age) into AttributeNode1
	     array on same index as of SimpleNode array.
	   */
	virtual void printdata();
	  /* 1. Apply the run-time polymorphism to override the SimpleGraph function by
	        this derived function.
	     2. print all the attributes and their neighbor
	        (for neighbor use same functionality as in Printneighbor() of SimpleNode class)
	   */
	virtual void printneighbor(int id);
	 //Runtime polymorphism to override the SimpleGraph function of printNeighbor()
	           /* 1. First of all find the index using the id
	             2. Getneighborcount against the id
	             3. getneighbor array against the index.
	             4. iterate the loop to print all neighbor in a given array
	           */
	virtual ~attributeGraph1(); // handle the memory leakage by using virtual destructor both for based & derived class.
};

#endif /* ATTRIBUTEGRAPH1_H_ */
