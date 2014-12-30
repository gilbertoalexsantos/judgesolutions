//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
const int INF = 1e9;

int qt_vert, qt_edge;
int source, sink;
vector<int> graph[MAX];
int res[MAX][MAX];
int path[MAX];
bool visited[MAX];

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
	}
	memset(res,0,sizeof res);
}

int augment(int v = sink, int minEdge = INF) {
	if(v == source) 
		return minEdge;
	else {
		int t = augment(path[v],min(res[path[v]][v],minEdge));
		res[path[v]][v] -= t, res[v][path[v]] += t;
		return t;
	}
}

bool bfs() {
	memset(visited,false,sizeof visited);
	memset(path,-1,sizeof path);
	queue<int> qe; qe.push(source);
	visited[source] = true;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		if(v == sink) return true;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i], flow = res[v][nv];
			if(!visited[nv] && flow > 0)
				path[nv] = v, visited[nv] = true, qe.push(nv);
		}
	}
	return false;
}

int edmond() {
	int maxflow = 0;
	while(bfs())
		maxflow += augment();
	return maxflow;
}

int main() {
	int cases = 1;
	while(scanf("%d",&qt_vert) && qt_vert) {
		clear();
		scanf("%d %d %d",&source,&sink,&qt_edge);
		source--, sink--;
		for(int i = 0; i < qt_edge; i++) {
			int x, y, w;
			scanf("%d %d %d",&x,&y,&w);
			x--, y--;
			if(res[x][y] == 0)
			graph[x].push_back(y), graph[y].push_back(x);
			res[x][y] += w, res[y][x] += w;
		}
		int ans = source == sink ? 0 : edmond();
		printf("Network %d\nThe bandwidth is %d.\n",cases++,ans);
		printf("\n");
	}
}
