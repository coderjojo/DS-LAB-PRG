#include <iostream>

using namespace std;

struct Node{
	int coeff, expo;
	Node *next;
};

Node *create(Node *n){
	int num, c, t;
	cout<<"Enter the Number of the terms: ";;
	cin>>num;

	for(int i = 0; i < num; i++){
		Node *temp = new Node;
		cout<<"\nEnter coefficient & Exponent: ";
		cin>>c>>t;

		temp->coeff = c;
		temp->expo = t;

		if(n == NULL){
			n = temp;
			temp->next = n;
		}
		else{
			temp->next = n->next;
            n->next = temp;
            n = temp;
		}
	}
	return n;
}


void Display(Node *n){
    Node *temp;
    if(n == NULL){
        cout<<"List is empty!";
        return;
    }

    temp = n->next;
    
    do{
        cout<<temp->coeff<<"x^"<<temp->expo<<" + ";
        temp = temp->next;
    }while(temp != n->next);
    
    /*if(temp == n->next)
        cout<<temp->coeff<<"x^"<<temp->expo;*/
}

void add(Node *a, Node *b){

    Node *temp, *temp1, *ans;

    temp = a->next;
    temp1 = b->next;

    do{
        if(temp->expo > temp1->expo){
            ans->expo = temp->expo;
            ans->coeff = temp->coeff;
            temp = temp->next;
        }
    }while(temp->next != a);

    /*Node *ans;
    Node *x = a->next;
    Node *y = b->next;

    while(x != a->next && y != b->next){
        if(x->expo > y->expo){
            ans->expo = a->expo;
            ans->coeff = x->expo;
            x = x->next;
        }

        else if(x->expo < y->expo){
            ans->expo = y->expo;
            ans->coeff = y->expo;
            x = y->next;
        }
        else{
            ans->expo = x->expo;
            ans->coeff = x->coeff + y->coeff;
            x = x->next;
            y = y->next;
        }
    }

    while(x != a->next || y!= b->next){
        if(x->next){
            ans->expo = x->expo;
            ans->coeff = x->coeff;
            x = x->next;
        }

        if(y->next){
            ans->expo = y->expo;
            ans->coeff = y->coeff;
            y = y->next;
        }

        ans->next = new Node;
        ans = ans->next;
        ans->next = ans;
    }

    Display(ans);*/

}

int main(int argc, char const *argv[])
{
	int val, ch, loc;
	Node *a = NULL;
	Node *b = NULL;
    Node *res =NULL;

	a = create(a);
	b = create(b);

    add(a, b);

    Display(a);
	return 0;
}
