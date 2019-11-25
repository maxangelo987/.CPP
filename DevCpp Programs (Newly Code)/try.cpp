#include <iostream>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct node
{
	string info;
	struct node *next;
}*start;

class list
{
	public:
		node *create_node(string);
		void ins_begin();
		void ins_last();
		void ins_pos();
		void delete_pos();
		void update();
		void display();
		void input();
		void process();
		list()
		{
			start=NULL;
		}	
	
};
int main(int argc, char** argv) {
	
	int choice;
	list sl;
	start=NULL;
	while (1)
		{
			cout<<"[1] Insert node at beginning"<<endl;
			cout<<"[2] Insert node at last"<<endl;
			cout<<"[3] Insert node at a given position"<<endl;
			cout<<"[4] Delete node"<<endl;
			cout<<"[5] Update node value"<<endl;
			cout<<"[6] Delete increasing element/s"<<endl;
			cout<<"[7] Terminate Program"<<endl;
			cout<<"Enter your choice: ";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"Inserting node at beginning"<<endl;
					sl.ins_begin();
					sl.display();
					cout<<endl;
					break;
				case 2:
					cout<<"Inserting node at last"<<endl;
					sl.ins_last();
					sl.display();
					cout<<endl;
					break;
				case 3:
					cout<<"Inserting node at the given position"<<endl;
					sl.ins_pos();
					sl.display();
					cout<<endl;
					break;
				case 4:
					cout<<"Deleting node"<<endl;
					sl.delete_pos();
					sl.display();
					break;
				case 5:
					cout<<"Updating node value"<<endl;
					sl.update();
					sl.display();
					cout<<endl;
					break;
				case 6:
					cout<<"Deleting increasing element"<<endl;
				//	sl.process();
					sl.display();
					cout<<endl;
					break;
				case 7:
					cout<<"Terminating program"<<endl;
					exit(1);
					break;
				default:
					cout<<"Invalid choice!"<<endl;
					cout<<"Try again."<<endl;
					break;
					
			}
			
		}
	return 0;
}

node *list::create_node(string word)
{
	struct node *temp;
	temp=new(struct node);
	if (temp==NULL)
	{
		cout<<"Memory not allocated"<<endl;
		return 0;
	}
	else
	{
		temp->info=word;
		temp->next=NULL;
		return temp;
	}
}

void list::ins_begin()
{
	string word;
	cout<<"Enter word to be inserted: ";
	cin>>word;
	struct node *temp,*s;
	temp=create_node(word);
	if (start==NULL)
	{
		start=temp;
		start->next=NULL;
	}
	else
	{
		s=start;
		start=temp;
		start->next=s;
	}
	cout<<"Word inserted at beginning."<<endl;
}

void list::ins_last()
{
	string word;
	cout<<"Enter word to be inserted: ";
	cin>>word;
	struct node *temp,*s;
	s=start;
	temp=create_node(word);
	if (start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	while (s->next!=NULL)
	{
		s=s->next;
	}
	temp->next=NULL;
	s->next=temp;
	cout<<"Word inserted at last"<<endl;
}

void list::ins_pos()
{
	 string word;
	 int counter=0,pos;
     cout<<"Enter the value to be inserted: ";
     cin>>word;
     cout<<"Enter the position at which node to be inserted: ";
     cin>>pos;
     struct node *temp,*s,*ptr;
     temp=create_node(word);
      
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
         for (int i=1;i<pos;i++)
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
        return;
    }       
}

void list::delete_pos()
{
	int counter=0,pos;
	struct node *s,*ptr;
	s=start;
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
         if (pos>1 && pos<=counter)
         {
                   s=start;
                   
                   for (int i=1;i<pos;i++)
                   {
                       ptr=s;
                       s=s->next;
                       }
                   ptr->next=s->next;
                   }
         else
    	 {
             cout<<"Position out of range!"<<endl;
             return;
         }
         
         cout<<"Word deleted."<<endl;
         free(s);  
         }
}

void list::update()
{
	int pos,counter=0;
	string word;
	
	if (start==NULL)
    {
    cout<<"List is Empty"<<endl;
    return;
    }     
 
 	cout<<"Enter the node position to be updated: ";
	cin>>pos;
	cout<<"Enter the new value: ";
	cin>>word;
	struct node *s;
	s=start;
 
 	if (pos==1)
    {
    start->info=word;
    }

  	else
    {
      for (int i=1;i<pos;i++)
      {
          if (s==NULL)
          {
             cout<<"There are less than"<<pos<<"elements";
             return;
          }
             
          s=s->next;
          
      }
          
      s->info=word;
    }  
    cout<<"Node Updated!"<<endl;
}

void list::display()
{
	
	struct node *temp;
	temp=start;
	if (start==NULL)
	{
		cout<<"There are no elements that could be displayed."<<endl;
	}
	cout<<"Elements: "<<endl;
	while (temp!=NULL)
	{
		cout<<temp->info<<"->";
		temp=temp->next;
		if (temp!=NULL)
		{
			cout<<"->";
		}
	}
	cout<<endl;
}

