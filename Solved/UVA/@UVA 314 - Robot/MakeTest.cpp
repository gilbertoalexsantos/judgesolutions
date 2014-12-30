#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int ROW = 50, COL = 50;
const int BLOCK = 200;

int grid[ROW][COL];
int x,y,ax,ay;
int pos;

int g() { return abs(rand()%ROW); }

void putZero() {
	memset(grid,0,sizeof grid);
}

void putOne() {
	for(int i = 0; i < BLOCK; i++) {
		int a = g(), b = g();
		grid[a][b] = 1;
	}
}

void putBeg() {
	int a = g(), b = g();
	while(a == 0 || b == 0 || grid[a][b] == 1)
		a = g(), b = g();
	x = a, y = b;
}

void putEnd() {
	int a = g(), b = g();
	while(a == 0 || b == 0 || grid[a][b] == 1 || (a == x && b == y))
		a = g(), b = g();
	ax = a, ay = b;
}

void putPos() {
	pos = abs(rand()%4);
}

char v[4][15] = {"east","south","west","north"};

int main() {
	srand(time(NULL));
	putZero();
	putOne();
	putBeg();
	putEnd();
	printf("%d %d\n",ROW,COL);
	putPos();
	for(int i = 0; i < ROW; i++) {
		printf("%d",grid[i][0]);
		for(int j = 1; j < COL; j++) printf(" %d",grid[i][j]);
		printf("\n");
	}
	printf("%d %d %d %d %s\n",x,y,ax,ay,v[pos]);
	printf("0 0\n");
}
