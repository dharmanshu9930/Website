#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int val)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (a[mid] == val)
        {
            return mid;
        }

        else if (val < a[mid])
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "ENter the size of array : ";
    cin >> n;
    int a[100];

    cout << "Enter the elements of the array : ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cout << "Enter the target element : ";
    cin >> x;

    cout << "Target Element is found at location : "<< binarySearch(a, n, x);

    return 0;
}