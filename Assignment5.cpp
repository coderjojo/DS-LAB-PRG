#include <iostream>
using namespace std;

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int partion(int arr[], int s, int e)
{
	int piv = arr[e];
	int pi = s;
	for (int i = pi; i < e; i++)
	{
		if (arr[i] <= piv)
		{
			swap(arr, i, pi);
			pi++;
		}
	}

	swap(arr, pi, e);
	return pi;
}

void quickS(int arr[], int s, int e)
{
	if (s < e)
	{

		int p = partion(arr, s, e);
		quickS(arr, s, p - 1);
		quickS(arr, p + 1, e);
	}
}

int main()
{
	int arr[10] = {66, 3, 33, 55, 6, 77, 1, 2, 99, 10};
	int n = 10;

	quickS(arr, 0, 10);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
