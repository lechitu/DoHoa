#include <iostream>
#include <graphics.h>
#include <math.h>
#define Round(a) (int)(a + 0.5)
#include <conio.h>

using namespace std;

int color = WHITE;

void lineDDA(int x1, int y1, int x2, int y2){
	int Dx = x2 - x1, Dy = y2 - y1;
	int x = x1;
	float y = y1;
	float m = 1.0*Dy/Dx;
	putpixel(x, Round(y), color);
	
	while(x < x2){
		delay(10);
		x += 1;
		y += m;
		putpixel(x, Round(y), color);
	}
}
int main(){
	int driver=0,mode;
	initgraph(&driver,&mode,"");
	lineDDA(50, 150, 300, 200);
	setcolor(WHITE);
	getch();
}
