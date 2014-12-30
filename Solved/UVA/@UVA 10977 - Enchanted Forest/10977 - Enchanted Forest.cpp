//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1918

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 201;
// R D L T
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

int qt_row, qt_col;
bool grid[MAX][MAX];
int dist[MAX][MAX];

void clear() {
	memset(grid,true,sizeof grid);
	memset(dist,0,sizeof dist);
}

inline bool check_dist(pint a, pint b, int l) { return (pow(a.first-b.first,2)+pow(a.second-b.second,2)) <= pow(l,2); }
inline bool check(int x, int y) { return !(x < 1 || y < 1 || x > qt_row || y > qt_col); }

void blockJiggly(int x, int y, int l) {
	grid[x][y] = false;
	pint t(x,y);
	// TOP_LEFT
	for(int row = x; row >= 0; row--) {
		if(!check_dist(t,pint(row,y),l)) break;
		for(int col = y; col >= 0; col--) {
			if(!check_dist(t,pint(row,col),l)) continue;
			grid[row][col] = false;
		}
	}
	// TOP_RIGHT
	for(int row = x; row >= 0; row--) {
		if(!check_dist(t,pint(row,y),l)) break;
		for(int col = y; col <= qt_col; col++) {
			if(!check_dist(t,pint(row,col),l)) continue;
			grid[row][col] = false;
		}
	}
	// BOTTON_LEFT
	for(int row = x; row <= qt_row; row++) {
		if(!check_dist(t,pint(row,y),l)) break;
		for(int col = y; col >= 0; col--) {
			if(!check_dist(t,pint(row,col),l)) continue;
			grid[row][col] = false;
		}
	}
	// BOTTON_RIGHT
	for(int row = x; row <= qt_row; row++) {
		if(!check_dist(t,pint(row,y),l)) break;
		for(int col = y; col <= qt_col; col++) {
			if(!check_dist(t,pint(row,col),l)) continue;
			grid[row][col] = false;
		}
	}
}

int bfs() {
	if(1 == qt_row && 1 == qt_col && grid[1][1]) return -1;
	queue<pint> qe;
	qe.push(pint(1,1));
	while(!qe.empty()) {
		int x = qe.front().first, y = qe.front().second; qe.pop();
		if(!grid[x][y]) continue;
		for(int i = 0; i < 4; i++) {
			int nx = x+dr[i], ny = y+dc[i];
			if(!check(nx,ny) || !grid[nx][ny]) continue;
			dist[nx][ny] = dist[x][y]+1;
			qe.push(pint(nx,ny));
			if(nx == qt_row && ny == qt_col) return dist[nx][ny];
		}
		grid[x][y] = false;
	}
	return 0;
}

int main() {
	while(scanf("%d %d",&qt_row,&qt_col) && qt_row+qt_col) {
		clear();
		int qt_block;
		scanf("%d",&qt_block);
		while(qt_block--) {
			int x, y;
			scanf("%d %d",&x,&y);
			grid[x][y] = false;
		}
		int qt_jiggly;
		scanf("%d",&qt_jiggly);
		while(qt_jiggly--) {
			int x, y, l;
			scanf("%d %d %d",&x,&y,&l);
			blockJiggly(x,y,l);
		}
		int ans = bfs();
		ans ? printf("%d\n",ans < 0 ? 0 : ans) : printf("Impossible.\n");
	}
}
