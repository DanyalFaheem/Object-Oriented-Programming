/*
 * Scheduler.cpp
 *
 *  Created on: Mar 4, 2020
 *      Author: root
 */

#include "Scheduler.h"

#include<iostream>
using namespace std;

Scheduler::Scheduler():SIZE(0) {
	// TODO Auto-generated constructor stub
	tasks=NULL;
	crit_no=0;
}
Scheduler::Scheduler(task* t, int s):SIZE(s){
	tasks=t;
	crit_no=0;
}
void Scheduler::setTaskDuration(){
	cout<<"Enter the values for the following times\n";
	for(int counter=0; counter<SIZE; counter++){
		tasks[counter].id=counter+1;
		cout<<"Enter the starting time of task "<<counter+1<<endl;
		cin>>tasks[counter].s_Time;
		cout<<"Enter the ending time of task "<<counter+1<<endl;
		cin>>tasks[counter].e_Time;
		if(tasks[counter].e_Time < tasks[counter].s_Time){
			for(bool check=false; check!=true; ){
				cout<<"Ending time should be after start time, Please enter correct value "<<counter+1<<endl;
				cin>>tasks[counter].e_Time;
				if(tasks[counter].e_Time > tasks[counter].s_Time){
					check=true;
				}
			}
		}
		tasks[counter].dur=tasks[counter].e_Time-tasks[counter].s_Time;
	}
}
void Scheduler::set_nth_TaskDuration(int index){
	cout<<"Enter the starting time of task "<<index<<endl;
			cin>>tasks[index-1].s_Time;
			cout<<"Enter the ending time of task "<<index<<endl;
			cin>>tasks[index-1].e_Time;
			if(tasks[index-1].e_Time < tasks[index-1].s_Time){
						for(bool check=false; check!=true; ){
							cout<<"Ending time should be after start time, Please enter correct value "<<index<<endl;
							cin>>tasks[index-1].e_Time;
							if(tasks[index-1].e_Time > tasks[index-1].s_Time){
								check=true;
							}
						}
			}
			tasks[index-1].dur=tasks[index-1].e_Time-tasks[index-1].s_Time;
}
int* Scheduler::setsTasksDependency(){
	int no_dep[SIZE];
	int* dep_no=no_dep;
	cout<<"Please enter the dependency of the following tasks\n";
	for(int counter=0; counter<SIZE; counter++){
		cout<<"Enter the number of tasks dependent on task "<<counter+1<<": ";
		cin>>no_dep[counter];
		tasks[counter].dep=new int[no_dep[counter]];
		cout<<"Enter the id of dependent tasks in ascending order of ids\n";
		for(int count=0; count<no_dep[counter]; count++){
			cout<<"Enter the id of task dependent on task "<<counter+1<<" :";
			cin>>tasks[counter].dep[count];
			if(tasks[counter].dep[count] >= counter+1){
				for(bool check=false; check!=true; ){
					cout<<"Tasks cannot depend on a higher number task. Please enter correct id: ";
					cin>>tasks[counter].dep[count];
					if(tasks[counter].dep[count] < counter+1){
						check=true;
					}
				}
			}
		}
	}
	return dep_no;
}
void Scheduler::printTaskDependencyList(int* no_dep){
	cout<<"Following are the tasks and their dependent tasks\n";
	for(int counter=0; counter<SIZE; counter++){
		if(no_dep[counter] != 0 && no_dep[counter] != SIZE){
		cout<<"Task "<<counter+1<<" is dependent on\n";
		for(int count=0; count<no_dep[counter]; count++){
			cout<<"Task "<<tasks[counter].dep[count];
		}
		}
	}
}
int Scheduler::completionTime(int* crit){
	int time=0;
	for(int counter=0; counter<crit_no; counter++){
		time+=tasks[counter].dur;
	}
	return time;
}
int* Scheduler::printCriticalTasks(int* no_dep){
	int max_time=0;
	crit_no=1;
	int* critical=new int[crit_no];
	for(int counter=0; counter<no_dep[SIZE-1]; counter++){
		if(tasks[tasks[SIZE-1].dep[counter]].dur > max_time){
			max_time=tasks[tasks[SIZE-1].dep[counter]].dur;
			critical[crit_no-1]=tasks[tasks[SIZE-1].dep[counter]].id;
		}
	}
	for(int count=1; critical[crit_no-count] != 1; count++){
	crit_no++;
		for(int counter=0; counter<no_dep[critical[crit_no-count]]; counter++){
			if(tasks[tasks[critical[crit_no-count]].dep[counter]].dur > max_time){
				max_time=tasks[tasks[critical[crit_no-count]].dep[counter]].dur;
				critical[crit_no-count+1]=tasks[tasks[critical[crit_no-1]].dep[counter]].id;
			}
		}
	}
	crit_no++;
	critical[crit_no] = tasks[SIZE-1].id;
	cout<<"Critical Tasks are\n";
	for(int counter=0; counter<crit_no; counter++){
		cout<<"Task "<<critical[counter]<<endl;
	}
	return critical;
}
Scheduler::~Scheduler() {
	// TODO Auto-generated destructor stub
	if(tasks != NULL){
		delete []tasks;
	}
}

