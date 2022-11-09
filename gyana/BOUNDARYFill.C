#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void boundary(long long int x, long long int y, long long int oldc, long long int newc)
{
	if(getpixel(x,y)!=oldc && getpixel(x,y)!=newc)
	{
		putpixel(x,y,newc);
		boundary(x,y+1,oldc,newc);
		boundary(x,y-1,oldc,newc);
		boundary(x+1,y,oldc,newc);
		boundary(x-1,y,oldc,newc);
		boundary(x+1,y+1,oldc,newc);
		boundary(x+1,y-1,oldc,newc);
		boundary(x-1,y+1,oldc,newc);
		boundary(x-1,y-1,oldc,newc);
	}
}
void main()
{
	long long int x=250, y=250, radius=50;
	int gm=DETECT,gd;
	initgraph(&gm,&gd,"c:\\TURBOC3\\BGI");
	circle(x,y,radius);
	boundary(x,y,6,10);
	delay(1000);
	getch();
	closegraph();
}