// (0000011101) Look and say! <CpE221/Mathematics>
// (class function)

#include<cstdlib>
#include<iostream>

using namespace std;


class lookandsay
{
      public:
             void input();
             void algo();
             
                char *a, *b, *x, c;
                int cnt, len,i,lim,s;

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


cout<<"Input Number: ";
cin>>s;
cout<<"Input Range: ";
cin>>lim;
     
     
     }
     
     
void lookandsay::algo()
{
     
    for (sprintf(a, "%d",s); (b = (char*)realloc(b, len * 2 + 1)); a = b, b = x)
    {
     
        puts(x = a);

	for (len = 0, cnt = 1; (c = *a); )
        {
            if (c == *++a)
                cnt++;
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


