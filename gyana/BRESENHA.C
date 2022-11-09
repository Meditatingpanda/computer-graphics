#include<graphics.h>
#include<conio.h>

void main()
{
	int gm=DETECT;
	int gd;
	int x0,x1,y0,y1;
	int dx,dy,p,x,y;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	dx=x1-x0;
	x=x0;
	dy=y1-y0;
	y=y0;
	p=2*dy-dx;
	while(x<x1)
	{
		if(p>=0)
		{
			putpixel(x,y,7);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			putpixel(x,y,7);
			p=p+2*dy;
		}
		x=x+1;
		getch();
	}
}