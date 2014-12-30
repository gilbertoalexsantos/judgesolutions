//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2352

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int MAX = 1000;
const int INF = 1e9;

vector<ii> graph[MAX];
int qt_vert, qt_edge;
int regen[MAX];
int dist[MAX][101];

void clear(int n) {
	for(int i = 0; i < n; i++) {
		graph[i].clear();
	}
}

int debug = 0;

int dijkstra(int fuel, int source, int sink) {
	priority_queue<iii> pq;
	pq.push(iii(0,ii(source,0)));
	dist[source][0] = 0;
	while(!pq.empty()) {
		iii p = pq.top();
		int w = -pq.top().first, v = pq.top().second.first, f = pq.top().second.second;

		if(v == sink) return w;

		pq.pop();
		if(w > dist[v][f]) continue;

		if(f < fuel && dist[v][f+1] > dist[v][f]+regen[v]) {
			dist[v][f+1] = dist[v][f]+regen[v];
			pq.push(iii(-dist[v][f+1],ii(v,f+1)));
		}

		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i].first, nw = graph[v][i].second;
			if(f >= nw && dist[nv][f-nw] > dist[v][f]) {
				dist[nv][f-nw] = dist[v][f];
				pq.push(iii(-dist[nv][f-nw],ii(nv,f-nw)));
			}
		}
	}

	return INF;
}

int main() {
	while(scanf("%d %d",&qt_vert,&qt_edge) != EOF) {
		clear(qt_vert);
		for(int i = 0; i < qt_vert; i++) scanf("%d",&regen[i]);
		for(int i = 0; i < qt_edge; i++) {
			int x, y, d;
			scanf("%d %d %d",&x,&y,&d);
			graph[x].push_back(ii(y,d)), graph[y].push_back(ii(x,d));
		}
		int qt_query;
		scanf("%d",&qt_query);
		while(qt_query--) {
			int f, x, y;
			scanf("%d %d %d",&f,&x,&y);
			for(int i = 0; i < qt_vert; i++) for(int j = 0; j <= f; j++)
				dist[i][j] = INF;
			int ans = dijkstra(f,x,y);
			ans == INF ? printf("impossible\n") : printf("%d\n",ans);
		}
	}
}
