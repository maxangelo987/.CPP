// (0000000001) Fibonacci Series in classes C++. <CpE221/Mathematics>
// (class function)

#include <cstdlib>
#include <iostream>

using namespace std;

class example {
    public:  
      
      void intro();
      void input();
      void fibo();
      void output();
           
      int inp,i,num[100],k;
      int x,y,sum;
      };

int main(int argc, char *argv[])
{
    
    example y;
    
    y.intro();
    y.input();
    y.fibo();
    y.output();
    system("PAUSE");
    return EXIT_SUCCESS;
}


void example::intro()
{
     cout<<"Fibonacci Series in classes C++."<<endl
     ;
     }

void example::input()
{
        cin>>inp;
         
                   
                        }

void example::fibo()
{
     k=0;
     x=0;
     y=1;
     for (i=2;i<inp;i++)
         {
         sum=x+y;
         num[k]=sum;
         k++;
         x=y;
         y=sum;
         }    
     }
     
void example::output()
{

cout<<0<<" "<<1;

for (i=0;i<k;i++)
    
    {
           cout<<" "<<num[i];
           
           
           }

cout<<""<<endl;
}
