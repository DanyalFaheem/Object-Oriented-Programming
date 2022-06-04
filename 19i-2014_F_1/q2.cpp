#include<iostream>
#include "q1.cpp"
using namespace std;
// Part 1
void countLetters ( char* string , int* &array , int &size){
	int arr_size=0;
	char letters[arr_size];
	bool check=false, check1=false;
	for( int counter=0; (*(string+counter))!=0; counter++){
		for(int count=-1; count<counter; count++){
			if(string[counter]!=string[count]){
				check=true;
			}
			else{
				check=false;
				break;
			}
		}
		if(check==true){
			for(int count2=0, index=0; (*(string+count2))!=0; count2++){
				if(string[count2]==string[counter]){
					arr_size++;
					letters[index]=string[counter];
					index++;
					break;
				}
			
			}
			}
	}
array=new int [arr_size];
	for(int counter=0; counter<arr_size; counter++){
		array[counter]=0;
	}
	for( int counter=0,index=0; (*(string+counter))!=0; counter++){
		for(int count=-1; count<counter; count++){
			if(string[counter]!=string[count]){
				check1=true;
			}
			else{
				check1=false;
				break;
			}
		}
		if(check1==true){
			array[index]+=1;
			for(int count2=counter+1; (*(string+count2))!=0; count2++){
				if(string[count2]==string[counter]){
					array[index]++;
				}
			}	
			index++;
		}
	}
	size=arr_size;	
}
//Part 2
void countWordsBasedOnLength(char* string, int *&array, int& size){
	int arr_size=0;
	int largest_string=0;
	for(int counter=0,count=0; (*(string+counter))!=0; counter++){
		if(string[counter]==32){
			count=counter-count;
			if(count>largest_string){
				largest_string=count;
			}
			//cout<<count<<endl;
			count=counter+1;
		}
	}
	arr_size=largest_string+1;
	array=new int[arr_size];
		for(int counter=0; counter<arr_size; counter++){
		array[counter]=0;
	}
	for(int counter=0; (*(string+counter))!=0; counter++){
			if(string[counter]==32){
				array[0]+=1;
			}
	}
	for(int counter=0,count=0; counter<=Strlen(string); counter++){
			if(string[counter]==32||string[counter]==0){
			count=counter-count;
				array[count]+=1;
			count=counter+1;
		}
	}
		size=arr_size;
}
//Part 3
void countingUniqueWords( char *string , char **&uwords, int *&array , int &size ){
	int arr_size=1,no_words=1,check1=0;
	uwords=new char*[no_words];
	char** words=new char*[no_words];
	bool check=false;
	array=new int[no_words];
	for(int counter=0;counter<no_words;counter++){
		array[counter]=0;
	}
	for(int counter=0,count=0,index=0; counter<=Strlen(string); counter++){
			//compare[count3]=string[counter];
			if(string[counter]==32||string[counter]==0){
			//	count3=-1;
			no_words++;
			count=counter-count;
			char* compare=new char[count];
				for(int count2=counter-count,count3=0; count2<counter; count2++,count3++){
				compare[count3]=string[count2];
			}
			uwords[index]=new char[count];
			words[index]=new char[count];
			for(int count2=counter-count, index1=0; count2<counter; count2++,index1++){
				words[index][index1]=string[count2];
			}
			for(int count4=0; count4<arr_size; count4++){
				check1=StrFind(words[count4],compare);
				//cout<<check1<<endl;
				if(check1!=-1){
					arr_size++;
				break;
				}
			}
			cout<<check1<<endl;
			if(check1==-1){
			for(int count2=counter-count, index1=0; count2<counter; count2++,index1++){
				uwords[index][index1]=string[count2];
			}
			//arr_size++;
		}
			index++;
			count=counter+1;
		}
	}
	/*array=new int[no_words];
	for(int counter=0;counter<no_words;counter++){
		array[counter]=0;
	}
	for(int counter=0,count=0; counter<=Strlen(string);counter++){
		compare[count]=string[counter];
			if(string[counter]==32||string[counter]==0){
				for(int count2=0; count2<no_words; count2++){
					check1=StrFind(compare,words[count2]);
				}
			}
	}*/
	size=arr_size;	
}
