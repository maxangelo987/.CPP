// (0000010101.0001) Complpete function Singly-List <CpE221/Mathematics>
// (class function)

#include <cstdlib>
#include <iostream>

using namespace std;
int choice, element, position,i;

struct node
{
 int info;
 struct node *next;
} *start;

class single_llist
{
      public:
             node* create_node(int);
             void insert_begin();
             void insert_last();
             void insert_pos();
             void display();
             void delete_pos();
             void update();
             void search();
             void front();
             void back();
             void current();
             void advance();
                          
             single_llist()
                           {
                           start=NULL;
                           }
             struct node *temp, *s, *ptr, *p,*s1;   
             int value,pos,counter;         
             int i,c;           
             bool flag;
};

int main(int argc, char *argv[])
{
    
    single_llist sl;
    start=NULL;
    
    cout<<"                              SINGLE LINKED LIST"<<endl;
    while(1)
            {
            cout<<"1. Insert Node at beginning. "<<endl;
            cout<<"2. Insert Node at last. "<<endl;
            cout<<"3. Insert Node at position. "<<endl;
            cout<<"4. Delete a particular node. "<<endl;
            cout<<"5. Update Node Value. "<<endl;
            cout<<"6. Search Element in Linked List. "<<endl;
            cout<<"7. Display elements of Link List. "<<endl;
            cout<<"8. Front. "<<endl;
            cout<<"9. Back. "<<endl;
            cout<<"10. Current. "<<endl;
            cout<<"11. Advance. "<<endl;
            cout<<"12. Exit. "<<endl;
            
            cout<<"Enter your choice: ";        
            cin>>choice;
            
            switch(choice)
                          {
                          case 1:
                                 cout<<"Inserting Node at beginning: "<<endl;
                                 cout<<endl;
                                 sl.insert_begin();
                                 sl.display();
                                 cout<<endl;
                                 break;
                          case 2:
                                 cout<<"Inserting Node at last: "<<endl;
                                 cout<<endl;
                                 sl.insert_last();
                                 sl.display();
                                 cout<<endl;
                                 break;
                          case 3:
                                 cout<<"Inseting Node at a given position: "<<endl;
                                 cout<<endl;
                                 sl.insert_pos();
                                 sl.display();
                                 cout<<endl;
                                 break;
                                 
                          case 4:
                               cout<<"Delete a particular Node: "<<endl;
                               cout<<endl;
                               sl.delete_pos();
                               sl.display();
                               cout<<endl;
                               break;
                          
                          case 5:
                               cout<<"Update Node Value: "<<endl;
                               cout<<endl;
                               sl.update();
                               cout<<endl;
                               break;
                          
                          case 6:
                               cout<<"Search element in Link List: "<<endl;
                               cout<<endl;
                               sl.search();
                               cout<<endl;
                               break;
                          
                          case 7:
                               cout<<"Display elements of Link List: "<<endl;
                               sl.display();
                               cout<<endl;
                               break;
                          case 8:
                               cout<<"Front: "<<endl<<endl;
                               sl.front();
                               cout<<endl;
                               sl.display();
                               break;
                          
                          case 9:
                               cout<<"Back: "<<endl<<endl;
                               sl.back();
                               sl.display();
                               cout<<endl;
                               break;
                               
                          case 10:
                               cout<<"Current: "<<endl<<endl;
                               sl.current();
                               sl.display();
                               cout<<endl;
                               break;
                          
                          case 11:
                               cout<<"Advance: "<<endl<<endl;
                               sl.advance();
                               sl.display();
                               cout<<endl;
                               break;
                                    
                          case 12:
                               cout<<"Exiting..."<<endl<<endl;
                               exit(1);
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


node *single_llist::create_node(int value) 
{
    
     temp=new(struct node);
     
     if (temp==NULL)
        {
        cout<<"Memory not allocated "<<endl;
        return 0;
        }
     
     else
         {
         temp->info=value;
         temp->next=NULL;
         return temp;
         }   
}


void single_llist::insert_begin()
{

     
cout<<"Enter the value to be inserted: ";
cin>>value; 
temp=create_node(value);    
pos=1;

if (start==NULL)
   {
   start=temp;
   start->next=NULL;
   }
     
else
    {
    p=start;
    start=temp;
    start->next=p;
    }
     
cout<<"Element inserted at the beginning. "<<endl;
}


void single_llist::insert_last()
{
pos=0;
cout<<"Enter the value to be inserted: ";
cin>>value; 
temp=create_node(value);    
s=start;

if (start==NULL)
   {
   cout<<"Error you can't insert last if the Link is empty."<<endl;
   return;
   }
   
while(s->next!=NULL)
                    {
                    s=s->next;
                    }



temp->next=NULL;
s->next=temp;
cout<<"Element Inserted at last."<<endl;

s=start;
while (s!=NULL)
      {
      pos++;
      s=s->next;
      }
}

void single_llist::insert_pos()
{

     counter=0;
     cout<<"Enter the value to be inserted: ";
     cin>>value;
     cout<<"Enter the position at which node to be inserted: ";
     cin>>pos;
     temp=create_node(value);
      
     s=start;
     while(s!=NULL)
                   {
                   s=s->next;
                   counter++;
                   }

     if (pos==1)
        {
        if (start==NULL)
           {
           start=temp;
           start->next=NULL;
           }  
        else
           {
           ptr=start;
           start=temp;
           start->next=ptr;
           } 
        }              
    
    else if (pos>1 && pos<=counter)
         {
         s=start;
         for (i=1;i<pos;i++)
             {
             ptr=s;
             s=s->next;
             }
         
         ptr->next=temp;
         temp->next=s;
         }  
    
    else
        {
        cout<<"Position out of range!"<<endl;
        }       
}


void single_llist::display()
{


 if (start==NULL)
    {
    cout<<"The list is Empty! "<<endl;
    return;
    }
    
    temp=start;
    cout<<"Elements of list are: "<<endl;
    while (temp!=NULL)
          {
          cout<<temp->info<<"->";
          temp=temp->next;
          }
   cout<<"NULL"<<endl;       
}


void single_llist::delete_pos()
{
     counter=0;
     if (start==NULL)
        {
        cout<<"List is Empty!"<<endl;
        return;
        }
        
        
     cout<<"Enter the position of value to be deleted: ";
     cin>>pos;


     s=start;
     if (pos==1)    
        {
        start=s->next;
        cout<<"Element at position "<<pos<<" deleted."<<endl;
        }
     
     else
         {
         while(s!=NULL)
                  {
                  s=s->next;
                  counter++;
                  }         
         if (pos>0 && pos<=counter)
                   {
                   s=start;
                   
                   for (i=1;i<pos;i++)
                       {
                       ptr=s;
                       s=s->next;
                       }
                   ptr->next=s->next;
                   }
         else
             {
             cout<<"Position out of range!"<<endl;
             }
         
         cout<<"Element at position "<<pos<<" deleted."<<endl;
         free(s);  
         }
}

void single_llist::update()
{
 if (start==NULL)
    {
    cout<<"List is Empty"<<endl;
    return;
    }     
 
 cout<<"Enter the node position to be updated: ";
 cin>>pos;
 cout<<"Enter the new value: ";
 cin>>value;
 
 s=start;
 
 if (pos==1)
    {
    start->info=value;
    }

  else
      {
      for (i=1;i<pos;i++)
          {
          if (s==NULL)
             {
             cout<<"There are less than"<<pos<<"elements";
             return;
             }
             
          s=s->next;
          
          }
          
      s->info=value;
      }  
      cout<<"Node Updated!"<<endl;
}

void single_llist::search()
{
flag=false;

if (start==NULL)
   {
   cout<<"List is empty!"<<endl;
   return;
   }
   
   
cout<<"Enter the value to be searched: ";
cin>>value;
s=start;

while (s!=NULL)
      {
      pos++;
      if (s->info==value)
          {
         flag=true;
         cout<<"Element "<<value<<" found at position "<<pos<<endl;
         }
      s=s->next;
      }

if (!flag)
   {
   cout<<"Element "<<value<<" not found in the list"<<endl;
   }

}

void single_llist::front()
{

if (start==NULL)
   {
   cout<<"Lis is empty! "<<endl;
   return;
   }

cout<<"The Front Number is "<<start->info<<".";

}


void single_llist::back()
{

if (start==NULL)
   {
   cout<<"Lis is empty! "<<endl;
   return;
   }

temp=start;

while (temp->next!=NULL)
      {
      temp=temp->next;
      }
cout<<"The Back Number is "<<temp->info<<endl;


}


void single_llist::current()
{

if (start==NULL)
   {
   cout<<"List is Empty! "<<endl;
   return;
   }

cout<<"The Current Number is "<<value<<"."<<endl;
}


void single_llist::advance()
{

counter=0;
if (start==NULL)
   {
   cout<<"List is Empty! "<<endl;
   return;
   }

s=start;
while(s!=NULL)
                  {
                  s=s->next;
                  counter++;
                  }         

temp=start;
             if ((pos==1)&&(counter>1))
                {
                temp=temp->next;
                cout<<temp->info;
                return;
                }   
             
             else if ((pos>1)&&(counter!=pos))
                  {
                  temp=start;

                  for (i=0;i<pos;i++)
                        {
                        temp=temp->next;
                        }
                  cout<<temp->info<<endl;                       
                  
                  }
                  
             else
                 {
                 cout<<"Hey! There's no advance number here! "<<endl;
                 return;
                 }
}
