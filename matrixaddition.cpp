//Write a program to perform the following operation in Matrix(Addition) 

#include<iostream>
using namespace std;
int main()
{
	int a[3][3],b[3][3],c[3][3],i,j;
	cout<<"\n enter element in array a:\n";
	for(i=0;i<=2;i++)\
	{
		for(j=0;j<=2;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"enter element for array b:\n";
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			cin>>b[i][j];
		}
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			c[i][j]>>a[i][j]+b[i][j];
		}
	}
	for(i=0;i<=2;i++)\
	{
		for(j=0;j<=2;j++)
		{
			cout<<c[i][j];
		}
	}
	return 0;
}