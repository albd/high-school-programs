#include <string.h>
#include <graphics.h>
#include <stdio.h>
#include <math.h>




void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void swap(char &a,char &b)
{
	char temp;
	temp=a;
	a=b;
	b=temp;
}
void palindrome(char a[])
{
	int l=strlen(a)-1;

	for(int i=0;i<=l;i+=2)
	{
		swap(a[i/2],a[l-(i/2)]);
	}

}
int factorial(int a)
{       int fac=1;
	for(;a;a--)
	{	fac*=a;
	}
	return fac;
}
void arrayin(int a[100][100],int x,int y)
{
	for(int i=0;i<x;i++)
	{	for(int j=0;j<y;j++)
		{
			cin>>a[i][j];
		}
	}
}

void arrayout(int a[2][3],int x,int y)
{	for(int i=0;i<x;i++)
	{	for(int j=0;j<y;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
void copyright()
{       int driver=DETECT,mode;
	initgraph(&driver,&mode,"d:\\tc\\bgi");
	setcolor(RED);
	settextstyle(5,0,1);
	outtextxy(220,450,"HIMANSU AND ALBERT");
	cout<<"this is atrial version \n For the full version log on to www.a_s_h.com\n";
	cout<<"you will have to press enter 10 times to exit";
	for(int a=0;a<10;a++)
	getch();
}



class graphics{         public:
			graphics()
			{    	int driver = DETECT, mode;
				initgraph(&driver,&mode,"..\\bgi");
			}


			void circle(int x1,int y1,int r=10,int col=4)
			{
				setcolor(col);
				::circle(x1,480-y1,r);
			}

			void pt(int x,int y,int col=4)
			{

			setcolor(col);
			putpixel(x,480-y,RED);
			}

			void line(double x,double y,double r,double t,int col=4)
			{
				setcolor(col);
				::line(x,y,x+r*cos(t),y+r*sin(t));
				::line(x,y,x-r*cos(t),y-r*sin(t));
			}
			void line(int x1,int y1,int x2,int y2,int col=4)
			{
				setcolor(col);
				::line(x1,480-y1,x2,480-y2);
			}




			};