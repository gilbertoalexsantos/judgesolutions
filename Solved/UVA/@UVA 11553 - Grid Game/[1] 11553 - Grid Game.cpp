//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2548

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool visited[8];
int m[8][8];

int backtrack(int row, int qt_grid) {
	if(row >= qt_grid) return 0;
	int sum = 1e9;
	for(register int i = 0; i < qt_grid; i++) {
		if(visited[i]) continue;
		visited[i] = 1;
		sum = min(sum,m[row][i] + backtrack(row+1,qt_grid));
		visited[i] = 0;
	}
	return sum;
}


int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		memset(visited,0,sizeof visited);
		int qt_grid;
		scanf("%d",&qt_grid);
		for(register int i = 0; i < qt_grid; i++)
			for(register int j = 0; j < qt_grid; j++)
				scanf("%d",&m[i][j]);
		printf("%d\n",backtrack(0,qt_grid));
	}
}
