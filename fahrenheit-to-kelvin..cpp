// Q9. Write a program to convert the temperature which is given in Fahrenheit to Celsius. 
// K = 5/9 (° F - 32) + 273
#include <iostream>

using namespace std;

int main()
{
   int f;
   cout<<"temp in Fahrenheit  : ";
   cin>>f;
   int k;
   cout<<"temp in kelvin is : ";
   cout<<"k=" << (5*(f-32)/9)+273;
   
}
