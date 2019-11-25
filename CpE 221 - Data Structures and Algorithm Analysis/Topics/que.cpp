#include <cstdlib>
#include <iostream>

using namespace std;

long k=0,g=1;
char inp[100];
long i;

class queue
{
      public:
             void enqueue();
             void dequeue();             
             
};

int main(int argc, char *argv[])
{
    
    queue m;
    char type;
    
         cout<<"[A] Type A for enqueue"<<endl;
         cout<<"[B] Type B for dequeue"<<endl;

for (;;)
     {  
         cout<<endl;
         cout<<"Process: ";
         cin>>type;
         if (type=='A'||type=='a')
            {
            m.enqueue();
            }
            
         else if (type=='B'||type=='b')
            {
            m.dequeue();
            
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

void queue::enqueue()
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

void queue::dequeue()
{
     
     inp[0]=0;
     
     for (i=0;i<k-1;i++)
         {
         inp[i]=inp[i+1];
         }
     
     cout<<endl;
     for (i=0;i<k-1;i++)
         {
         cout<<inp[i]<<" ";
         }
     k--;    
     
}
