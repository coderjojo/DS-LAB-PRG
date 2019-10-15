/*Author: CSJOJO 
  Date: 23/8/2019
  Acr: Assignment 3b 
  Code Plagiarized 
  Add code to print array after each pass */

#include<iostream>
#define MAX_SIZE 8
int arr[MAX_SIZE];
using namespace std;

void mergearray(int a, int b, int c, int d);

void mergesort(int i, int j){

	int m;

	while(i<j){
		m = (i+j)/2;
		mergesort(i, m);
		mergesort(m+1, j);

		mergearray(i,m,m+1,j);

	}

}

void mergearray(int a, int b, int c, int d){

	int arr1[50];
	int i = a, j = c, k(0);

	while(i<=b && j<=d){
		if(arr[i] < arr[j])
			arr1[k++] = arr[i++];
		else
			arr1[k++] = arr[j++];

	}

	while(i <= b)
		arr1[k++] = arr[i++];
	while(j <= c)
		arr1[k++] = arr[j++];


	for(i = a, j = 0; i <= d; i++, j++)
		arr[i] = arr1[j];

}





int main(){
	int N;
	cin>>N;

	arr[N];

	for(int i = 0; i < N; i++)
		cin>>arr[i];
	mergesort(0, N-1);

	for (int i = 0; i < N; ++i)
	{
		cout<<arr[i];
	}
}