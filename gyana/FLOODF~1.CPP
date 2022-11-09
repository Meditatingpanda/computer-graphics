
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include <conio.h>
int oldCol=0,newCol=15;
//void far *p(unsigned char, unsigned char);
void f1(unsigned char x, unsigned char  y)
{
if(getpixel(x,y) == oldCol)
{
putpixel(x,y,newCol);
f1(x+1,y);
f1(x,y+1);
f1(x-1,y);
f1(x,y-1);
}
}

//getpixel(x,y) gives the color of specified pixel

int main()
{
int gm,gd=DETECT,radius;
int x,y;
//void far *p=&;
cout<<"Enter x and y positions for circle\n";
cin>>x>>y;
cout<<"Enter radius of circle\n";
cin>>radius;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
circle(x,y,radius);
f1(x,y);
delay(1);
getch();
//closegraph();
return 0;
}