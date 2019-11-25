// (0000010100) Add all digit and one digit from decimal places <CpE221/Mathematics>
// Ex: 1.2 = 3

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    long inp;
    double num,b;
    long a,rem,rev,b1,rem1;
    long rev1, rem2;
    long deci, whole;
    long i;
    long f;
    long sum, remx[100],remy[100];
    long base;
    long d,e; 
    long sum1,sumv,rem9;   
    long j;
    long temp;
    long m;
    
    deci=0;
    whole=0;
    
    scanf("%lf",&num);
    a=(long)num;
   
    b=num-a;
    f=b*1000000000+1;
     b1=(long)f;
    
    for (;;) //  Making the deci whole
        {
        b1=b1/10;
        rem1=b1%10;
        if (rem1>0){break;}
        }
        
    temp=b1;
    rev=0;

    for (;temp!=0;) // Counting how many digits
        {
        temp=temp/10;
        deci++;
        }
    
    for (;a!=0;) // Reversing the Whole
        {
        rev=rev*10;        
        rem=a%10;
        rev=rev+rem;
        a=a/10;
        whole++;
        }

    rev1=0;
    for (;b1!=0;) // Reversing the Decimal
        {
        rev1=rev1*10;        
        rem2=b1%10;
        rev1=rev1+rem2;
        b1=b1/10;
        }
        
        
    for (i=0;i<whole;i++)
        {
        remx[i]=rev%10;
        rev=rev/10;
        }
        
     
    for (i=0;i<deci;i++)
        {
        remy[i]=rev1%10;
        rev1=rev1/10;
        }
    d=0;
    base=1;
    sum1=0;
    

    for (i=0;i<whole;i++)
        {
        sum=(remx[d]+remy[d])*base;
        sum1=sum1+sum;
        base=base*10;
        d++;
        }    

    sumv=0;   
    for (;sum1!=0;) // Reversing the Summation
        {
        sumv=sumv*10;        
        rem9=sum1%10;
        sumv=sumv+rem9;
        sum1=sum1/10;
        }
    cout<<sumv;
     
     if (deci>whole)   
        {
        e=deci-whole;
        printf(".");
        
        for (j=0;j<e;j++)
            {
            printf("%ld",remy[d]);
            d++;
            }
        }
        
              
    system("PAUSE");
    return EXIT_SUCCESS;
}
