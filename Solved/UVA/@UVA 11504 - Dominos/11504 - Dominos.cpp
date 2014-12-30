//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2499

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

const int UNVISITED = 0, VISITED = 1;
const int MAX = 100000;

vi graph[MAX];
int dfs_low[MAX], dfs_num[MAX], degree[MAX];
bool visited[MAX];
int qt_vert, qt_edge, qt_comp, dfsCount, ans;
vi scc;

void clear() {
	ans = dfsCount = 0;
	scc.clear();
	for(int i = 0; i < qt_vert; i++) {
		degree[i] = 0;
		dfs_low[i] = dfs_num[i] = -1;
		graph[i].clear();
		visited[i] = UNVISITED;;
	}
}

void TarjanSCC(int v) {
	dfs_low[v] = dfs_num[v] = dfsCount++;
	visited[v] = VISITED;
	scc.push_back(v);

	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(dfs_num[nv] == -1)
			TarjanSCC(nv);
		
		if(visited[nv] == VISITED) {
			dfs_low[v] = min(dfs_low[v],dfs_low[nv]);
			degree[nv]--;
		}
	}

	if(dfs_low[v] == dfs_num[v]) {
		bool incoming_edge = false;
		int u;
		do {
			u = scc.back(); scc.pop_back();
			visited[u] = UNVISITED;
			if(degree[u]) incoming_edge = true;
		} while(u != v);

		if(!incoming_edge) ans++;
	}
}

void TarjanSCC() {
	for(int i = 0; i < qt_vert; i++) if(dfs_num[i] == -1)
		TarjanSCC(i);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_vert, &qt_edge);
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			graph[x-1].push_back(y-1);
			degree[y-1]++;
		}

		TarjanSCC();

		printf("%d\n",ans);
	}
}
