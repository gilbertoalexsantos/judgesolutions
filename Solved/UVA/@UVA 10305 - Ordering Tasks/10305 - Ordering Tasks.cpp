//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;

vector<vector<int> > graph(MAX);
int degree[MAX];

void clear(int n) {
	for(int i = 0; i < n; i++) {
		graph[i].clear();
		degree[i] = 0;
	}
}

void topsort(int qt_vert) {
	queue<int> qe, ans;
	for(int i = 0; i < qt_vert; i++) if(!degree[i])
		qe.push(i);

	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		ans.push(v);

		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			degree[nv]--;
			if(!degree[nv]) qe.push(nv);
		}
	}

	printf("%d",ans.front()+1); ans.pop();
	while(!ans.empty()) {
		printf(" %d",ans.front()+1);
		ans.pop();
	}
	printf("\n");
}

int main() {
	int qt_vert, qt_edge;
	while(scanf("%d %d",&qt_vert,&qt_edge) && qt_vert+qt_edge) {
		clear(qt_vert);
		for(int i = 0; i < qt_edge; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			graph[x-1].push_back(y-1);
			degree[y-1]++;
		}
		topsort(qt_vert);
	}
}
