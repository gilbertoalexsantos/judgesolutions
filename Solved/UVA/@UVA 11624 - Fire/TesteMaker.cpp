#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int ROW = 10, COL = 10;
const int FIRE = 5;
const int EXIT = 3;

char grid[ROW+1][COL+1];

int g() { return abs(rand()%ROW); }

void putJoe() {
	int x = g(), y = g();
	grid[x][y] = 'J';
}

void putFire() {
	for(int i = 0; i < FIRE; i++) {
		int x = g(), y = g();
		if(grid[x][y] == 'J' || grid[x][y] == '#') continue;
		grid[x][y] = 'F';
	}
}

void putWall() {
	for(int i = 0; i < ROW; i++) {
		grid[0][i] = '#';
		grid[ROW-1][i] = '#';
		grid[i][0] = '#';
		grid[i][COL-1] = '#';
	}
}

void putEmpty() {
	for(int i = 0; i < ROW; i++) for(int j = 0; j < COL; j++)
		grid[i][j] = '.';
}

void putExit() {
	for(int i = 0; i < EXIT; i++) {
		int x = g();
		if(x%2) grid[0][x] = '.';
		else grid[x][0] = '.';
	}
}

int main() {
	srand(time(NULL));
	putEmpty();
	putWall();
	putExit();
	putJoe();
	putFire();
	printf("1\n");
	printf("%d %d\n",ROW,COL);
	for(int i = 0; i < ROW; i++) printf("%s\n",grid[i]);
}
