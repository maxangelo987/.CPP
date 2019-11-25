// (0000001011) Sorting Numbers <CpE221/Mathematics>


#include <cstdlib>
#include <iostream>

using namespace std;
typedef long *index;
int main(int argc, char *argv[])
{
    index num;    
    long h,s,i,j,hold;
    
    num=new long[s];
    
    h=1;
    s=0;
    for (i=0;h!=0;i++)
        {
        cin>>num[i];
        
        if (num[i]==0)
           {
           h=0;
           }
           
        else
           {
           num[s]=num[i];
           s++;
           }
        }
        
    for (i=0;i<s;i++)
        {
        for (j=0;j<(s-1);j++)
            {
            if (num[j]>num[j+1])
               {
               hold=num[j];
               num[j]=num[j+1];
               num[j+1]=hold;
               }
            
            }
        }
   
    for (i=0;i<s;i++)
        {
        cout<<" "<<num[i];
        }
    
    delete[]num;
         
    system("PAUSE");
    return EXIT_SUCCESS;
}
