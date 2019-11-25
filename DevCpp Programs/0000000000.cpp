// (0000000000) Oban Numbers,
// Example: 4, Four - Oban
// (stack, class function) <CpE221/Engl1>


#include <cstdlib>
#include <iostream>

using namespace std;

long p=0;
long g=0;
class stack
{
      public:
             void input();
             void convert();
             void movtoword();
             void decision();
             void push();
             void GT GHTNY pop();

             long num,num1,num2;
             long q,q1,q2;
             long bil,hmil,rmil,tmil,omil,hthou,rthou,tthou,othou,h,r,t,o;
             long i,i1,i2,i3,i4,i5,i6,i7,i8,i9;
             long i10, i11, i12, i13, i14;
             char name[1000],name1[1000],name2[1000],name3[1000],name4[1000],name5[1000];
             char name6[1000],name7[1000],name8[1000],name9[1000],name10[1000],name11[1000];
             char name12[1000],name13[1000],name14[1000],name15[1000];
             long j,d,z;
             long w;
             char word[1000],word1[1000];
             long count,temp[1000];
             long not_ban[1000];
};

int main(int argc, char *argv[])
{
stack m;
char access;
     cout<<"OBan Numbers in Stack: "<<endl;
     cout<<"(All numbers that has letter O will be ban.)"<<endl;
     cout<<"[A] - Push. "<<endl;
     cout<<"[B] - Pop. "<<endl;
     cout<<"[C] - Exit. "<<endl;
     
     for (;;)
         {
          cout<<"Input Process: ";
          cin>>access;
         if (access=='A'||access=='a')
            {
            m.input();
            m.convert();
            m.movtoword();
            m.decision();
            m.push();            
            }
         
         if (access=='B'||access=='b')
            {
            m.pop();
            }
         
         if (access=='C'||access=='c')
            {
            break;
            }
         
         }      
      

    system("PAUSE");
    return EXIT_SUCCESS;
}

void stack::input() // This class is for getting input
{
count=0;
bil=0; hmil=0; rmil=0; tmil=0; omil=0;
hthou=0; rthou=0; tthou=0; othou=0; 
h=0; t=0; r=0; o=0;
i=0; i1=0; i2=0; i3=0; i4=0; i5=0;
i6=0; i7=0; i8=0; i9=0; i10=0; i11=0;
i12=0; i13=0; i14=0;
cout<<"Input Number to determine: ";
cin>>num;
temp[g]=num;

if (temp[g]==0)
   {
   strcpy(word1,"zero");
   z=strlen(word1);
   }
}

