// (0000011001) Double Link List <CpE221/Mathematics>
// (class function)

#include <cstdlib>
#include <iostream>

using namespace std;


struct node
{
int info;
struct node *next;
struct node *prev;
}*start;

class double_list
{
      public:
             void create_list(int value);
             void add_begin(int value);
             void add_after(int value, int pos);
             void delete_element(int value);
             void search_element(int value);
             void display();
             void count();
             void reverse();

             struct node *s, *temp, *q;             
             
             double_list()
                        {
                        start=NULL;
                        }             
};

int main(int argc, char *argv[])
{
   double_list dl;
    int choice, element, pos;
    start=NULL;
    
    cout<<"                              DOUBLE LINKED LIST"<<endl;
    while(1)
            {
            cout<<"1. Create Node. "<<endl;
            cout<<"2. Add at beginning. "<<endl;
            cout<<"3. Add after position. "<<endl;
            cout<<"4. Delete. "<<endl;
            cout<<"5. Display. "<<endl;
            cout<<"6. Count. "<<endl;
            cout<<"7. Reverse. "<<endl;
            cout<<"8. Quit. "<<endl;
            
            cout<<"Enter your choice: ";        
            cin>>choice;
            
            switch(choice)
                          {
                          case 1:
                                 cout<<"Enter the element: "<<endl;
                                 cin>>element;
                                 cout<<endl;
                                 dl.create_list(element);           
                                 cout<<endl;
                                 break;
                          case 2:
                                 cout<<"Enter the element: "<<endl;
                                 cin>>element;
                                 cout<<endl;
                                 dl.add_begin(element);
                                 dl.display();
                                 cout<<endl;
                                 break;
                          case 3:
                                 cout<<"Inseting Node at a given position: "<<endl;
                                 cout<<endl;

                                 cout<<endl;
                                 break;
                                 
                          case 4:
                               cout<<"Delete a particular Node: "<<endl;
                               cout<<endl;

                               cout<<endl;
                               break;
                          
                          case 5:
                               cout<<"Update Node Value: "<<endl;
                               cout<<endl;

                               cout<<endl;
                               break;
                          
                          case 6:
                               cout<<"Search element in Link List: "<<endl;
                               cout<<endl;

                               cout<<endl;
                               break;
                          
                          case 7:
                               cout<<"Display elements of Link List: "<<endl;

                               cout<<endl;
                               break;
                          case 8:
                               exit(1);
                               cout<<endl;
                               break;
                          
                          default:
                               cout<<"Wrong Choice!"<<endl;
                               cout<<endl;
                               break;
                          }
            
            }
 

    system("PAUSE");
    return EXIT_SUCCESS;
}

void double_list::create_list(int value)
{

temp=new(struct node);
temp->info=value;
temp->next=NULL;

if (start==NULL)
   {
   temp->prev=NULL;
   start=temp;
   }

else
    {
    s=start;
    while (s->next!=NULL)
          {
          s=s->next;
          s->next=temp;
          temp->prev=s;      
          }
    }
}

void double_list::add_begin(int value)
{

if (start==NULL)
   {
   cout<<"First create the list! "<<endl;
   return;
   }

temp=new(struct node);

temp->prev=NULL;
temp->info=value;
temp->next=start;
start->prev=temp;
start=temp;

cout<<"Element inserted! "<<endl;
}

void double_list::display()
{

if (start=NULL)
   {
   cout<<"Nothing to display! "<<endl;
   return;
   }

q=start;

while (q!=NULL)
      {
      cout<<q->info<<"<->";
      q=q->next;
      }
cout<<"NULL"<<endl;
}
