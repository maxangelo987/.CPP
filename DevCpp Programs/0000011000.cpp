// (0000011000) Input numbers then determine the
// composite and determine the largest number of the
// composite and it's prime factors <CpE221/Mathematics>


#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int num[100],i,j,h,temp[100];
    int count[100],y,compo[100];
    int max,t;
    h=0;
    
    printf("Input Numbers press ZERO to break: "); 
    for (i=0;;i++) /* This loop is for scanning the inputs and moundang ug mo press zero */
        {
        scanf("%d",&num[i]);
        if (num[i]==0) /* This decision is the part for breaking for example if num[0]==0 then you already break it */
           {
           break;
           }
        
        h++;  /*the variable h mo silbing tig ihap ug pila imong gi pasud sa imong array kay in this problem wala man ta nangayog reference number so mao na ni gamiton natong reference number para sa next loop*/ 
        }
    
    y=0; /* ayaw libuga ninyo si y kay si y ani mao ang index sa composite nga array ug pwede pud tig ihap ug pila ang atong nagamit nga array sa para sa composites and mo serves nasad ni ug reference variable para sa next loop */
    for (i=0;i<h;i++) /* So nagamit na nato ag h as reference i<h so taman ra ang loop ani depende sa h */
        {
        count[i]=0; /* remember in getting the prime you need to put count so this time you have lots of inputs so you will assume every inputs that has count=0 and this is array so count[i] the is the indexing please ayaw libuga nga ang i ang gisud sa array*/
        temp[i]=num[i]; /*Atong gi swap si array num sa temp kay sa sunod nga loop kay dili naman mahimong exact value si num kay imo man siyang gi divided by to i so si temp atong gamiton sa decision (try to look if (count[i]!=0))*/
        for (j=2;j<num[i];j++) /* this loop is for prime try to open on your notes in getting the prime in one input, recap */
            {
            if (num[i]%2==0)
               {
               count[i]++; /*So every input in your array has their own count so if count[0] ning increment so ang imong compo[0] prime */
               }  
            }
        
        if (count[i]!=0) /*but kay imong gipangita kay composite man so directly change the decision to !=0 */
           {
           compo[y]=temp[i]; /*Mao na kung every count in every array kay dili zero 1 or 2 or 3 ba siya so ipasa nato si array temp sa compo then mag create tag new index para sa compo kay lahi naman ang kauban niya I mean nakuhaan sila dili nata mogamit ni i kay mao man to ang index or number of groups kintahay sa wala pa nakuhaan*/
           y++; /*Ning increment ang index para sa compo */
           }
        }
        
    printf("These are the composites you entered: ");
    for (i=0;i<y;i++) /*Atong gi print kung sakto ba ang mingsud sa array compo, si y atong reference ani nga loop*/
        {
        cout<<compo[i]<<" ";
        } 
     
     
        
     
    max=compo[0];    /*Kani nga algo para sa maximum number, so naa ni ninyo sa inyung notes, si array compo atong num sa inyung example sa maximum taw! */
    for (i=1;i<y-1;i++)
        {
        if (compo[i]>max)     
           {
           max=compo[i];
           } 
        }
        
        
        
    cout<<"\nThe Largest of the composite is: "<<max; /*Atong gisigurado kung sakto ba ang ming sud ni max maong gi print nato*/
    
    
    t=2; /*Last part is the Prime Factorization: Mao ni ang code sa Prime Factorization, try to analyze the algo. */
    cout<<"\nAnd its Prime Factorization are: ";
    for (;max!=0;)
        {
        if (max%t==0)
           {
           printf("%d ",t);
           max=max/t;
           
           if (max==1)
              {
              break;
              }
           }
        
        else
            {
            t++;
            }
        }
        
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
