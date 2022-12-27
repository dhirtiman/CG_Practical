//Midpoint circle drawing algorithm

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void circlepoints(int,int);
int  main( )
{
int x,y,p,r;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,(char*)"");
printf("Enter the radius");
scanf("%d",&r);
x=0;y=r;p=1-r;
while(x<y)
{
x++;
if(p>0)
{
p=p+2*(x-y)+1;
y--;
}
else
p=p+2*x+1;
circlepoints(x,y);
}
getch();
closegraph();
return 0;
}
void circlepoints(int x,int y)
{
putpixel(x+300,y+300,8);
putpixel(x+300,-y+300,8);
putpixel(-x+300,y+300,8);
putpixel(-x+300,-y+300,8);
putpixel(y+300,x+300,8);
putpixel(y+300,-x+300,8);
putpixel(-y+300,x+300,8);
putpixel(-y+300,-x+300,8);
}