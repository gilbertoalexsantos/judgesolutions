//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2671

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 1000;
const char WALL = '#', FIRE = 'F', JOE = 'J', EMPTY = '.';
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

int qt_row, qt_col;
pint init;

char grid[MAX+1][MAX+1];
int dist[MAX][MAX];
bool visited[MAX][MAX];
queue<pint> fire;

void clear() {
	memset(visited,false,sizeof visited);
	memset(dist,0,sizeof dist);
	while(!fire.empty()) fire.pop();
}

inline bool check(pint x) { return !(x.first < 0 || x.second < 0 || x.first >= qt_row || x.second >= qt_col); }

void propagate() { 
	int size = fire.size();
	for(int k = 0; k < size; k++) {
		pint n = fire.front(); fire.pop();
		for(int i = 0; i < 4; i++) {
			pint nx(n.first+dr[i],n.second+dc[i]);
			char& ret = grid[nx.first][nx.second];
			if(!check(nx) || ret == WALL || ret == FIRE) continue;
			fire.push(nx);
			ret = FIRE;
		}
	}
}

void getPos() {
	for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++) {
		if(grid[i][j] == FIRE) fire.push(pint(i,j));
		else if(grid[i][j] == JOE) init = pint(i,j);
	}
}

int bfs() {
	queue<pint> qe;
	qe.push(init);
	visited[init.first][init.second] = true;
	int flag_fire = qe.size();
	while(!qe.empty()) {
		int x = qe.front().first, y = qe.front().second; qe.pop();
		flag_fire--;
		if(grid[x][y] != FIRE) {
			for(int i = 0; i < 4; i++) {
				int nx = x+dr[i], ny = y+dc[i];

				if(!check(pint(nx,ny))) return dist[x][y]+1;

				if(visited[nx][ny] || grid[nx][ny] == FIRE || grid[nx][ny] == WALL || dist[nx][ny] > 0) continue;

				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				qe.push(pint(nx,ny));
			}
		}
		if(flag_fire <= 0) {
			propagate();
			flag_fire = qe.size();
		}
	}
	return -1;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		clear();
		scanf("%d %d",&qt_row,&qt_col);
		for(int i = 0; i < qt_row; i++) scanf("%s",grid[i]);
		getPos();
		int ans = bfs();
		ans < 0 ? printf("IMPOSSIBLE\n") : printf("%d\n",ans);
	}
}
