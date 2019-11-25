#include <iostream>
#include <cstring>
#include<stdlib.h>
#include <cstdlib>

using namespace std;

	char str[100],leftstr[1][100],rightstr[1][100],hier[1][100],var[100];
	char choice[1],str2[100],cons[100][100],var2[100],exp[100];
	int a,b,c,d,e,i,j,k,v,x,size,lsize,rsize;
	int in,in0,in1,error;
	int oper,soper,soper0;
	int openp,closep;

	void getequation();
	void leftside();
	void rightside();
	void constantonly();
	void doubleoperation();
	void doublevariable();
	void operationborder();
	void constantvariable();
	void parenthesis();
	void hierarchy();
	void trash();
	void validity();
	void refresh();
	void parse();
	
	struct NODE{
		char Info[100];
		struct NODE *Left_Child;
		struct NODE *Right_Child;
	}*start;

	struct NODE *create_node(char []);
	int separation(char [],char [][50]);
	int search_root(char [][50],int);
	void bnf(char []);
	void bnf_out();	
	void Binary_Tree(char [][50],int,int);
	void Output(struct NODE *,int);
	void In_order(struct NODE *);


int main(int argc, char** argv) {
			cout<<"Enter an equation: ";
			getequation();
			leftside();
			rightside();
			doubleoperation();
			doublevariable();
			operationborder();
			constantvariable();
			constantonly();
			parenthesis();
			hierarchy();
			trash();	
			validity();
			return 0;
}
void getequation(){
	gets(str);
	size=strlen(str);
	cout<<endl;
}
void leftside(){
	a=0;
	b=0;
	for(i=0;i!=size;i++){
		if(str[a]!='='){
			leftstr[0][a]=str[a];
			if(str[a]>='a'&&str[a]<='z'){
				var[b]=str[a];
				b++;
			}
			a++;
		}
	}
	j=b;
	k=1;
	for(d=0;d<b;d++){
		for(i=k;i<b;i++){
			if(var[d]==var[i]){
				j--;
			}
		}
		k++;
	}
	if(j>3){
		error++;
		cout<<"1 Error(s) - Variable exceeded the limit of 3"<<endl;
	}
	lsize=a;
	if(a==0){
		in++;
		cout<<"1 Error(s) - Left side is empty"<<endl;
	}
	error=error+in;
	in=0;
}
void rightside(){
	b=0;
	a=a+1;
	for(i=a;i<size;i++){
		if((str[a]!='=' && str[a]!='\0')&&(str[a]>='0'&&str[a]<='9')){
			rightstr[0][b]=str[a];
		b++;
		}
		else{
			in++;
		}
		a++;
	}
	if(in>0){
		cout<<in<<" Error(s) - Right side must only contain a constant"<<endl;	
	}
	error=error+in;
	in=0;
	if(b==0){
		in++;
		cout<<"1 Error(s) - Right side is empty"<<endl;
	}
	error=error+in;
	in=0;
	rsize=b;
}
void constantonly(){
	j=0;
	in0=0;
	for(i=0;i<lsize;i++){
		if(str[j]>='0' && str[j]<='9'){
			j++;
			if(str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/'||str[j]=='='||str[j]==')'){
				in++;
				for(x=j;x>=0;x--){
					if(str[x]=='('){
						in0++;
						x=0;
					}
				}
			}
			j--;
		}
		j++;		
	}
	in=in-in0-in1;
	if(in>0){
		cout<<in<<" Error(s) - Left side contains constant not enclosed in a parenthesis"<<endl;	
	}
	error=error+in;
	in=0;
}
void doubleoperation(){
	j=0;
	for(i=0;i<size;i++){	
		if(str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/'){
			oper++;
			if(str[j+1]=='+'||str[j+1]=='-'||str[j+1]=='*'||str[j+1]=='/'){	
				in++;
			}
		}
		j++;
	}
	if(in>0){
		cout<<in<<" Error(s) - Operation followed by an operation"<<endl;	
	}
	error=error+in;
	in=0;
}
void doublevariable(){
	j=0;
	for(i=0;i<size;i++){
		if((str[j]>='a' && str[j]<='z') && (str[j+1]>='a' && str[j+1]<='z')){
			in++;
		}
		j++;
	}
	if(in>0){
		cout<<in<<" Error(s) - Variable followed by a variable"<<endl;	
	}
	error=error+in;
	in=0;
}
void operationborder(){
	if(str[0]=='+'||str[0]=='-'||str[0]=='*'||str[0]=='/'||str[0]=='='||str[0]==')'){
		in++;
	}
	if(in>0){
		cout<<in<<" Error(s) - An operation is found at the beginning of the equation"<<endl;	
	}
	error=error+in;
	in=0;		
	if(str[lsize-1]=='+'||str[lsize-1]=='-'||str[lsize-1]=='*'||str[lsize-1]=='/'||str[lsize-1]=='('){
		in++;
	}
	if(in>0){
		cout<<in<<" Error(s) - An operation is found at the end of left side of the equation"<<endl;	
	}
	error=error+in;
	in=0;
}
void constantvariable(){
	j=0;
	for(i=0;i<size;i++){
		if((str[j]>='a' && str[j]<='z')&&(str[j+1]>='0' && str[j+1]<='9')){
			in++;
		}
		j++;
	}
	if(in>0){
		cout<<in<<" Error(s) - Incorrect placement of coefficient and variable"<<endl;	
	}
	in1=in;
	error=error+in;
	in=0;
}
void parenthesis(){
	j=0;
	for(i=0;i<lsize;i++){
		if(str[j]=='('){
			openp++;
			if( openp>0 && str[j+1]=='('){
				in++;
			}
			if(str[j+1]=='+'||str[j+1]=='-'||str[j+1]=='*'||str[j+1]=='/'){
				in++;
			}
			if((str[j-1]>='0'&&str[j-1]<='9')||(str[j-1]>='a'&&str[j-1]<='z')){
				in++;
			}
		}
		if((openp>0)&&(openp>closep)&&
		   (str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/')&&str[j+1]!='('){
			oper--;	
			soper++;
			soper0++;
		}
		if(str[j]==')'){
			closep++;
			if(closep>0 && str[j+1]==')'){
				in++;
			}
			if(str[j-1]=='+'||str[j-1]=='-'||str[j-1]=='*'||str[j-1]=='/'||str[j-1]=='('||str[j+1]=='('){
				in++;
			}
			if((str[j+1]>='0'&&str[j+1]<='9')||(str[j+1]>='a'&&str[j+1]<='z')){
				in++;
			}
			if(openp==closep && openp>0){
				if(soper0==0){
					in++;
				}
			}
			if(openp>closep){
				in++;
			}
		}
		j++;
	}
	if(openp!=closep || soper<in0){	
		in++;
	}
	if(soper>openp){
		in++;
	}
	if(in>0){
	cout<<in<<" Error(s) - Parenthesis"<<endl;	
	}
	error=error+in;
	in=0;
}
void hierarchy(){
	j=0;
	a=0;
	for(i=0;i<=lsize;i++){
		if(str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/'||str[j]=='='||str[j]=='('||str[j]==')'||str[j]=='='){
			hier[0][a]=str[j];
			if(a>0){
				if(((hier[0][a-1]=='+'||hier[0][a-1]=='-')&&(hier[0][a]=='*'||hier[0][a]=='/'))||
				  ((hier[0][a-1]=='*'||hier[0][a-1]=='/')&&(hier[0][a]=='+'||hier[0][a]=='-'))){
			  		in++;
				}
			}
			a++;	
		}
		j++;
	}
	if(in>0){
		cout<<in<<" Error(s) - Hierarchy of operations"<<endl;	
	}
	error=error+in;
	in=0;
	i=0;
	j=0;
	for(i=0;i<lsize;i++){
		if(hier[0][i]=='('&&(hier[0][i-1]=='+'||hier[0][i-1]=='-')){
						if(hier[0][i+1]=='+'||hier[0][i+1]=='-'||hier[0][i+1]=='*'||hier[0][i+1]=='/'){
							if(hier[0][i+2]==')'){
								if(hier[0][i+3]=='+'||hier[0][i+3]=='-'||hier[0][i+3]=='='){
									x=lsize+1;
								}
								else{
									in++;
								}
							}
						}
		}
		if(hier[0][i]=='('&&(hier[0][i-1]=='*'||hier[0][i-1]=='/')){
						if(hier[0][i+1]=='+'||hier[0][i+1]=='-'||hier[0][i+1]=='*'||hier[0][i+1]=='/'){
							if(hier[0][i+2]==')'){
								if(hier[0][i+3]=='*'||hier[0][i+3]=='/'||hier[0][i+3]=='='){
									x=lsize+1;
								}
								else{
									in++;
								}
							}
						}
		}
	}
	if(in>0){
		cout<<in<<" Error(s) - Hierarchy of operations"<<endl;	
	}
	error=error+in;
	in=0;
}
void trash(){
	j=0;
	for(i=0;i<size;i++){
		if(str[j]!='+'&&str[j]!='-'&&str[j]!='*'&&str[j]!='/'&&str[j]!='='&&str[j]!='('&&str[j]!=')'&&
		  ((str[j]<'0'||str[j]>'9')&&(str[j]<'a'||str[j]>'z'))){
			in++;
		}
		j++;
	}
	if(in>0){
		cout<<in<<" Error(s) - Trash is found in the equation"<<endl;	
	}
	error=error+in;
	in=0;
}
void validity(){
	if(oper>2||oper<0){
		cout<<"Error - Operation must not exceed to the limit of 2"<<endl;
		error++;
		cout<<endl<<"Total errors - "<<error<<'\n'<<"Your input is an invalid equation"<<endl;
	}
	else if(error>0||in1>0){
		cout<<endl<<"Total errors - "<<error<<'\n'<<"Your input is an invalid equation"<<endl;
	}
	else{
	cout<<"Your input is a valid equation"<<endl;
	parse();
	cout<<endl;
	}	
}
void refresh(){
	size=0;
	rsize=0;
	lsize=0;
	oper=0;
	in=0;
	in0=0;
	openp=0;
	closep=0;
	soper=0;
	soper0=0;
	error=0;
	in1=0;
	c=0;
	e=0;
	v=0;
}
struct NODE *create_node(char str[]){
    struct NODE *temp, *s;
	temp = (struct NODE*)malloc(sizeof(struct NODE));
        strcpy(temp->Info,str);
        temp->Right_Child = NULL;
		temp->Left_Child = NULL; 
        return temp;
}
void parse(){
	int a,root;
	char List[50][50];
	cout<<endl<<"P A R S E     T R E E"<<endl;
	a = separation(str,List);
	root = search_root(List,a);
	Binary_Tree(List,a,root);
	Output(start,1);
	cout<<endl<<endl;
	In_order(start);
	cout<<endl<<endl<<"B A C K U S     N O R M     F O R M"<<endl<<endl;
	cout<<str2<<endl;
	bnf_out();
}
void Output(struct NODE *T,int Level){
	int i;
	if(T){
		Output(T->Right_Child, Level+1);
		cout<<"\n";
		for(int i=0;i<Level;i++){
			cout<<"   ";
		}
		cout<<T->Info;
		Output(T->Left_Child,Level+1);
	}
}
void In_order(struct NODE *Node){
	if(Node){
		In_order(Node->Left_Child);
		cout<<" "<<Node->Info;
		bnf(Node->Info);
		In_order(Node->Right_Child);
	}
}
int separation(char str[],char str1[][50]){
	int length=strlen(str),b=0,c=0;
	for(int i=0;i<length;i++){
		if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
			if((str[i+1]>='0'&&str[i+1]<='9')||(str[i+1]>='a'&&str[i+1]<='z')||(str[i+1]>='A'&&str[i+1]<='Z')){
				str1[b][c]=str[i];
				c++;				
			}
			else{
				str1[b][c]=str[i];
				c++;
				str1[b][c]='\0';
				b++;
				c=0;
			}
		}
		else if((str[i]>='a'&&str[i]<='z')||(str[i]=='A'&&str[i]=='Z')){
			str1[b][c]=str[i];
			c++;
			str1[b][c]='\0';
			b++;
			c=0;
		}
		else{
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='='||str[i]=='('||str[i]==')'){
				str1[b][c]=str[i];
				c++;
				str1[b][c]='\0';
				b++;
				c=0;
			}
		}
	}
	str1[b][c]='\0';
	b++;
	return b;
}

