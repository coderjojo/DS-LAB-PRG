#include<iostream>
using namespace std;
struct Mat
{
	int row,col,data;
}sparce;


void readMatrix(Mat arr[], int r, int c){
	int i, j, e;
	arr[0].row = r;
	arr[0].col = c;
	int k = 1;

	cout<<"Enter the elements: \n";
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin>>e;
			//simple transpose
			if(e == 0)
				continue;

			arr[k].row = i;
			arr[k].col = j;
			arr[k].data = e;
			k++;
		}
	}

	arr[0].data = k-1;

	cout<<"\nEnterd sparce matric is: "<<endl;
	for(int i = 0; i <= arr[0].data; i++){
		cout<<arr[i].row<<"  "<<arr[i].col<<"  "<<arr[i].data;
		cout<<endl;
	}
}

/*
void fasttranspose(Mat a[], Mat b[]){
	int rows[100], start[100];

	int num = a[0].data;
	int cols = a[0].col;

	b[0].data = num;
	b[0].col = a[0].row;
	b[0].row = cols;
	if(num>0){
		for(int i = 0; i < cols; i++)
			rows[i] = 0;
		for(int i = 1; i <= num; i++)
			rows[a[i].col]++;
		start[0] = 1;
		for(int i = 1; i < cols; i++)
			start[i] = start[i-1] + rows[i-1];

		for(int i = 1; i < num; i++){
			int j = start[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].data = a[i].data;
		}
	}


	cout<<"\nFast transpose:  "<<endl;
	for(int i = 0; i <= a[0].data; i++){
		cout<<a[i].row<<"  "<<a[i].col<<"  "<<a[i].data;
		cout<<endl;
	}

}*/




int main(){

	int r,c;
	Mat arr[50], b[20];

	cout<<"Enter the number of the rows and colums: ";
	cin>>r>>c;

	readMatrix(arr,r,c);	
	//fasttranspose(arr,b);
}
