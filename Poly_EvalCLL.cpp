 #include<bits/stdc++.h>
 #include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
             int coeff;
             int expon;
             struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
            NODE x;
            x = (NODE) malloc(sizeof(struct node));
            return x;
}

NODE attach(int coeff, int expon, NODE head)
{
            NODE temp, cur;
            temp = getnode();
            temp->coeff = coeff;
            temp->expon = expon;
            cur = head->link;
            while(cur->link != head)
            {
                        cur = cur->link;
            }
            cur->link = temp;
            temp->link = head;
            return head;
}

NODE  read_poly(NODE head)
{
            int i = 1, coeff, expon;
            printf("\nEnter the coefficient as -999 to end the polynomial ");
            while(1)
            {
                        printf("\nEnter the %d term:\n",i++);
                        printf("\n\tCoeff = ");
                        scanf("%d", &coeff);
                        if(coeff == -999)
                                    break;
                        printf("\n\tPow x = ");
                        scanf("%d", &expon);
                        head = attach(coeff, expon, head);
            }
              return head;
}

NODE poly_add(NODE head1, NODE head2, NODE head3)
{
            NODE a,b;
            int coeff;
            a = head1->link;
            b = head2->link;
            while(a != head1 && b != head2)
            {
                        if(a->expon == b->expon)
                        {
                                    coeff = a->coeff + b->coeff;
                                    if(coeff != 0)
                                                head3 = attach(coeff, a->expon, head3);
                                    a = a->link;
                                    b = b->link;
                        }
                        else if(a->expon > b->expon)
                        {
                                     head3 = attach(a->coeff, a->expon, head3);
                                    a = a->link;
                        }
                        else
                        {
                                    head3 = attach(b->coeff, b->expon, head3);
                                    b = b->link;
                        }
            }
            while(a != head1)
            {
                        head3 = attach(a->coeff, a->expon, head3);
                        a = a->link;
            }
            while(b != head2)
            {
                        head3 = attach(b->coeff, b->expon, head3);
                        b = b->link;
            }
            return head3;
}

NODE poly_Mul(NODE head1, NODE head2, NODE head3)
{
            NODE a,b;
            int coeff;
            a = head1->link;
            b = head2->link;
            while(a != head1 && b != head2)
            {
                        if(a->expon == b->expon)
                        {
                                    coeff = a->coeff * b->coeff;
                                    if(coeff != 0){

                                                a->expon = a->expon + a->expon; 
                                                head3 = attach(coeff, a->expon, head3);
                                          }
                                    a = a->link;
                                    b = b->link;
                        }
                        else if(a->expon > b->expon)
                        {
                                     head3 = attach(a->coeff, a->expon, head3);
                                    a = a->link;
                        }
                        else
                        {
                                    head3 = attach(b->coeff, b->expon, head3);
                                    b = b->link;
                        }
            }
            while(a != head1)
            {
                        head3 = attach(a->coeff, a->expon, head3);
                        a = a->link;
            }
            while(b != head2)
            {
                        head3 = attach(b->coeff, b->expon, head3);
                        b = b->link;
            }
            return head3;
}

int Pol_eval(NODE head1){
      NODE a;
      int v, res = 0;
      cout<<"Enter Value: ";
      cin>>v;

      a = head1->link;
      while(a != head1){
            res += ((a->coeff)* pow(v,(a->expon))); 
            a = a->link;
      }

      return res;
}

void display(NODE head)
{
            NODE temp;
            if(head->link == head)
            {
                         printf("\nPolynomial does not exist");
                         return;
            }
            temp = head->link;
            while(temp != head)
            {
                         printf("%dx^%d",temp->coeff, temp->expon);
                         temp = temp->link;
                         if(temp != head)
                                    printf(" + ");
            }
}

int main()
{
            NODE head1, head2, head3, head4;
            head1 = getnode();
            head2 = getnode();
            head3 = getnode();
            head4 = getnode();

            head1->link=head1;
            head2->link=head2;
            head3->link=head3;
            head4->link=head4;

            printf("\nEnter the first polynomial \n");
            head1 = read_poly(head1);
            printf("\nEnter the second polynomial \n");
            head2 = read_poly(head2);

            head3 = poly_add(head1, head2, head3);

            head4 = poly_Mul(head1, head2, head4);

            printf("\nPolynomial 1:\t");
            display(head1);
            printf("\nPolynomial 2:\t");
            display(head2);
            printf("\nPolynomial Result:\t");
            display(head3);

            printf("\nPolynomial Multiplication: \t");
            display(head4);

            printf("\nPolynomial Evaluation: \t");
            int r = Pol_eval(head1);
            cout<<r<<endl;

            return 0;
}
