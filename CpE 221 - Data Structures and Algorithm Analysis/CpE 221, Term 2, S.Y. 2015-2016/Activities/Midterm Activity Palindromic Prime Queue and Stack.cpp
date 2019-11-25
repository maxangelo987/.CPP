#include <cstdlib>
#include <iostream>
#include<string>

using namespace std;

long p=0,a;
long g=0,inputs;

class activity2
{
      public:
             void input();
             void movtoword();
             void decision();
             void enactivity2();
             void dequeue();
             void preinp();
             void pop();
             
             long long q,q1,q2;
             long long i,i1,i2,i3,i4,i5,i6,i7,i8,i9;
             long long i10, i11, i12, i13, i14;
             long long j,d,z;
             long long w;
             long long not_ban[1000];
             long b,c;
                          
             long range, pdrange,pdnum;
             long a,y;
             long real;
             long base;
             long bin;
             long rem;
             long rev;
             long key;
             long count,temp;
             long num;
             long back;    



};



int main(int argc, char *argv[])
{
activity2 m;
char access;
 
     cout<<"Prime Oban Numbers in Queue/Stack: "<<endl;

     m.preinp();   
     for (a=0;a<inputs;a++)
         {
            m.input();    
           } 
            m.enactivity2();     
          
         cout<<"[A] - Queue "<<endl;
         cout<<"[B] = Stack "<<endl;
         cin>>access;
         
         
         if (access=='A'||access=='a')
            {
            for (;;)
                {
                cout<<"You've choose letter A, you can only dequeue here. "<<endl;           
                cout<<"Press A to dequeue or X to exit."<<endl;
                cin>>access;
                if (access=='A'||access=='a')
                  {
                  m.dequeue();
                  }
                
                else if (access=='X'||access=='x')
                  {
                  break;
                  }
                }
            }
         
         else if (access=='B'||access=='b')
            {
            for (;;)
                {
                cout<<"You've choose letter B, you can only pop here. "<<endl;           
                cout<<"Press A to pop or X to exit."<<endl;
                cin>>access;
                if (access=='A'||access=='a')
                  {
                  m.pop();
                  } 
                
                else if (access=='X'||access=='x')
                  {
                  break;
                  }
                }
            }
         
                        
    system("PAUSE");
    return EXIT_SUCCESS;
}

void activity2::preinp()
{
cout<<"Enter inputs: ";
cin>>inputs;

}

void activity2::input() // This class is for getting input
{
key=0;
rev=0;
cin>>num;
back=num;
a=0;
    count=0;
    for (j=2;j<num;j++)
        {
        if (num%j==0)
           {
           count++;
           }
           
        }


pdrange=0;    
    if (count==0)
       {
       pdnum=num;
       }                 
 
   else
       {
       return;
       }
       
    bin=0;
    base=1;
    
    for (;pdnum>0;)
        {
        rem=pdnum%2;
        bin=bin+rem*base;
        base=base*10;
        pdnum=pdnum/2;
        } 
     

    key=bin;
    temp=0;
    
    for (;bin!=0;)
        {
        temp=bin%10;
        bin=bin/10;
        rev=temp+(rev*10);
        }
d=0;
    if (key==rev)
       {
       not_ban[p]=back;
       p++;
       } 

   
}



void activity2::enactivity2()
{

if (p==0)
   {
   cout<<"[The Queue is empty!]"<<endl;
   }

else
    {
    for(d=0;d<p;d++)
             {           
             cout<<"["<<not_ban[d]<<"]"<<" ";
             }
    cout<<endl;
    }        

g++;
cout<<endl;
}

void activity2::dequeue()
{
 if (p==0)
       {
       cout<<endl;
       cout<<"You can't delete."<<endl;
       cout<<"[The Queue is empty!]"<<endl;
       }

  else
  {     
        
cout<<endl;
cout<<"You deleted "<<not_ban[0]<<"."<<endl;

for (d=0;d<p-1;d++)
         {
         not_ban[d]=not_ban[d+1];
         }
     cout<<endl;
    
     for (d=0;d<p-1;d++)
         {
         cout<<"["<<not_ban[d]<<"]"<<" ";
         }
    
    cout<<endl;
     p--;    
    
    if (p==0)
       {
       cout<<"[The Queue is empty!]"<<endl;
       }
    }

cout<<endl;
}



void activity2::pop()
{
 if (p==0)
       {
       cout<<endl;
       cout<<"You can't delete."<<endl;
       cout<<"[The Stack is empty!]"<<endl;
       }

  else
  {     
        
cout<<endl;
cout<<"You deleted "<<not_ban[p-1]<<"."<<endl;

    
     for (d=0;d<p-1;d++)
         {
         cout<<"["<<not_ban[d]<<"]"<<" ";
         }
    
    cout<<endl;
    
    
    p--;    
    if (p==0)
       {
       cout<<"[The Queue is empty!]"<<endl;
       }
    }

cout<<endl;
}

