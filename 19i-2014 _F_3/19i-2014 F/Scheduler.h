/*
 * Scheduler.h
 *
 *  Created on: Mar 4, 2020
 *      Author: root
 */
#include<iostream>
using namespace std;

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
struct task{
int id;
int dur;
int s_Time; //start time of each task
int e_Time; //end time of each task
int* dep; /*list of predecessors of this task - To simplify we assume that a higher
number task will depend on a lower number task e.g. T2 can depend on T1 OR T4 can
depend on T2 but the opposite is not true.*/
};

class Scheduler {
private:
	task* tasks;
	const int SIZE;
	int crit_no;
public:
	Scheduler();
	Scheduler(task* , int );//initialized the project with n tasks
	void setTaskDuration();//change task duration of all tasks
	void set_nth_TaskDuration(int);//change duration of a specific task
	int* setsTasksDependency();
	void printTaskDependencyList(int*);//print dependencies of a specific task
	int completionTime(int*);//print completion time of the project
	int* printCriticalTasks(int*);/*returns array of critical tasks and displays them – sum of
	their duration should be equal to project completion time*/
	~Scheduler();
};

#endif /* SCHEDULER_H_ */
