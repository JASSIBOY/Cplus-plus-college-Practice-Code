#include<iostream>
#include<stdlib.h>

using namespace std;

class VECTOR
{
	int *n,size,curr,len;
	public :
		
		VECTOR();
		VECTOR(int,int);
		void push(int data);
		int length();
		void add(int);
		int pop();
		void addAt(int ,int);
		void mulBy(int);
		void display();
		int search(int);
		void reverse();
};

VECTOR :: VECTOR()
{
	len = 0;
	size = 0;
}

VECTOR :: VECTOR(int len, int value)
{
	int i;
	size = len;

	n = (int*)malloc(size*sizeof(int));
	for(i=0; i < size; i++)
		n[i] = value;
}
		
int VECTOR :: length()
{
	return size;
}

void VECTOR :: add(int value)
{
	size++;
	n = (int*)realloc(n,size);
	n[size-1] = value;
}

int VECTOR :: pop()
{
	int i;
	int data = n[0];
	size--;
	int *temp=(int*)malloc(size*sizeof(int));
	for(i=0; i < size; i++)
		temp[i] = n[i+1];
		
	delete n; 
	n = temp;
	
	return data;
}

void VECTOR :: addAt(int pos,int value)
{
	n[pos] = value;
}

void VECTOR :: mulBy(int scalar)
{
	int i;
	for(i=0 ; i < size; i++)
		n[i] *= scalar;
}

void VECTOR :: display()
{
	cout<<'(';
	int i;
	
	for(i=0; i < size-1; i++)
		cout<<n[i]<<',';
	if(size != 0)	
	cout<<n[size-1];
	cout<<')'<<endl;
}

int VECTOR :: search(int value)
{
	int i;
	for(i = 0; i < size; i++)
		if(n[i] == value)
			return i;
			
	cout<<'\n'<<value<<" not present\n";
	return -1;
}

void VECTOR :: reverse()
{
	int i,temp;
	for(i=0; i <size/2 ; i++)
	{
		temp = n[i];
		n[i] = n[size-1-i];
		n[size-1-i] = temp;
	}
}

int main()
{
	VECTOR v(10,2);
	cout<<v.pop();
	cout<<v.length();
	v.add(9);
	v.add(9);
	v.addAt(2,5);
	v.display();
	v.mulBy(2);
	v.reverse();
	v.display();
	int k = v.search(88);
	cout<<v.length();
}//main
