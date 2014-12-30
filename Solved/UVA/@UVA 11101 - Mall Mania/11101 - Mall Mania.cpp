//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2042

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 2000;
const int MALL1 = 1, MALL2 = 2;
const int INF = 1e9;
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

int grid[MAX+1][MAX+1], type[MAX+1][MAX+1];
queue<pint> qe;

inline bool check(int x, int y) { return !(x < 0 || y < 0 || x >= MAX || y >= MAX); }

int bfs() {
	while(!qe.empty()) {
		int x = qe.front().first, y = qe.front().second; qe.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x+dr[i], ny = y+dc[i];
			if(!check(nx,ny) || grid[nx][ny] != -1) continue;

			grid[nx][ny] = grid[x][y] + 1;

			if(type[nx][ny] == MALL2) return grid[nx][ny];

			qe.push(pint(nx,ny));
		}
	}
	return -1;
}

void clear() {
	while(!qe.empty()) qe.pop();
	memset(type,-1,sizeof type);
	memset(grid,-1,sizeof grid);
}

int main() {
	int mal1, mal2;
	while(scanf("%d",&mal1) && mal1) {
		clear();
		while(mal1--) {
			int x, y;
			scanf("%d %d",&x,&y);
			type[x][y] = MALL1;
			grid[x][y] = 0;
			qe.push(pint(x,y));
		}
		scanf("%d",&mal2);
		while(mal2--) {
			int x, y;
			scanf("%d %d",&x,&y);
			type[x][y] = MALL2;
		}
		int ans = bfs();
		printf("%d\n",ans);
	}
}
