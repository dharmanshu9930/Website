#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

        
    int i=1;
    while (i<=n)
    {
        int j=1;
        int x=63+i;                             //65 is the ascii for A

        while (j<=n)
        {
            char ch=x+j;
            cout<<ch;
            j++;

        }
        cout<<endl;
        i++;

        
    }

    return 0;

}