void stack::convert() // This class is for converting Nummbers to Words
{    
bil=num/1000000000;
num=num%1000000000;
hmil=num/100000000;
num=num%100000000;
q=num/1000000;
num1=num;

if ((q>10)&&(q<20))
{
num=num%10000000;
rmil=num/1000000;
tmil=0;
omil=0;
}

else
{
tmil=num/10000000;
num=num%10000000;
omil=num/1000000;
}


num1=num1%1000000;
hthou=num1/100000;
num1=num1%100000;
q1=num1/1000;
num2=num1;

if ((q1>10)&&(q1<20))
{
num1=num1%10000;
rthou=num1/1000;
tthou=0;
othou=0;
}

else
{
tthou=num1/10000;
num1=num1%10000;
othou=num1/1000;
}

num2=num2%1000;
h=num2/100;
num2=num2%100;
q2=num2;

if ((q2>10)&&(q2<20))
{
num2=num2%10;
r=num2;
t=0;
o=0;
}

else
{
t=num2/10;
num2=num2%10;
o=num2;
}


switch(bil)
{
case 1: strcpy(name,"one billion "); i=strlen(name); break;
case 2: strcpy(name,"two billion "); i=strlen(name); break;
case 3: strcpy(name,"three billion "); i=strlen(name); break;
case 4: strcpy(name,"four billion "); i=strlen(name); break;
case 5: strcpy(name,"five billion "); i=strlen(name); break;
case 6: strcpy(name,"six billion "); i=strlen(name); break;
case 7: strcpy(name,"seven billion "); i=strlen(name); break;
case 8: strcpy(name,"eight billion "); i=strlen(name); break;
case 9: strcpy(name,"nine billion "); i=strlen(name); break;
}

if ((tmil==0)&&(omil==0)&&(rmil==0))
{
switch(hmil)
{
case 1: strcpy(name1,"one hundred million "); i1=strlen(name1); break;
case 2: strcpy(name1,"two hundred million "); i1=strlen(name1); break;
case 3: strcpy(name1,"three hundred million "); i1=strlen(name1); break;
case 4: strcpy(name1,"four hundred million "); i1=strlen(name1); break;
case 5: strcpy(name1,"five hundred million "); i1=strlen(name1); break;
case 6: strcpy(name1,"six hundred million "); i1=strlen(name1); break;
case 7: strcpy(name1,"seven hundred million "); i1=strlen(name1); break;
case 8: strcpy(name1,"eight hundred million "); i1=strlen(name1); break;
case 9: strcpy(name1,"nine hundred million "); i1=strlen(name1); break;
}
}

else
{
switch(hmil)
{
case 1: strcpy(name1,"one hundred "); i1=strlen(name1); break;
case 2: strcpy(name1,"two hundred "); i1=strlen(name1); break;
case 3: strcpy(name1,"three hundred "); i1=strlen(name1); break;
case 4: strcpy(name1,"four hundred "); i1=strlen(name1); break;
case 5: strcpy(name1,"five hundred "); i1=strlen(name1); break;
case 6: strcpy(name1,"six hundred "); i1=strlen(name1); break;
case 7: strcpy(name1,"seven hundred "); i1=strlen(name1); break;
case 8: strcpy(name1,"eight hundred "); i1=strlen(name1); break;
case 9: strcpy(name1,"nine hundred "); i1=strlen(name1); break;
}
}


switch(rmil)
{
case 1: strcpy(name2,"eleven million "); i2=strlen(name2); break;
case 2: strcpy(name2,"twelve million "); i2=strlen(name2); break;
case 3: strcpy(name2,"thirteen million "); i2=strlen(name2); break;
case 4: strcpy(name2,"fourteen million "); i2=strlen(name2); break;
case 5: strcpy(name2,"fifthteen million "); i2=strlen(name2); break;
case 6: strcpy(name2,"sixteen million "); i2=strlen(name2); break;
case 7: strcpy(name2,"seventeen million "); i2=strlen(name2); break;
case 8: strcpy(name2,"eighteen million "); i2=strlen(name2); break;
case 9: strcpy(name2,"nineteen million "); i2=strlen(name2); break;
}


if (omil==0)
{
switch(tmil)
{
case 1: strcpy(name3,"ten million "); i3=strlen(name3); break;
case 2: strcpy(name3,"twenty million "); i3=strlen(name3); break;
case 3: strcpy(name3,"thirty million "); i3=strlen(name3); break;
case 4: strcpy(name3,"forty million "); i3=strlen(name3); break;
case 5: strcpy(name3,"fifty million "); i3=strlen(name3); break;
case 6: strcpy(name3,"sixty million "); i3=strlen(name3); break;
case 7: strcpy(name3,"seventy million "); i3=strlen(name3); break;
case 8: strcpy(name3,"eighty million "); i3=strlen(name3); break;
case 9: strcpy(name3,"ninety million "); i3=strlen(name3); break;
}
}

else
{
switch(tmil)
{
case 2: strcpy(name3,"twenty "); i3=strlen(name3); break;
case 3: strcpy(name3,"thirty "); i3=strlen(name3); break;
case 4: strcpy(name3,"forty "); i3=strlen(name3); break;
case 5: strcpy(name3,"fifty "); i3=strlen(name3); break;
case 6: strcpy(name3,"sixty "); i3=strlen(name3); break;
case 7: strcpy(name3,"seventy "); i3=strlen(name3); break;
case 8: strcpy(name3,"eighty "); i3=strlen(name3); break;
case 9: strcpy(name3,"ninety  "); i3=strlen(name3); break;
}

switch(omil)
{
case 1: strcpy(name4,"one million "); i4=strlen(name3); break;
case 2: strcpy(name4,"two million "); i4=strlen(name3); break;
case 3: strcpy(name4,"three million "); i4=strlen(name3); break;
case 4: strcpy(name4,"four million "); i4=strlen(name3); break;
case 5: strcpy(name4,"five million "); i4=strlen(name3); break;
case 6: strcpy(name4,"six million "); i4=strlen(name3); break;
case 7: strcpy(name4,"seven million "); i4=strlen(name3); break;
case 8: strcpy(name4,"eight million "); i4=strlen(name3); break;
case 9: strcpy(name4,"nine million "); i4=strlen(name3); break;
}

}

if ((tthou==0)&&(othou==0)&&(rthou==0))
{
switch(hthou)
{
case 1: strcpy(name5,"one hundred thousand "); i5=strlen(name5); break;
case 2: strcpy(name5,"two hundred thousand "); i5=strlen(name5); break;
case 3: strcpy(name5,"three hundred thousand "); i5=strlen(name5); break;
case 4: strcpy(name5,"four hundred thousand "); i5=strlen(name5); break;
case 5: strcpy(name5,"five hundred thousand "); i5=strlen(name5); break;
case 6: strcpy(name5,"six hundred thousand "); i5=strlen(name5); break;
case 7: strcpy(name5,"seven hundred thousand "); i5=strlen(name5); break;
case 8: strcpy(name5,"eight hundred thousand "); i5=strlen(name5); break;
case 9: strcpy(name5,"nine hundred thousand "); i5=strlen(name5); break;
}
}

else
{
switch(hthou)
{
case 1: strcpy(name5,"one hundred "); i5=strlen(name5); break;
case 2: strcpy(name5,"two hundred "); i5=strlen(name5); break;
case 3: strcpy(name5,"three hundred "); i5=strlen(name5); break;
case 4: strcpy(name5,"four hundred "); i5=strlen(name5); break;
case 5: strcpy(name5,"five hundred "); i5=strlen(name5); break;
case 6: strcpy(name5,"six hundred "); i5=strlen(name5); break;
case 7: strcpy(name5,"seven hundred "); i5=strlen(name5); break;
case 8: strcpy(name5,"eight hundred "); i5=strlen(name5); break;
case 9: strcpy(name5,"nine hundred "); i5=strlen(name5); break;
}

}
switch(rthou)
{
case 1: strcpy(name6,"eleven thousand "); i6=strlen(name6); break;
case 2: strcpy(name6,"twelve thousand "); i6=strlen(name6); break;
case 3: strcpy(name6,"thirteen thousand "); i6=strlen(name6); break;
case 4: strcpy(name6,"fourteen thousand "); i6=strlen(name6); break;
case 5: strcpy(name6,"fifthteen thousand "); i6=strlen(name6); break;
case 6: strcpy(name6,"sixteen thousand "); i6=strlen(name6); break;
case 7: strcpy(name6,"seventeen thousand "); i6=strlen(name6); break;
case 8: strcpy(name6,"eighteen thousand "); i6=strlen(name6); break;
case 9: strcpy(name6,"nineteen thousand "); i6=strlen(name6); break;
}


if (othou==0)
{
switch(tthou)
{
case 1: strcpy(name7,"ten thousand "); i7=strlen(name7); break;
case 2: strcpy(name7,"twenty thousand "); i7=strlen(name7); break;
case 3: strcpy(name7,"thirty thousand "); i7=strlen(name7); break;
case 4: strcpy(name7,"forty thousand "); i7=strlen(name7); break;
case 5: strcpy(name7,"fifty thousand "); i7=strlen(name7); break;
case 6: strcpy(name7,"sixty thousand "); i7=strlen(name7); break;
case 7: strcpy(name7,"seventy thousand "); i7=strlen(name7); break;
case 8: strcpy(name7,"eighty thousand "); i7=strlen(name7); break;
case 9: strcpy(name7,"ninety thousand "); i7=strlen(name7); break;
}
}

else
{
switch(tthou)
{
case 2: strcpy(name7,"twenty "); i7=strlen(name7); break;
case 3: strcpy(name7,"thirty "); i7=strlen(name7); break;
case 4: strcpy(name7,"forty "); i7=strlen(name7); break;
case 5: strcpy(name7,"fifty "); i7=strlen(name7); break;
case 6: strcpy(name7,"sixty "); i7=strlen(name7); break;
case 7: strcpy(name7,"seventy "); i7=strlen(name7); break;
case 8: strcpy(name7,"eighty "); i7=strlen(name7); break;
case 9: strcpy(name7,"ninety "); i7=strlen(name7); break;
}

switch(othou)
{
case 1: strcpy(name8,"one thousand "); i8=strlen(name8); break;
case 2: strcpy(name8,"two thousand "); i8=strlen(name8); break;
case 3: strcpy(name8,"three thousand "); i8=strlen(name8); break;
case 4: strcpy(name8,"four thousand "); i8=strlen(name8); break;
case 5: strcpy(name8,"five thousand "); i8=strlen(name8); break;
case 6: strcpy(name8,"six thousand "); i8=strlen(name8); break;
case 7: strcpy(name8,"seven thousand "); i8=strlen(name8); break;
case 8: strcpy(name8,"eight thousand "); i8=strlen(name8); break;
case 9: strcpy(name8,"nine thousand "); i8=strlen(name8); break;
}
}

switch(h)
{
case 1: strcpy(name9,"one hundred "); i9=strlen(name9); break;
case 2: strcpy(name9,"two hundred "); i9=strlen(name9); break;
case 3: strcpy(name9,"three hundred "); i9=strlen(name9); break;
case 4: strcpy(name9,"four hundred "); i9=strlen(name9); break;
case 5: strcpy(name9,"five hundred "); i9=strlen(name9); break;
case 6: strcpy(name9,"six hundred "); i9=strlen(name9); break;
case 7: strcpy(name9,"seven hundred "); i9=strlen(name9); break;
case 8: strcpy(name9,"eight hundred "); i9=strlen(name9); break;
case 9: strcpy(name9,"nine hundred "); i9=strlen(name9); break;
}

switch(r)
{
case 1: strcpy(name10,"eleven "); i10=strlen(name10); break;
case 2: strcpy(name10,"twelve "); i10=strlen(name10); break;
case 3: strcpy(name10,"thirteen "); i10=strlen(name10); break;
case 4: strcpy(name10,"fourteen "); i10=strlen(name10); break;
case 5: strcpy(name10,"fifteen "); i10=strlen(name10); break;
case 6: strcpy(name10,"sixteen "); i10=strlen(name10); break;
case 7: strcpy(name10,"seventeen "); i10=strlen(name10); break;
case 8: strcpy(name10,"eighteen "); i10=strlen(name10); break;
case 9: strcpy(name10,"nineteen "); i10=strlen(name10); break;
}

switch(t)
{
case 1: strcpy(name11,"ten "); i11=strlen(name11); break;
case 2: strcpy(name11,"twenty "); i11=strlen(name11); break;
case 3: strcpy(name11,"thirty "); i11=strlen(name11); break;
case 4: strcpy(name11,"forty "); i11=strlen(name11); break;
case 5: strcpy(name11,"fifty "); i11=strlen(name11); break;
case 6: strcpy(name11,"sixty "); i11=strlen(name11); break;
case 7: strcpy(name11,"seventy "); i11=strlen(name11); break;
case 8: strcpy(name11,"eighty "); i11=strlen(name11); break;
case 9: strcpy(name11,"ninety "); i11=strlen(name11); break;
}

switch(o)
{
case 1: strcpy(name12,"one"); i12=strlen(name12); break;
case 2: strcpy(name12,"two"); i12=strlen(name12); break;
case 3: strcpy(name12,"three"); i12=strlen(name12); break;
case 4: strcpy(name12,"four"); i12=strlen(name12); break;
case 5: strcpy(name12,"five"); i12=strlen(name12); break;
case 6: strcpy(name12,"six"); i12=strlen(name12); break;
case 7: strcpy(name12,"seven"); i12=strlen(name12); break;
case 8: strcpy(name12,"eight"); i12=strlen(name12); break;
case 9: strcpy(name12,"nine"); i12=strlen(name12); break;
}


}

