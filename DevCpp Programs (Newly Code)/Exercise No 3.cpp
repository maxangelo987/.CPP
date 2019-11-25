#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char str[100],*x;
	int y,b,a,sum,i,j,j2;
	float b2,sum2,sum3;
	
	cout<<"Input binary to be converted to decimal: ";
	gets(str);
	
	x=strtok(str," ");
	while (x!=NULL)
	{
		a=0;
		y=strlen(x)-1;
		for (i=y;i>=0;i--)
		{
			if (x[i]=='.')
			{
				a++;
				break;
			}
		}
		if (a!=0)
		{
			sum=0;
			b=1;
			sum2=0;
			b2=0.5;
			for (j=i-1;j>=0;j--)
			{
				if (x[j]=='1')
				{
					sum=sum+b;
				}
					b=b*2;
			}
			for (j2=i+1;j2<=y;j2++)
			{
				if (x[j2]=='1')
				{
					sum2=sum2+b2;
				}
					b2=b2*0.5;
			}
			sum3=sum+sum2;
			cout<<sum3<<endl;
		}
		else
		{
			sum=0;
			b=1;
			for (j=y;j>=0;j--)
			{
				if (x[j]=='1')
				{
					sum=sum+b;
					b=b*2;
				}
				else
				{
					b=b*2;
				}
			}
			cout<<sum<<endl;
		}
		x=strtok(NULL," ");
	}
	
	
	
	return 0;
}
