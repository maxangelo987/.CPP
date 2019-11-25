#include <iostream>
#include <cstring>
#include<stdlib.h>
#include <cstdlib>
#include<graphics.h>
#include<string.h>

using namespace std;

void input();
void dfa();

int main(int argc, char** argv) {
	input();
	return 0;
}

void input()
{
	cout<<"L={A program that will accept numbers,letters,and selected characters.  ";
	cout<<"Your input will be valid if all kinds of the number system are ";
	cout<<"present and must follow the pattern (binaryB-octalO*decimalD_hexaH)  ";
	cout<<"Once one is incorrect, reject. The letter after each kind of number  ";
	cout<<"system must be in uppercase.                                         ";
	char inp[100];
	int valid=0;
	cin>>inp;
		if (inp[0]=='0' || inp[0]=='1')
		{
			for (int j=0; j<strlen(inp); j++)
			{
				if (inp[j]!='0' && inp[j]!='1')
				{
					if (inp[j]=='B')
					{
						if (inp[j+1]=='-')
						{
							for (int k=j+2; k<strlen(inp); k++)
							{
								if (inp[k]!='0' && inp[k]!='1' && inp[k]!='2' && inp[k]!='3' && inp[k]!='4' && inp[k]!='5' && inp[k]!='6' && inp[k]!='7')
								{
									if (inp[k]=='O')
									{
										if (inp[k+1]=='*')
										{
											for (int l=k+2; l<strlen(inp); l++)
											{
												if (inp[l]!='0' && inp[l]!='1' && inp[l]!='2' && inp[l]!='3' && inp[l]!='4' && inp[l]!='5' && inp[l]!='6' && inp[l]!='7' && inp[l]!='8' && inp[l]!='9')
												{
													if (inp[l]=='D')
													{
														if (inp[l+1]=='_')
														{
															for (int p=l+2; p<strlen(inp); p++)
															{
																if (inp[p]!='0' && inp[p]!='1' && inp[p]!='2' && inp[p]!='3' && inp[p]!='4' && inp[p]!='5' && inp[p]!='6' && inp[p]!='7' && inp[p]!='8' && inp[p]!='9' && inp[p]!='a' && inp[p]!='b' && inp[p]!='c' && inp[p]!='d' && inp[p]!='e' && inp[p]!='f')
															{
																if (inp[p]!='H')
																{
																	valid=1;
																	k=strlen(inp);
																	l=k;
																	j=k;
																	break;

																}
																else
																{
																	k=strlen(inp);
																	l=k;
																	j=k;
																	break;
																}
															}
															}
														}
														else
														{
														 valid=1;
														 k=strlen(inp);
														 j=k;
														 break;
														}
													}
													else
													{
														valid=1;
														k=strlen(inp);
														j=k;
														break;
													}
												}

											}
										}
										else
										{
											valid=1;
											j=strlen(inp);
											break;
										}
									}
									else
									{
										valid=1;
										j=strlen(inp);
										break;
									}
								}
							}
						}
						else
						{
							valid=1;
							break;
						}
					}
					else
					{
						valid=1;
						break;
					}
				}
			}
		}
		else
		{
			valid=1;
		}

		if (valid==1)
		{
			cout<<endl<<"Invalid!"<<endl;
		}
		else
		{
			cout<<endl<<"Valid!"<<endl;
			dfa();
		}

}

