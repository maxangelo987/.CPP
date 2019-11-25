#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Mathematics
{
	int a, b;
	public:
	void input(){
		cout<<"Input a: ";
		cin>>a;
		cout<<"Input b: ";
		cin>>b;
	}
	void add(){
		cout<<"(a+b)^2= "<<((a*a)+(2*a*b)+(b*b));
	}
};

int main(int argc, char** argv) {
	Mathematics m; // Creating object of class
	
	m.input();
	m.add();	
	cout<<"\n";
	system("PAUSE");
	return 0;
}
