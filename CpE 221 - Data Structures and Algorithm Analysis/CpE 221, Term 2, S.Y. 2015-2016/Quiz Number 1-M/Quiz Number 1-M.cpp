#include<cstdlib>
#include<iostream>

using namespace std;


class lookandsay
{
      public:
             void input();
             void algo();
             
                char *a, *b, *x, c,d;
                int cnt, len,i,lim,s;
                long long m;
                long long t;
                
//char *foo = (char*)malloc(1);
      
      };

int main (int argc, char *argv[])
{

lookandsay z;

z.input();
z.algo();

system("PAUSE");
return 0;

}


void lookandsay::input()
{
len=1;
i=1;
b=0;
a=(char*)malloc(2);


s=1;
cout<<"Input Range: ";
cin>>lim;
          
}


     
     
void lookandsay::algo()
{
     
    for (sprintf(a, "%d",s); (b = (char*)realloc(b, len * 2 + 1)); a = b, b = x)
    {
     
       x=a;
     
     
       t=atoi(x);
       cout<<t<<": Prime Factors - "; 
       //puts(x);
         
       m=2;
       
       if (t==1)
          {
          cout<<" 1 ";
          }        
       else
       {
       cout<<" 1 ";
       for (;t!=0;) // Prime Factorization
        {
        if (t%m==0)
           {
           t=t/m;
           cout<<m<<" ";

           if (t==1)
              {
              break;
              }
           }       
        else
           {
           m++;
           }

           }
 
      }    
      
       cout<<endl;    




               
	for (len = 0, cnt = 1; (c = *a); )
        {
            if (c == *++a)
                {
                cnt++;
                }
            else if (c)
                 {

                len += sprintf(b + len, "%d%c", cnt, c);
                cnt = 1;
                }
        }


if(i==lim+1)
	{
	break;
	}
  i++;
    
    }
}
