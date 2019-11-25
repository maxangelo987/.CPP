#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class activity1
{
 public:
        void input();
        char in1[100], *ptr, *myword[20],*anagrams[20];
        long a;
        char s1[100];
        char s2[100];
        long i,j,isanag,k,l,t;
        long countanagrams;
      };
typedef ptr
int main(int argc, char *argv[])
{
    activity1 m;
    m.input();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


void activity1::input()
{
     cout<<"Enter Input: ";
	 gets(in1);
     
a=0;

ptr=strtok(in1, " ");

while(ptr!=NULL)
	{
	myword[a]=ptr;
	a++;
	ptr=strtok(NULL, " ");
	}

     
t=0;
countanagrams=0;
for (i=0;i<a;i++)
    {
    for (j=0;j<a;j++)
        {
        
         strcpy(s1, myword[i]);
         strcpy(s2, myword[j]);
         
        if(strlen(s1)!=strlen(s2))
        { 
        cout<<"Not anagrams. "<<endl;
        }
        
        for(k=0;k<strlen(s1);k++)
        {
         isanag=0;
         for(l=0;l<strlen(s2);l++)
              {
              if(s1[k]==s2[l])
                {
                isanag = 1;
                break;
                }
              }

        if(isanag == 0)
              {
              cout<<"Not anagrams. "<<endl;
              return;
              exit(0);
              }
   
              }
               cout<<"s1="<<s1<<endl;
     cout<<"s2= "<<s2<<endl;
   
      if (((strcmp(s2,s1))!=0))
          {
          anagrams[t]=myword[i];
          t++;
          countanagrams++;
          }
    
        }              
    }

    
for (i=0;i<countanagrams;i++)
    {
    cout<<anagrams[i]<<endl;
    }


}

