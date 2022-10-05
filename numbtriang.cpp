#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int i=1;
    while(i<=n)
    {
        int k=1;
        int j=1;
        int l=i;
        
        while (k<=n-i)
        {
            cout<<' ';
            k++;
        }
        while (j<=i)
        {
            cout<<l;
            l++;
            j++;
        }
        j=2*(i-1);
        while (j>=i)
        {
            cout<<j;
            j--;
        }

        cout<<endl;
        i++;

    }

    return 0;
}