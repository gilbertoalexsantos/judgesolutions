//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2391

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int UNCOLOR = -1, BLACK = 0, WHITE = 1;
const int MAX = 300;

vector<int> graph[MAX];
int color[MAX];
int qt_vert;

void clear() {
	for(int i = 0; i < MAX; i++) {
		graph[i].clear();
		color[i] = UNCOLOR;
	}
}

bool bfs(int vert) {
	if(color[vert] != UNCOLOR) return true;
	queue<int> qe;
	color[vert] = BLACK;
	qe.push(vert);
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(color[nv] == UNCOLOR) {
				color[nv] = !color[v];
				qe.push(nv);
			} else if(color[nv] == color[v]) return false;
		}
	}
	return true;
}

int main() {
	while(scanf("%d",&qt_vert) && qt_vert) {
		clear();
		int x, y;
		while(scanf("%d %d",&x,&y) && x+y)
			graph[x-1].push_back(y-1), graph[y-1].push_back(x-1);
		bool ans = true;
		for(int i = 0; i < qt_vert; i++) ans &= bfs(i);
		ans ? printf("YES\n") : printf("NO\n");
	}
}
