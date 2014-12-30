//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;

const int MAX = 100;
const int UNVISITED = -1;

vector<vi> graph(MAX);
vi dfs_num(MAX), dfs_low(MAX), dfs_parent(MAX);
bool articularPoint[MAX];
bool has_edge[MAX][MAX];

int qt_vert, dfsCounter, dfsRoot, rootChildren;

void clear(int n) {
	dfsCounter = dfsRoot = rootChildren = 0;
	memset(has_edge,false,sizeof has_edge);
	for(int i = 0; i < n; i++) {
		articularPoint[i] = false;
		dfs_num[i] = dfs_low[i] = UNVISITED;
		dfs_parent[i] = i;
		graph[i].clear();
	}
}

void dfs(int v) {
	dfs_num[v] = dfs_low[v] = dfsCounter++;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(dfs_num[nv] == UNVISITED) {
			dfs_parent[nv] = v;
			if(v == dfsRoot) rootChildren++;

			dfs(nv);

			if(dfs_low[nv] >= dfs_num[v]) articularPoint[v] = true;
			dfs_low[v] = min(dfs_low[v],dfs_low[nv]);
		} else if(dfs_parent[v] != nv) dfs_low[v] = min(dfs_low[v],dfs_num[nv]);
	}
}

int main() {
	while(scanf("%d\n",&qt_vert) && qt_vert) {
		clear(qt_vert);
		char w[120];
		while(fgets(w,120,stdin) && w[0] != '0') {
			char *f = strtok(w," ");
			int x = atoi(f);
			f = strtok(NULL," ");
			while(f != NULL) {
				int y = atoi(f);	
				if(has_edge[x][y] == false) {
					graph[x-1].push_back(y-1), graph[y-1].push_back(x-1);
					has_edge[x][y] = has_edge[y][x] = true;
				}
				f = strtok(NULL," ");
			}
		}
		dfs(0);
		int ans = 0;
		if(articularPoint[0] && rootChildren >= 2) ans++;
		for(int i = 1; i < qt_vert; i++) if(articularPoint[i]) ans++;
		printf("%d\n",ans);
	}
}
