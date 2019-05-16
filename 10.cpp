#include<bits/stdc++.h>
using namespace std;

class student
{
	protected :
		string name;
		string subject[3];
	
	public :
		void input(); 
		
};//student


class personal : public virtual student
{
	protected :
		int height,weight;
		char gender;
		
		personal()
		{
			height = weight = 0;
			gender = ' ';
		}
		
		void input();

};//personal

class acad : public virtual student
{
	protected :
		float marks[3];
	
	public :
	
	acad()
	{
		marks[0] = marks[1] = marks[2] = 0 ;
	}
	
	void input();
};//acad

class all : public personal, public acad
{
	public :
		int roll;
		
		all()
		{
			roll = 0;
		}
		
		void input();
		
		void output();
		
		void del()
		{
			this -> roll = 0;
		}
};//all

void all :: output()
{
	cout<<"\n Name : "<<student :: name;
	cout<<"\n Height : "<<personal :: height;
	cout<<"\n Weight : "<<personal :: weight;
	cout<<"\n Gender : "<<personal :: gender;
	cout<<"\n Marks in "<<student ::subject[0]<<" is "<<acad :: marks[0];
	cout<<"\n Marks in "<<student ::subject[1]<<" is "<<acad :: marks[1];
	cout<<"\n Marks in "<<student ::subject[2]<<" is "<<acad :: marks[2];
}

void all :: input()
{
	student :: input();
	personal :: input();
	acad :: input();
}//input

void acad :: input()
{
	int i;
	cout<<"Enter marks\n------------\n"<<endl;
	for(i=0; i < 3; i++)
	{
		cout<<"Enter marks for "<<subject[i]<<" : ";
		cin>>marks[i];
	}
}//input


void personal :: input()
{
	cout<<"Enter height : ";
	cin>>height;
	cout<<"Enter weight : ";
	cin>>weight;
	cout<<"Enter gender : ";
	cin>>gender;
}

void student :: input()
{
	cout<<"Enter name : ";
	cin>>name;
	
	cout<<"Enter subject name\n\n";
	for(int i = 0; i< 3; i++)
	{
		cout<<i+1<<". ";
		cin>>subject[i];
	}
}//input

int main()
{
	all obj[10];
	int ch,r;
	
	while(1)
	{
		cout<<"1. Enter a record\n2.Delete a record\n3.Display a record\n4.Exit\n";
		cin>>ch;
		
		if(ch == 1)
		{
			cout<<"Enter roll number : ";
			cin>>r;
			obj[r].roll = r;
			obj[r].input();
		}
		else if( ch == 2)
		{
			cout<<"Enter roll number : ";
			cin>>r;
			obj[r].del();
			cout<<"Record for roll "<<r<<" deleted sucessfully\n";
		}
		else if(ch == 3)
		{
		 cout<<"Enter roll number : ";
			cin>>r;
			if(obj[r].roll != 0)
				obj[r].output();
			else
				cout<<"Record not exist"<<endl;
		}
		else if(ch == 4)
		{
			break;
		}
		else
		{
			cout<<"Wrong input";
		}
	}//while
}//main
