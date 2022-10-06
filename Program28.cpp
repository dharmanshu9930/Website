//to check whether the number is palindrome or not
//when we reverse 1221 it again comes 1221 so it is a palindrome
#include <iostream>
using namespace std;
int main()
{
    int n,digit,temp,rev = 0,m;
    cout<<"enter the number: ";
    cin>>n;
    temp = n;
    while(n>0)
    {
      digit = n%10;
      rev = (rev*10) + digit;
      n=n/10;
     }
     if(temp == rev)
     {
        cout<<"it is a palindrome";
     }
     else
     {
       cout<<"it is not a palindrome";
     }
    return 0;
}