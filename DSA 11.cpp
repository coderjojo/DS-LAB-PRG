#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
  int info;
  struct node *left;
  struct node *right;
}*root;

class BST{
 public:

     void insert(node *,node *);
     void case_a(node *,node *);
     void case_b(node *,node *);
     void case_c(node *,node *);
     void preorder(node *);
     void postorder(node *);
     void inorder(node *);
     BST()

     {
        root=NULL;
     }
};

int main()
{
  int choice,num;
  BST bst;
  node *temp;

  while(1)
   {
      cout<<"-------------------------------"<<endl;
      cout<<"Operation on BST"<<endl;
      cout<<"-------------------------------"<<endl;
      cout<<"1.Insert Element"<<endl;
      cout<<"2.Inorder Traversal"<<endl;
      cout<<"3.Preorder Traversal"<<endl;
      cout<<"4.Postorder Traversal"<<endl;
      cout<<"5.Quit"<<endl;
      cout<<"Enter your choice:";
      cin>>choice;

      switch(choice)
       {
        case 1:
            temp=new node;
            cout<<"Enter the number to be inserted:";
            cin>>temp->info;
            bst.insert(root,temp);
            break;
       case 2:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(root);
            cout<<endl;
            break;
       case 3:
            cout<<"Preorder Traversal of BST"<<endl;
            bst.preorder(root);
            cout<<endl;
            break;
       case 4:
            cout<<"Postorder Traversal of BST"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
       case 5:
             exit(1);
       default:
            cout<<"Wrong Choice"<<endl;
     }
   }

}
 //Inserting element into Tree

void BST::insert(node *tree,node *newnode)
{
  if(root==NULL)
  {
    root=new node;
    root->info=newnode->info;
    root->left=NULL;
    root->right=NULL;
    cout<<"Root node is added "<<endl;
    return;
  }


 if(tree->info==newnode->info)
  {
    cout<<"Element already in the Tree"<<endl;
    return;
  }
  if(tree->info>newnode->info)
  {
   if(tree->left!=NULL)
    {
      insert(tree->left,newnode);
    }
   else
    {
      tree->left=newnode;
      (tree->left)->left=NULL;
      (tree->left)->right=NULL;
      cout<<"Node Added to left"<<endl;
      return;
    }
  }
 else
 {
   if(tree->right!=NULL)
   {

   insert(tree->right,newnode);
   }
   else
   {
     tree->right=newnode;
     (tree->right)->left=NULL;
     (tree->right)->right=NULL;
     cout<<"Node Added to Right"<<endl;
     return;

   }
 }

}

//Preorder Traversal

void BST::preorder(node *ptr)
{
  if(root==NULL)
   {
     cout<<"Tree is Empty"<<endl;
     return;
   }
  if(ptr!=NULL)
  {
   cout<<ptr->info<<" ";
   preorder(ptr->left);
   preorder(ptr->right);

  }
}

//Inorder Traversal

void BST::inorder(node *ptr)
{
 if(root==NULL)
 {
   cout<<"Tree is Empty"<<endl;
   return;
 }
 if(ptr!=NULL)
 {
   inorder(ptr->left);
   cout<<ptr->info<<" ";
   inorder(ptr->right);
 }
}

//Postrorder Traversal

void BST::postorder(node *ptr)
{
  if(root==NULL)
  {
    cout<<"Tree is Empty"<<endl;
    return;
  }
  if(ptr!=NULL)
  {
   postorder(ptr->left);
   postorder(ptr->right);
   cout<<ptr->info<<" ";

  }
}

































