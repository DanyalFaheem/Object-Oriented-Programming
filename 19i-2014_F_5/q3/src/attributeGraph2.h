/*
 * attributeGraph2.h
 *
 *  Created on: Apr 17, 2020
 *      Author: danyal-faheem
 */

#ifndef ATTRIBUTEGRAPH2_H_
#define ATTRIBUTEGRAPH2_H_
#include "SimpleGraph.h"
#include "attributedNode2.h"
#include<iostream>
using namespace std;
class attributeGraph2 : public SimpleGraph{
protected:
	attributedNode2* arrnodes;
public:
	attributeGraph2();//default constructor
	void appendAttribute();
	   /*
	     iterate a loop over array of SimpleNode "allnode" to read the NodeID's
	     and ask user to add attributes (Profession, location) into AttributeNode2
	     array on same index as of SimpleNode array.
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
	virtual ~attributeGraph2(); // handle the memory leakage by using virtual destructor both for based & derived class.
};

#endif /* ATTRIBUTEGRAPH2_H_ */
