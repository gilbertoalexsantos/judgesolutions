//Author:	Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2035

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int dr[4] = {0,1, 0,-1};
const int dc[4] = {1,0,-1, 0};

char LAND, WATER;
int qt_row, qt_col;
int beg_row, beg_col;
char m[23][23];

int dfs(int x, int y) {
	if(x < 0 || x >= qt_row || y < 0 || y >= qt_col || m[x][y] != LAND) return 0;
	m[x][y] = WATER;
	int ans = 1;
	for(int i = 0; i < 4; i++) ans += dfs(x+dr[i],y+dc[i]);
	if(y == 0 || y == qt_col-1) {
		ans += y == 0 ? dfs(x,qt_row-1) : dfs(x,0);
	}
	return ans;
}

int main() {
	while(scanf("%d %d",&qt_row,&qt_col) != EOF) {
		for(int i = 0; i < qt_row; i++) scanf("%s",m[i]);
		scanf("%d %d",&beg_row,&beg_col);
		LAND = m[beg_row][beg_col];
		WATER = LAND == '0' ? '1' : '0';
		dfs(beg_row,beg_col);
		int ans = -1;
		for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++) ans = max(ans,dfs(i,j));
		printf("%d\n",ans);
	}
}
