#include<iostream>
using namespace std;


 int fib(int n)
 {
  return fib(n-2)+fib(n-1);
 }
 {
  if(n<=1)
  {return 1;}
 return n*factorial(n-1);
 }
 
    int main()

    { 
      //factorial or number:
      int a;
      cout<<"enter the number"<<endl;
      cin>>a;
      cout<<"factorial of a is"<<a<<factorial(a)<<endl;
      return 0;
    }
 
