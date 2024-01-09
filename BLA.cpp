#include<iostream>
#include<graphics.h>
using namespace std;

float x1,x2,y1,y2,m,pk;

int main (){
cout<<"Enter the initial point (x1,y1):\n";
cin>>x1>>y1;

cout<<"Enter the final point (x2,y2):\n";
cin>>x2>>y2;

m=(y2-y1)/(x2-x1);
int gd = DETECT, gm; 
initgraph(&gd, &gm, NULL);

if(m<=1){
	pk=2*(y2-y1)-(x2-x1);
	while(x1<=x2){
		if(pk<0){
		 	x1++;
		 	putpixel(x1,y1,5);
			delay(100);
		 	pk+=2*(y2-y1);
			}
		else{
			x1++;
			y1++;
			putpixel(x1,y1,5);
			delay(100);
			pk=pk+2*(y2-y1)-2*(x2-x1);
		}
	}
}
else{
	pk=2*(x2-x1)-(y2-y1);
	while(x1<=x2){
	    if(pk<0){
		    y1++;
		    putpixel(x1,y1,5);
			delay(100);
		    pk+=2*(x2-x1);
		}
		else{
			x1++;
			y1++;
			putpixel(x1,y1,5);
			delay(100);
			pk=pk+2*(x2-x1)-2*(y2-y1);
		}
	}
}
closegraph();
return 0;
}
