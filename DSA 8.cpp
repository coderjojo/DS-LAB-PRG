#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

typedef struct node
 {
  int expo,coef;
  struct node *next;
 }node;

node * insert(node *,int,int);
node * create();
node * add(node *p1,node *p2);
node * multi(node *p1,node *p2);
int eval(node *p1);
void display(node *head);


node *insert(node*head,int expo1,int coef1)
  {
   node *p,*q;
   p=(node *)malloc(sizeof(node));
   p->expo=expo1;
   p->coef=coef1;
   p->next=NULL;
   if(head==NULL)
    {
      head=p;
      head->next=head;
      return(head);
    }
   if(expo1>head->expo)
    {
      p->next=head->next;
      head->next=p;
      head=p;
      return(head);
    }
   if(expo1==head->expo)
    {
      head->coef=head->coef+coef1;
      return(head);
    }
    q=head;
    while(q->next!=head&&expo1>=q->next->expo)
      q=q->next;
      if(p->expo==q->expo)
               q->coef=q->coef+coef1;
      else
       {
                p->next=q->next;
                q->next=p;
       }
      return(head);
  }


node *create()
 {
  int n,i,expo1,coef1;
  node *head=NULL;
  cout<<"\n\nEnter no of terms of polynomial==>";
    cin>>n;
  for(i=0;i<n;i++)
   {
     cout<<"\n\nEnter coef & expo==>";
    cin>>coef1>>expo1;
     head=insert(head,expo1,coef1);
   }
  return(head);
 }


node *add(node *p1,node *p2)
 {
  node *p;
  node *head=NULL;
  cout<<"\n\n\nAddition of polynomial==>";
  p=p1->next;
  do
   {
     head=insert(head,p->expo,p->coef);
     p=p->next;
   }while(p!=p1->next);
    p=p2->next;
  do
   {
     head=insert(head,p->expo,p->coef);
     p=p->next;
   }while(p!=p2->next);
    return(head);
  }



node *multi(node *p1,node *p2)
 {
  node *head1,*head2;
  node *head=NULL;
  cout<<"\n\n\nMultiplication of polynomial==>";
  head2=p2->next;
  do
   {
    head1=p1->next;
    do
     {
       head=insert(head,head1->expo+head2->expo,head1->coef*head2->coef);
       head1=head1->next;
     }while(head1!=p1->next);
       head2=head2->next;
   }while(head2!=p2->next);
    return(head);
 }

int eval(node *head)
 {
  node *p;
  int x,ans=0;
  cout<<"\n\nEnter the value of x=";
 cin>>x;
  p=head->next;
  do
   {
     ans=ans+p->coef*pow(x,p->expo);
     p=p->next;
   }while(p!=head->next);
    return(ans);
 }
class poly
{
    public:
void display(node *head)
 {
  node *p,*q;
  int n=0;
  q=head->next;
  p=head->next;
  do
  {
   n++;
   q=q->next;
  }while(q!=head->next);
  cout<<"\n\n\tThe polynomial is==>";
  do
   {
    if(n-1)
     {
      cout<<p->coef<<"x^"<<p->expo;
      p=p->next;
     }
    else
    {
     cout<<p->coef<<"x^"<<p->expo;
     p=p->next;
    }
    n--;
   } while(p!=head->next);
 }
};
int main()
 {
  poly p;
  char ans;
  int a,x,ch;
  node *p1,*p2,*p3;
  p1=p2=p3=NULL;
  do
  {
   cout<<"\n\tPolynomial Operations :";
   cout<<" 1.Add";
   cout<<"\n\t\t\t\t2.Multiply";
   cout<<"\n\t\t\t\t3.Evaluate";
   cout<<"\n\t\t\t\t4.Exit";
   cout<<"\n\n\n\tEnter your choice==>";
   cin>>ch;
   switch(ch)
    {
     case 1 :
                      p1=create();
                      p.display(p1);
                      p2=create();
                      p.display(p2);
                      p3=add(p1,p2);
                      p.display(p3);
                       break;
     case 2 :
                     p1=create();
                     p.display(p1);
                     p2=create();
                     p.display(p2);
                     p3=multi(p1,p2);
                     p.display(p3);
                     break;
     case 3 :
                     p1=create();
                     p.display(p1);
                     a=eval(p1);
                     cout<<"\n\nValue of polynomial="<<a;
                     break;
     case 4 :
                     exit(0);
                     break;
    default :
                     cout<<"\n\n\tinvalid choice";
                     break;

   }
   cout<<"\n\n\nDo you want to continue(Y/N)?==>";
   cin>>ch;
  }while(ans=='Y'||ans=='y');
   return 0;
 }
