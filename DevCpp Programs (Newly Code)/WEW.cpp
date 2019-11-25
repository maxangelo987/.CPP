#include <iostream>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x, inp[100], i;
	cout<<"HELLO";
	cin>> x;
	for(i = 0; i < x; i++)
	{
		cin>>inp[i];
	}
	for(int j = 0; j < i; j++)
	{
		cout<<inp[j]<<" ";
	}
	int y = 0, z = 0, a = 0;
	cout<<endl;
	for(int ko = 0; ko < 10000; ko++)
	{
		y++;
	}
	cout<<y;
	return 0;
}
