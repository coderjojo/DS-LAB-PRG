/*Author: CSJOJO
  Date: 10/8/2019
  Acr: Assignment 1
  Changes Required for optimization */

#include <iostream>
using namespace std;

int FindLength(char *c, int &length)
{
	while (*c != '\0')
	{
		length++;
		*c++;
	}
	cout << "Length of the string : " << length << endl;
}

void copyString(char *c)
{
	int i = 0;
	char str1[16];
	while (*c != '\0')
	{
		str1[i++] = *c;
		*c++;
	}

	str1[i] = '\0';
	cout << "Copied string: " << str1 << endl;
}

void reverseString(int &length, char str[])
{
	char str2[16];
	int j = 0;
	for (int i = length - 1; i >= 0; i--)
		str2[j++] = str[i];
	str2[j] = '\0';
	cout << "Reverse:" << str2 << endl;
}

void compareString(char str[], char *c)
{
	char str1[10];
	int flag = 1;
	cout << "Enter a String to comapre : ";
	cin >> str1;
	char *ch = str1;
	while (*ch || *c)
	{
		if (*ch != *c)
		{
			flag = 0;
			break;
		}
		ch++;
		c++;
	}

	if (flag)
		cout << "equal" << endl;
	else
		cout << "Not Equal" << endl;
}

void concanitateString(char str[], char str2[])
{

	int i = 0;
	int j = 0;

	cout << "Enter string 2 to concanitate: ";
	cin >> str2;

	while (str[i] != '\0')
	{
		i++;
	}
	while (str2[j] != '\0')
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	str[i] = '\0';

	cout << str;
}

int main()
{
	char str[50];
	char *c = str;
	char str1[10];
	int length = 0;
	char str4[6] = "Hello";

	cout << "Enter string: ";
	cin >> str;

	FindLength(c, length);
	copyString(c);
	reverseString(length, str);
	compareString(str, c);
	concanitateString(str, str1);
}