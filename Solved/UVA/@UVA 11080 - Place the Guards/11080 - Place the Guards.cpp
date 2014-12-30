//Author:	Gilberto Alexandre dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2021

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int UNCOLOR = -1, BLACK = 0, WHITE = 1;
const int MAX = 200;

vector<vector<int> > graph(MAX);
int color[MAX];
int qt_vert, qt_edge;

int bfs(int vert) {
	if(color[vert] != UNCOLOR) return 0;
	int qt_black = 1, qt_white = 0;
	color[vert] = BLACK;
	queue<int> qe;
	qe.push(vert);
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(color[nv] == UNCOLOR) {
				color[nv] = !color[v];
				color[nv] == BLACK ? qt_black++ : qt_white++;
				qe.push(nv);
			}
			else if(color[nv] == color[v]) return -1;
		}
	}
	return qt_white == 0 ? 1 : min(qt_black,qt_white);
}

void clear(int n) {
	for(int i = 0; i < n; i++) {
		graph[i].clear();
		color[i] = UNCOLOR;
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_vert,&qt_edge);
		clear(qt_vert);
		for(int i = 0; i < qt_edge; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			graph[x].push_back(y), graph[y].push_back(x);
		}
		int ans = 0;
		for(int i = 0; i < qt_vert; i++) {
			int t = bfs(i);
			if(t == -1) {
				ans = -1;
				break;
			} else ans += t;
		}
		printf("%d\n",ans);
	}
}
