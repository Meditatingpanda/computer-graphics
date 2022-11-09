#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int gd, gm, n, *x, i, k=0;
	int w[] = {220, 140, 420, 140, 420, 340, 220, 340, 220, 140};
	initgraph(&gd,&gm, "c:\\turboc3\\bgi");
	printf("Window- ");
	setcolor(RED);
	drawpoly(5,w);
	printf("Enter the number of vertices of polygon ");
	scanf("%d", &n);
	x = malloc(n*2+1);
	printf("Enter the coordinbates of the points:");

	k=0;
	for(i=0; i<n*2; i+=2){
		printf("(x,y): ",k,k);
		scanf("%d%d", &x[i], &x[i+1]);
		k++;
	}
	x[n*2] = x[0];
	x[n*2+1]= x[1];
	setcolor(WHITE);
	drawpoly(n+1,x);
	printf("Press a button to clip a polygon");
	getch();
	setcolor(RED);
	drawpoly(5,w);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(2,2,RED);
	gotoxy(1,1);
	getch();
	closegraph();

}