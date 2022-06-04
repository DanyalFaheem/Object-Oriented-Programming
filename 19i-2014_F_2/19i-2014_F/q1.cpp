#include<iostream>
using namespace std;
int fact_n(int input_1){	//Function for use in Q1	
		if(input_1==0||input_1==1){
			return 1;
		}
		return input_1*fact_n(input_1-1);
	}
int fact_r(int input_2){	//Function for use in Q1
		if(input_2==0||input_2==1){
			return 1;
		}
		return input_2*fact_r(input_2-1);
	}
int fact_subtr(int subtr){	//Function for use in Q1
		if(subtr==0||subtr==1){
			return 1;
		}
		return subtr*fact_subtr(subtr-1);
	}
int rec_ncr(int n,int r)
{
	int subtr=n-r;
	return fact_n(n)/(fact_r(r)*fact_subtr(subtr));
	
}

