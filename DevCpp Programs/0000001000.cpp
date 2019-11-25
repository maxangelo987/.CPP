// (0000001000) Checking if your equation is valid <CpE221/Mathematics>
// (class function)


#include <cstdlib>
#include <iostream>

using namespace std;

class equation
{
      public:
             void input();
             void output();
             char str1[100],y, let[100];        
             long x,i; 
   
      
      };

int main(int argc, char *argv[])
{
    equation m;

    m.input();
    m.output();

    system("PAUSE");
    return EXIT_SUCCESS;
}


void equation::input()
{
     cout<<"Enter Equation: "<<endl;
     gets(str1);
     x=strlen(str1);
     }

     
void equation::output()
{
     cout<<"Out: ";
     
     y=str1[x-1];    
         
         switch(y)
                   {
                   case '+': cout<<"Invalid"<<endl; break;
                   case '-': cout<<"Invalid"<<endl; break;
                   case '/': cout<<"Invalid"<<endl; break;
                   case ')': cout<<"Invalid"<<endl; break;
                   case '*': cout<<"Invalid"<<endl; break; 
                   case '(': cout<<"Invalid"<<endl; break;
                   default :  break;
                   }
 y=str1[0];    
         
         switch(y)
                   {
                   case '+': cout<<"Invalid"<<endl; break;
                   case '-': cout<<"Invalid"<<endl; break;
                   case '/': cout<<"Invalid"<<endl; break;
                   case ')': cout<<"Invalid"<<endl; break;
                   case '*': cout<<"Invalid"<<endl; break; 
                   case '(': cout<<"Invalid"<<endl; break;
                   default : cout<<"Valid"<<endl; break;
                   }
         for (int i=0; i<x; i++){
             if(isalnum(str1[i])){
                                if(str1[i+1]== '+' && str1[i+2] == '-'){
                                               cout<<"Valid";
                                                   }
                                else{
                                     cout<<"Invalid";
                                     }  
                                  }
             }
}

