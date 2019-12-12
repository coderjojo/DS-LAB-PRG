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


void fasttranspose(Mat a[], Mat b[]){
	 int row_terms[100],  start_pos[100];
            int i,  j,  p;       

            int numTerms = a[0].data;
            int numCols = a[0].col;
             
            b[0].row = numCols;
            b[0].col = a[0].row;
            b[0].data = numTerms;
            if(numTerms>0)
            {
                        for(i =0; i<numCols;  i++)
                                                row_terms[i] = 0;

                        for(i=1; i<=numTerms; i++)
                                                row_terms[a[i].col]++;

                        start_pos[0]=1;

                        for(i=1; i<numCols; i++)
                                                start_pos[i] = start_pos[i-1] + row_terms[i-1];

                        for(i=1; i<=numTerms; i++)
                        {
                                                j = start_pos[a[i].col]++;
                                    b[j].row = a[i].col;
                                                b[j].col = a[i].row;
                                                b[j].data = a[i].data;
                        }
             }
            printf("\nThe Fast Transpose sparse matrix is:\n");
            printf("\nRow\tColumn\tValue\n");
            for(p=0; p<=a[0].data; p++)
            {
                        printf("%d\t", b[p].row);
                        printf("%d\t", b[p].col);
                        printf("%d\n", b[p].data);
            }

}




int main(){

	int r,c;
	Mat arr[50], b[20];

	cout<<"Enter the number of the rows and colums: ";
	cin>>r>>c;

	readMatrix(arr,r,c);	
	fasttranspose(arr,b);
}

//https://tejaswinihbhat.blogspot.com/2016/08/sparse-matrix-fast-transpose.html
