#include<iostream>
using namespace std;

struct Student
 {
 	char name[10];
	unsigned int roll_no;
	char address[10];
 	
 }; 

void Accept(struct Student S[], int n) 
{
	for (int i = 0; i < n; ++i)
	{
		cout<<"\nEnter roll no: ";
		cin>>S[i].roll_no;

		cout<<"\nEnter the name of the student: ";
		cin>>S[i].name;

		cout<<"\nEnter student Address: ";
		cin>>S[i].address;
	}
}


void Display(struct Student S[], int n){

	for (int i = 0; i < n; ++i)
	{
		cout<<"\nStudent Roll No: "<<S[i].roll_no;

		cout<<"\nStudent Name: "<<S[i].name;

		cout<<"\nStudent Address: "<<S[i].address;

		cout<<"\n------------------------------------------";

	}
}


void SortDetails(struct Student S[], int n){

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(S[i].roll_no < S[j].roll_no){
				Student temp = S[i];
				S[i] = S[j];
				S[j] = temp;
			}
		}
	}
}


void SearchDetails(struct Student S[], int n){
	cout<<"\nEnter the roll number of the student to be searched: ";
	int key, flag = 0;
	cin>>key;

	for (int i = 0; i < n; ++i)
	{
		if(S[i].roll_no == key){
			flag = 1;
			cout<<"Name of student is: "<<S[i].name;
			break;
		}

	}

	if(!flag)
		cout<<"\nTry again with correct roll number / roll number not exist!";

}



int main(){

	int n;
	cout<<"Enter the name of the Student: ";
	cin>>n;
	Student S[n];

	Accept(S,n);
	SortDetails(S,n);
	Display(S,n);
	SearchDetails(S,n);
}