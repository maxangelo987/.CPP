// (0000001001) Enter Input then,
// [A] - Integer Ascending Sort
// [B] - Decimal Descending Sort <CpE221/Mathematics>
// (class function)


#include <cstdlib>
#include <iostream>

using namespace std;

class sorting
      {
      public:
             void input();
             void integ();
             void decim();
             long m,a,sw,i;
             double inp[100],inp1[100]; 
             
             long inp2[100],rem[100][100],cw[100],i1,c,d,swap[100],base[100];
             long whole_int1[100],whole_int2[100],whole_int3[100],whole_int[100];
             long sw1[100],inp8[100],rem1[100];
             double inp3[100],inp9[100];
             
             long inp20[100],sw10[100],inp80[100],rem10[100],cw0[100],rem9[100][100];
             long swap9[100],base9[100],whole_int9[100],q,t;
             long whole_int10[100],whole_int20[100],whole_int30[100],b;
             double inp30[100],inp90[100],inp33[100],inp333[100];
             
             double inp3330[100],inp330[100];
      };

int main(int argc, char *argv[])
{
    
char access;
     
     sorting m;
     m.input();
     cin>>access;
     cout<<endl;
     if ((access=='A')||(access=='a'))
        {
        m.integ();
        }
        
     else if ((access=='B')||(access=='b'))
        {
        m.decim();
        }
    system("PAUSE");
    return EXIT_SUCCESS;
}

void sorting::input()
{

cout<<"Input(s)"<<endl;     
sw=1;
a=0;
b=0;
for (i=0;sw>0;i++)     
    {
    cin>>inp[i];
    
    if (inp[i]==0)
       {
       sw=0;
       }
    else
       {
       inp1[a]=inp[i];
       a++;
       b++;
       }
    }
cout<<endl;
cout<<"[A] - Integer Ascending Sort"<<endl;
cout<<"[B] - Decimal Descending Sort"<<endl;
cout<<endl;
cout<<"ENTER: ";

}

void sorting::integ()
{
cout<<"Integer Ascending Sorting"<<endl;

q=0;
t=0;
for (i=0;i<a;i++)
    {
    inp2[i]=(long)inp1[i]; // We will use inp2 for SORTING
    inp3[i]=inp1[i]-inp2[i]; // inp3 for its decimal
    
    
    if (inp3[i]==0)
       {
       inp33[q]==inp3[i];
       q++;
       }
    
    else
       {
       inp333[t]=inp3[i];
       t++;
       }
    
    }


for (i=0;i<t;i++) // (This Loop) Is for making inp3 a whole and become inp8
    {
    inp9[i]=(inp333[i]*10000000)+1;
    inp8[i]=(long)inp9[i];
    
    sw1[i]=1;
    for (;sw1[i]!=0;)
        {
        inp8[i]=inp8[i]/10;
        rem1[i]=inp8[i]%10;
          
          if (rem1[i]>0)
             {
             sw1[i]=0;
             }
        }
    }


for (i=0;i<a;i++)  // (This Loop) For Breaking inp2
 {
    cw[i]=0;
       for (i1=0;inp2[i]!=0;i1++) 
         {
         rem[i][i1]=inp2[i]%10;
         inp2[i]=inp2[i]/10;
         cw[i]++;
         }
    }

for (i=0;i<a;i++)   // (This loop) Ascending Sorting
    {
     for (c=0;c<(cw[i]-1);c++) 
         {
         for (d=0;d<cw[i]-c-1;d++)
             {
              if (rem[i][d]>rem[i][d+1])
                  {
                  swap[i]=rem[i][d];
                  rem[i][d]=rem[i][d+1];
                  rem[i][d+1]=swap[i];
              }
             }
         }
    }

for (i=0;i<a;i++)    // (This Loop) To Determine the Base       
    {
    base[i]=1;
      for (i1=0;i1<cw[i]-1;i1++) 
         {
         base[i]=base[i]*10;                  
         }
    }

for (i=0;i<a;i++) // (This Loop) Combining sa mga nabungkag nga numbers
    {
       whole_int1[i]=0;
       for (i1=0;i1<cw[i];i1++) 
         {
         whole_int[i]=rem[i][i1]*base[i];   
         whole_int3[i]=whole_int[i]+whole_int1[i];
       
         whole_int1[i]=whole_int3[i];
         base[i]=base[i]/10;
         }
    
    }

 t=0;
for (i=0;i<a;i++) // (This Loop) For Printing
    {
    
   
    if (inp3[i]>0)
       {
       cout<<whole_int3[i]<<"."<<inp8[t];
       cout<<" ";
       t++;
       }
    else
       {
       cout<<whole_int3[i];
       cout<<" ";
       }   
   
    }

     


cout<<endl;
}


void sorting::decim()
{
cout<<"Decimal Descending Sorting"<<endl;


q=0;
t=0;
for (i=0;i<b;i++)
    {
    inp20[i]=(long)inp1[i]; // We will use inp2 for SORTING
    inp30[i]=inp1[i]-inp20[i]; // inp3 for its decimal
    
    
    if (inp30[i]==0)
       {
       inp330[q]==inp30[i];
       q++;
       }
    
    else
       {
       inp3330[t]=inp30[i];
       t++;
       }
    
    }
    
    
for (i=0;i<t;i++) // (This Loop) Is for making inp30 a whole and become inp80
    {
    inp90[i]=(inp3330[i]*10000000)+1;
    inp80[i]=(long)inp90[i];
    
    sw10[i]=1;
    for (;sw10[i]!=0;)
        {
        inp80[i]=inp80[i]/10;
        rem10[i]=inp80[i]%10;
          
          if (rem10[i]>0)
             {
             sw10[i]=0;
             }
        }
    }

for (i=0;i<t;i++)  // (This Loop) For Breaking inp80
 {
    cw0[i]=0;
       for (i1=0;inp80[i]!=0;i1++) 
         {
         rem9[i][i1]=inp80[i]%10;  
         inp80[i]=inp80[i]/10;
         cw0[i]++;
         }
    }

for (i=0;i<t;i++)   // (This loop) Descending Sorting
    {
     for (c=0;c<(cw0[i]-1);c++) 
         {
         for (d=0;d<cw0[i]-c-1;d++)
             {
              if (rem9[i][d]<rem9[i][d+1])
                  {
                  swap9[i]=rem9[i][d];
                  rem9[i][d]=rem9[i][d+1];
                  rem9[i][d+1]=swap9[i];
                  }
             }
         }
    
    }



for (i=0;i<t;i++)    // (This Loop) To Determine the Base       
    {
    base9[i]=1;
      for (i1=0;i1<cw0[i]-1;i1++) 
         {
         base9[i]=base9[i]*10;                  
         }
         
     }
     
for (i=0;i<t;i++) // (This Loop) Combining sa mga nabungkag nga numbers
    {
       whole_int10[i]=0;
       for (i1=0;i1<cw0[i];i1++) 
         {
         whole_int9[i]=rem9[i][i1]*base9[i];   
         whole_int30[i]=whole_int9[i]+whole_int10[i];
       
         whole_int10[i]=whole_int30[i];
         base9[i]=base9[i]/10;
         }
    
    }     
    

t=0;
for (i=0;i<a;i++) // (This Loop) For Printing
    {
    
   
    if (inp30[i]>0)
       {
       cout<<inp20[i]<<"."<<whole_int30[t];
       cout<<" ";
       t++;
       }
    else
       {
       cout<<inp20[i];
       cout<<" ";
       }   
   
    }

     

cout<<endl;
}
