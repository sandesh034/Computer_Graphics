#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircle(float h, float k, float r) {
    float x = 0, y = r, pk = 1 - r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(7); 
    cleardevice();  
    while (x <= y) {
        putpixel(h + x, k - y, BLACK);
        putpixel(h - x, k - y, BLACK);
        putpixel(h + x, k + y, BLACK);
        putpixel(h - x, k + y, BLACK);
        putpixel(h + y, k + x, BLACK);
        putpixel(h - y, k + x, BLACK);
        putpixel(h + y, k - x, BLACK);
        putpixel(h - y, k - x, BLACK);

        if (pk < 0) {
            x++;
            pk = pk + 2 * x + 1;
        } else {
            x++;
            y--;
            pk = pk + 2 * x - 2 * y + 1;
        }
    }
    getch();
    closegraph();
}

int main() {
    float h, k, r;
    h=200; // X coordinate of center
    k=200; // Y coordinate of center
    r=100; // radius of circle
    drawCircle(h,k,r);
    return 0;
}
