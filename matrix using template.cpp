#include<bits/stdc++.h>
using namespace std;
template<class T>
class matrix
{
	T x[100][100];
	T y[100][100];
	T z[100][100];
	int r,c;
public:
	void input();
	void add();
	void sub();
	void mul();
	void display();  

};
template<class T>
void matrix<T>:: input()

{
	int i,j;
	cout<<"enter the row and column for matrix"<<endl;
	cin>>r>>c;
	cout<<"enter the input for 1st matrix"<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>x[i][j];
		}
	}
	cout<<"enter the input for 2nd matrix"<<endl;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>y[i][j];
			}
		}
}
template<class T>
void matrix<T> :: add()
{
	int i,j;
	 for(i=0;i<r;i++)
	 {
		 for(j=0;j<c;j++)
		 {
			 z[i][j]=x[i][j]+y[i][j];
		 }
	 }
}
template<class T>
void matrix<T> ::sub()
{
	int i,j;
		 for(i=0;i<r;i++)
		 {
			 for(j=0;j<c;j++)
			 {
				 z[i][j]=x[i][j]-y[i][j];
			 }
		 }
}
template<class T>
void matrix <T>::mul()
{
	int i,j,m,n,o,p;
		 for(i=0;i<r;i++)
		 {
			 for(j=0;j<c;j++)
			 {
				 z[i][j]=0;
			 }
		 }
		 m=0;
		 n=0;
		 o=0;
		 p=0;
		 for(i=0;i<r;i++)
		 		 {
		 		     p=0;
		 			 for(j=0;j<c;j++)
		 			 {
		 			     n=0;
		 			     o=0;

		 						 while(m<r&&n<c&&o<r&&p<c)
		 						 {

		 							 z[i][j]=z[i][j]+x[m][n]*y[o][p];
		 							 n++;
		 							 o++;
		 						 }
		 				 		 p++;
		 			 }
		 			 m++;
		 		 }
}
template<class T>
void matrix<T> :: display()
{
	int i,j;
	cout<<"1st matrix is:"<<endl;
			for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					{
						cout<<x[i][j]<<" ";
					}
					cout<<"\n";
				}
	cout<<"2nd matrix is:"<<endl;
				for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							cout<<y[i][j]<<" ";
						}
						cout<<"\n"<<endl;
					}
				cout<<"resultant matrix is:"<<endl;
								for(i=0;i<r;i++)
									{
										for(j=0;j<c;j++)
										{
											cout<<z[i][j]<<" ";
										}
										cout<<"\n"<<endl;
									}

}
int main()
{
	matrix <int>m;
	char cho;
	int ch;
    do
    {
    	cout<<"1. enter the input for two matrix"<<endl;
    	cout<<"2. addition of two matrix"<<endl;
    	cout<<"3. subtraction of two matrix"<<endl;
    	cout<<"4. multiply of two matrix"<<endl;
    	cout<<"5.  of matrix"<<endl;
    	cout<<"6. display all matrix"<<endl;
    	cout<<"enter your choice"<<endl;
    	cin>>ch;
    	switch(ch)
    	{
    	case 1:
    		m.input();
    		break;
    	case 2:
    		m.add();
    		break;
    	case 3:
    		m.sub();
    		break;
    	case 4:
    		m.mul();
    		break;
        case 5:
        //    m.inverse();
            break;
    	case 6:
    		m.display();
    		break;
    	default:
    		exit(0);
    	}
    	 cout<<"do u want to continue"<<endl;
        cin>>cho;
    }while(cho=='y'||cho=='Y');
	return 0;
}
