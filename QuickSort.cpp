#include <iostream>

using namespace std;
int partition(int a[], int low, int high)
{
    int i, j, temp, key;
    key = a[low];
    i = low;
    j = high + 1;
    while (i <= j)
    {
        do
            i++;
        while (key >= a[i] && i <= high);
        do
            j--;
        while (key < a[j]);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void qs(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        qs(a, low, mid - 1);
        qs(a, mid + 1, high);
    }
}

int main()
{
    int n, i;
    cout << "Quicksort Test\n";
    // Input no.of Elements
    cout << "\nEnter the number of elements\n";
    cin >> n;
    // Created array of n elements
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nThe elements are\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    // Calling QuickSort
    qs(arr, 0, n - 1);
    // Printing Sorted Array
    cout << "\nThe elements after sorting \n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}