#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char *ptr,str[100],*myword[100];
    int i,count=0,process;
    
    gets(str);
    
    ptr=strtok(str," ");
    
    for(i=0;ptr!=NULL;i++)
                    {
                    myword[i]=ptr;
                    count++;
                    ptr=strtok(NULL," ");
    
                    }
    for(i=0;i<count;i++)
                        {
                        cout<<myword[i]<<endl;
                        }
    for(;;)
    {
    cout<<"Process";
    cin>>process;
    if(process==1)
                  {
                  myword[0]=0;
                  count--;
                  for(i=0;i<count;i++)
                                      {
                                      myword[i]=myword[i+1];
                                      cout<<myword[i];
                                      }
                  }
    if(process==2)
                  {
                  
                  cout<<"input";
                  
                  cin>>myword[i];
                  count++;
                  for(i=0;i<count;i++)
                         {
                         cout<<myword[i];
                         }
                  }
                  
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
