#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void circleDraw(int a, int b, int radius)
{
	int x = radius;
	int y=0;
	int err = 0;
	while(x >= y){
		putpixel(a+x,b+y,GREEN);
		putpixel(a+y,b+x,GREEN);
		putpixel(a-y,b+x,GREEN);
		putpixel(a-x,b+y,GREEN);
		putpixel(a-x,b-y,GREEN);
		putpixel(a-y,b-x,GREEN);
		putpixel(a+y,b-x,GREEN);
		putpixel(a+x,b-y,GREEN);

		if(err <= 0){
			y+=1;
			err+= (2*y) + 1;
		}
		else{
			x-=1;
			err -= (2*x) + 1;
		}

	}
}

void main(){
	int gm = DETECT, gd, error, x, y, r;
	initgraph(&gm, &gd, "C:\\TURBOC3\\BGI");
	printf("Enter radius of the circle:");
	scanf("%d", &r);
	printf("Enter coordinates of center: ");
	scanf("%d %d", &x, &y);
	circleDraw(x,y,r);
	getch();
}

