#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int maxx,maxy,midx,midy;
void axis()
{
	getch();
	cleardevice();
	line(midx,0,midx,maxy);
	line(0,midy,maxx,midy);
}

void main()
{
	int x,y,z,ang,x1,x2,y1,y2, maxx,maxy,midx,midy;
	int gd = DETECT,gm;
	initgraph(&gd,&gm, "c:\\turboc3\\bgi");
	setfillstyle(3,25);
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;

	outtextxy(100,100,"Original object");
//	line(midx,0,midx,maxy);
//	line(0,midy,maxx,midy);
	bar3d(midx+100,midy-20,midx+60, midy-90, 20,5);
	axis();

//	outtextxy(100,20,"Translation");
	printf("\n\nEnter the Translation vector: ");
	scanf("%d%d", &x,&y);
	bar3d(midx+50, midy-100, midx+60, midy-90, 10,1);
	bar3d(midx+(x+50),midy-(y+100),midx+(x+60), midy-(y+90), 10,1);
	axis();

//	outtextxy(100,20,"Scaling");
	printf("\n\nEnter the Scaling vector: ");
	scanf("%d%d%d", &x,&y,&z);
	bar3d(midx+50, midy-100, midx+60, midy-90, 10,1);
	bar3d(midx+(x*50),midy-(y*100),midx+(x*60), midy-(y*90), 5*z,1);
	axis();

//	outtextxy(100,20,"Rotation");
	printf("\n\nEnter the Rotation Angle: ");
	scanf("%d", &ang);

	x1= 50*cos(ang*3.14/180) - 100*sin(ang*3.14/180);
	y1= 50*sin(ang*3.14/180) + 100*sin(ang*3.14/180);
	x2= 60*cos(ang*3.14/180) - 90*sin(ang*3.14/180);
	y2= 60*sin(ang*3.14/180) + 90*sin(ang*3.14/180);
	axis();

	printf("\n\nAfter rotating about z-axis:\n");
	bar3d(midx+50, midy-100, midx+60, midy-90, 5,1);
	bar3d(midx+x1, midy-y1, midx+x2, midy-y2, 5, 1);
	axis();

	printf("\n\nAfter rotating about x-axis:\n");
	bar3d(midx+50, midy-100, midx+60, midy-90, 5,1);
	bar3d(midx+50, midy-x1, midx+60, midy-x2, 5, 1);
	axis();

	printf("\n\nAfter rotating about y-axis:\n");
	bar3d(midx+50, midy-100, midx+60, midy-90, 5,1);
	bar3d(midx+x1, midy-100, midx+x2, midy-90, 5, 1);
	axis();

	closegraph();

}