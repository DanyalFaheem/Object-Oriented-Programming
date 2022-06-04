//============================================================================
// Name        : q3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Scheduler.h"
#include <iostream>
using namespace std;

int main() {
	task* t=new task[8];//Initializing array
	Scheduler s(t,8);//Calling Constructor
	s.setTaskDuration();
	int* depen_no=s.setsTasksDependency();
	//s.printTaskDependencyList(depen_no);
	cout<<"Completion time of Project is "<<s.completionTime(s.printCriticalTasks(depen_no))<<endl;
	return 0;
}
