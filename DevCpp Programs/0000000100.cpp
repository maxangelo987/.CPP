// (0000000100) Decimal to Hexadecimal <CpE221/CpE321>\
// (class function)

#include <cstdlib>
#include <iostream>

using namespace std;


class convert {
      public:
             void input();
             void hexa();
             long l,num[100],k[100],hex[100][100],rem[100],i,hexaa[100];
             long access,j;
      };
int main(int argc, char *argv[])
{
    convert l;
    
    l.input();
    l.hexa();
    system("PAUSE");
    return EXIT_SUCCESS;
}

void convert::input()
{
cout<<"Decimal to Hexadecimal Converter"<<endl;
cout<<"Input Number you desire: ";
cin>>access;
cout<<"Inputs: "<<endl;

for (j=0;j<access;j++)
    {
    cin>>num[j];
    }

}

void convert::hexa()
{

for (j=0;j<access;j++)
{

k[j]=-1;
hexaa[j]=num[j];
for (i=0;num[j]>0;i++)
    {
    rem[j]=num[j]%16;
    hex[i][j]=rem[j];
    num[j]=num[j]/16;
    k[j]++;
    }


    if (hexaa[j]<10)
       {
       cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
       cout<<hexaa[j]<<endl;
       }

    else if (hexaa[j]==10)
       {
       cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
       cout<<"A"<<endl;
       }
    else if (hexaa[j]==11)
       {
       cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
       cout<<"B"<<endl;
       }
    else if (hexaa[j]==12)
       {
       cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
       cout<<"C"<<endl;
       }   
    else if (hexaa[j]==13)
       {
       cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
       cout<<"D"<<endl;
       }
    else if (hexaa[j]==14)
       {
       cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
       cout<<"E"<<endl;
       }
    else if (hexaa[j]==15)
       {
       cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
       cout<<"F"<<endl;
       }   

else
{
    cout<<"The Hexadecimal of "<<hexaa[j]<<" is"<<":"<<endl;
    
 for (i=k[j];i>-1;i--)
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
    cout<<""<<endl;
 }
}
cout<<""<<endl;
}
