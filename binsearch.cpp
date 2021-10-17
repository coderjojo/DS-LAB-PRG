#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int k)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k)
            return mid;
        if (arr[mid] > k)
            return binarySearch(arr, l, mid - 1, k);
        return binarySearch(arr, mid + 1, r, k);
    }
    return r;
}
