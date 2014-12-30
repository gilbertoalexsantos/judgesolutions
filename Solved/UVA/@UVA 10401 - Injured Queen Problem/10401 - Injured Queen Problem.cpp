//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1342

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

const int MAX_SIZE = 16;

char word[20];
bool grid[MAX_SIZE][MAX_SIZE];
ull dist[MAX_SIZE][MAX_SIZE];
int size;
ii source;

inline int transform(char c) { return (c >= 'A') ? c - 'A' + 10 : c - '0'; }

void clear() {
	memset(grid,true,sizeof grid);
	memset(dist,0,sizeof dist);
	size = strlen(word);
}


ull dp() {
	for(int row = 1; row <= size; row++)
		dist[row][1] = 1;
	for(int col = 1; col < size; col++) {
		int ncol = col + 1;
		for(int row = 1; row <= size; row++) if(grid[row][col]) {
			for(int nrow = 1; nrow <= size; nrow++) if(grid[nrow][ncol]) {
				if(nrow < row-1 || nrow > row+1)
					dist[nrow][ncol] += dist[row][col];
			}
		}
	}
	ull ret = 0;
	for(int row = 1; row <= size; row++)
		ret += dist[row][size];
	return ret;
}

int main() {
	while(scanf("%s",word) != EOF) {
		clear();
		for(int col = 0; col < size; col++) if(word[col] != '?') {
			for(int row = 1; row <= size; row++)
				grid[row][col+1] = false;
			grid[size - transform(word[col]) + 1][col+1] = true;
		}
		ull ans = dp();
		printf("%llu\n",ans);
	}
}