void dfa(){
	initwindow(1250,680,"First Sample");
	setcolor(RED);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	outtextxy(20,10,"STATE DIAGRAM");
	setcolor(YELLOW);

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(285,480,"TRANSITION TABLE");
	outtextxy(40,500,"0      1      B     -     0-7     O     *     0-9     D     _     a-f      H ");
	outtextxy(40,510,"q1     q2    q13   q13    q13    q13    q13   q13     q13   q13   q13     q13");
	outtextxy(40,520,"q1     q2    q13   q13    q13    q13    q13   q13     q13   q13   q13     q13");
	outtextxy(40,530,"q2     q2    q3    q13    q13    q13    q13   q13     q13   q13   q13     q13");
	outtextxy(40,540,"q13    q13   q13   q4     q13    q13    q13   q13     q13   q13   q13     q13");
	outtextxy(40,550,"q13    q13   q13   q13    q5     q13    q13   q13     q13   q13   q13     q13");
	outtextxy(40,560,"q13    q13   q13   q13    q5     q6     q13   q13     q13   q13   q13     q13");
	outtextxy(40,570,"q13    q13   q13   q13    q13    q13    q7    q13     q13   q13   q13     q13");
	outtextxy(40,580,"q13    q13   q13   q13    q13    q13    q13   q8      q13   q13   q11     q12");
	outtextxy(40,590,"q13    q13   q13   q13    q13    q13    q13   q8      q9    q13   q13     q13");
	outtextxy(40,600,"q13    q13   q13   q13    q13    q13    q13   q13     q13   q10   q13     q13");
	outtextxy(40,610,"q13    q13   q13   q13    q13    q13    q13   q7      q13   q13   q11     q13");
	outtextxy(40,620,"q13    q13   q13   q13    q13    q13    q13   q7      q13   q13   q11     q12");
	outtextxy(40,630,"q12    q12   q12   q12    q12    q12    q12   q12     q12   q12   q12     q12");
	outtextxy(40,640,"q13    q13   q13   q13    q13    q13    q13   q13     q13   q13   q13     q13");
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(CYAN);
	outtextxy(730,480,"MDFA");
	outtextxy(730,500,"E=0,1,B,-,0-7,O,*,0-9,D,_,a-f,H");
	outtextxy(730,520,"q0=q0");
	outtextxy(730,540,"Final State= q12");
	outtextxy(730,560,"Dead State= q13");
	
	
	setcolor(MAGENTA);
	line(30,470,30,660);
	line(30,500,670,500);
	line(30,470,670,470);
	line(670,470,670,660);
	line(30,660,670,660);


	setcolor(BLUE);
	circle(30,150,20);//q0
		line(50,150,115,150);
		line(115,150,95,135);
		line(115,150,95,165);

		line(30,170,325,330);
		line(325,330,315,330);
		line(325,330,320,320);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(20,150,"q0");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(60,130,"0");
	//	ellipse(350,170,0,180,60,60);
	setcolor(BLUE);
	circle(135,150,20);//q1
		line(155,150,220,150);
		line(220,150,200,135);
		line(220,150,200,165);

		line(135,170,325,330);
	//	ellipse(135,170,30,150,135,150);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(125,150,"q1");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(175,130,"1");

	    settextstyle(DEFAULT_FONT,HORIZ_DIR,1.7);
		setcolor(GREEN);
		outtextxy(90,250,"!=0;!=1");
		outtextxy(110,200,"!=0;!=1");
		outtextxy(200,200,"!=0;!=1;!=B");
		outtextxy(350,200,"!=-");
		outtextxy(430,200,"!=0-7");
		outtextxy(530,200,"!=0-7;!=O");
		outtextxy(600,180,"!=*");
		outtextxy(630,200,"!=0-9;!=H:!=a-f");
		outtextxy(650,230,"!=H");
		outtextxy(900,215,"!=a-f");
		
	setcolor(BLUE);
	circle(240,150,20);//q2
		line(260,150,325,150);
		line(325,150,305,135);
		line(325,150,305,165);

		line(240,170,345,310);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(230,150,"q2");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(280,130,"B");
	setcolor(BLUE);
	circle(345,150,20);//q3
		line(365,150,430,150);
		line(430,150,410,135);
		line(430,150,410,165);

		line(345,170,345,310);//gkan q3
		line(345,310,310,290);//arrow
		line(345,310,375,290);//arrow

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(335,150,"q3");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(385,130,"-");
	setcolor(BLUE);
	circle(450,150,20);//q4
		line(470,150,535,150);
		line(535,150,515,135);
		line(535,150,515,165);

		line(450,170,345,310);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(440,150,"q4");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(480,130,"0-7");
	setcolor(BLUE);
	circle(555,150,20);//q5
		line(575,150,640,150);
		line(640,150,620,135);
		line(640,150,620,165);

		line(555,170,365,330);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(545,150,"q5");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(595,130,"O");
	setcolor(BLUE);
	circle(660,150,20);//q6
		line(680,150,745,150);
		line(745,150,725,135);
		line(745,150,725,165);
//	circle(345,330,20);//q13
		line(660,170,365,330);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(650,150,"q6");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(690,130,"*");
	setcolor(BLUE);
	circle(765,150,20);//q7
		line(785,150,850,150);
		line(850,150,830,135);
		line(850,150,830,165);

		line(765,170,765,210);
		line(765,210,750,190);
		line(765,210,780,190);

		line(765,170,365,330);
		line(365,330,375,330);//arrow ikatulo sa ubos
		line(365,330,365,320);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(755,150,"q7");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(795,130,"0-9");
	setcolor(BLUE);
	circle(870,150,20);//q8
		line(890,150,955,150);
		line(955,150,935,135);
		line(955,150,935,165);

	//	line(870,170,365,330);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(860,150,"q8");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(910,130,"D");
	setcolor(BLUE);
	circle(975,150,20);//q9
		line(995,150,1060,150);
		line(1060,150,1040,135);
		line(1060,150,1040,165);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(965,150,"q9");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(1005,130,"_");
	setcolor(BLUE);
	circle(1080,150,20);//q10
		line(1080,170,785,230);
		line(785,230,800,245);
		line(785,230,800,215);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(1070,150,"q10");

	setcolor(BLUE);
	circle(765,230,20);//q11
		line(765,250,765,290);
		line(765,290,750,270);
		line(765,290,780,270);

		line(745,230,365,330);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(755,230,"q11");
	setcolor(BLUE);
	circle(765,310,16);//q12 small
	circle(765,310,20);//q12 big
	circle(345,330,20);//q13
	//	line(745,310,365,330);


		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(755,310,"q12");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(GREEN);
		outtextxy(335,330,"q13");



	while (!kbhit())
	{
		delay(200);
	}

}
