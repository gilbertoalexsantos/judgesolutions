//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1990

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 7;
const int RIGHT = 0, DOWN = 1, LEFT = 2, TOP = 3;
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};
const char word[] = {'E','S','W','N','\0'};

int source_x, source_y, sink_x, sink_y;
int dist[MAX][MAX], parent[MAX][MAX];
bool grid[MAX][MAX], can_move[MAX][MAX][4];

void clear() {
	memset(dist,0,sizeof dist);
	memset(grid,true,sizeof grid);
	memset(can_move,true,sizeof can_move);
	memset(parent,-1,sizeof parent);
}

void blockPath(int bx, int by, int ex, int ey) {
	// Horizontally
	if(by == ey) {
		for(int i = bx+1; i <= ex; i++) {
			if(by > 0) can_move[i][by][RIGHT] = false;
			if(by+1 < MAX) can_move[i][by+1][LEFT] = false;
		}
	// Vertically
	} else {
		for(int i = by+1; i <= ey; i++) {
			if(bx > 0) can_move[bx][i][DOWN] = false;
			if(bx+1 < MAX) can_move[bx+1][i][TOP] = false;
		}
	}
}

inline bool check(int x, int y) { return !(x < 1 || y < 1 || x >= MAX || y >= MAX); }

void bfs() {
	queue<pint> qe;
	qe.push(pint(source_x,source_y));
	while(!qe.empty()) {
		int x = qe.front().first, y = qe.front().second; qe.pop();
		if(!grid[x][y]) continue;
		for(int i = 0; i < 4; i++) {
			int nx = x+dr[i], ny = y+dc[i];
			if(!check(nx,ny) || !can_move[x][y][i] || !grid[nx][ny]) continue;
			dist[nx][ny] = dist[x][y]+1;
			parent[nx][ny] = i;
			qe.push(pint(nx,ny));
			if(nx == sink_x && ny == sink_y) return;
		}
		grid[x][y] = false;
	}
}

void pr() {
	stack<int> st;
	do {
		st.push(parent[sink_x][sink_y]);
		sink_x -= dr[st.top()], sink_y -= dc[st.top()];
	} while(parent[sink_x][sink_y] != -1);
	while(!st.empty()) {
		printf("%c",word[st.top()]);
		st.pop();
	}
	printf("\n");
}

int main() {
	while(scanf("%d %d",&source_x,&source_y) && source_x+source_y) {
		swap(source_x,source_y);
		clear();
		scanf("%d %d",&sink_x,&sink_y);
		swap(sink_x,sink_y);
		for(int i = 0; i < 3; i++) {
			int bx, by, ex, ey;
			scanf("%d %d %d %d",&bx,&by,&ex,&ey);
			swap(bx,by), swap(ex,ey);
			blockPath(bx,by,ex,ey);
		}
		bfs();
		pr();
	}
}
