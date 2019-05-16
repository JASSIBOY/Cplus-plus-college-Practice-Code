#include<iostream>
#include<exception>

using namespace std;   

class MyException : public exception
{
	
	public :

		const char * what() const throw ()
		{
			return "Exception found in what";
		}
}exp;//MyException

class tv
{
	string model;
	int size;
	float price;
	
	public:
		tv()
		{
			model = "";
			size = 0;
			price = 0.0;
		}
		
		friend ostream& operator <<(ostream &out, tv &t);
		friend istream& operator >> (istream &in, tv &t);
};//tv

ostream& operator <<(ostream &out, tv &t)
{
	out<<"\nModel number : "<<t.model;
	out<<"\nSize : "<<t.size;
	out<<"\nPrice : "<<t.price;
	
}//operator <<

istream& operator >>(istream &in, tv &t)
{
	
		cout<<"\nEnter model number : ";
		in>>t.model;
		cout<<"Enter size : ";
		in>>t.size;
		cout<<"Enter price : ";
		in>>t.price;
	
	
		if(t.model.length()>4)
		{
			t.model = "";
			t.size = 0;
			t.price = 0.0;
			throw exp;
		}
		if(t.size <12 || t.size > 70)
		{
			t.model = "";
			t.size = 0;
			t.price = 0.0;
			throw exp;
		}
		if(t.price <0 || t.price > 5000)
		{
			t.model = "";
			t.size = 0;
			t.price = 0.0;
			throw exp;
		}	
	
	return in;
}//operator

int main()
{
	tv t;
	try
	{
		cin>>t;
	}
	
	catch (MyException &e)
	{
		cout<<e.what()<<endl;
	}
	cout<<t;
}//main
