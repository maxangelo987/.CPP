#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char *argv[]) {
	
	int i, j, x, y, count, k, l, count1=0;
	char str[100], str1[100];
	char *myword1[20],*myword2[20],*ptr;
	long a,counta,countnaa;	
	cout<<"Enter a word:";
	gets(str);
	
a=0; counta=0;

ptr=strtok(str, " ");
while(ptr!=NULL)
	{
	myword1[a]=ptr;
	a++;
	ptr=strtok(NULL, " ");
	}

	
	cout<<"Enter a word to be searched:";
	gets(str1);
	myword2[0]=str1;
	
	countnaa=0;
	for (i=0;i<a;i++)
		{
		if (strcmp(myword1[i],myword2[0])==0)
			{
			countnaa++;
			}
		}
	
	if (countnaa==0)
		{
		cout<<"NOT FOUND FUCKERS";
		}
	
	else
		{
		cout<<"FOUND BITCH";
		}
	return 0;
}
