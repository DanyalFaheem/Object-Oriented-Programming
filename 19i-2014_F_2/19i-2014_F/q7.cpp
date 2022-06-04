#include<iostream>
using namespace std;
struct SoccerPlayer
{ char PlayerName[20];
int Player_Number;
int Points_Scored;
};
void getdata(SoccerPlayer *&sp,int size)
{
	sp=new SoccerPlayer[size];
	for(int counter=0; counter<size; counter++){
		cout<<"Enter the name of Player(First Name Only) "<<counter+1<<endl;
		cin>>sp[counter].PlayerName;
		cout<<"Enter the Number of Player "<<counter+1<<endl;
		cin>>sp[counter].Player_Number;
		if(sp[counter].Player_Number<0){
		for(bool check=false; check==true; ){
				cout<<"Please enter positive number only";
				cin>>sp[counter].Player_Number;
				if(sp[counter].Player_Number>0){
					check=true;
				}
			}
		}
		cout<<"Enter the Points Scored by Player "<<counter+1<<endl;
		cin>>sp[counter].Points_Scored;
		if(sp[counter].Points_Scored<0){
		for(bool check=false; check==true; ){
				cout<<"Please enter positive number only";
				cin>>sp[counter].Points_Scored;
				if(sp[counter].Points_Scored>0){
					check=true;
				}
			}
		}
	}
}

void displayAllPlayers( SoccerPlayer*&sp,int size)
{
	for(int counter=0; counter<size; counter++){
		cout<<"Name of Player "<<counter+1<<": "<<sp[counter].PlayerName<<endl;
		cout<<"Number of Player "<<counter+1<<"is "<<sp[counter].Player_Number;
		cout<<"Points scored by Player "<<counter+1<<": "<<sp[counter].Points_Scored;
	}
}

SoccerPlayer &addnewPlayer(SoccerPlayer*&sp,int size)
{
	sp=new SoccerPlayer[size+1];
	cout<<"Enter the name of Player(First Name Only) "<<endl;
		cin>>sp[size+1].PlayerName,20;
		cout<<"Enter the Number of Player "<<endl;
		cin>>sp[size+1].Player_Number;
			if(sp[size+1].Player_Number<0){
		for(bool check=false; check==true; ){
				cout<<"Please enter positive number only";
				cin>>sp[size+1].Player_Number;
				if(sp[size+1].Player_Number>0){
					check=true;
				}
			}
		}
		cout<<"Enter the Points Scored by Player "<<endl;
		cin>>sp[size+1].Points_Scored;
		if(sp[size+1].Points_Scored<0){
		for(bool check=false; check==true; ){
				cout<<"Please enter positive number only";
				cin>>sp[size+1].Points_Scored;
				if(sp[size+1].Points_Scored>0){
					check=true;
				}
			}
		}
}

void insertPlayer(SoccerPlayer*&sp,int index)
{
		cout<<"Enter the name of Player(First Name Only) "<<endl;
		cin>>sp[index].PlayerName,20;
		cout<<"Enter the Number of Player "<<endl;
		cin>>sp[index].Player_Number;
			if(sp[index].Player_Number<0){
		for(bool check=false; check==true; ){
				cout<<"Please enter positive number only";
				cin>>sp[index].Player_Number;
				if(sp[index].Player_Number>0){
					check=true;
				}
			}
		}
		cout<<"Enter the Points Scored by Player "<<endl;
		cin>>sp[index].Points_Scored;
		if(sp[index].Points_Scored<0){
		for(bool check=false; check==true; ){
				cout<<"Please enter positive number only";
				cin>>sp[index].Points_Scored;
				if(sp[index].Points_Scored>0){
					check=true;
				}
			}
		}
}

void deletePlayer(SoccerPlayer*&sp,int index)
{
	for(int counter=0; counter<19; counter++){
		sp[index].PlayerName[counter]='\0';
	}
	sp[index].Player_Number=0;
	sp[index].Points_Scored=0;
}

void displayPlayer(SoccerPlayer*&sp,int size)
{
	for(int counter=0; counter<size; counter++){
	cout<<"Soccer Player Details "<<endl;
	cout<<"Name: "<<sp[counter].PlayerName<<endl;
	cout<<"Number: "<<sp[counter].Player_Number<<endl;
	cout<<"Points Scored: "<<sp[counter].Points_Scored<<endl<<endl;
}
}
void displayPlayerhighest(SoccerPlayer *&sp, int size){
	int max=0,counter=0;
	for(; counter<size; counter++){
		if(sp[counter].Points_Scored>max){
			max=sp[counter].Points_Scored;
		}
	}
	
	cout<<"Soccer Player Details who earned the most Points"<<endl;
	cout<<"Name: "<<sp[counter].PlayerName<<endl;
	cout<<"Number: "<<sp[counter].Player_Number<<endl;
	cout<<"Points Scored: "<<sp[counter].Points_Scored<<endl<<endl;
}
int main(){
	SoccerPlayer* sp;
	int arr_size=0,option=0,player_index=0;
	cout<<"Enter total Number of players: ";
	cin>>arr_size;
	getdata(sp,arr_size);
	cout<<"Press the option number to choose that option\n\n1) Add new players information:\n2) Insert a new player:\n3) Delete the player's information\n4) Display Players information:\n5) Display Highest Scoring Player:\n";
	cin>>option;
	switch(option){
		case 1:
			addnewPlayer(sp,arr_size);
			break;
		case 2:
			insertPlayer(sp,arr_size);
			break;
		case 3:
			cout<<"Enter the index to be deleted: ";
			cin>>player_index;
			deletePlayer(sp,player_index);
			break;
		case 4:
			displayPlayer(sp,arr_size);
			break;
		case 5:
			displayPlayerhighest(sp,arr_size);		
			break;
		defualt:
			cout<<"Please only choose the options provided\n";
			break;						
	}
	return 0;
}

