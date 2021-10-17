#include <iostream>
using namespace std;
char stack[20];
int top = -1;

char pop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

void push(char x)
{
	stack[++top] = x;
}

int priority(char c)
{

	if (c == '(')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == '/' || c == '*')
		return 3;
	else if (c == '^')
		return 4;
	else
		return -1;
}

int main()
{
	char inf[20], post[20], *e, s;

	cout << "Enter the infix notation: ";
	cin >> inf;
	e = inf;
	while (*e != '\0')
	{
		if (isalnum(*e))
			cout << *e;
		else if (*e == '(')
			push(*e);
		else if (*e == ')')
		{
			while ((s = pop()) != '(')
				cout << s;
		}

		else
		{
			while (priority(stack[top]) >= priority(*e))
				cout << pop();
			push(*e);
		}
		e++;
	}

	while (top != -1)
		cout << pop();
}
