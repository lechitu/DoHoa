#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#define MAXVERTEX 20
#define MAXEDGE 20
#define TRUE 1
#define FALSE 0

typedef struct{
	int x;
	int y;
}POINT;

typedef struct{
	int NumVertex;
	POINTaVertex[MAXVERTEX];
}POLYGON;

typedef struct{
	int NumPt;
	float xPt[MAXEDGE];
}XINTERSECT;

typedef struct{
	int yMin;
	float xIntersect;
	float dxPerScan;
	int DeltaY;
}EDGE;

typedef struct{
	int NumEdge;
	EDGE aEdge[MAXEDGE];
}EDGELIST;

void PutEdgeInList(EDGELIST &EdgeList, POINT p1, POINT p2, int NextY){
	EDGE EdgeTmp;
	EdgeTmp.dxPerScan = float(p2.x - p1.x)/(p2.y - p1.y);
	if (p1.y < p2.y){
		if (p2.y < NextY){
			p2.y--;
			p2.x -= EdgeTmp.dxPerScan;
		}
		EdgeTmp.yMin = p1.y;
		EdgeTmp.xIntersect = p1.x;
		EdgeTmp.DeltaY = abs(p2.y - p1.y) + 1;
	}
	else{
		if (p2.y > NextY){
			p2.y++;
			p2.x += EdgeTmp.dxPerScan;
		}
		EdgeTmp.yMin = p2.y;
		EdgeTmp.xIntersect = p2.x;
		EdgeTmp.DeltaY = abs(p2.y - p1.y) + 1;
	}
	int j = EdgeList.NumEdge;
	while((j > 0)&&(EdgeList.aEdge[j - 1].yMin > EdgeTmp.yMin)){
		EdgeList.aEdge[j] = EdgeList.aEdge[j - 1];
		j--;
	}
	EdgeList.NumEdge++;
	EdgeList.aEdge[j] EdgeTmp;
}
int FindNextY(POLYGON P, int id){
	int j = (id + 1) % P.NumVertex;
	while ((j < P.NumVertex)&&(P.aVertex[id].y == P.aVertex[j].y)){
		j++;
	}
	if(j < P.NumVertex){
		return(P.aVertex[j].y);
	}
	return 0;
}
void MakeSortedEdge(POLYGON P, EDGELIST &EdgeList, int &TopScan, int &BottomScan){
	TopScan = BottomScan = P.aVertex[0].y;
	EdgeList.NumEdge = 0;
	for (int i = 0;i < P.NumVertex;i++){
		if (P.aVertex[i].y != P.aVertex[i+1].y){
			PutEdgeInList(EdgeList, , P.aVertex[i], P.aVertex[i+1], FindNextY(P, i + 1));
		}
		if (P.aVertex[i+1].y > TopScan){
			TopScan = P.aVertex[i+1].y;	
		}
	}
	BottomScan = EdgeList.aEdge[0].yMin;
}











