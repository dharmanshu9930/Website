#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=1;
    int k=64;

    while (i<=n)
    {
        k++;
        int j=1;
        while (j<=i)
        {
            char ch=k;
            cout<<ch;
            j++;
        }
        i++;
        cout<<endl;
    }

    return 0;
}
