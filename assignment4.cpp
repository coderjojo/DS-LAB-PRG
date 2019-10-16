#include<iostream>
using namespace std;

int main()
{
	int n,a[20],i,j,temp,k;
	cout<<endl<<"Sorting in ascending order by using selection sort"<<endl<<endl;
	cout<<"Enter how many number you want to sort? ";
	cin>>n;

	cout<<"Enter numbers="<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"acsending order using selection sort"<<endl;
	cout<<"Passes";
	for(i=0;i<n;i++)
	{
		j=i;

		while(j>0&&a[j]<a[j-1])
		{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			
			j--;
			
		}
		
		for(k=0;k<n;k++)
		{
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"sorted numbers are="<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl<<endl<<"Decsending order using insertion sort"<<endl;
	for(i=0;i<n;i++)
	{
		j=i;
		while(j>0&&a[j]>a[j-1])
		{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			j--;
		}
		for(k=0;k<n;k++)
		{
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"sorted nubers are="<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}


	
	return 0;
}
