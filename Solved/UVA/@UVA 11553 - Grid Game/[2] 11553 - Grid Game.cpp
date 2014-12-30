//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2548

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m[8][8];
int memo[1<<8][1<<8];

int dp(int row, int col, int size) {
	if(row >= (1<<size)-1 && col >= (1<<size)-1) return 0;
	int &ret = memo[row][col];
	if(ret != -1e9) return ret;
	int flag_max = -1e9;
	for(register int i = 0; i < size; i++) {
		if(row & (1 << i)) continue;
		int flag_min = 1e9; 
		for(register int j = 0; j < size; j++) {
			if(col & (1 << j)) continue;
			flag_min = min(flag_min,m[i][j] + dp((row | (1 << i)),(col | (1 << j)), size));
		}
		flag_max = max(flag_max,flag_min);
	}
	return ret = flag_max;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int qt_grid;
		scanf("%d",&qt_grid);
		for(register int i = 0; i < qt_grid; i++)
			for(register int j = 0; j < qt_grid; j++)
				scanf("%d",&m[i][j]);
		for(register int i = 0; i < (1 << qt_grid); i++)
			for(register int j = 0; j < (1 << qt_grid); j++)
				memo[i][j] = -1e9;
		printf("%d\n",dp(0,0,qt_grid));
	}
}
