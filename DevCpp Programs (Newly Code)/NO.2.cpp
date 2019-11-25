#include<cstdlib>
#include <iostream>
#include<math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class example
{
	public:
		void intro();
		void input();
		void process();
		void output();
		
		long inp, i, a, back, dig, j, sum, k, b, l, check[100];
		long m, n, happy[100], p;
}; 

int main(int argc, char *argv[]) 
{
	example x;
	x.intro();
	x.input();
	x.process();
	x.output();
	
	system ("PAUSE");
	return 0;
}

void example::intro()
{
	cout<<"Happy Number within Range:\n";
}

void example::input()
{
	cin>>inp;
}

void example::process()
{
	back=inp;
	for (;;)
		{
			sum=0;
			for (;back!=0;)
				{
				dig=back%10;
				sum=dig*dig+sum;
				back=back/10;
				}
				if (sum==1)
					{
					cout<<"MAOT PRETZY";	
					break;
					}
					
				else if (sum==145)
					{
					cout<<"UNHAPPY";
					break;
					}
		back=sum;
		
		}
	
}
void example::output()
{
	
}