void stack::movtoword()
{
strcpy(word," ");
w=0;

if (bil>0)
{
strcat(word,name);
}

if (hmil>0)
{
strcat(word,name1);
}

if (rmil>0)
{
strcat(word,name2);
}

if (tmil>0)
{
strcat(word,name3);
}

if (omil>0)
{
strcat(word,name4);
}

if (hthou>0)
{
strcat(word,name5);
}

if (rthou>0)
{
strcat(word,name6);
}

if (tthou>0)
{
strcat(word,name7);
}

if (othou>0)
{
strcat(word,name8);
}

if (h>0)
{
strcat(word,name9);
}

if (r>0)
{
strcat(word,name10);
}

if (t>0)
{
strcat(word,name11);
}

if (o>0)
{
strcat(word,name12);
}

w=strlen(word);

for (j=0;j<w;j++)
{
if (word[j]=='O'||word[j]=='o')
   {
   count++;
   break;
   }
}

}


void stack::decision()
{
if (count!=0)
{
cout<<"You can't Push number "<<temp[g]<<". It contain's letter O. "<<endl;
cout<<">> ";
for (j=0;j<w;j++)
    {
    
    if (word[j]=='O'||word[j]=='o')
       {
       cout<<"("<<word[j]<<")";
       }
    
    else
        {
        cout<<word[j];
        }
    }
}

else if (temp[g]==0)
{
cout<<"You can't Push number "<<temp[g]<<". It contain's letter O. "<<endl;
cout<<">> ";

for (j=0;j<z;j++)
    {
    
    if (word1[j]=='O'||word1[j]=='o')
       {
       cout<<"("<<word1[j]<<")";
       }
    
    else
        {
        cout<<word1[j];
        }
    }
}

else
 {

 cout<<"You can Push number "<<temp[g]<<". It doesn't contain letter O. "<<endl;
 cout<<">> ";
 not_ban[p]=temp[g];
 p++;

 for (j=0;j<w;j++)
     {
     cout<<word[j];
     }
 }
cout<<endl;
}




void stack::push()
{

if (p==0)
   {
   cout<<"[The Stack is empty!]"<<endl;
   }

else
    {
    for(d=0;d<p;d++)
             {           
             cout<<"["<<not_ban[d]<<"]"<<" ";
             }
    cout<<endl;
    }        

g++;
}

void stack::pop()
{
 if (p==0)
       {
       cout<<"You can't delete anymore."<<endl;
       cout<<"[The Stack is empty!]"<<endl;
       }

  else
  {     
p--;
cout<<"You deleted "<<not_ban[p]<<"."<<endl;
    
     for (d=0;d<p;d++)
         {
         cout<<"["<<not_ban[d]<<"]"<<" ";
         }
    
    cout<<endl;
    
    if (p==0)
       {
       cout<<"[The Stack is empty!]"<<endl;
       }
    }

cout<<endl;
}
