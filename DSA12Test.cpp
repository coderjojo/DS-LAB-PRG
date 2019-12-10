#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};

Node *create(int d){
	Node *temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = d;

	return temp;

}

Node *Insert(Node *temp, int d){
	if(temp == NULL )
		return create(d);
	if(temp->data > d)
		temp->left = Insert(temp->left, d);
	else
		temp->right = Insert(temp->right, d);
 }

 void inorder(Node *temp){
 	
 	if(temp != NULL){
 		inorder(temp->left);
 		cout<<temp->data<<" ";
 		inorder(temp->right);
 	}

 }

 void Search(Node *temp, int key){
 	if(temp == NULL) cout<<"Not found!!";

 	else if(temp->data == key)
 		cout<<"Element found!";

 	else if(temp->data < key)
 		Search(temp->right, key);
 	else
 		Search(temp->left, key);
 }

Node *Findmin(Node *temp){
	while(temp->left != NULL)
		temp = temp->left;
	return temp;
} 

Node *Delete(Node *root, int key){
	if(root == NULL) return root;
	else if(key < root->data) 
		root->left = Delete(root->left, key);
	else if(key > root->data)
		root->right = Delete(root->right, key);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}

		else if(root->left == NULL){
			Node *temp = root;
			root = root->right;
			delete root;

		}

		else if(root->right == NULL){
			Node *temp = root;
			root = root->left;
			delete root;
		}

		else{
			Node *temp = Findmin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

int main(int argc, char const *argv[])
{
	int ch,e;
	Node *root = NULL;

	do{
	cout<<"\n1.Insert \n2.Delete \n3.Display \n4.Search \n5.Exit";
	cout<<"\nEnter your choice: ";
	cin>>ch;


	switch(ch){
		case 1:
			cout<<"\nEnter element: ";
			cin>>e;
			root = Insert(root,e);
			break;

		case 2:
			cout<<"\nEnter element to delete: ";
			cin>>e;
			root = Delete(root, e);
			break; 
			
		case 3:
		inorder(root);
		break;

		case 4:
			cout<<"\nEnter element to search: ";
			cin>>e;
			Search(root, e);
			break;

		}

	}while(ch!=4);

	return 0;
}
