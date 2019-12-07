#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
}*head = NULL;


void create(){
	Node *temp, *nn;
	nn = new Node;

	cout<<"Enter the data: ";
	cin>>nn->data;

	nn->next = NULL;

	if(head == NULL){
		head = nn;
	}
	else{
		temp =head;
		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = nn;
	}
}

void insertFront(){
	Node *nn, *temp;
	nn = new Node;

	cout<<"Enter the data: ";
	cin>>nn->data;

	nn->next = head;
	head = nn;
}

void insertPosition(){
	int pos;
	Node *nn, *temp;
	nn = new Node;

	cout<<"\nEnter data: ";
	cin>>nn->data;

	cout<<"\nEnter the position: ";
	cin>>pos;
	temp = head;

	while(pos-- && temp != NULL)
		temp = temp->next;

	nn->next = temp->next;
	temp->next = nn;

}

void display(){
	Node *temp;
	temp = head;
	if(temp == NULL)
		cout<<"Empty!";
	else{
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
}

int main(){

	int ch = 3;

	while(ch){
		cout<<"\nEnter 1. Create\n2.display\n3.Insert at the front\n4.InsertInBetween"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
			create();
			break;
			case 2:
			display();
			break;
			case 3: 
			insertFront();
			break;
			case 4:
			insertPosition();
			break;
		}
	}

}
