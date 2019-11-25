#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;


class myfinal
      {
      public:
             void input();
             void process();
             void output();
             long a,b,c,d,cond1;
             long pv,end[100],count,num[100][100],cond3,mycond;
             double number[1000],cond2;
             char numb[100][100];
      };

int main(int argc, char *argv[])
{
    myfinal n;
    n.input();
    cout<<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

void myfinal::input()
     {
     a=0;
     cout<<"Enter number here: ";
     for (;number[a-1]!=0;)
         {
         cin>>number[a];
         a++;
         }


     cout<<"Enter place value here: ";
     cin>>pv;    
     }
     
     
     
