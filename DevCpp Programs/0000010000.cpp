// (0000010000) Stack (Push/Pop) <CpE221/Mathematics>
// (class function)


#include <cstdlib>
#include <iostream>

using namespace std;

long k=0, inp[100];
long i;

class stack
{
      public:
             void push();
             void pop();             
             
};

int main(int argc, char *argv[])
{
    
    stack m;
    char type;
    
         cout<<"[A] Type A for push"<<endl;
         cout<<"[B] Type B for pop"<<endl;

for (;;)
     {  
         cout<<endl;
         cout<<"Process: ";
         cin>>type;
         if (type=='A'||type=='a')
            {
            m.push();
            }
            
         else if (type=='B'||type=='b')
            {
            m.pop();
            }
         
         else
            {
            cout<<"Goodbye!"<<endl;
            break;
            }           
     
     }             
    system("color f2");
    system("PAUSE");
    return EXIT_SUCCESS;
}

void stack::push()
{
     cout<<"Input: ";
     cin>>inp[k];     
     k++;
     
     cout<<endl;
     for (i=0;i<k;i++)
         {
         cout<<inp[i]<<" ";
         }

}

void stack::pop()
{
          
     k--;
     
     for (i=0;i<k;i++)
         {
         cout<<inp[i]<<" ";
         }
         
}
