#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int p,pn;
    int odd=0;
    cout<<"Enter how many numbers you have: ";
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        cout<<"Enter the number: ";
        cin>>pn;
        if(pn%2==1)
        {
            odd++;
        }
   }
    cout<<"Number of odd numbers found is: "<<odd;
    return 0;
}

