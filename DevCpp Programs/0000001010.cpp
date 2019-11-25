// (0000001010) Number (Whole or Decimal Places) to 
// Roman Numerals <CpE221/Mathematics>
// (class function)


#include <cstdlib>
#include <iostream>

using namespace std;


class converter
     {
     public:
            void input();
            void prcsone();
            void prcsthree();
            void prcstwo();
            void integer();
            void decimal();
            converter();
            ~converter();
            
            long m1,k,count,i,j,g,t;
            double num[100],inp[100],ans[100];
            long inp1[100],intnum[100];
            double decif[100];
            long i1[100],v[100],x[100],l[100],d[100],c[100],m[100],n[100];
            long num1[100],ans9[100],j1[100],temp[100],rem[100],intnum1[100];
            double ans1[100],deci2[100],ans8[100];
            long i2[100],v2[100],x2[100],l2[100],d2[100],c2[100],m2[100],n2[100];
            long i3[100],v3[100],x3[100],l3[100],d3[100],c3[100],m3[100],n3[100];
            long tg[100],r,j9[100];
            
                };
                
converter::converter(void)
{cout<<"This Program can change a Decimal or Whole Number to Roman Numerals"<<endl;}

converter::~converter(void)
{}

int main(int argc, char *argv[])
{
    long z;
    converter m1;
    m1.input(); 
    m1.prcsone();
      m1.prcsthree();
      m1.prcstwo();
  
        cin>>z;
           if (z==2)
              {
          
              m1.decimal();
              }
           else if (z==1)
              {
              m1.integer();
              }
           
           else if (z>2) {cout<<"No designated number!"<<endl;}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


void converter::input()
{
     
     cout<<"Input(s): ";
     k=0;
     count=1;
     for (i=0;count>0;i++)
         {
         cin>>num[i];          
          
         if (num[i]==0)
              {
              count=0;
              }
         else
              {
              inp[i]=num[i];
              k++;
              }
         
         }          
        
         

}

void converter::prcsone()
{

  j=0;
  g=0;
  t=0;
   for (i=0;i<k;i++)
      {
      
      inp1[i]=(long)inp[i];
      ans[i]=inp[i]-inp1[i];
      
      if (ans[i]==0)
         {
          intnum[t]=inp1[i];       
          t++; // Whole Numbers         
         }
      
      else {
           decif[g]=inp[i];
           g++; // Decimal Numbers
           }
      }
       
          
}

void converter::prcsthree()
{

for (i=0;i<g;i++)
    {
    intnum1[i]=(long)decif[i]; // intnum1 serves for the whole
    deci2[i]=decif[i]-intnum1[i];
    }


for (i=0;i<g;i++)
    {
 temp[i]=1;
 ans1[i]=deci2[i]*100000+1;
ans9[i]=(long)ans1[i];
j9[i]=0;

for (;temp[i]!=0;)
    {
    ans9[i]=ans9[i]/10;
    rem[i]=ans9[i]%10;
    j9[i]++;
    
    if (rem[i]>0)
       {temp[i]=0;}
    }
    }

}


void converter::prcstwo()
{

cout<<"Choose type to be converted: "<<endl;
cout<<"[1] Integer"<<endl;
cout<<"[2] Decimal"<<endl;
cout<<"Please ENTER: "<<endl;

}





void converter::integer()
{

for (i=0;i<t;i++)
    {
   
    if (intnum[i]>=1000)
   {
   m[i]=intnum[i]/1000;
  
       {
       for (n[i]=0;n[i]<m[i];n[i]++)
           {
           cout<<"M";
           }
       }
   intnum[i]=intnum[i]%1000;
   }


if (intnum[i]>=900)
   {
   cout<<"CM";
   intnum[i]=intnum[i]%900;
   }

else if (intnum[i]>=500)
     {
     d[i]=intnum[i]/500;
    
     
         for (n[i]=0;n[i]<d[i];n[i]++)
             {
             cout<<"D";             
             }
     intnum[i]=intnum[i]%500;
     } 
     
if (intnum[i]>=400)
   {
   cout<<"CD";
   intnum[i]=intnum[i]%400;
   }

else if (intnum[i]>=100)
     {
     c[i]=intnum[i]/100;
      
      for (n[i]=0;n[i]<c[i];n[i]++)
             {
             cout<<"C";             
             }
      intnum[i]=intnum[i]%100;
     }

if (intnum[i]>=90)
   {
   cout<<"XC";
   intnum[i]=intnum[i]%90;
   }

else if (intnum[i]>=50)
     {
     l[i]=intnum[i]/50;
      
      for (n[i]=0;n[i]<l[i];n[i]++)
             {
             cout<<"L";             
             }
      intnum[i]=intnum[i]%50;
     }

if (intnum[i]>=40)
   {
   cout<<"XL";
   intnum[i]=intnum[i]%40;
   }

else if (intnum[i]>=10)
     {
     x[i]=intnum[i]/10;
      
      for (n[i]=0;n[i]<x[i];n[i]++)
             {
             cout<<"X";             
             }
      intnum[i]=intnum[i]%10;
     }

if (intnum[i]>=9)
   {
   cout<<"IX";
   intnum[i]=intnum[i]%9;
   }

else if (intnum[i]>=5)
     {
      v[i]=intnum[i]/5;
      
      for (n[i]=0;n[i]<v[i];n[i]++)
             {
             cout<<"V";             
             }
      intnum[i]=intnum[i]%5;
     }
if (intnum[i]>=4)
   {
   cout<<"IV";
   intnum[i]=intnum[i]%4;
   }

else if (intnum[i]>=1)
     {
     i1[i]=intnum[i];
      
      for (n[i]=0;n[i]<i1[i];n[i]++)
             {
             cout<<"I";             
             }
      intnum[i]=intnum[i]%1;
     }
cout<<" ";
    }


}





void converter::decimal()
{

for (i=0;i<g;i++)
    {
    
    for (r=0;r<g;r++)
    {
   
    if (intnum1[i]>=1000)
   {
   m2[i]=intnum1[i]/1000;
  
       {
       for (n2[i]=0;n2[i]<m2[i];n2[i]++)
           {
           cout<<"M";
           }
       }
   intnum1[i]=intnum1[i]%1000;
   }


if (intnum1[i]>=900)
   {
   cout<<"CM";
   intnum1[i]=intnum1[i]%900;
   }

else if (intnum1[i]>=500)
     {
     d2[i]=intnum1[i]/500;
    
     
         for (n2[i]=0;n2[i]<d2[i];n2[i]++)
             {
             cout<<"D";             
             }
     intnum1[i]=intnum1[i]%500;
     } 
     
if (intnum1[i]>=400)
   {
   cout<<"CD";
   intnum1[i]=intnum1[i]%400;
   }

else if (intnum1[i]>=100)
     {
     c2[i]=intnum1[i]/100;
      
      for (n2[i]=0;n2[i]<c2[i];n2[i]++)
             {
             cout<<"C";             
             }
      intnum1[i]=intnum1[i]%100;
     }

if (intnum1[i]>=90)
   {
   cout<<"XC";
   intnum1[i]=intnum1[i]%90;
   }

else if (intnum1[i]>=50)
     {
     l2[i]=intnum1[i]/50;
      
      for (n2[i]=0;n2[i]<l2[i];n2[i]++)
             {
             cout<<"L";             
             }
      intnum1[i]=intnum1[i]%50;
     }

if (intnum1[i]>=40)
   {
   cout<<"XL";
   intnum1[i]=intnum1[i]%40;
   }

else if (intnum1[i]>=10)
     {
     x2[i]=intnum1[i]/10;
      
      for (n2[i]=0;n2[i]<x2[i];n2[i]++)
             {
             cout<<"X";             
             }
      intnum1[i]=intnum1[i]%10;
     }

if (intnum1[i]>=9)
   {
   cout<<"IX";
   intnum1[i]=intnum1[i]%9;
   }

else if (intnum1[i]>=5)
     {
      v2[i]=intnum1[i]/5;
      
      for (n2[i]=0;n2[i]<v2[i];n2[i]++)
             {
             cout<<"V";             
             }
      intnum1[i]=intnum1[i]%5;
     }
if (intnum1[i]>=4)
   {
   cout<<"IV";
   intnum1[i]=intnum1[i]%4;
   }

else if (intnum1[i]>=1)
     {
     i2[i]=intnum1[i];
      
      for (n2[i]=0;n2[i]<i2[i];n2[i]++)
             {
             cout<<"I";             
             }
      intnum1[i]=intnum1[i]%1;
     }

    }
  
  cout<<".";  
     for (r=0;r<g;r++)
    {
   
    if (ans9[i]>=1000)
   {
   m3[i]=ans9[i]/1000;
  
       {
       for (n3[i]=0;n3[i]<m3[i];n3[i]++)
           {
           cout<<"M";
           }
       }
   ans9[i]=ans9[i]%1000;
   }


if (ans9[i]>=900)
   {
   cout<<"CM";
   ans9[i]=ans9[i]%900;
   }

else if (ans9[i]>=500)
     {
     d3[i]=ans9[i]/500;
    
     
         for (n3[i]=0;n3[i]<d3[i];n3[i]++)
             {
             cout<<"D";             
             }
     ans9[i]=ans9[i]%500;
     } 
     
if (ans9[i]>=400)
   {
   cout<<"CD";
   ans9[i]=ans9[i]%400;
   }

else if (ans9[i]>=100)
     {
     c3[i]=ans9[i]/100;
      
      for (n3[i]=0;n3[i]<c3[i];n3[i]++)
             {
             cout<<"C";             
             }
      ans9[i]=ans9[i]%100;
     }

if (ans9[i]>=90)
   {
   cout<<"XC";
   ans9[i]=ans9[i]%90;
   }

else if (ans9[i]>=50)
     {
     l3[i]=ans9[i]/50;
      
      for (n3[i]=0;n3[i]<l3[i];n3[i]++)
             {
             cout<<"L";             
             }
      ans9[i]=ans9[i]%50;
     }

if (ans9[i]>=40)
   {
   cout<<"XL";
   ans9[i]=ans9[i]%40;
   }

else if (ans9[i]>=10)
     {
     x3[i]=ans9[i]/10;
      
      for (n3[i]=0;n3[i]<x3[i];n3[i]++)
             {
             cout<<"X";             
             }
      ans9[i]=ans9[i]%10;
     }

if (ans9[i]>=9)
   {
   cout<<"IX";
   ans9[i]=ans9[i]%9;
   }

else if (ans9[i]>=5)
     {
      v3[i]=ans9[i]/5;
      
      for (n3[i]=0;n3[i]<v3[i];n3[i]++)
             {
             cout<<"V";             
             }
      ans9[i]=ans9[i]%5;
     }
if (ans9[i]>=4)
   {
   cout<<"IV";
   ans9[i]=ans9[i]%4;
   }

else if (ans9[i]>=1)
     {
     i3[i]=ans9[i];
      
      for (n3[i]=0;n3[i]<i3[i];n3[i]++)
             {
             cout<<"I";             
             }
      ans9[i]=ans9[i]%1;
     }

    
    }

cout<<" ";
 }

}
