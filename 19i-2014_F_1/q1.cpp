#include<iostream>
using namespace std;

int Str_Len(const char* string_1){ //For own use in program
	int length=0;
	for(; string_1[length]!=0; length++){	
	}
	return length;}
int Strlen(char* string_1){
	int length=0;
	for(; string_1[length]!=0; length++){	
	}
	return length;
}
char *Strcpy(char* string_1, const char* string_2){
	if(Strlen(string_1)<Str_Len(string_2)){
		char smaller[]="";
		char* ptr_small=smaller;
		string_1=ptr_small;
		return string_1;
	}
	char* ptr_DMA= new char[Str_Len(string_2)];
	for(int counter=0; (*(string_2+counter))!=0; counter++){
		*(ptr_DMA+counter)=string_2[counter];
	}
	string_1=ptr_DMA;
	return string_1;
	delete []ptr_DMA;
	
}
char *Strncpy(char* string_1, const char* string_2, int end){
	char ncpy[Strlen(string_1)];
	char* ptr_ncpy=ncpy;
	for(int counter=0; counter<end; counter++){
		*(ptr_ncpy+counter)=*(string_2+counter);
	}
	for(int counter=end; (*(string_1+counter))!=0; counter++){
		*(ptr_ncpy+counter)=string_1[counter];
	}
	for(int counter=0; (*(ptr_ncpy+counter))!=0; counter++){
		*(string_1+counter)=ptr_ncpy[counter];
	}
	return string_1;
} 
char *StrCat(char* string_1, const char* string_2){
	char* ptr_DMA=new char[(Strlen(string_1)+Str_Len(string_2))];
	int counter=0;
	for(; counter<(Strlen(string_1)); counter++){
		ptr_DMA[counter]=string_1[counter];
	}
	for(int count=0; count<(Str_Len(string_2))||(*(string_2+count))!=0; counter++,count++){
		ptr_DMA[counter]=string_2[count];
	}  
	string_1=ptr_DMA;
	return string_1;
	delete []ptr_DMA;
}
char *StrnCat(char* string_1, const char* string_2, int end){
	char* ptr_DMA=new char[(Strlen(string_1)+end)];
	int counter=0;
	for(; counter<(Strlen(string_1)); counter++){
		ptr_DMA[counter]=string_1[counter];
	}
	for(int count=0; count<end; counter++,count++){
		ptr_DMA[counter]=string_2[count];
	} 
	string_1=ptr_DMA;
	return string_1;
	delete []ptr_DMA;
}
int StrCmp( const char* string_1 , const char* string_2 ){
	int count_string1=0, count_string2=0;
	for(; string_1[count_string1]!=0; count_string1++){
	}
	for(; string_2[count_string2]!=0; count_string2++){
	}
	if(count_string1==count_string2){
		return 0;
	}
	else{
		return (count_string1-count_string2);
	}
}
int StrnCmp( const char* string_1 , const char* string_2 , int end ){
	int count_string1=0, count_string2=0;
	for(; count_string1<end; count_string1++){
	}
	for(; string_2[count_string2]!=0; count_string2++){
	}
	if(count_string1==count_string2){
		return 0;
	}
	else{
		return (count_string1-count_string2);
	}
}
char** StrTok ( char * string_1 , const char stop ){
	int no_words=1;
	char** words=new char*[no_words];
	for(int counter=0,count=0,index=0; counter<=Strlen(string_1); counter++){
			if(string_1[counter]==stop||string_1[counter]==0){
			no_words++;
			count=counter-count;
			words[index]=new char[count];
			for(int count2=counter-count, index1=0; count2<counter; count2++,index1++){
				words[index][index1]=string_1[count2];
			}
			index++;
			count=counter+1;
		}
	}
	return words;
}
int StrFind( char* string_1, char* string_2){
	int string_pos=0,counter=0;
	bool check=false;
	for(; (*(string_1+counter))!=0; counter++){
		if(string_1[counter]==string_2[0]){
			for(int count=0; count<(Strlen(string_2)); count++){
				if(string_1[counter+count]==string_2[count]){
					check=true;
				}
				else{
					check=false;
					break;
				}
			}
			if(check==true){
				break;
			}
		}
	}
	string_pos=counter;
	if(check==false){
		return -1;
	}
	else if(check==true){
		return string_pos;
	}
}
char* SubStr( char* string_1, int start_pos, int str_len){
	char substr_arr[str_len];
	char* ptr_substr_arr=new char[str_len];
	for(int counter=0; (*(string_1+counter))!=0; counter++)
	{
		if (counter==start_pos){
			for(int count=0; count<str_len; count++){
				ptr_substr_arr[count]=string_1[counter+count];
			}
			break;
		}
	}
	return ptr_substr_arr;
	delete []ptr_substr_arr;
}

