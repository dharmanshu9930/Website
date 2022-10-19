#include <iostream>
using namespace std;
int main()
{
    int p,pn;
    cout<<"Enter how many numbers you have:";
    cin>>p;
    int even[p];
    int array=0;
    for(int i=1;i<=p;i++)
    {
        cout<<"Enter the numbers: ";
        cin>>pn;
        if(pn%2==0)
        {
         even[array] = pn;
         array++;  
        }  
    }
    cout<<"The last even number found is:"<<even[array-1];
    return 0;
}


