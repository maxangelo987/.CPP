#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long x[100],countx,i,count,j;
	
	countx=0;
	for (i=0;;i++)
		{
		cin>>x[i];
		if (x[i]==0)
			{
			break;
			}
		countx++;
		}

	for (i=0;i<countx;i++)
		{
		count=0;
		for (j=2;j<x[i];j++)
			{
			if (x[i]%j==0)
				{
				count++;
				}
			}	
		if (count!=0)
			{
			if (x[i]%2==0)
				{
				cout<<x[i]<<" ";
				}
				
			}
		}
		
	
	
	return 0;
}
