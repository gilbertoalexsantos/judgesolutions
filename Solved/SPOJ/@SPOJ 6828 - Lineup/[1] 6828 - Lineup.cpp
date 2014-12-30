//Author:	Gilberto A. dos Santos
//Website:	http://www.spoj.com/problems/LINEUP/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int grid[11][11];
bool hit[11];

bool verify(int row, int col) {
	if(hit[col] || !grid[row][col]) return false;
	return true;
}

int backtrack(int row) {
	if(row == 11) return 0;
	int ret = -1e9;
	for(int c = 0; c < 11; c++) {
		if(!verify(row,c)) continue;
		hit[c] = 1;
		ret = max(ret,grid[row][c] + backtrack(row+1));
		hit[c] = 0;
	}
	return ret;
}

int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		memset(hit,0,sizeof hit);
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++) 
				scanf("%d", &grid[i][j]);
		printf("%d\n",backtrack(0));
	}
	return 0;
}
