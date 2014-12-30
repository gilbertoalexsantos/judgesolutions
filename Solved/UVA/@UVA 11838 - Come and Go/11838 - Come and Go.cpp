//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;

const int UNCALC = -1, UNVISITED = 0, VISITED = 1;
const int MAX = 2000;

vi graph[MAX], scc;
int dfs_low[MAX], dfs_num[MAX];
bool visited[MAX];
int qt_vert, qt_edge, dfsCounter, qt_scc;

void clear() {
	dfsCounter = qt_scc = 0;
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
		dfs_low[i] = dfs_num[i] = UNCALC;
		visited[i] = UNVISITED;
	}
}

void TarjanSCC(int v) {
	dfs_low[v] = dfs_num[v] = dfsCounter++;
	visited[v] = VISITED;
	scc.push_back(v);
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(dfs_num[nv] == UNCALC)
			TarjanSCC(nv);
		if(visited[nv] == VISITED)
			dfs_low[v] = min(dfs_low[v],dfs_low[nv]);
	}

	if(dfs_low[v] == dfs_num[v]) {
		int nv;
		qt_scc++;
		do {
			nv = scc.back(); scc.pop_back();
			visited[nv] = UNVISITED;
		} while(nv != v);
	}
}

void TarjanSCC() {
	for(int i = 0; i < qt_vert; i++) if(dfs_num[i] == UNCALC) {
		TarjanSCC(i);
		if(qt_scc > 1) return;
	}
}

int main() {
	while(scanf("%d %d",&qt_vert,&qt_edge) && qt_vert+qt_edge) {
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			graph[x-1].push_back(y-1);
			if(z == 2) graph[y-1].push_back(x-1);
		}
		TarjanSCC();
		int ans = (qt_scc == 1) ? 1 : 0;
		printf("%d\n",ans);
	}
}
