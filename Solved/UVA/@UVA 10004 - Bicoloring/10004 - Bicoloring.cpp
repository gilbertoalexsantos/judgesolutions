//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int UNCOLOR = -1, BLACK = 0, WHITE = 1;
const bool UNVISITED = 0, VISITED = 1;

vector<vector<int> > graph(200);
int color[200];

void clear(int n) {
	for(int i = 0; i < n; i++) {
		graph[i].clear();
		color[i] = UNCOLOR;
	}
}

bool bfs(int vert) {
	queue<int> qe;
	color[vert] = BLACK;
	qe.push(vert);

	while(!qe.empty()) {
		int v = qe.front();
		qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(color[nv] == UNCOLOR) {
				color[nv] = !color[v];
				qe.push(nv);
			}
			else if(color[nv] == color[v]) return false;
		}
	}

	return true;
}

int main() {
	int qt_vert;
	while(scanf("%d",&qt_vert) && qt_vert) {
		clear(qt_vert);
		int qt_edge;
		scanf("%d",&qt_edge);
		for(int i = 0; i < qt_edge; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			graph[x].push_back(y), graph[y].push_back(x);
		}
		bool ans = bfs(0);
		ans ? printf("BICOLORABLE.\n") : printf("NOT BICOLORABLE.\n");
	}
}
