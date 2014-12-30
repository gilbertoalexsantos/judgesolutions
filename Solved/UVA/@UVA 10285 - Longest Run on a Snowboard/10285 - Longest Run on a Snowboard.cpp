//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1226

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 100;
const int MAX_GRAPH = MAX_SIZE * MAX_SIZE;
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

char word[105];

int qt_row, qt_col, qt_vert;
int grid[MAX_SIZE][MAX_SIZE];
vector<int> graph[MAX_GRAPH];
int dist[MAX_GRAPH], degree[MAX_GRAPH];

inline bool border(int x, int y) { return x < 0 || y < 0 || x >= qt_row || y >= qt_col; }
inline int pin(int x, int y) { return x * qt_col + y; }

void clear() {
	qt_vert = qt_row * qt_col;
	for(int i = 0; i < qt_vert; i++) {
		dist[i] = degree[i] = 0;
		graph[i].clear();
	}
}

void buildGraph() {
	for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++) {
		for(int z = 0; z < 4; z++) {
			int nx = i+dr[z], ny = j+dc[z];
			if(border(nx,ny) || grid[nx][ny] >= grid[i][j]) continue;
			graph[pin(i,j)].push_back(pin(nx,ny));
			degree[pin(nx,ny)]++;
		}
	}
}

int bfs() {
	int ret = -1;
	queue<int> qe;
	for(int i = 0; i < qt_vert; i++) if(degree[i] == 0)
		qe.push(i);
	while(!qe.empty()) {
		int v = qe.front();	qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(dist[nv] == 0 || dist[nv] < dist[v] + 1) {
				dist[nv] = dist[v] + 1;
				ret = max(ret,dist[nv]);
				qe.push(nv);
			}
		}
	}
	return ret+1;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%s %d %d",word,&qt_row,&qt_col);
		clear();
		for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
			scanf("%d",&grid[i][j]);
		buildGraph();
		int ans = bfs();
		printf("%s: %d\n",word,ans);
	}
}
