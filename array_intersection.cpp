#include <iostream>
using namespace std;
int main()
{
    int n = 5, m = 5;
    int a[n] = {1, 2, 3, 4, 5};
    int b[m] = {4, 5, 6, 7, 8};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                cout<<"intersection element: "<<a[i]<<endl;
            }
        }
    }
    return 0;
}