#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void snake();
void set();
void food();
int x[100][4]={{100,100,110,110},{80,100,100,110},{80,100,90,110},{70,100,80,100}};
int n=4;
int c;
int r1,r2;
void main()
{
	int a=DETECT;
	int b;
	clrscr();
	initgraph(&a,&b,"");
	r1=50+random(700);
	r2=50+random(500);
	do
	{
		c=getch();
		snake();
	}while(c!=97);
	getch();
}
void snake()
{
	while(kbhit()==0)
	{
		int i;
		for(i=0;i<n;i++)
		{
			rectangle(x[i][0],x[i][1],x[i][2],x[i][3]);
			food();
		}
	if(c==77)
		{
			set();
			x[0][0]+=10;
			x[0][2]+=10;
		}
	if(c==75)
		{
			set();
			x[0][0]-=10;
			x[0][2]-=10;
		}
	if(c==72)
		{
			set();
			x[0][1]-=10;
			x[0][3]-=10;
		}
	if(c==80)
		{
			set();
			x[0][1]+=10;
			x[0][3]+=10;
		}
		if(x[0][0]==r1 && x[0][1]==r2)
		{
			n++;
			r1=random(500);
			r2=random(400);
		}
		delay(100);
		cleardevice();
	}
}
void set()
{
	int i;
	for(i=n-1;i>0;i--)
	{
		x[i][0]=x[i-1][0];
		x[i][1]=x[i-1][1];
		x[i][2]=x[i-1][2];
		x[i][3]=x[i-1][3];
	}
}
void food()
{
	r1=r1-r1%10;
	r2=r2-r2%10;
	rectangle(r1,r2,r1+10,r2+10);
}