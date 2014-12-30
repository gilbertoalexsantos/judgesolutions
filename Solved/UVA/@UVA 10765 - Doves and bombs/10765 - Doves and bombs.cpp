w//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1706

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 10000;
const int UNVISITED = -1;

int n, m;
int dfs_num[MAX], dfs_low[MAX], dfs_parent[MAX], qt_comp[MAX];
vector<int> graph[MAX];
int dfs_count, rootChildren;

void clear() {
	dfs_count = rootChildren = 0;
	for(int i = 0; i < n; i++) {
		dfs_num[i] = dfs_parent[i] = UNVISITED;
		qt_comp[i] = 1;
		graph[i].clear();
	}
}

void articularPoint(int u) {
	dfs_num[u] = dfs_low[u] = dfs_count++;
	for(int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if(dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if(u == 0) rootChildren++;
			articularPoint(v);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			if(dfs_low[v] >= dfs_num[u]) qt_comp[u]++;
		} else if(dfs_parent[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	while(scanf("%d %d", &n, &m) && n+m) {
		clear();

		int a, b;
		while(scanf("%d %d", &a, &b) && !(a == -1 && b == -1)) 
			graph[a].push_back(b), graph[b].push_back(a);

		articularPoint(0);
		if(rootChildren < 2) qt_comp[0] = 1;

		vector<pint> ans;
		for(int i = 0; i < n; i++) ans.push_back(pint(-qt_comp[i],i));
		sort(ans.begin(), ans.end());

		for(int i = 0; i < m; i++) printf("%d %d\n", ans[i].second, -ans[i].first);
		printf("\n");
	}
}
