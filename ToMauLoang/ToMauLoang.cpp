#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

using namespace std;

struct ToaDo{
	int x, y;
};
int MauNen;
void nhapDaGiac(ToaDo p[], int v){
	int i;
	for(i=0;i<v;i++){
		cout<<"\nNhap toa do dinh "<<i+1<<": ";
		cout<<"\n\tx["<<(i+1)<<"] = ";cin>>p[i].x;
		cout<<"\n\ty["<<(i+1)<<"] = ";cin>>p[i].y;
	}
	p[i].x=p[0].x;
	p[i].y=p[0].y;
}
void veDaGiac(ToaDo p[], int v){
	for(int i=0;i<v;i++){
		line(p[i].x, p[i].y, p[i+1].x, p[i+1].y);
	}
}
void ToLoang(int x,int y,int color)
{
    if (getpixel(x,y)==MauNen  && x<getmaxx() && y<getmaxy())
    {
    putpixel(x,y,color);
    ToLoang(x-1,y,color);
    ToLoang(x,y-1,color);
    ToLoang(x+1,y,color);
    ToLoang(x,y+1,color);
    }   
    delay(1);
}
int main(){
	int c = BLUE;
	int driver=0,mode;
	initgraph(&driver,&mode,"");
	int xh, yh, v;
	cout<<"nhap so dinh da giac: ";cin>>v;
	ToaDo p[v];
	nhapDaGiac(p,v);
	veDaGiac(p,v);
	cout<<"/nNhap diem H(x,y) thuoc da giac:\n";
    cout<<"nhap x="; cin>>xh;
    cout<<"nhap y="; cin>>yh;
    ToLoang(xh,yh,c);
	setcolor(c);
	getch();
}
