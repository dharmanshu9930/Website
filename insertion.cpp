
#include <iostream>
using namespace std;

void printArray(int arr[], int N)
{
	// Traverse the element of arr[]
	for (int i = 0; i < N; i++) {

		cout << arr[i] << ' ';
	}
}

int main()
{
	
	int arr[4];

	
	int N = 4;


	for (int i = 1; i < 5; i++) {
		arr[i - 1] = i;
	}


	printArray(arr, N);
	return 0;
}
