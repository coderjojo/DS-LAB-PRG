#include<iostream>
using namespace std;

template<class T>
T SelSort(T arr[], T n){
	int min;
	T temp;
	bool f = 0;
	for(int i = 0; i < n; i++){
		 min = i;
		for(int j = i+1; j < n; j++){
			if(arr[j]<arr[min]){
				min = j;
				f = 1;
			}

		}
		if(f){
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp; 
		}
			
	}
}


int main(){
	int arr[] = {10,16,2,4,56,23,55,33,23,11};
	int n = 10;

	SelSort<int>(arr,n);

	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";


	
}
