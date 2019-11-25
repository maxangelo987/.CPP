#include <cstdlib>
#include <iostream>
#include <llist.h>
using namespace std;
void option();
long comparestring_ana(char[], char[]);
int main(int argc, char *argv[])
{
char words[100], *mychar[20], *tokenptr;
long a,b,c,mycond;
string anag;
char str1[30], str2[30];
linklist<string> mylink;
cout<<"Enter list of words here: ";
gets(words);
tokenptr=strtok(words," ");
a=0;
while(tokenptr!=NULL){
mychar[a]=tokenptr;
tokenptr=strtok(NULL, " ");
a++;
}
b=0;
while(b<a){ 
c=b+1; 
while(c<a){
mycond=0; 
strcpy(str1, mychar[b]);
strcpy(str2, mychar[c]);
mycond=comparestring_ana(str1,str2);
if(mycond==1){
anag=str1;
mylink.insert_last(anag);
anag=str2;
mylink.insert_last(anag);
}
c++;
}
b++;
}
mylink.display();
cout<<endl<<endl;
system("PAUSE");
return EXIT_SUCCESS;
}
long comparestring_ana(char mychar1[], char mychar2[]){
int i,j,k,l,mycond,count1,count2;
if(strlen(mychar1)==strlen(mychar2)){
j=0;
mycond=0;
while(j<strlen(mychar1) && mycond!=1){
i=0;
count1=1;
while(i<strlen(mychar1)){
if(i!=j && mychar1[i]==mychar1[j]){
count1++; 
}
i++;
}
k=0;
count2=0;
while(k<strlen(mychar2)){
if(mychar2[k]==mychar1[j]){
count2++;
}
k++;
}
if(count1!=count2){
mycond=1;
} 
j++;
}
if(mycond==1){
return 0;
}
else 
return 1;
}
else{
return 0;
} 
}
