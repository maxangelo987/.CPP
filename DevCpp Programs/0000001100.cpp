// (0000001100) Reversing Unilimited Inputs <CpE221/Mathematics>
// (dynamic array)

#include <cstdlib>
#include <iostream>

using namespace std;

typedef long *index;
typedef long *index3;
typedef long **index1;

int main(int argc, char *argv[])
{
    
   
    index num;
    index3 d;
    index1 rem;
    
    long t,i,s,h,y,u,q,z;
    
    num= new long[s];    
    rem= new long*[s];
    d=new long[s];
    
   
        
        
    h=1;
    s=0;
    q=0;
   
    for (i=0;h!=0;i++)
        {
        system("color f1 ");
        cin>>num[i];
        
        if (num[i]==0)
           {
           h=0;
           }
           
        else
           {
           num[s]=num[i];
           s++;
           q++;
           }
        }
     
   y=0;
    for (i=0;i<s;i++)
        {
         d[i]=0;
         rem[i]=new long[y];
        
        for (u=0;num[i]!=0;u++)
            {
            rem[i][u]=num[i]%10;
            y++; // Highest possible Remainder
            d[i]++;
            num[i]=num[i]/10;
            }
        }        
    
    
    for (i=0;i<s;i++)
        {
        for (u=0;u<d[i];u++)
            {
            cout<<rem[i][u]<<" ";
            }
        cout<<endl;
        }

    
    
        
        

    delete[]num;   
    delete[]d;
     
    system("PAUSE");
    return EXIT_SUCCESS;
}
