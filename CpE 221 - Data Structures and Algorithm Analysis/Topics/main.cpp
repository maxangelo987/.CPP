#include <cstdlib>
#include <iostream>
using namespace std; 

class robin
{
      public:
             void input();
             void output();             
             char in1[50], *ptr, *myword[20],*myprime[20];
             long a,b,c,d,cond,i,x;
             long count,j,countprime,k;
      };

int main(int argc, char *argv[])
{
    
    robin m;
    m.input();
    
    
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void robin::input()
{
     
cout<<"Input: ";     
gets(in1);

a=0;
ptr=strtok(in1, " ");
while(ptr!=NULL)
	{
	myword[a]=ptr;
	a++;
	ptr=strtok(NULL, " ");
	}

countprime=0;
k=0;

for (i=0;i<a;i++)
{
x=0;
cout<<myword[i];
cout<<endl;
x=strlen(myword[i]);
cout<<x;
cout<<endl;

count=0;
for (j=2;j<x;j++)
    {
    if (x%j==0)
       {
       count++;
       }
    }
    
if (count==0)
   {
   myprime[k]=myword[i];
   k++;
   countprime++;
   }   
}


cout<<"Here are the Prime length words: ";
countprime-1;
for (i=0;i<countprime-1;i++)
    {
    cout<<myprime[i]<<" ";
    }



}
