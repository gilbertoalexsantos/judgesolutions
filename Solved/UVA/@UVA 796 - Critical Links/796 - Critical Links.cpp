//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;
typedef vector<int> vi;
const int MAX = 500;
const int UNVISITED = -1;

vector<vi> graph(MAX);
vi dfs_num(MAX), dfs_low(MAX), dfs_parent(MAX);
vector<pint> ans;
bool has_vert[MAX][MAX], bridge[MAX][MAX];
int qt_vert, dfsCount;

void pr() {
	for(int i = 0; i < qt_vert; i++) {
		printf("[%d]",i);
		for(int j = 0; j < graph[i].size(); j++) printf(" => %d",graph[i][j]);
		printf("\n");
	}
}

void clear() {
	dfsCount = 0;
	memset(has_vert,false,sizeof has_vert);
	memset(bridge,false,sizeof bridge);
	ans.clear();
	for(int i = 0; i < qt_vert; i++) {
		dfs_num[i] = dfs_low[i] = UNVISITED;
		dfs_parent[i] = i;
		graph[i].clear();
	}
}

void dfs(int v) {
	if(dfs_num[v] != UNVISITED) return;
	dfs_num[v] = dfs_low[v] = dfsCount++;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(dfs_num[nv] == UNVISITED) {
			dfs_parent[nv] = v;
			dfs(nv);
			if(dfs_low[nv] > dfs_num[v]) {
				int a = min(v,nv), b = max(v,nv);
				if(!bridge[a][b]) {
					bridge[a][b] = true;
					ans.push_back(pint(a,b));
				}
			}
			dfs_low[v] = min(dfs_low[v],dfs_low[nv]);
		} else if(dfs_parent[v] != nv) dfs_low[v] = min(dfs_low[v],dfs_num[nv]);
	}
}

int main() {
	while(scanf("%d",&qt_vert) != EOF) {
		clear();
		for(int i = 0; i < qt_vert; i++) {
			int x, y, k;
			scanf("%d (%d) ",&x,&k);
			for(int j = 0; j < k; j++) {
				scanf("%d",&y);
				if(!has_vert[x][y]) {
					graph[x].push_back(y), graph[y].push_back(x);
					has_vert[x][y] = has_vert[y][x] = true;
				}
			}
		}
		//pr();
		for(int i = 0; i < qt_vert; i++) dfs(i);
		sort(ans.begin(),ans.end());
		printf("%lu critical links\n",ans.size());
		for(int i = 0; i < ans.size(); i++) printf("%d - %d\n",ans[i].first,ans[i].second);
		printf("\n");
	}
}
