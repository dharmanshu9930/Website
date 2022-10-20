#include<iostream>
using namespace std;
int main ()
{ int i,n, even=0 ,odd=0;
 cout << "size of the array=";
 cin>>n;
  int arr[n];
  cout<<"Enter the elements of array=";
  for (i=0;i<n;i++)
  cin>>arr[i];
   for (i=0;i<n;i++)
   { 
       if(arr[i]%2==0)
   {even=even +arr[i];}
   else
   {odd=odd +arr[i];}}
   cout<<"sum of even elements="<<even;
   cout<<"\nsum of odd elemnets="<<odd;
   
    return 0;
}


