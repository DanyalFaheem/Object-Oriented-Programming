#include"Matrix.h"
#include<iostream>
using namespace std;

int main(){
	Matrix M1(3, 3);
		M1(0, 0) = 1; M1(0, 1) = 2; M1(0, 2) = 3;
		M1(1, 0) = 1; M1(1, 1) = 1; M1(1, 2) = 1;
		M1(2, 0) = 0; M1(2, 1) = 2; M1(2, 2) = 4;
		cout<<"\nCreating M1\n";
		Matrix M2(M1);//copy constructor;
		cout<<"\nCreating M2 by copy constructor using M1\n";
		cout<<"Current values of M2 and M1 are\n";
		cout<<M1;
		cout<<"Matrix M2 is equal to M1 as ";
		if( M2 == M1 ){
			cout<<"1\n";
		}
		cout<<"\nAdding ++ to Matrix M2 \n";
		M2++;
		cout<<"\nCurrent values of M2 are "<<M2<<endl;
		cout<<"Multiplying M2 and M1 and assigning to M3\n";
		Matrix M3 = M2 * M1;//assigning value
		cout<<"\n Adding M1 to M3\n";
		M3 += M1;
		cout<<"\n Subtracting M2 from M3";
		M3 -= M2;
		cout<<"\nShowing values of matrix M3\n";
		cout<< M3;
		return 0;
}
