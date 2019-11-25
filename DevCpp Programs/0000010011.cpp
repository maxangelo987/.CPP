// (0000010011) Wasteful number in Queue <CpE221/Mathematics>
// (class function)

#include <cstdlib>
#include <iostream>

 long digits,factors;
 long q=0;
 char access;
 
 using namespace std;

class queue 
{
 public:
        void input();
        void enqueue();
        void choices(); 
        void dequeue();       
        void head();
        void tail();
        
        long x,y,i,t;
        long rem[1000];
        long inp;
        long que[1000];   

};

int main(int argc, char *argv[])
{

char yn;
queue m;
      system("color f1");
      cout<<"Wasteful Number."<<endl;
      cout<<"- A number is said to be wasteful if the number of digits in it's"<<endl;
      cout<<" prime factorization is greater than the number of digits of n."<<endl;
      for (;;)
      {
      m.input();   
      
      
      if (factors>digits)
         {
         cout<<"The number you input is a Wasteful Number!"<<endl;
         cout<<"What do you want to do with this number?"<<endl;
         cout<<endl;
         m.choices();
        
        if (access=='A'||access=='a')
           {
           m.enqueue();
           
           if (q>0)
              {
              cout<<endl;
              cout<<"The Queue is not empty! Would you like to go to the choices?"<<endl;
              cout<<"Y - Yes./ Any letters - Input another. : [ ]\b\b";
              cin>>yn;
               
               if (yn=='Y'||yn=='y')
                  {
                  m.choices();
                  
                  if (access=='A'||access=='a')
                     {
                     cout<<"You can't use Enqueue here."<<endl;
                     }
                  
                  else if (access=='B'||access=='b')
                     {
                     m.dequeue();
                     }
         
                  else if (access=='C'||access=='c')
                     {
                     m.head();
                     }
                  else if (access=='D'||access=='d')
                     {
                     m.tail();
                     }
                  else if (access=='E'||access=='e')
                     {
                     cout<<"Thankyou for using my program."<<endl;
                     cout<<"PERIN, MAX ANGELO BSCPE 2A."<<endl;
                     break;
                     }       
                  }
                
              
              }
           }
        
        else if (access=='B'||access=='b')
           {
           m.dequeue();
           }
         
        else if (access=='C'||access=='c')
           {
           m.head();
           }
        else if (access=='D'||access=='d')
           {
           m.tail();
           }
        else if (access=='E'||access=='e')
           {
           cout<<"Thankyou for using my program."<<endl;
           cout<<"PERIN, MAX ANGELO BSCPE 2A."<<endl;
           break;
           }            
        else
             {
             cout<<"The Letter you input is not availabe."<<endl;
             }
         
         }
      else
          {
          cout<<"Sorry. The input is not a wasteful number!"<<endl;
          cout<<"The digits of n is greater than the digits of prime factors."<<endl;
          
          }
      }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void queue::choices()
{
cout<<"[A] - Enqueue "<<endl;
         cout<<"[B] - Dequeue "<<endl;
         cout<<"[C] - Head "<<endl;
         cout<<"[D] - Tail "<<endl;
         cout<<"[E] - Exit "<<endl<<endl;
         cout<<"Access: [ ]\b\b";
         cin>>access; 
}

void queue::input()
{
cout<<endl;
cout<<"Input Number: ";
cin>>inp;
x=0;
y=0;
    
    
    digits=0;
    x=inp;
    y=inp;
    
    
    for (;y!=0;) // Digits Counting
        {
        y=y/10;
        digits++;
        }
    
    i=2;
    t=0;
    factors=0;
    for (;x!=0;) // Prime Factorization
        {
        if (x%i==0)
           {
           x=x/i;
           rem[t]=i;
           t++;
           factors++;
           if (x==1)
              {
              break;
              }
           }       
        else
           {
           i++;
           }
        
        }
    
cout<<"The number "<<inp<<" you inputed has "<<digits<<" digit(s)"<<endl;
cout<<"And it has "<<factors<<" prime factors which are: ";
for (i=0;i<factors;i++)
    {
    cout<<rem[i]<<" ";
    }

cout<<endl;

}

void queue::enqueue()
{
que[q]=inp;
q++;

if (q==0)
   {
   cout<<"The Queue is Empty!"<<endl;
   }
   
else
    {         
    for (i=0;i<q;i++)
        {
        cout<<"["<<que[i]<<"]"<<" ";
        }
    }    

}

void queue::dequeue()
{

cout<<"You deleted "<<que[0]<<"."<<endl;
q--;

if (q==0)
   {
   cout<<"The Queue is Empty!"<<endl;
   }
   
else
    {         
    for (i=0;i<q;i++)
        {
        que[i]=que[i+1];
        }
    
    for (i=0;i<q;i++)
        {
        cout<<"["<<que[i]<<"]"<<" ";
        }
    }    
}

void queue::head()
{
if (q==0)
   {
   cout<<"The Queue is Empty!"<<endl;
   }
   
else
    {         
    cout<<"The head of the queue is: "<<que[q-1]<<endl;
    }
}

void queue::tail()
{
if (q==0)
   {
   cout<<"The Queue is Empty!"<<endl;
   }
   
else
    {         
    cout<<"The tail of the queue is: "<<que[0]<<endl;
    }
}
