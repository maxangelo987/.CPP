#include <iostream>
#include <cstring>
#include<stdlib.h>
#include <cstdlib>
#include<graphics.h>
using namespace std;

	int i,j,k,a;
	int size,inv,terms,cntr,caps,equals,lc10,lc20;
	char str[100],lstr[100][100],rstr[1][100],lc1[100],lc2[100];

	void refresh();
	void getinput();
	void trash();
	void parentname();
	void childname();
	void encryptname();
	void out();
	void dfa();
int main(int argc, char** argv) {
	
	refresh();
	getinput();
	trash();
	parentname();
	encryptname();
	childname();
	out();
	return 0;
}
void refresh(){
	size=0;
	inv=0;
	terms=0;
	caps=0;
	cntr=0;
	equals=0;
	lc10=0;
	lc20=0;
}
void getinput(){
	gets(str);
	size=strlen(str);
}
void trash(){
	if((str[0]<'A'||str[0]>'Z')||(str[size-1]!='$')){
		inv++;	
	}
	for(i=0;i<size;i++){
		if((str[i]!='+'&&str[i]!='='&&str[i]!='$')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')){
			inv++;
		}
		if(str[i]=='='){
			equals++;
			if(equals==1){
				cntr=i;
				if(str[i+1]!='A'&&str[i+1]!='O'){
					inv++;
				}
			}
		}
	}
	if(equals!=1){
		inv++;
	}
	cout<<endl;
}
void parentname(){
	i=0;
	k=0;
	a=0;
	for(j=0;j<=cntr;j++){
		if((str[j]>='a'&&str[j]<='z')||(str[j]>='A'&&str[j]<='Z')){
			lstr[i][k]=str[j];
			k++;
			if(str[j]>='A'&&str[j]<='Z'){
				caps++;
				if(str[j]=='A'||str[j]=='O'){
					inv++;
				}
			}
			if(str[j]>='a'&&str[j]<='z'){
				if((str[j]>='p'&&str[j]<='z')||(str[j]=='n')){
					lc20++;
				}
				if(str[j]>='b'&&str[j]<='m'){
					lc1[a]=str[j];
					a++;
				}
			}
		}
		if(str[j]=='+'||str[j]=='='){
			if(caps!=1){
				inv++;
			}
			if(str[j-1]!='a'&&str[j-1]!='o'){
				inv++;
			}
			if(str[j+1]<'A'||str[j+1]>'Z'){
				inv++;
			}
			if(lc20>0){
				inv++;
			}
			k=0;
			caps=0;
			i++;
		}
		if(str[j]=='='){
			j=size;
		}
	}
	terms=i;	
}
void encryptname(){
	for(i=0;i<=a;i++){
		if(lc1[i]=='b'){
			lc2[i]='n';
		}
		else{
			lc2[i]=lc1[i]+13;
		}
	}
}
void childname(){
	k=0;
	for(j=cntr+2;j<size;j++){
		if(str[j]>='a'&&str[j]<='z'){
			if((str[j]>='a'&&str[j]<='m')||(str[j]=='o')){
				inv++;
			}
			else{
				rstr[0][k]=str[j];
				k++;
				lc10=0;
				for(i=0;i<=a;i++){
					if(lc2[i]==str[j]){
						lc10++;
					}
				}
				if(lc10==0){
					inv++;
				}
			}
		}
		if(str[j]>='A'&&str[j]<='Z'){
			inv++;
		}		
	}
	
}
void out(){
	if(inv>0){
		cout<<"Invalid Input";
	}
	else{
		dfa();
	}
}
void dfa(){  
	initwindow(1250, 680, "First Sample");
	int gd=DETECT,gm;
	int points0[]={123,150,118,145,118,155,123,150};
	int points1[]={260,150,255,145,255,155,260,150};
	int points2[]={399,150,394,145,394,155,399,150};
	int points3[]={449,150,454,145,454,155,449,150};
	int points4[]={672,150,667,145,667,155,672,150};
	int points5[]={809,150,804,145,804,155,809,150};
	int points6[]={946,150,941,145,941,155,946,150};
	int points7[]={1073,150,1068,145,1068,155,1073,150};
	int points8[]={286,124,281,119,291,119,286,124};
	int points9[]={424,124,419,119,429,119,424,124};
	int points10[]={560,56,555,61,565,61,560,56};
	int points11[]={834,124,829,119,839,119,834,124};
	int points12[]={971,124,966,119,976,119,971,124};
	int points13[]={1083,270,1078,265,1078,275,1083,270};
	int points14[]={1108,245,1103,240,1113,240,1108,245};
	int points15[]={540,134,533,134,540,127,540,134};
	int sq1[]={520,300,520,630,1092,630,1092,300,520,300};

 	settextstyle(SANS_SERIF_FONT,LEFT_TEXT,1);
 	
	setcolor(1);
    outtextxy(138,140, "q1");
    circle(149, 150, 20);
    circle(149, 150, 21);
    circle(149, 150, 22);
    circle(149, 150, 23);
    circle(149, 150, 24);
	setcolor(14);
    line(174,150,255,150);
  	drawpoly(4,points1);
	line(149,175,149,270);
	line(149,270,1078,270);
   	drawpoly(4,points13);
	line(36,150,118,150);
	drawpoly(4,points0);
    
	setcolor(1);
    outtextxy(275,140, "q2");
    circle(286, 150, 20);
    circle(286, 150, 21);
    circle(286, 150, 22);
    circle(286, 150, 23);
    circle(286, 150, 24);
	setcolor(14);
    line(311,150,394,150);
  	drawpoly(4,points2);
	line(286,175,286,270);
	arc(271,118,20,255,16);
  	drawpoly(4,points8);
	
	setcolor(1);
    outtextxy(413,140, "q3");
    circle(424, 150, 20);
    circle(424, 150, 21);
    circle(424, 150, 22);
    circle(424, 150, 23);
    circle(424, 150, 24);
	setcolor(14);
    line(454,150,535,150);
  	drawpoly(4,points3);
	line(424,175,424,270);
	arc(408,118,350,255,16);
  	drawpoly(4,points9);

	setcolor(1);
    outtextxy(549,140, "q4");
    circle(560, 150, 20);
    circle(560, 150, 21);
    circle(560, 150, 22);
    circle(560, 150, 23);
    circle(560, 150, 24);
	setcolor(14);
    line(585,150,668,150);
  	drawpoly(4,points4);
	arc(545,118,20,240,16);
	arc(490,148,22,163,50);
	drawpoly(4,points15);
	line(560,125,560,60);
  	drawpoly(4,points10);
	line(560,175,560,270);

	setcolor(1);
    outtextxy(549,20, "q5");
    circle(560, 30, 20);
    circle(560, 30, 21);
    circle(560, 30, 22);
    circle(560, 30, 23);
    circle(560, 30, 24);
	setcolor(14);
    line(585,30,1108,30);
    line(1108,30,1108,90);
	arc(1108,150,90,270,60);
	line(535,30,326,30);
	arc(327,70,90,180,40);
	line(286,120,286,67);

	setcolor(1);
    outtextxy(686,140, "q6");
    circle(697, 150, 20);
    circle(697, 150, 21);
    circle(697, 150, 22);
    circle(697, 150, 23);
    circle(697, 150, 24);
	setcolor(14);
    line(722,150,805,150);
  	drawpoly(4,points5);
	line(697,175,697,270);

	setcolor(1);
    outtextxy(823,140, "q7");
    circle(834, 150, 20);
    circle(834, 150, 21);
    circle(834, 150, 22);
    circle(834, 150, 23);
    circle(834, 150, 24);
	setcolor(14);
    line(859,150,942,150);
   	drawpoly(4,points6);
	line(834,175,834,270);
	arc(818,118,350,255,16);
   	drawpoly(4,points11);

	setcolor(1);
    outtextxy(960,140, "q8");
    circle(971, 150, 20);
    circle(971, 150, 21);
    circle(971, 150, 22);
    circle(971, 150, 23);
    circle(971, 150, 24);
	setcolor(14);
    line(996,150,1069,150);
  	drawpoly(4,points7);
	line(971,175,971,270);
	arc(955,118,350,255,16);
   	drawpoly(4,points12);

	setcolor(2);
    outtextxy(1097,140, "q9");
    circle(1108, 150, 20);
    circle(1108, 150, 21);
    circle(1108, 150, 22);
    circle(1108, 150, 23);
    circle(1108, 150, 24);
    circle(1108, 150, 30);
    circle(1108, 150, 31);
    circle(1108, 150, 32);
    circle(1108, 150, 33);
    circle(1108, 150, 34);
	setcolor(14);
    line(1108,185,1108,240);
    drawpoly(4,points14);
     
	setcolor(4);
    outtextxy(1091,258, "q10");
    circle(1108, 270, 20);
    circle(1108, 270, 21);
    circle(1108, 270, 22);
    circle(1108, 270, 23);
    circle(1108, 270, 24);

	setcolor(15);
 	settextstyle(DEFAULT_FONT,LEFT_TEXT,1);
	outtextxy(200,135,"UC");
	outtextxy(256,90,"UC");
	outtextxy(424,15,"UC");
	outtextxy(338,135,"LC1");
	outtextxy(382,90,"LC1");
	outtextxy(486,135,"LC1");
	outtextxy(476,85,"o,a");
	outtextxy(525,85,"o,a");
	outtextxy(570,85,"+");
	outtextxy(620,135,"=");
	outtextxy(750,135,"O,A");
	outtextxy(800,90,"O,A");
	outtextxy(885,135,"LC2");
	outtextxy(931,90,"LC2");
	outtextxy(1025,135,"$");
	outtextxy(169,200,"NOT UC");
	outtextxy(306,200,"NOT LC1");
	outtextxy(311,210,"ALL UC");
	outtextxy(444,200,"NOT o,a");
	outtextxy(580,200,"NOT =");
	outtextxy(717,200,"NOT O,A");
	outtextxy(854,200,"NOT LC2");
	outtextxy(859,210,"ALL O,A");
	outtextxy(991,200,"NOT $");
	outtextxy(996,210,"NOT LC2");
	outtextxy(1128,200,"ALL");
	outtextxy(1133,210,"ELEMENTS");
	outtextxy(810,15,"NOT UC");
	
 	outtextxy(169,315,"DFA"); 	

 	settextstyle(SANS_SERIF_FONT,LEFT_TEXT,3);
 	outtextxy(149,300,"M");
 	outtextxy(199,300,":");
 	settextstyle(SANS_SERIF_FONT,LEFT_TEXT,1);
	outtextxy(525,305,"Q        UC1    LC1   LC2      o        a        O        A        +        =        $");
	outtextxy(530,335," q1      q2      q10    q10    q10    q10     q10    q10    q10    q10    q10");
	outtextxy(530,365," q2      q10     q3     q10    q10    q10     q10    q10    q10    q10    q10");
	outtextxy(530,395," q3      q10     q3     q10     q4      q4      q10    q10    q10    q10    q10");
	outtextxy(530,425," q4      q10    q10    q10    q10    q10     q10    q10     q5      q6     q10");
	outtextxy(530,455," q5      q2      q10    q10    q10    q10     q10    q10    q10    q10    q10");
	outtextxy(530,485," q6      q10    q10    q10    q10    q10      q7      q7     q10    q10    q10");
	outtextxy(530,515," q7      q10    q10     q8     q10    q10     q10    q10    q10    q10    q10");
	outtextxy(530,545," q8      q10    q10     q8     q10    q10     q10    q10    q10    q10     q9");
	outtextxy(530,575," q9      q10    q10    q10    q10    q10     q10    q10    q10    q10    q10");
	outtextxy(530,605,"q10     q10    q10    q10    q10    q10     q10    q10    q10    q10    q10");

	outtextxy(520,275,"TRANSITION TABLE");
	outtextxy(100,30,"STATE DIAGRAM");
	
	outtextxy(195,330,"Q:    q1,q2,q3,q4,q5,q6,q7,q8,q9,q10"); 	
	outtextxy(195,355,"E:    a,b,c,d,e,f,g,h,i,j,k,l,m"); 	
	outtextxy(195,380,"        n,o,p,q,r,s,t,u,v,w,x,y,z"); 	
	outtextxy(195,405,"        A,B,C,D,E,F,G,H,I,J,K,L,M"); 	
	outtextxy(195,430,"        N,O,P,Q,R,S,T,U,V,W,X,Y,Z"); 		
	outtextxy(195,455,"        +,=,$"); 	
	outtextxy(180,480,"Q0:    q1"); 	
	outtextxy(177,505,"QF:    q9");
	outtextxy(177,530,"QD:    q10");

	drawpoly(5,sq1);
	line(520,300,572,330); 
	line(567,304,557,304);
	line(557,304,567,310);
	line(557,315,567,310);
	line(567,315,557,315);
	
	line(572,300,572,630);	
	line(624,300,624,630);	
	line(676,300,676,630);	
	line(728,300,728,630);	
	line(780,300,780,630);	
	line(832,300,832,630);	
	line(884,300,884,630);	
	line(936,300,936,630);	
	line(988,300,988,630);	
	line(1040,300,1040,630);	

	line(520,330,1092,330);	
	line(520,360,1092,360);	
	line(520,390,1092,390);	
	line(520,420,1092,420);	
	line(520,450,1092,450);	
	line(520,480,1092,480);	
	line(520,510,1092,510);	
	line(520,540,1092,540);	
	line(520,570,1092,570);	
	line(520,600,1092,600);	
	
	getch();	
 }
