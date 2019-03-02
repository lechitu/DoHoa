#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>

using namespace std;

int color = WHITE;

void put8pixel(int xc, int yc, int x, int y, int color)
{
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}
void Midpoint(int xc, int yc, int r, int color)
{
    int x = 0; int y = r;
    int f = 5/4 - r;
    put8pixel(xc, yc, x, y, color);
    while (x < y)
    {
    	delay(10);
        if (f < 0) f += 2*x + 3;
        else
        {
            y--;
            f += 2*(x - y) + 5;
        }
        x++;
        put8pixel(xc, yc, x, y, color);
    }
}
int main(){
	int driver=0,mode;
	initgraph(&driver,&mode,"");
	Midpoint(200,200,100,color);
	getch();
}
