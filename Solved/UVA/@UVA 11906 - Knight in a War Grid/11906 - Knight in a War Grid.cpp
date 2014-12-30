//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3057

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int EVEN = 5, ODD = 6;

typedef pair<int,int> pint;

int grid[100][100];
int qt_row, qt_col, m, n;

void clear() {
	memset(grid,-1,sizeof grid);
}

inline bool check(int x, int y) { return !(x < 0 || x >= qt_row || y < 0 || y >= qt_col || grid[x][y] >= 0); }
inline bool canvisit(int x, int y) { return !(x < 0 || x >= qt_row || y < 0 || y >= qt_col || !grid[x][y]); }
inline bool iseven(int n) { return !(n%2); }

void dfs(int x, int y) {
	int dr[8] = {m,-m,n,-n, m,-m, n,-n};
	int dc[8] = {n,-n,m,-m,-n, n,-m, m};
	grid[x][y] = 0;
	int qt = 0;
	if(m && n && m != n) {
		for(int i = 0; i < 8; i++) qt += canvisit(x+dr[i],y+dc[i]);
		grid[x][y] = iseven(qt) ? EVEN : ODD;
		for(int i = 0; i < 8; i++) if(check(x+dr[i],y+dc[i])) dfs(x+dr[i],y+dc[i]);
	} else {
		if(m != n) {
			for(int i = 0; i < 4; i++) qt += canvisit(x+dr[i],y+dc[i]);
			grid[x][y] = iseven(qt) ? EVEN : ODD;
			for(int i = 0; i < 4; i++) if(check(x+dr[i],y+dc[i])) dfs(x+dr[i],y+dc[i]);
		} else {
			int dr2[4] = {m,-m, m,-m};
			int dc2[4] = {m,-m,-m, m};
			for(int i = 0; i < 4; i++) qt += canvisit(x+dr2[i],y+dc2[i]);
			grid[x][y] = iseven(qt) ? EVEN : ODD;
			for(int i = 0; i < 4; i++) if(check(x+dr2[i],y+dc2[i])) dfs(x+dr2[i],y+dc2[i]);
		}
	}

}

int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		clear();
		scanf("%d %d %d %d",&qt_row,&qt_col,&m,&n);
		int qt_water;
		scanf("%d",&qt_water);
		for(int i = 0; i < qt_water; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			grid[x][y] = 0;
		}
		dfs(0,0);
		pint ans(0,0);
		for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
			ans.first += grid[i][j] == EVEN, ans.second += grid[i][j] == ODD;
		printf("Case %d: %d %d\n",cases++,ans.first,ans.second);
	}
}