int search_root(char str[][50],int a){
	int count,c,b;
	if(str[2][0]=='('||str[6][0]=='('){
		if(str[2][0]=='('){
			return 4;
		}
		if(str[6][0]=='('){
			return 8;
		}
	}
	else{
		count=0;
		for(int i=0;i<a;i++){
			if(str[i][0]=='('){
				b=i;
				count++;
				break;
			}
		}
		if(count==0){
			for(int j=0;j<a;j++){
				if(str[j][0]=='+'||str[j][0]=='-'||str[j][0]=='*'||str[j][0]=='/'){
					return j;
				}
			}
			return 0;
		}
		else{
			for(int j=b;j<a;j++){
				if(str[j][0]=='+'||str[j][0]=='-'||str[j][0]=='*'||str[j][0]=='/'){
					return j;
				}
			}
		}
	}
}
void Binary_Tree(char List[][50],int a,int root){
	int b,count=0,c;
	char str[100];
	struct NODE *temp,*s,*prev,*r;
	start = (struct NODE*)malloc(sizeof(struct NODE));
	temp = (struct NODE*)malloc(sizeof(struct NODE));
	start = NULL;
	s = create_node(List[root]);
	prev = NULL;
	for(int i=0;i<root;i++){
		if((List[i][0]!='(')&&(List[i][0]!=')')){
			count++;
			temp = create_node(List[i]);
			if(List[i+1][0]==')'){
				prev->Right_Child = temp;
			}
			else{
				if(count==1){
					prev = temp;
				}
				else{
					temp->Left_Child = prev;
					prev = temp;
				}				
			}
		}
	}
	s->Left_Child = prev;
	for(int i=0;i<a;i++){
		if(List[i][0]=='='){
			c = i;
		}
	}
	prev = NULL;
	count=0;
	for(int i=c-1;i>root;i--){
		if((List[i][0]!='(')&&(List[i][0]!=')')){
			count++;
			temp = create_node(List[i]);
			if(List[i-1][0]=='('){
				prev->Left_Child = temp;
			}
			else{
				if(count==1){
					prev = temp;
				}
				else{
					temp->Right_Child = prev;
					prev = temp;
				}				
			}
		}		
	}
	s->Right_Child = prev;
	start = create_node(List[c]);
	start->Left_Child = s;
	r = create_node(List[c+1]);
	start->Right_Child = r;
}
void bnf(char str[]){
	int count,a=0;
	char str3[50];
	for(int i=0;i<strlen(str);i++){
		if(str[i]>='0'&&str[i]<='9'){
			if((str[i+1]>='a'&&str[i+1]<='z')||(str[i+1]>='A'&&str[i+1]<='Z')||(str[i+1]=='\0')){
				strcat(str2,"<cons>");
				str3[a]=str[i];
				a++;
				str3[a]='\0';
				count=0;
				for(int j=0;j<v;j++){
					if(strcmp(cons[j],str3)==0){
						count++;
					}
				}
				if(count==0){
					strcpy(cons[c],str3);
					c++;
				}
			}
			else{
				str3[a] = str[i];
				a++;
			}
		}
		if(str[i]>='a'&&str[i]<='z'){
			strcat(str2,"<var>");
			count=0;
			for(int j=0;j<v;j++){
				if(str[i]==var2[j]){
					count++;
				}
			}
			if(count==0){
				var2[v] = str[i];
				v++;
			}
		}
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='='){
			strcat(str2,"<exp>");	
			count=0;
			for(int j=0;j<e;j++){
				if(str[i]==exp[j]){
					count++;
				}
			}
			if(count==0){
				exp[e] = str[i];
				e++;
			}
		}
	}
}
void bnf_out(){
	cout<<"\n <constant>:: ";
	for(int i=0;i<c;i++){
		cout<<" | "<<cons[i]<<" | ";
	}
	cout<<"\n <variable>:: ";
	for(int i=0;i<v;i++){
		cout<<" | "<<var2[i]<<" | ";
	}
	cout<<"\n <expression>:: ";
	for(int i=0;i<e;i++){
		cout<<" | "<<exp[i]<<" | ";
	}
}
