#include<iostream>
using namespace std;
//Start of Part 1( Arrow)
void Spaces_Arrow(int x){
	if(x==0){
		return;
	}
	cout<<" ";
	Spaces_Arrow(x-1);
}
void Asterisk_Arrow(int n){
	if(n==0){
		return;
	}
	cout<<"*";
	Asterisk_Arrow(n-1);
}
void Pattern_Arrow1(int x, int y){
	if(x==0){
		return;
	}
	Spaces_Arrow(y+1);
	Asterisk_Arrow(y+1);
	cout<<endl;
	Pattern_Arrow1(x-1,y+1);
}
void Pattern_Arrow2(int x){
	if(x==0){
		return;
	}
	Spaces_Arrow(x-1);
	Asterisk_Arrow(x-1);
	cout<<endl;
	Pattern_Arrow2(x-1);
}
//End of Part 1( Arrow)

//Start of Part 2(Rhombus)
void Spaces_Rhombus(int x){
	if(x==0){
		return;
	}
	cout<<" ";
	Spaces_Rhombus(x-1);
}
void Asterisk_Rhombus(int n){
	if(n==0){
		return;
	}
	cout<<"* ";
	Asterisk_Rhombus(n-1);
}
void Pattern_Rhombus(int x,int y){
	if(x==0){
		return;
	}
	Spaces_Rhombus(x-1);
	Asterisk_Rhombus(y);
	cout<<endl;
	Pattern_Rhombus(x-1,y);
}
//End of part 2(Rhombus)

//Start of Part 3( X pattern)
void Spaces_X(int x){
	if(x==0){
		return;
	}
	if(x<0){
		cout<<" ";
		Spaces_X(x+1);
	}
	else{
	cout<<" ";
	Spaces_X(x-1);
	}
}
void Pattern_X(int x,int y){
	if(x==0){
		return;
	}
	if(x>=y){
		Spaces_X(y);
		cout<<"*";
		Spaces_X(x-y);
		cout<<"*\n";
	}
	else{
		Spaces_X(x);
		cout<<"*";
		Spaces_X(x-y);
		cout<<"*\n";
	}
	Pattern_X(x-1,y+1);
}
//End of Part 3( X pattern)

//Printing Function
void Display_Patterns(int input){
	if(input<=0){
		cout<<"Please enter positive numbers only\n";
		return;
	}
	cout<<"\n\nArrow pattern for input: "<<input<<endl<<endl;
	Pattern_Arrow1(input,0);
	Pattern_Arrow2(input);
	cout<<"\n\nRhombus pattern for input: "<<input<<endl<<endl;
	Pattern_Rhombus(input,input);
	cout<<"\n\nX pattern for input: "<<input<<endl<<endl;
	Pattern_X(input,0);
}
int main()
{
	int lines=0, option=0;
	cout<<"Enter size: ";
	cin>>lines;
	Display_Patterns(lines);
	cout<<"\n\nFor an Arrow Pattern, press 1\nFor a Rhombus Pattern, press 2\nFor a X shaped pattern, press 3\n";
	cin>>option;
	switch(option){
		case 1:
			cout<<"Enter size of arrow: ";
			cin>>lines;
			Pattern_Arrow1(lines,0);
			Pattern_Arrow2(lines);
			break;
		case 2:
			cout<<"Enter number of rows of Rhombus: ";
			cin>>lines;
			Pattern_Rhombus(lines,lines);
			break;
		case 3:
			cout<<"Enter number of symbols of X pattern: ";
			cin>>lines;
			Pattern_X(lines,0);
			break;
		default: 
			cout<<"Please only choose the options provided\n";
			return 0;
			break;			
	}
	return 0;
}
