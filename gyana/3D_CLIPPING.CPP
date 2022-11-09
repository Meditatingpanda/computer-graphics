#include<graphics.h>
#include<conio.h>
#include<iostream.h>

void cube(int tlx,int tly,int brx,int bry){
  int cx=(2*tlx+brx)/3,cy=(2*tly+bry)/3,len=bry-tly,wid=brx-tlx;
  rectangle(tlx,tly,brx,bry);
  rectangle(cx,cy,cx+wid,cy+len);
  line(tlx,tly,cx,cy);
  line(tlx+wid,tly,cx+wid,cy);
  line(tlx,tly+len,cx,cy+len);
  line(tlx+wid,tly+len,cx+wid,cy+len);
}
void clip(int tlx,int tly,int brx,int bry,int x1,int y1,int x2,int y2){
  float m = (float)(y2-y1)/(x2-x1);
  float c = (y1-m*x1);
  if(x1<tlx) {x1=tlx;y1=m*x1+c;};
  if(x2<tlx) {x2=tlx;y2=m*x2+c;};
  if(x1>brx) {x1=brx;y1=m*x1+c;};
  if(x2>brx) {x2=brx;y2=m*x2+c;}
  if(y1<tly) y1=tly;
  if(y2>bry) y2=bry;
  if(y1>bry) y1=bry;
  if(y2<tly) y2=tly;
  /*if(x1<tlx) x1=tlx;
  if(x2<tlx) x2=tlx;
  if(x1>brx) x1=brx;
  if(x2>brx) x2=brx;
  if(y1<tly) y1=tly;
  if(y2>bry) y2=bry;
  if(y1>bry) y1=bry;
  if(y2<tly) y2=tly;*/

  cube(tlx,tly,brx,bry);
  setcolor(RED);
  line(x1,y1,x2,y2);
}

int main(){
 int gd=DETECT, gm;
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 int tlx,tly,brx,bry,x1,x2,y1,y2;
 cout<<"Enter coordinates of cube(tlx,tly,brx,bry): ";
 cin>>tlx>>tly>>brx>>bry;
 cout<<"Enter endpoints of the line(x1,y1,x2,y2): ";
 cin>>x1>>y1>>x2>>y2;

 clip(tlx,tly,brx,bry, x1,y1,x2,y2);

 getch();
 closegraph();

 return 0;
 }