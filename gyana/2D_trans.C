#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void translate(int x1,int y1,int x2,int y2);
void rotate(int x1,int y1,int x2,int y2);
void scale(int x1,int y1,int x2,int y2);
void reflect(int x1,int y1,int x2,int y2,int x3,int y3);
void shear(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);

void main(){
	int gd = DETECT, gm, s, x1, y1, x2, y2, x3, y3,x4,y4;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shearing");
	printf("\nSelection:");
	scanf("%d", &s);
	switch(s){
	   case 1:
		{
			printf("Enter the coordinates of object:");
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				translate(x1, y1, x2, y2);
			getch();
			break;
		}
	   case 2:
		{
			printf("Enter the coordinates of object:");
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			rotate(x1, y1, x2, y2);
			getch();
			break;
		}
	   case 3:
		{
			printf("Enter the coordinates of object:");
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			scale(x1, y1, x2, y2);
			getch();
			break;
		}
	   case 4:
		{
			printf("Enter the coordinates of object:");
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
			reflect(x1, y1, x2, y2,x3,y3);
			getch();
			break;
		}
	   case 5:
		{
			printf("Enter the coordinates of object:");
		scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
			shear(x1, y1, x2, y2,x3,y3,x4,y4);
			getch();
			break;
		}
	   default:
		{
			printf("Invalid Selection");
			break;
		}
	}
	closegraph();
}

void translate(int x1, int y1, int x2, int y2){
	int tx, ty;
	printf("Enter translation unit: ");
	scanf("%d%d", &tx, &ty);
	setcolor(4);
	rectangle(x1, y1, x2, y2);
	printf("Rectangle after translation is: ");
	rectangle(x1+tx, y1+ty, x2+tx, y2+ty);
}

void rotate(int x1, int y1, int x2, int y2){
	double a;
	int xr,yr;
	printf("Enter angle of rotation: ");
	scanf("%d", &a);
	setcolor(3);
	printf("Rectangle before rotation\n");
	rectangle(x1, y1, x2, y2);
	a = (a*3.14)/180;
	xr = x1+((x2-x1)*cos(a)-(y2-y1)*sin(a));
	yr = y1+((x2-x1)*sin(a)+(y2-y1)*cos(a));
	setcolor(2);
	printf("Rectangle with rotation: ");
	rectangle(x1, y1, xr, yr);
}

void scale(int x1, int y1, int x2, int y2){
	int x, y;
	printf("Enter scaling factors: ");
	scanf("%d%d", &x, &y);
	printf("Before scaling:\n");
	rectangle(x1, y1, x2, y2);
	setcolor(2);
	printf("After scaling: ");
	rectangle(x1*x, y1*y, x2*x, y2*y);
}

void shear(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int shx;
	printf("Enter shearing factor: ");
	scanf("%d", &shx);
	setcolor(3);
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x3, y3, x4, y4);
	line(x2, y2, x4, y4);
	printf("After shearing:\n");
	x1 = x1+shx*y1;
	x2 = x2+shx*y2;
	x3 = x3+shx*y3;
	x4 = x4+shx*y4;
	setcolor(4);
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x3, y3, x4, y4);
	line(x2, y2, x4, y4);
}

void reflect(int x1, int y1, int x2, int y2, int x3, int y3){
	setcolor(5);
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
	setcolor(2);
	line(x1, -y1+x2, x2, -y2+x2);
	line(x1, -y1+x2, x3, -y3+x2);
	line(x2, -y1+x2, x3, -y3+x2);

}