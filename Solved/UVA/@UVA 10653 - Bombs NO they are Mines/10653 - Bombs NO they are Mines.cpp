//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1594

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1001;

typedef pair<int,int> pint;

int qt_row, qt_col;
int source_x, source_y, sink_x, sink_y;
bool grid[MAX][MAX];
int dist[MAX][MAX];

int dr[] = {0,1, 0,-1};
int dc[] = {1,0,-1, 0};

inline bool check(int x, int y) { return !(x < 0 || y < 0 || x > qt_row || y > qt_col); }

int bfs() {
	queue<pint> qe;
	qe.push(pint(source_x,source_y));
	while(!qe.empty()) {
		int x = qe.front().first, y = qe.front().second; qe.pop();
		if(!grid[x][y]) continue;
		for(int i = 0; i < 4; i++) {
			int nx = x+dr[i], ny = y+dc[i];
			if(!check(nx,ny) || !grid[nx][ny]) continue;
			dist[nx][ny] = dist[x][y] + 1;
			qe.push(pint(nx,ny));
			if(nx == sink_x && ny == sink_y) return dist[nx][ny];
		}
		grid[x][y] = false;
	}
	return dist[sink_x][sink_y];
}

void clear() {
	memset(grid,true,sizeof grid);
	memset(dist,0,sizeof dist);
}

int main() {
	while(scanf("%d %d",&qt_row,&qt_col) && qt_row+qt_col) {
		clear();
		int qt_bomb;
		scanf("%d",&qt_bomb);
		for(int i = 0; i < qt_bomb; i++) {
			int k, x, y;
			scanf("%d %d",&x, &k);
			while(k--) {
				scanf("%d",&y);
				grid[x][y] = false;
			}
		}
		scanf("%d %d %d %d",&source_x,&source_y,&sink_x,&sink_y);
		int ans = bfs();
		printf("%d\n",ans);
	}
}
