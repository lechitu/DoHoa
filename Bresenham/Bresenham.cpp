#include <iostream>
#include <graphics.h>
#include <conio.h>
#define DELAY 10
#include <math.h>

using namespace std;

int color = WHITE;

void Breseham(int x1, int x2, int y1, int y2){
	int Dx = abs(x2 - x1);
	int Dy = abs(y2 - y1);
	int p = 2*Dy - Dx;
	int c1 = 2*Dy;
	int c2 = 2*(Dy - Dx);
	int x = x1;
	int y = y1;
	putpixel(x, y, color);
	while(x != x2){
		delay(DELAY);
		if (p < 0) p += c1;
		else{
			p += c2;
			y += 1;
		}
		x += 1;
		putpixel(x, y, color);
		
	}
}
int main(){
	int driver=0,mode;
	initgraph(&driver,&mode,"");
	Breseham(50,150,300,200);
	getch();
}
