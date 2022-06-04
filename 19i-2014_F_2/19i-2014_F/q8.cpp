#include<iostream>
using namespace std;
struct Temperature{
	double max_temperature;
	double min_temperature;
};
struct Rainfall{
	int max_rainfall;
	int min_rainfall;
};
struct weather{
	Rainfall total_rain;
	Temperature temp;
};
void getdata(weather *&w,int size)
{
 	w=new weather[12];
 	int middle=0;
 	double mid=0;
 	cout<<"Enter following values for the following months: \n";
 	for(int counter=0; counter<size; counter++){
 		cout<<"Enter Maximum rainfall for month(more than minimum): "<<counter+1<<endl;
 		cin>>w[counter].total_rain.max_rainfall;
 		cout<<"Enter Minimum rainfall for month(more than maximum): "<<counter+1<<endl;
 		cin>>w[counter].total_rain.min_rainfall;
 		if(w[counter].total_rain.max_rainfall>25 || w[counter].total_rain.min_rainfall<w[counter].total_rain.min_rainfall || w[counter].total_rain.min_rainfall<1){
 			cout<<"Please enter values between 1mm and 25mm\nPlease enter minimum rainfall lesser than maximum rainfal\n";
 			return;
	}
 		middle+=(w[counter].total_rain.max_rainfall)+(w[counter].total_rain.min_rainfall);
 		cout<<"Enter Maximum temperature for month(more than minimum): "<<counter+1<<endl;
 		cin>>w[counter].temp.max_temperature; 
 		cout<<"Enter Minimum temperature for month(more than maximum): "<<counter+1<<endl;
 		cin>>w[counter].temp.min_temperature;		
 			if(w[counter].temp.max_temperature>140 || w[counter].temp.max_temperature<w[counter].temp.min_temperature || w[counter].total_rain.min_rainfall<-100){
 			cout<<"Please enter values between -100 degrees Farenheit and 140 degree Farenheit\nPlease enter minimum temperature lesser than maximum Temperature\n";
 			return;
	}
		mid+=(w[counter].temp.max_temperature)+(w[counter].temp.min_temperature);
	 }
}
float* avgtempermonth(weather*&w,int size)
{
	float* avg_temp=new float;
	double mid=0;
	for(int counter=0; counter<size; counter++){
	mid+=(w[counter].temp.max_temperature)+(w[counter].temp.min_temperature);
	}
	*avg_temp=(mid/(size*2));
	return avg_temp;
}
float* avgrainfallpermonth(weather*&w,int size)
{
	float* avg_rain=new float;
	int middle=0;
	for(int counter=0; counter<size; counter++){
	middle+=(w[counter].total_rain.max_rainfall)+(w[counter].total_rain.min_rainfall);
	}
	*avg_rain=(middle)/(size*2);
	return avg_rain;
}
float* avgtemperyear(weather*&w,int size)
{
float* avg_temp_year=new float;
	double mid=0;
	for(int counter=0; counter<size; counter++){
	mid+=(w[counter].temp.max_temperature)+(w[counter].temp.min_temperature);
	}
	*avg_temp_year=(mid/(size*2))/6;
	return avg_temp_year;
}
float* avgrainfallperyear(weather*&w,int size)
{	
		float* avg_rain_year=new float;
	int middle=0;
	for(int counter=0; counter<size; counter++){
	middle+=(w[counter].total_rain.max_rainfall)+(w[counter].total_rain.min_rainfall);
	}
	*avg_rain_year=((middle)/(size*2))/6;
	return avg_rain_year;
}
void print( weather*&w,int size)
{
	cout<<"Average Temperature for Month: "<<*avgtempermonth(w,size)<<endl;
	cout<<"Average Rainfall for Month: "<<*avgrainfallpermonth(w,size)<<endl;
	cout<<"Average Temperature per Year: "<<*avgtemperyear(w,size)<<endl;
	cout<<"Average Rainfall per Year: "<<*avgrainfallperyear(w,size)<<endl;
}
int main()
{
	weather* weath;
	int arr_size=0;
	cout<<"Please enter size of array: ";
	cin>>arr_size;
	getdata(weath,arr_size);
    print(weath,2);
}
