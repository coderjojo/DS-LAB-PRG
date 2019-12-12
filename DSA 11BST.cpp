#include<iostream>
using namespace std;

struct Node
{	
	int data;
	Node *right, *left;
};

Node *newNode(int key){
	Node *temp;
	temp = new Node;
	temp->data = key;
	temp->left = temp->right = NULL;
}

Node *Insert(Node *root, int data){
	if(root == NULL) return newNode(data);
	if(data > root->data)
		root->right = Insert(root->right, data);
	if(data < root->data)
		root->left = Insert(root->left, data);

	return root;
}

void inorder(Node *temp){
	if(temp != NULL){
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
}

void preorder(Node *temp){
	if(temp != NULL){
		cout<<temp->data<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(Node *temp){
	if(temp != NULL){
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<" ";
	}
}

int main(){
	Node *root = NULL;
	int data;

	while(1){
		char c;

		cout<<"\nEnter the data: ";
		cin>>data;

		root = Insert(root, data);
		cout<<"\nContinue (y/n)";
		cin>>c;

		if(c == 'n')
			break;
	}

	inorder(root);
	cout<<endl;

	postorder(root);
	cout<<endl;

	preorder(root);
	cout<<endl;
}
