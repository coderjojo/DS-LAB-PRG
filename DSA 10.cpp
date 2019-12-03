#include<iostream>
#define size 5
using namespace std;

struct queue
{
  int que[size];
  int front,rear;
}q;

int isfull()
{
  if(q.front==(q.rear+1)%size)
      return 1;
  else
      return 0;
}

int isempty()
{
   if(q.front==-1)
     return 1;
   else
     return 0;
}

void place_order(int order)
{
        if(q.front==-1)
            q.front=q.rear=0;
        else
            q.rear=(q.rear+1)%size;
     q.que[q.rear]=order;
}

void serve_order()
{
     int item;
             item=q.que[q.front];
             if(q.front==q.rear)
               q.front=q.rear=-1;
             else
               q.front=(q.front+1)%size;
     cout<<"\norder "<<item<<" is served\n";

}

void display()
{
    int i=q.front;
    if(isempty())
           cout<<"\nNo any pending orders.....\n";
else
{
     cout<<"Pending orders are: ";
           while(i!=q.rear+1)
           {
            cout<<"\n"<<q.que[i];
                 i=(i+1)%size;
           }
          // cout<<"\n"<<q.que[i];
}
}

int main()
{
 int ch,order,ch1,ch2;
 q.front=-1;
q.rear=-1;
      cout<<"\n                          Welcome to PiZZa HuT:)\n";
      cout<<"================================================================================";

 do
    {
      cout<<"\n\nEnter your choice\n";
      cout<<"1.place order 2.serve order 3.Display order list 4.Exit \n";
      cin>>ch;
      switch(ch)
               {
              	case 1:

                                      if(isfull())
                                        {
                                           cout<<"Sorry order cant be accepted...\n";
                                           cout<<"plzz try after some time:)\n";
                                        }
                                       else
                                         {
                                           cout<<"Enter order no:";
                                           cin>>order;
                                           place_order(order);
                                         }
                                           cout<<"\nOrder is placed successfully\n";
                                        break;
                        case 2:
                                if(isempty())
                                    cout<<"No order\n";
                                  else
                                      serve_order();
                                   break;
                        case 3:
                                   display();
                                   break;
                        case 4 :
                                return 0;
                        default:
                                   cout<<"\nInvalid case....\n";
                                    break;
	   }
                  cout<<"\n Press 1 to continue.......\n";
                  cin>>ch;
    }while(ch==1);
return 0;
}
