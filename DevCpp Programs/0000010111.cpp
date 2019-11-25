// (0000010111) Input numbers then determine the maximum
// number and locate what position. <CpE221/Mathematics>


#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int x,i,j,pos;
    int arr_1[100],max;

    cout<<"Input # of elements: ";
    cin>>x;
    
    for (i=0;i<x;i++)
        {
        cin>>arr_1[i];
        }
    
    pos=1;
    max=arr_1[0];
    for (i=0;i<x-1;i++)
        {
        if (arr_1[i+1]>max)
           {
           max=arr_1[i+1];
           pos++;
           }
        }    
        
        
    cout<<"The largest number is "<<max<<". Found at position "<<pos;
    system("PAUSE");
    return EXIT_SUCCESS;
}
