#include <cstdlib>
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class example
{
	public:
		void intro();
		void input();
		void prime();
		void process();
		void output();
		
		long inp, i, j, count, k, check[100], back, bin, base, rev;
		long temp[100], l, n, pal[100], bak, rem, mer;
};
int main(int argc, char *argv[])
{
	example x;
	x.intro();
	x.input();
	x.prime();
	x.process();
	x.output();
	
	system ("PAUSE");
	return EXIT_SUCCESS;
}

void example::intro()
{
	cout<<"Palindromic Prime n Base 2:\n";
}

void example::input()
{
	cin>>inp;
}

void example::prime()
{
	k=0;
	for (i=2;i<=inp;i++)
	{
		count=0;
		for (j=2;j<i;j++)
		{
			if (i%j==0)
			{
				count++;
			}
		}
		if (count==0)
		{
			check[k]=i;
			k++;
		}
	}
}

void example::process()
{
	l=0;
	
	for (j=0;j<k;j++)
	{
		
		bak=check[j];
		bin=0;
		base=1;
		rev=0;
		while (check[j]!=0)
		{
			rem=check[j]%2;
			bin=bin+rem*base;
			base=base*10;
			check[j]=check[j]/2;
		}
		back=bin;
		while (bin!=0)
		{
			mer=bin%10;
			rev=rev*10+mer;
			bin=bin/10;
		}
		if (rev==back)
		{
			temp[l]=bak;
			pal[l]=rev;
			l++;
		}
	}
}

void example::output()
{
	for (n=0;n<l;n++)
	{
		cout<<temp[n]<<"=";
		cout<<pal[n];
		cout<<"\n";
		
	}
}
