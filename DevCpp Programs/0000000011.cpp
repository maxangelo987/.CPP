// (0000000011) Area of Rectangle <CpE221/Math0>
// Turbo C functions (getch)


#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
                    
long width,height,area,perimeter;

cout<<"Enter Width of Rectangle = ";
cin>>width;

cout<<"Enter Height of Rectangle = ";
cin>>height;

area=height*width;
cout<<"\nArea of Rectangle = "<<area<<endl;

perimeter=2*(height+width);
cout<<"Perimeter of Rectangle are = "<<perimeter<<endl;

getch();
}
