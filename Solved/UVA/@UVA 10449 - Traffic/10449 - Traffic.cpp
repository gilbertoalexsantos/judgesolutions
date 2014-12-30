//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1390

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_VERT = 200;
const int INF = 1e9;

int qt_vert, qt_edge, qt_query;
int bus[MAX_VERT], dist[MAX_VERT];
bool visited[MAX_VERT];
vector<int> graph[MAX_VERT];

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
		dist[i] = INF;
		visited[i] = false;
	}
}

void dfs(int v) {
	visited[v] = true;
	dist[v] = -INF;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(!visited[nv]) dfs(nv);
	}
}

void bellman() {
	dist[0] = 0;
	for(int i = 0; i < qt_vert-1; i++)
		for(int j = 0; j < qt_vert; j++) for(int z = 0; z < graph[j].size(); z++) {
			int v = j, nv = graph[j][z];
			int w = pow(bus[nv]-bus[v],3);
			dist[nv] = min(dist[nv],dist[v]+w);
		}

	// Checking Negative Cycles
	bool mark[qt_vert];
	memset(mark,false,sizeof mark);
	for(int i = 0; i < qt_vert; i++) for(int j = 0; j < graph[i].size(); i++) {
		int v = i, nv = graph[i][j];
		int w = pow(bus[nv]-bus[v],3);
		if(dist[nv] > dist[v]+w) mark[v] = mark[nv] = true;
	}
	for(int i = 0; i < qt_vert; i++) if(mark[i])
		dfs(i);
}

int main() {
	int cases = 1;
	while(scanf("%d",&qt_vert) == 1) {
		clear();
		for(int i = 0; i < qt_vert; i++) scanf("%d",&bus[i]);
		scanf("%d",&qt_edge);
		for(int i = 0; i < qt_edge; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			x--, y--;
			graph[x].push_back(y);
		}
		bellman();
		scanf("%d",&qt_query);
		printf("Set #%d\n",cases++);
		while(qt_query--) {
			int x; scanf("%d",&x);
			x--;
			(x >= qt_vert || x < 0 || dist[x] < 3 || dist[x] == INF) ? printf("?\n") : printf("%d\n",dist[x]);
		}
	}	
}
