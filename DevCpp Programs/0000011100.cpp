// (0000011100) Rounding off numbers <CpE221/Mathematics>

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
double inp,x2,x23;
long x,x1,i,x22,temp,rem,temp1;
long count,j,digs[100],d,a,b,c,digst[100];

cout<<"Enter Input: ";
cin>>inp;

cout<<"Enter digit to round off: ";
cin>>x;


x1=(long)inp;
x2=inp-x1;

if (x2!=0)
	{
	x2=(x2*1000000)+1;
	x22=(long)x2;
	temp=x22%10;

	if (temp==1)
		{
		x22=x22-1;
		}

		rem=0;
		for(;;)
			{

			if (rem!=0)
				{
				break;
				}

			x22=x22/10;
			rem=x22%10;
			}

		temp1=x22;
		count=0;
		d=0;
		for(;temp1!=0;)
			{
            digs[d]=temp1%10;
			temp1=temp1/10;
			count++;
			d++;
			}
        a=d-1;
        c=0;
        for (b=0;b<x+1;b++)
            {
            digst[c]=digs[a];
            c++;
            a--;
            }
            
            cout<<digst[c-1]<<" ";
            if (digst[c-1]>=5)
               {
               digst[c-2]=digst[c-2]+1;              
               cout<<"Hey";
               }
           
           for (j=0;j<x;j++)
               {
               cout<<digst[j];
               }
   }

    system("PAUSE");
    return EXIT_SUCCESS;
}
