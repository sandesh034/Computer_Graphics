# include<iostream>
# include <graphics.h>

using namespace std;

int main(){
	float x1,x2,y1,y2;
	cout<<"Enter the coordinate (x1,y1)"<<endl;
	cin>>x1>>y1;
	cout<<"Enter the coordinate (x2,y2)"<<endl;
	cin>>x2>>y2;
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, NULL);
	
	float m=(y2-y1)/(x2-x1);	
	while((x1<=x2)&&(y1<=y2)){
		if(m==1){
			putpixel(x1,y1,5);
			delay(100);
			cout<<"(x1,y1)="<<"("<<x1<<","<<y1<<")"<<endl;
			x1++;
			y1++;
	}
		else if(m<1){
			putpixel(x1,y1,5);
			delay(100);
			cout<<"(x1,y1)="<<"("<<x1<<","<<y1<<")"<<endl;
			x1++;
			y1+=m;
		}
		else{
			putpixel(x1,y1,4);
			delay(100);
			cout<<"(x1,y1)="<<"("<<x1<<","<<y1<<")"<<endl;
			x1+=(1/m);
			y1++;
		}
	}
	closegraph();
	return 0;
}