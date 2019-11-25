#include <cstdlib>
#include <iostream>

using namespace std;

struct Node //Structure to represent a Node or Vertices of a Graph 
{ 
char data[10]; 
struct Node *next,*head; //Pointers to next node and Start 
struct Adjacent *adj; //Pointer to Adjacent node 
};
struct Adjacent //Structure to represent Adjacent node of a Graph 
{ 
char data; 
struct Node *next; 
struct Adjacent *adj; //Pointer for next Adjacent 
};
Node *New,*top; //Global Variables for New node and Pointer to Top void create() 
{ 
New = new Node; //Create a node 
New -> next = NULL; 
New -> adj = NULL; 
}
void CreateVertices(Node *&n,char *Item) //Function to Create a Vertices of a Graph { 
if(n == NULL) //if first node 
{ 
n = new Node; //Create a node 
strcpy(n -> data,Item); //Insert Data 
n -> next = NULL; 
n -> adj = NULL; 
n -> head = n; //Initialize head 
top = n; //Update top 
return; 
}
create(); //Create a node 
strcpy(New -> data,Item); //Insert Item 
top -> next = New; //Assign new node to next of top 
top = New; //Update top 
}
void LinkVertices(Node *&n) 
{ 
Adjacent *a,*ptr; 
int inputSize; 
char *inputString; 
cout << "\nHow many inputs? "; 
cin >> inputSize; 
inputString = new char[inputSize]; 
cout << "\nEnter Input Alphabets : "; 
for(int j = 0;j < inputSize;j++) 
cin >> inputString[j];
Node *temp = n -> head; 
while(temp != NULL) //Until last 
{ 
int flag = 0,i = 0; 
char ch[10]; 
do 
{ 
cout << "\nEnter Transition (" << temp -> data << ", " << inputString[i] << ") : "; 
cin >> ch; //Scan Adjacent 
a = new Adjacent; //Create an Adjacent 
a -> data = inputString[i++]; //Insert Data 
a -> adj = NULL; 
a -> next = NULL; 
if(flag == 0) //if first Adjacent 
{ 
temp -> adj = a; 
ptr = a; 
flag++; //Increase flag 
}
else 
{ 
ptr -> adj = a; 
ptr = a; 
}
Node *tmp = n -> head; 
while(tmp != NULL) 
{ 
if(strcmpi(tmp -> data,ch) == 0) 
a -> next = tmp; 
tmp = tmp -> next; 
}
}while(i < inputSize); 
temp = temp -> next; 
} 
}
char* CurrentState(Node *n,char *state, char input) 
{ 
Node *temp = n -> head, *tmp; 
Adjacent *a; 
char nextState[10] = ""; 
while(temp != NULL) 
{ 
if (strcmpi(temp -> data,state) == 0) 
{ 
a = temp -> adj; 
while(a != NULL) 
{ 
if (a -> data == input) 
{ 
tmp = a -> next; 
strcpy(nextState,tmp­ -> data); 
return nextState; 
} 
a = a -> adj; 
} 
} 
temp = temp -> next; 
} 
return nextState; 
}
char* Transition(Node *n,char *state, char *inputString) 
{ 
int len = strlen(inputString);­ 
int i = 0; 
char chrTemp; 
while(i < len) 
{ 
chrTemp = inputString[i++]; 
strcpy(state,Current­State(n,state,chrTem­p)); 
if (i != len) 
{ 
chrTemp = inputString[i++]; 
strcpy(state,Current­State(n,state,chrTem­p)); 
} 
} 
return state; 
}
void display(Node *n) 
{ 
if(n == NULL) 
{ 
cout << "Nothing to Display."; 
return; 
}
Node *temp = n, *tmp; 
Adjacent *a; 
while(temp != NULL) //Until Last 
{ 
cout << temp -> data << ' '; //Print first data 
a = temp -> adj; //go to adjacent node 
while(a != NULL) //Until last of adjacent 
{ 
tmp = a -> next; 
cout << tmp -> data << ' '; //print adjacent 
a = a -> adj; //goto next adjacent 
} 
cout << endl; 
temp = temp -> next; //goto next Node 
} 
}
int main() 
{ 
int m; 
char startState[10],final­State[10]; 
Node *nd = NULL; 
cout << "How Many States? "; //Number of Nodes on a Graph 
cin >> m;
cout << "\nState(s) Name : "; //Input the name of Vertices 
for(int i = 0;i < m;i++) 
{ 
char strBuf[15],strTemp[1­0]; 
strcpy(strBuf,"Q"); 
itoa(i,strTemp,10); 
strcat(strBuf, strTemp); 
strcat(strBuf, "\0"); 
if (i == 0) 
strcpy(startState,st­rBuf); 
CreateVertices(nd,st­rBuf); 
cout << strBuf << " "; 
}
cout << "\n\nEnter Final State : "; 
cin >> finalState;
LinkVertices(nd); 
cout << "\nThe Transition Table is\n"; 
cout << "-------------------­----\n"; 
display(nd); 
cout << endl; 
char inputString[50]; 
cout << endl << "Enter a String : "; 
cin >> inputString;
char State[10]; 
strcpy(State,Transit­ion(nd,startState,in­putString)); 
if (strcmpi(State,final­State) == 0) 
cout << "\nString Accepted"; 
else 
cout << "\nInvalid String"; 
getch(); 
return 0; 
}
