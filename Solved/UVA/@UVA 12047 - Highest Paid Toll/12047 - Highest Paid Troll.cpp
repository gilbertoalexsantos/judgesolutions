//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3198

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int SOURCE = 0, SINK = 1;

const int MAX_VERT = 10000;
const int MAX_EDGE = 100000;
const int INF = 1e9;

int qt_vert, qt_edge, source, sink, p;
vector<ii> graph[MAX_VERT][2];
vector<iii> edge(MAX_EDGE);
int dist[MAX_VERT][2];

void clear() {
	source--, sink--;
	for(int i = 0; i < qt_vert; i++) {
		graph[i][SOURCE].clear(); graph[i][SINK].clear();
		dist[i][SOURCE] = dist[i][SINK] = INF;
	}
}

void dijkstra(int u, int type) {
	priority_queue<ii> pq;
	pq.push(ii(0,u));
	dist[u][type] = 0;
	while(!pq.empty()) {
		int v = pq.top().second, w = -pq.top().first; pq.pop();
		if(w > dist[v][type]) continue;
		for(int i = 0; i < graph[v][type].size(); i++) {
			int nv = graph[v][type][i].first, nw = graph[v][type][i].second;
			if(dist[nv][type] > dist[v][type]+nw) {
				dist[nv][type] = dist[v][type]+nw;
				pq.push(ii(-dist[nv][type],nv));
			}
		}
	}
}

int solve() {
	int ans = -1;
	for(int i = 0; i < qt_edge; i++) {
		int u = edge[i].second.first, v = edge[i].second.second, w = edge[i].first;
		int d = dist[u][SOURCE] + w + dist[v][SINK];
		if(d <= p) ans = max(ans,w);
	}
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d %d %d",&qt_vert,&qt_edge,&source,&sink,&p);
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, w;
			scanf("%d %d %d",&x,&y,&w);
			x--, y--;
			edge[i] = iii(w,ii(x,y));
			graph[x][SOURCE].push_back(ii(y,w));
			graph[y][SINK].push_back(ii(x,w));
		}
		dijkstra(source,SOURCE); dijkstra(sink,SINK);
		int ans = solve();
		printf("%d\n",ans);
	}
}
