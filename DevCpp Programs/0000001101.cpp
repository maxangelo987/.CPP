
// (0000001101) Longest Word <CpE221/English>
// (class function, string)

#include<stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

class long_word
      {
      public:
             void input();
             
             char phrase[100],phrase2D[100][100],word_storage[100];    
             long k,j,i,m,phrase_len,phrase2D_len[100][1],y,z,x,v,g,t,max,h;
             long loop;
      };
int main(int argc, char *argv[])
{
    
    long_word m;
    
    m.input();
    system("PAUSE");
    return EXIT_SUCCESS;
}


void long_word::input()
{

cout<<"Input a Phrase: "<<endl;     
gets(phrase);
phrase_len=strlen(phrase);
z=0; // Number of Words


for (i=0;i<phrase_len;i++)
    {
    if (isalnum(phrase[i])&&(phrase[i+1]==' '||phrase[i+1]==NULL)) 
       {
       y=0;
       
       for (j=i;;j--)
           {
           if (isalnum(phrase[j]))
              {
              word_storage[y]=phrase[j];
              y++;
              }
           
           else
               {
               break;
               }
           }
       
       phrase2D_len[z][0]=y; // Ani nimo ibutang ang an kanang pila kabook ang taga words
       
       
       for (x=y-1,v=0;x>=0,v<y;x--,v++)
           {
           phrase2D[z][v]=word_storage[x];
           }
        z++;
       }
    
    }


max=phrase2D_len[0][0];

for (g=1;g<z;g++)
    {
    if (max<phrase2D_len[g][0])
       {
       max=phrase2D_len[g][0];
       }
    }
    
for (t=0;t<z;t++)
    {
    if (max==phrase2D_len[t][0])
       {
       cout<<"Word No."<<t+1<<": ";
       
       for (k=0;k<phrase2D_len[t][0];k++)
           {
           cout<<phrase2D[t][k];
           }
       
       cout<<" is the longest word.";
       }
    
    
    }

cout<<endl;
}
