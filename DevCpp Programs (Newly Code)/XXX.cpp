#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long countx,i,x[100],dig,k;
	long digits,temp,sum,count;
	countx=0;
	for (i=0;;i++)
		{
		cin>>x[i];
		countx++;
		if (x[i]==0)
			{
			break;
			}
		}
		
	cout<<"Digits: ";
	cin>>dig;
	
	for (i=0;i<countx;i++)
		{
			temp=x[i];
			digits=0;
			for (;temp!=0;)
				{
				temp=temp/10;
				digits++;
				}
			if (digits==dig)
				{
				temp=x[i];
				sum=0;
				for (;temp!=0;)
					{
					sum=sum+(temp%10);
					temp=temp/10;
					}
				count=0;
				for (k=2;k<sum;k++)
					{
					if (x[i]%k==0)
						{
						count++;
						}
					}
					
				if (count==0)
					{
					cout<<x[i]<<" "; 
					}			
				}
		}
		
	
	
	
	return 0;
}
