// (0000010110) Happy Number <CpE221/Mathematics>
// (class function)


#include <cstdlib>
#include <iostream>

using namespace std;

class happy_number
{
 public:
        void happy();
        
        
        long inp,i,t,base[100],rem[100],sum[100],tsum[100];
        long temp,j,ttsum[100],k,m;
        long y,z;
        bool flag;
};

int main(int argc, char *argv[])
{
    happy_number m;
    
    m.happy();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void happy_number::happy()
{
flag=true;
cin>>inp;

temp=inp;
k=0;

for (;;)
{

for (i=0;inp!=0;i++)
    {
    rem[i]=inp%10;
    inp=inp/10;
    }    
j=0;
base[j]=0;
for (j=0;j<i;j++)
    {
    sum[j]=rem[j]*rem[j];
    tsum[j]=sum[j]+base[j];
    base[j+1]=tsum[j];
    }

cout<<tsum[j-1]<<endl;

ttsum[k]=tsum[j-1];
k++;
inp=tsum[j-1];

if (tsum[j-1]==1)
   {
   cout<<"It's a Happy Number!"<<endl;
   break;
   }

else
    {
    for (y=0;y<k;y++)
        {
        if (ttsum[y]==16)
           {
           flag=false;
           }
        }
    
    if (!flag)
       {
       break;
       }
    }



}
}
