//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2501

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_VERT = 50;
const int MAX_EDGE = 1000;
const int INF = 1e9;

int qt_vert, qt_edge;
int source, sink;
vector<int> graph[MAX_VERT*2];
int res[MAX_VERT*2][MAX_VERT*2];
int path[MAX_VERT*2];
bool visited[MAX_VERT*2];

inline int pin(int x) { return x; }
inline int pout(int x) { return x + MAX_VERT; }
inline void split(int x, int w) { graph[pin(x)].push_back(pout(x)), res[pin(x)][pout(x)] = w; }

void clear() {
	source = 0;
	sink = qt_vert-1;
	memset(res,0,sizeof res);
	for(int i = 0; i < qt_vert*2; i++) {
		graph[i].clear();
	}
}

int augment(int v = sink, int minEdge = INF) {
	if(v == source) return minEdge;
	else {
		int t = augment(path[v],min(res[path[v]][v],minEdge));
		res[path[v]][v] -= t, res[v][path[v]] += t;
		return t;
	}
}

bool bfs() {
	memset(path,-1,sizeof path);
	memset(visited,false,sizeof visited);
	queue<int> qe; qe.push(source);
	visited[source] = true;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		if(v == sink) return true;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i], flow = res[v][nv];
			if(!visited[nv] && flow > 0)
				visited[nv] = true, path[nv] = v, qe.push(nv);
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
	while(scanf("%d %d",&qt_vert,&qt_edge) && qt_vert+qt_edge) {
		clear();
		split(source,INF), split(sink,INF);
		for(int i = 0; i < qt_vert-2; i++) {
			int x, w; scanf("%d %d",&x,&w); x--;
			split(x,w);
		}
		for(int i = 0; i < qt_edge; i++) {
			int x, y, w; scanf("%d %d %d",&x,&y,&w); x--, y--;
			// Because are Bi-Directional
			graph[pout(x)].push_back(pin(y));
			graph[pin(y)].push_back(pout(x));

			graph[pout(y)].push_back(pin(x));
			graph[pin(x)].push_back(pout(y));

			res[pout(x)][pin(y)] = res[pout(y)][pin(x)] = w;
		}
		int ans = edmond();
		printf("%d\n",ans);
	}
}
