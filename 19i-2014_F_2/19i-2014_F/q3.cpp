#include<iostream>
using namespace std;
int sum_of_Perfect(int num,int mid)
{
		if(mid<1){
			return 0;
		}	
		if(num%mid==0 && mid!=1){
			sum_of_Perfect(num,mid-1);
			return num;		
		}
}
