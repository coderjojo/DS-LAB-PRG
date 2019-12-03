#include<bits/stdc++.h>

using namespace std ;

struct node{
int roll,marks;
struct node *next;

}*head=NULL;

void create()
{
//    int r,m;
    struct node *tmp,*nn;
    nn=new node;
    cout<<"\nEnter Roll No:";
    cin>>nn->roll;
    cout<<"\nEnter Marks:";
    cin>>nn->marks;
    nn->next=NULL;
    if(head==NULL)
        head=nn;
    else
    {
        tmp=head;
        while(tmp->next!=NULL)
            tmp=tmp->next;
        tmp->next=nn;
    }


}
void insertF()
{
    struct node *tmp,*nn;
    nn=new node;
    cout<<"Enter Roll No:";
    cin>>nn->roll;
    cout<<"Enter Marks:";
    cin>>nn->marks;
    nn->next=NULL;
    if(head==NULL)
        head=nn;
    else{
        tmp=head;
        head=nn;
        head->next=tmp;
    }

}
void display()
{
    struct node *tmp;
    tmp=head;
    if(tmp==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        cout<<"=========================================================================="<<endl;
        cout<<"Members in Linked List are:"<<endl<<endl;
        int j=1;
        while(tmp!=NULL)
        {


            cout<<"\n Roll no: "<<tmp->roll<< "\t Marks: "<< tmp->marks<<endl;
            tmp=tmp->next;

        }
        cout<<"=========================================================================="<<endl;
    }
}

void insertAtPos()
{
    int pos;
    struct node *tmp,*nn;
    nn=new node;
    cout<<"\nEnter Roll no:";
    cin>>nn->roll;
    cout<<"\nEnter Marks";
    cin>>nn->marks;
    cout<<"\nEnter position to insert node";
    cin>>pos;
    int i=1;
    tmp=head;
    while(i<pos-1&&tmp!=NULL)
    {
        tmp=tmp->next;
        i++;
    }
    if(tmp==NULL)
        cout<<"Inavlid Position"<<endl;
    else
    {

    nn->next=tmp->next;
    tmp->next=nn;
    }
}

void deleteF()
{
    if(head==NULL)
        cout<<"\nList is empty";
    else{
        struct node *tmp;
        tmp=head;
        head=head->next;
        delete(tmp);
    }
}
void deleteL()
{
    if(head==NULL)
        cout<<"List is empty";
    else{
        struct node *tmp,*nn=NULL;
        tmp=head;
        while(tmp->next!=NULL)
        {
            nn=tmp;
            tmp=tmp->next;
        }
        if(head->next==NULL)
        {
            delete(tmp);
            head=NULL;
        }
        else
        {
        nn->next=NULL;
        delete(tmp);
        }
    }

}
void deleteAtPos()
{
    int pos;
    struct node *tmp,*nn;
    cout<<"\nEnter Position to delete node:";
    cin>>pos;
    if(head==NULL)
        cout<<"List is Empty"<<endl;
    else{
        int i=1;
        tmp=head;
        while(i<pos&&tmp!=NULL)
        {
            nn=tmp;
            tmp=tmp->next;
            i++;
        }
        if(tmp==NULL)
            cout<<"Invalid Position"<<endl;
        else
        {
            nn->next=tmp->next;
            delete(tmp);
        }

    }
}
void modify()
{
    int r;
    node *tmp;
    if(head==NULL)
        cout<<"\nList is Empty"<<endl;
    else
    {
        tmp=head;
        cout<<"Enter roll no to be modified";
        cin>>r;
        while(tmp!=NULL)
        {
            if(tmp->roll==r)
                break;
            else
                tmp=tmp->next;
        }
        if(tmp==NULL)
            cout<<"Record not Fourd..!"<<endl;
        else
        {
            cout<<"Enter new roll no:";
            cin>>tmp->roll;
            cout<<"Enter Modified Marks:";
            cin>>tmp->marks;
        }
    }

}

int main()
{
    int n;
    char ch='n';
    do
    {

        cout<<"1.Create\n2.Insert first\n3.Insert Last\n4.Insert at position\n5.Delete Fisrt\n6.Delete Last\n7.Delete at position\n8.modify\n9.Display"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
                create();
                //display();
            break;

            case 2:
                insertF();
                //display();
            break;

            case 3:
                create();
                //display();
            break;

            case 4:
                insertAtPos();
                //display();
            break;

            case 5:
                deleteF();
                //display();
            break;

            case 6:
                deleteL();
                //display();
            break;

            case 7:
                deleteAtPos();
                //display();
            break;

            case 8:
                modify();
                //display();
            break;

            case 9:
                display();
            break;

            default:
                cout<<"Invalid choice"<<endl;


        }
        cout<<"Do you want to continue?->(y/n)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}
