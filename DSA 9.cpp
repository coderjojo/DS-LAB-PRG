#include<iostream>

# define max 100
char st[max];
int top=-1;
using namespace std;
void push(char ele)
{
  st[++top]=ele;
}
char pop()
{
   return (st[top--]);
}
int priorty(char ch)
{
  switch(ch)
  {

   case '^' : return 4;
   case '*' : return 3;
   case '/' : return 3;
   case '+' : return 2;
   case '-' : return 2;
   case '(' : return 1;
   }
 }
 int main()
 {
   char infix[50],postfix[50],ch,element;
   int i=0,k=0;
   cout<<"enter the infix notation: ";
   cin>>infix;
   for(i=0;infix[i]!='\0';i++)
   {
    ch=infix[i];

      if(isalnum(ch))
     {
       postfix[k++]=ch;
     }
      else if(ch=='(')
     {
       push(ch);
     }
     else if(ch==')')

     {
          while(st[top]!='(')
             postfix[k++]=pop();
       element=pop();
       }
     else
     {
       while(priorty(ch)<=priorty(st[top]))
       {
         postfix[k++]=pop();
        }
       push(ch);
     }
    }
    while(st[top]>=0)
         postfix[k++]=pop();
    postfix[k++]='\0';
    cout<<"postfix="<<postfix;
    return 0;
}




