// (0000000010) Conversion (Decimal to Binary, Octal, Hexadecimal) <CpE221/CpE321>
// (class function)

#include <cstdlib>
#include <iostream>

using namespace std;


class converter
     {
     public:
            void input();
            void prcsone();
            void prcstwo();
            void integer();
            void decimal();
            long key;
            long m,i,inp1[100],in[100],k,count,d,o,access,d1;
            double num[100],ans[100],deci[100],inp[100];  
            long rem[100],bin[100],base[100]; 
            long oct[100],rem1[100],base1[100],in2[100];  
            long h[100],j,hexaa[100],hex[100][100];
            long num1[100];
            long deci1[100],g,t,hum1[100],gop[100];
            double deci2[100],decif[100],n,inp8[100];
            long hu;
                };
int main(int argc, char *argv[])
{
    long z;
    converter m;
    m.input(); 
    m.prcsone();
    m.prcstwo();
    cin>>z;
           if (z==2)
              {
              m.decimal();
              }
           else if (z==1)
              {
              m.integer();
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
                         
  o=0;
  j=0;
  d=0;
  g=0;
  t=0;
   for (i=0;i<k;i++)
      {
      
      inp1[i]=(long)inp[i];
      ans[i]=inp[i]-inp1[i];
      
      if (ans[i]==0)
         {
          in[t]=inp1[i];  
          in2[t]=inp1[i]; 
          num1[t]=inp1[i];     
          o++;
          t++; // Whole Numbers         
         }
      
      else {
          
           inp8[g]=inp[i];
           decif[g]=inp[i];
           g++;
           d++;
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

    cout<<"You choose Integer!"<<endl
    <<"Here's it's conversion:"<<endl;


// Decimal to Binary    
cout<<"Binary: ";
for (i=0;i<o;i++) 
    {
    
    bin[i]=0;
    base[i]=1;
    
    for (;in[i]>0;)
        {
        rem[i]=in[i]%2;
        bin[i]=bin[i]+rem[i]*base[i];
        base[i]=base[i]*10;
        in[i]=in[i]/2;
        }
    }
for (i=0;i<o;i++)
    {
    cout<<" "<<bin[i]<<" ";
    }



cout<<""<<endl;

// Decimal to Octal
cout<<"Octal: ";
for (i=0;i<o;i++) 

    {
    
    oct[i]=0;
    base1[i]=1;
    
    for (;in2[i]>0;)
        {
        rem1[i]=in2[i]%8;
        oct[i]=oct[i]+rem1[i]*base1[i];
        base1[i]=base1[i]*10;
        in2[i]=in2[i]/8;
        }
    }
    
for (i=0;i<o;i++)
    {
    cout<<" "<<oct[i]<<" ";
    }
        
cout<<""<<endl;

// Decimal to Hexadecimal

cout<<"Hexadecimal: ";

for (j=0;j<o;j++)
{

h[j]=-1;
hexaa[j]=num1[j];
for (i=0;num1[j]>0;i++)
    {
    rem[j]=num1[j]%16;
    hex[i][j]=rem[j];
    num1[j]=num1[j]/16;
    h[j]++;
    }


    if (hexaa[j]<10)
       {
       cout<<hexaa[j]<<" ";
       }

    else if (hexaa[j]==10)
       {
       cout<<"A"<<" ";
       }
    else if (hexaa[j]==11)
       {
       cout<<"B"<<" ";
       }
    else if (hexaa[j]==12)
       {
       cout<<"C"<<" ";
       }   
    else if (hexaa[j]==13)
       {
       cout<<"D"<<" ";
       }
    else if (hexaa[j]==14)
       {
       cout<<"E"<<" ";
       }
    else if (hexaa[j]==15)
       {
       cout<<"F"<<" ";
       }   

else
{
    
 for (i=h[j];i>-1;i--)
    {
    
 
   
    if (hex[i][j]<10)
       {
       cout<<hex[i][j];
       }
    
    else if (hex[i][j]==10)
       {
       cout<<"A";
       }
    else if (hex[i][j]==11)
       {
       cout<<"B";
       }
    else if (hex[i][j]==12)
       {
       cout<<"C";
       }   
    else if (hex[i][j]==13)
       {
       cout<<"D";
       }
    else if (hex[i][j]==14)
       {
       cout<<"E";
       }
    else if (hex[i][j]==15)
       {
       cout<<"F";
       }   
    
    }
    cout<<" ";
 }
}

}


 
void converter::decimal()
{


    cout<<"You choose Decimal!"<<endl
    <<"Here's it's conversion:"<<endl;          
    
    
for (i=0;i<d;i++)
  { 
  deci1[i]=(long)decif[i];
  deci2[i]=decif[i]-deci1[i];
  }

hu=1;

for (i=0;i<d;i++)
  {
  cout<<deci2[0]<<endl;
  }
    
    
      
     
 
  }



// Decimal to Binary
