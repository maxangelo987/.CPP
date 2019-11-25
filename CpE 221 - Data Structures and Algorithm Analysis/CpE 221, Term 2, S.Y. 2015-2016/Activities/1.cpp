#include <cstdlib>
#include <iostream>

using namespace std;

class activity1
{
public:
     void process(); 
     void output();
     void push();
     void pop();
     char in1[50], in2[50], *ptr, *myword[20], *myword2[20],str[100];
     long a,b,c,d,cond,count,i,l[100],count1[100],count2,j,k,max;
     char *primewords[100]; 

      };

int main(int argc, char *argv[])
{
    activity1 z;
     char access;

    z.process();
    
     cout<<"[A] - Push. "<<endl;
     cout<<"[B] - Pop. "<<endl;
     cout<<"[C] - Exit. "<<endl;
     
     for (;;)
         {
          cout<<endl;
          cout<<"Input Process: ";
          cin>>access;
         if (access=='A'||access=='a')
            {
            cout<<"PUSH:"<<endl;
            z.output();
            }
         
         if (access=='B'||access=='b')
            {
            cout<<"POP:"<<endl;
            z.pop();
            z.output();
            }
         
         if (access=='C'||access=='c')
            {
            break;
            }
         
         }  

    
    system("PAUSE");
    return EXIT_SUCCESS;
}



void activity1::process()
{

cout<<"Input 1: ";
gets(in1);
k=0;
a=0;
count=0;
ptr=strtok(in1, " ");
while(ptr!=NULL)
	{
	myword[a]=ptr;
	a++;
	count++;
    ptr=strtok(NULL, " ");
	}

max=count;
for (i=0;i<count;i++)
    {
    strcpy(str,myword[i]);
    l[i]=strlen(str);
    }
                     
count2=0;                     
for (i=0;i<count;i++)
    {
    count1[i]=0;
     for (j=2;j<l[i];j++)
         {
         if (l[i]%2==0)
            {
            count1[i]++;   
            }
         } 
     
     if (count1[i]==0)
        {
        strcpy(str,myword[i]);
        primewords[k]=myword[i];
        k++;
        count2++;
        }
                     
     }


for (i=0;i<count2;i++)
    {
    cout<<primewords[i]<<" ";
    }     
     
     cout<<endl;
    
     
     }


void activity1::output()
{
for (i=0;i<count2;i++)
    {
                      
    cout<<"["<<primewords[i]<<"]";
    }     
     
     
     }


void activity1::pop()
{

count2--;

if (count2==0)
   {
              cout<<"EMPTY"<<endl;
              }     
     
     }


