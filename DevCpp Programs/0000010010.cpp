// (0000010010) Converting Uppercase to Lowercase vice versa <CpE221/Mathematics>


#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char str[1000];
    long h;
    
    gets(str);
    h=strlen(str);
    
    for (int i=0;i<h;i++)
        {
        if ('a'<=str[i]&&str[i]<='z')
           {
           str[i]=char(((int)str[i])-32);
           }
         
        else if ('A'<=str[i]&&str[i]<='Z')
           {
           str[i]=char(((int)str[i])+32);
           }
        }
        
    for (int i=0;i<h;i++)
        {
        cout<<str[i];     
        }
    system("PAUSE");
    return EXIT_SUCCESS;
}
