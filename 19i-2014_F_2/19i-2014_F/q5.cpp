#include<iostream>
using namespace std;
struct name{
	char F_Name[20];
	char L_Name[20];
};
struct student{
	string reg_no;
	name student_name;
	int marks[5];
	float GPA;
};
void getdata(student *&s,int size)
{
	s=new student[size];
	cout<<"Please enter values for the following students: \n";
	for(int counter=0; counter<size; counter++){
			for(int count=0; count<5; count++){
			cout<<"Please enter marks for assessment "<<count+1<<" for Student "<<counter+1<<endl;
			cin>>(s[counter].marks[count]);
		}
		cout<<"Enter First Name of Student "<<counter+1<<endl;
		cin>>(s[counter].student_name.F_Name);
		cout<<"Enter Last Name of Student "<<counter+1<<endl;
		cin>>(s[counter].student_name.L_Name);
		cout<<"Enter Registration Number of Student "<<counter+1<<endl;
		cin>>s[counter].reg_no;
	}
}
student & calcGPA(student *&s,int size)
{
	for(int counter=0; counter<size; counter++){
		int middle=0;
		for(int count=0; count<5; count++){
			middle+=s[counter].marks[count];
		}
		middle=middle/5;	
		if(middle<50){
			s[counter].GPA=0.0;
		}
		else if(middle>49 && middle<60){
			s[counter].GPA=1.80;
		}
		else if(middle>59 && middle<70){
			s[counter].GPA=2.87;
		}
		else if(middle>69 && middle<80){
			s[counter].GPA=3.10;
		}
		else if(middle>79 && middle<90){
			s[counter].GPA=3.62;
		}
		else if(middle>89 && middle<100){
			s[counter].GPA=4.0;
		}
	}
}
student &sort(student*& s, int size)
{
	for(int counter=0; counter<size; counter++){
		for(int count=0; count<size-1; count++){
			if(s[count].GPA<s[count+1].GPA){
				float middle=s[count+1].GPA;
				s[count+1].GPA=s[count].GPA;
				s[count].GPA=middle;
				swap(s[count].student_name,s[count+1].student_name);
				swap(s[count].reg_no,s[count+1].reg_no);
			}		
		}
	}
}
void print(student *&s,int size)
{
	cout<<"Following are the details for the students:\n";
	for(int counter=0; counter<size; counter++){
    	cout<<"Name: "<<s[counter].student_name.F_Name<<" "<<s[counter].student_name.L_Name<<endl;
    	cout<<"Registration Number: ";
		cout<<s[counter].reg_no<<endl;
    	cout<<"Grade Point Average: "<<s[counter].GPA<<endl;
	}
}

int main()
{
    student *stud;
    int arr_size=0;
    cout<<"Enter number of students: ";
    cin>>arr_size;
    getdata(stud,arr_size);
    calcGPA(stud,arr_size);
	sort(stud,arr_size);
	print(stud,arr_size);
}
