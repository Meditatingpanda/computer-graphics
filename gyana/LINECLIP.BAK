#include <conio.h>
#include <graphics.h>

void main()

{
	int rb[4]={0,0,0,0},re[4]={0,0,0,0},rc[4];
	int wxmax,wxmin,wymin,wymax,flag=0;
	float slope;
	int x,y,x1,y1,i,xc,yc;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("\n COHEN SUTHERLAND LINE CLIPPEING\n\n");
	printf("Enter XMIN, YMIN : ");
	scanf("%d%d",&wxmin,&wymin);
	printf("Enter XMAX, YMAX : ");
	scanf("%d%d",&wxmax,&wymax);
	printf("Enter INITIAL points : ");
	scanf("%d%d",&x,&y);
	printf("Enter FINAL points : ");
	scanf("%d%d",&x1,&y1);
	cleardevice();
	rectangle(wxmin,wymin,wxmax,wymax);
	setcolor(GREEN);
	line(x,y,x1,y1);
//	line(0,0,600,0);
//	line(0,0,0,600);

	if(y>wymax)
	{
		rb[0]=1;
		flag=1;
	}
	if(y<wymin)
	{
		rb[1]=1;
		flag=1;
	}
	if(x>wxmax)
	{
		rb[2]=1;
		flag=1;
	}
	if(x<wxmin)
	{
		rb[3]=1;
		flag=1;
	}

	if(y1>wymax)
	{
		re[0]=1;
		flag=1;
	}
	if(y1<wymin)
	{
		re[1]=1;
		flag=1;
	}
	if(x1>wxmax)
	{
		re[2]=1;
		flag=1;
	}
	if(x1<wxmin)
	{
		re[3]=1;
		flag=1;
	}

	if(flag==0){
	printf("\nNO NEED OF CLIPPING\n\n");
	    }
	flag =1;
	for(i=0;i<4;i++)
	{
		rc[i]=rb[i] && re[i];
		if(rc[i]==1)
		{
			flag=0;
		}

	}
	if(flag==0)
	{
		printf("\nLINE IS COMPLETELUY OUTSIDE\n\n");
	}

	else
	{
		slope=(float)(y1-y)/(x1-x);

		if(rb[2]==0 && rb[3]==1)
		{
			y=y+(float)(wxmin-x)* slope;
			x=wxmin;
		}
		if(rb[2]==1 && rb[3]==0)
		{
			y=y+(float)(wxmax-x)* slope;
			x=wxmax;
		}
		if(rb[0]==1 && rb[1]==0)
		{
			x=x+(float)(wymax-y)/ slope;
			y=wymax;
		}
		if(rb[0]==0 && rb[1]==1)
		{
			x=x+(float)(wymin-y)/slope;
			y=wymin;
		}


		if(re[2]==0 && re[3]==1)
		{
			y1=y1+(float)(wxmin-x1)* slope;
			x1=wxmin;
		}
		if(re[2]==1 && re[3]==0)
		{
			y1=y1+(float)(wxmax-x1)* slope;
			x1=wxmax;
		}
		if(re[0]==1 && re[1]==0)
		{
			x1=x1+(float)(wymax-y1)/ slope;
			y1=wymax;
		}
		if(re[0]==0 && re[1]==1)
		{
			x1=x1+(float)(wymin-y1)/slope;
			y1=wymin;
		}
	}
	delay(1000);
	clearviewport();
	rectangle(wxmin, wymin, wxmax, wymax);
	//line(0,0,600,0);
	//line(0,0,0,600);

	setcolor(RED);
	line(x,y,x1,y1);

	getch();
	closegraph();
}
