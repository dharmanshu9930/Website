// Program to check vowel or not.

#include <iostream>
using namespace std;
int main()
{
   char c;
   cout<<"Enter the Character:";
   cin>>c;
   if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='i'||c=='o'||c=='O'||c=='u'||c=='U')
   {
       cout<<"It is an vowel";
   }
   else
   {
       cout<<"It is not a vowel";
   }

    return 0;
}