#include<iostream>
#include<graphics.h>
using namespace std;

void drawEllipse(float h, float k, float r_x, float r_y){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(7); 
    cleardevice();  
    //region-1
    float x=0, y=r_y;
    float pk1 = r_y * r_y - r_x * r_x * r_y + 1/4 * r_x * r_x;
    while (2 * r_y * r_y * x <= 2 * r_x * r_x * y) {
        putpixel(h + x, k - y, BLACK);
        putpixel(h - x, k - y, BLACK);
        putpixel(h + x, k + y, BLACK);
        putpixel(h - x, k + y, BLACK);

        if (pk1 < 0) {
            x++;
            pk1 = pk1 + 2 * r_y * r_y * x + r_y * r_y;
        } else {
            x++;
            y--;
            pk1 = pk1 + 2 * r_y * r_y * x - 2 * r_x * r_x * y + r_y * r_y;
        }
    }
    //region-2
    float pk2 = r_y * r_y * (x + 0.5) * (x + 0.5) + r_x * r_x * (y - 1) * (y - 1) - r_x * r_x * r_y * r_y;

    while (y > 0) {
        putpixel(h + x, k - y,BLACK);
        putpixel(h - x, k - y,BLACK);
        putpixel(h + x, k + y,BLACK);
        putpixel(h - x, k + y,BLACK);

        if (pk2 > 0) {
            y--;
            pk2 = pk2 - 2 * r_x * r_x * y + r_x * r_x;
        } else {
            x++;
            y--;
            pk2 = pk2 + 2 * r_y * r_y * x - 2 * r_x * r_x * y + r_x * r_x;
        }
    }

    getch();
    closegraph();
}

int main(){
    float h = 200;   // X-coordinate of the centerc
    float k = 200;   // Y-coordinate of the center
    float r_x = 100; // Major axis radius
    float r_y = 60;  // Minor axis radius

    drawEllipse(h, k, r_x, r_y);

    return 0;
}
