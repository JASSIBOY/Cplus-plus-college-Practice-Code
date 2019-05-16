#include <iostream>
using namespace std;

class weather
{
private:
	int day,max,min,rain,snow;
public:
	weather();
	void getdata(weather arr[],int n); 
	void report(weather arr[]);

	friend void average(weather arr[]);
};
weather::weather()
{
	day=99;
	max=999;
	min=-999;
	snow=rain=0;
}
void weather::getdata(weather arr[],int n)
{
	weather w;
	for(int i=1;i<=n;i++)
	{
		cout<<"enter day$$hightemp$$$$lowtemp$$$$amountofrain$$$$$amountofsnow"<<endl;
		cin>>w.day>>w.max>>w.min>>w.rain>>w.snow;
		arr[w.day-1]=w;
	}
}
void weather::report(weather arr[])
{
	cout<<"day---------high_temp---------low_temp---------amount_rain---------amount_snow"<<endl;
	for(int i=0;i<5;i++)
	{
	   cout<<arr[i].day<<"   "<<arr[i].max<<"	"<<arr[i].min<<"	"<<arr[i].rain<<"	"<<arr[i].snow<<endl;
	}
}
void average(weather arr[])
{
 int max =0,min=0,rain=0,snow=0;
 for(int i=0;i<5;i++)
 {
	 max = max+arr[i].max;
	 min= min+ arr[i].min;
	 rain = rain+arr[i].rain;
	 snow=snow+arr[i].snow;
 }
 cout<<"Average is "<<endl;
 cout<<"high_temp---------low_temp---------amount_rain---------amount_snow"<<endl;
 cout<<max/5<<"---------"<<min/5<<"---------"<<rain/5<<"---------"<<snow/5<<endl;
}
int main()
{
	weather arr[5];
	weather w;
	int ch,n;
	int cho=1;
		do
		{
			cout<<"enter choice"<<endl;
			cout<<"\n1.enter data\n2.display data\n3.find average of all days\n";
			cin>>ch;
			switch(ch)
			{
			case 1:
				cout<<"ntr days for report";
				cin>>n;
				w.getdata(arr,n);
				break;
			case 2:
				w.report(arr);
				break;
			case 3:
				average(arr);
				break;
			}
			cout<<"want to continue(0/1)";
			cin>>cho;
		}
		while(cho == 1);
	return 0;
}
