#include<fstream.h>
#include<conio.h>
#include<function.h>
#define pi 3.14159
#include <math.h>
#include <dos.h>
class vector
{       public:
	vector()
	{	i=0;
		j=0;
	}
	float i;
	float j;
}ch[5];

class charge
{       public:
	charge()
	{	x=0;
		y=0;
		mag=0;
	}
	int x;
	int y;
	int mag;
}q[5];

float cal(float x,float y)
{       float r;
	for(int c=0;c<5;c++)
	{	r=sqrt(pow((x-q[c].x),2)+pow((y-q[c].y),2));
		ch[c].i=((x-q[c].x)/pow(r,3))*q[c].mag;
		ch[c].j=((y-q[c].y)/pow(r,3))*q[c].mag;
	}
	vector sum;
	for(c=0;c<5;c++)
	{	sum.i+=ch[c].i;
		sum.j+=ch[c].j;
	}
	return atan2(sum.j,sum.i);
}
int check(int x,int y)
{	for(int c=0;c<5;c++)
	{	if((pow((x-q[c].x),2)+pow((y-q[c].y),2))<(80))
		return 0;
	}
	return 1;
}


void main()
{	clrscr();
		graphics g;

	for(int c=0,ch;ch;c++)
	{	cout<<"x";
		cin>>q[c].x;
		cout<<"y";
		cin>>q[c].y;
		cout<<"mag";
		cin>>q[c].mag;
		cout<<"do you want to enter more";
		cin>>ch;
	}


	for(c=0;c<5&&q[c].mag;c++)
	{	g.circle(q[c].x,q[c].y,10);
		q[c].y=480-q[c].y;
	}
	double theta;
	for(c=0;c<5&&q[c].mag;c++)
	{	for(double t=0,x,y;t<(2*pi);t+=(pi/(12*abs(q[c].mag))))
		{       x=q[c].x+10*cos(t);
			y=q[c].y+10*sin(t);

			for(int d=0;d<1000&&check(x,y);d++)
			{       if(q[c].mag<0)
				{      theta=pi+cal(x,y);
				}
				else
				{	theta=cal(x,y);
				}
				g.line(x,y,3.0,theta,4);
				//delay(10);
				x+=3*cos(theta);
				y+=3*sin(theta);
			}
			delay(50);
		}
	}
	getch();
	copyright();


}

