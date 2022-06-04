#include<iostream>
using namespace std;
struct Address
{
char city[20];
int postcode;
char email_id[20];
};
struct Salary
{
int Year;
float gross_salary;
};
struct Tax
{
int Year;
float tax_due;
float net_salary;
};
struct Employee
{
char name[20];
int scale;
Salary YearlySalary[3];
Tax YearlyTax[3];
Address addr;
Employee* next;
};
void inputData(Employee *&ptr){
	ptr=new Employee[10];
	Employee* emp_ptr=NULL;
	cout<<"\nEnter the Following data for the Employees \n";
	for(int counter=0; counter<10; counter++){
		emp_ptr=&ptr[counter];
		ptr[counter].next=(emp_ptr+1);
		cout<<"Enter the name of the Employee "<<counter+1<<endl;
		cin>>ptr[counter].name,20;
		cout<<"Enter the pay scale of the Employee "<<counter+1<<" (Between 1-17)"<<endl;
		cin>>ptr[counter].scale;
		if(ptr[counter].scale<1 || ptr[counter].scale>17){
			cout<<"Please enter scale between 1 and 17\n";
			exit(0);
		}
		for(int count=0; count<3;count++){
			cout<<"Enter year of Salary to be added for Employee "<<counter+1<<endl;
			cin>>ptr[counter].YearlySalary[count].Year;
			cout<<"Enter Salary of Employee "<<counter+1<<" for year "<<ptr[counter].YearlySalary[count].Year<<endl;
			cin>>ptr[counter].YearlySalary[count].gross_salary;
		}
		cout<<"Enter city name of Employee "<<counter+1<<endl;
		cin>>ptr[counter].addr.city;
		cout<<"Enter postcode of city of Employee "<<counter+1<<endl;
		cin>>ptr[counter].addr.postcode;
		cout<<"Enter Email Address of Employee "<<counter+1<<endl;
		cin>>ptr[counter].addr.email_id,20;
	}
}
void Tax_Calculation(Employee *&ptr){
	for(int counter=0; counter<10; counter++){
		if(ptr[counter].scale<10 && ptr[counter].scale>0){
			for(int count=0; count<3; count++){
				ptr[counter].YearlyTax[count].tax_due=(0.05*(ptr[counter].YearlySalary[count].gross_salary));
				ptr[counter].YearlyTax[count].Year=ptr[counter].YearlySalary[count].Year;
				ptr[counter].YearlyTax[count].net_salary=(ptr[counter].YearlySalary[count].gross_salary)-(ptr[counter].YearlyTax[count].tax_due);
			}
		}
		else if(ptr[counter].scale>10 && ptr[counter].scale<18){
			for(int count=0; count<3; count++){
				ptr[counter].YearlyTax[count].tax_due=(0.075*(ptr[counter].YearlySalary[count].gross_salary));
				ptr[counter].YearlyTax[count].Year=ptr[counter].YearlySalary[count].Year;
				ptr[counter].YearlyTax[count].net_salary=(ptr[counter].YearlySalary[count].gross_salary)-(ptr[counter].YearlyTax[count].tax_due);
			}
		}
	}
}
int Average_Calculation(Employee *&ptr){
	int average=0;
	for(int counter=0; counter<10; counter++){
		for(int count=0; count<3; count++){
			average+=ptr[counter].YearlySalary[count].gross_salary;
		}
	}
	average=average/30;
	return average;
}
void Print_Highest(Employee *&ptr){
	int index_1=0, index_2=0;
	float max=0;
	for(int counter=0; counter<10; counter++){
		for(int count=0; count<3; count++){
			if(ptr[counter].YearlyTax[count].net_salary>max){
				max=ptr[counter].YearlyTax[count].tax_due;
				index_1=counter;
				index_2=count;
			}
		}
	}
	cout<<"The Employee who has paid the highest tax is: \n";
	cout<<ptr[index_2].name<<endl;
	cout<<ptr[index_1].addr.city<<endl<<ptr[index_1].addr.email_id<<endl<<ptr[index_1].addr.postcode<<endl;
	cout<<"The highest tax he has paid is: "<<ptr[index_1].YearlyTax[index_2].tax_due<<" for the year "<<ptr[index_1].YearlyTax[index_2].Year<<endl;
}
int main(){
	Employee* ptr;
	inputData(ptr);
	Tax_Calculation(ptr);
	Average_Calculation(ptr);
	Print_Highest(ptr);
	return 0;
}	
