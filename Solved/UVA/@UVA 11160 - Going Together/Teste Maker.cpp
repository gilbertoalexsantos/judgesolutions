#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX = 4;
const int BAR = 5;

int g(int n) { return abs(rand()%n); }

char grid[MAX][MAX];

void change(char c) { grid[rand()%MAX][rand()%MAX] = c; }

bool check() {
	int sum = 0;
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++) {
			char c = grid[i][j];
			if(c == 'A' || c == 'B' || c == 'C' || c == 'X') sum++;
		}
	return (sum == 6);
}

void put() {
	change('A'), change('B'), change('C');
	for(int i = 0; i < 3; i++) change('X');
}

void put2() {
	for(int i = 0; i < BAR; i++) {
		int x = rand()%MAX, y = rand()%MAX;
		char t = grid[x][y];
		if(t == 'A' || t == 'B' || t == 'C' || t == 'X') continue;
		grid[x][y] = '#';
	}
}

int main() {
	srand(time(NULL));

	printf("1\n%d\n",MAX);

	memset(grid,'.',sizeof grid);
	while(!check()) {
		memset(grid,'.',sizeof grid);
		put();
	}

	put2();

	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) printf("%c",grid[i][j]);
		printf("\n");
	}
}
