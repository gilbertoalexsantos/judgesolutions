//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3553

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 100;
const int INF = 1e9;

vector<ii> graph[MAX];
int dist[MAX];

int qt_vert, qt_edge, out, limit;

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
		dist[i] = INF;
	}
}

int dijkstra() {
	priority_queue<ii> pq;
	pq.push(ii(0,out-1));
	dist[out-1] = 0;
	while(!pq.empty()) {
		int v = pq.top().second, w = -pq.top().first; pq.pop();
		if(dist[v] > w) continue;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i].first, nw = graph[v][i].second;
			if(dist[nv] > dist[v]+nw) {
				dist[nv] = dist[v]+nw;
				pq.push(ii(-dist[nv],nv));
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < qt_vert; i++)
		if(dist[i] <= limit) ans++;
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d %d",&qt_vert,&out,&limit,&qt_edge);	
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, w;
			scanf("%d %d %d",&x,&y,&w);
			x--, y--;
			graph[x].push_back(ii(y,w)), graph[y].push_back(ii(x,w));
		}
		int ans = dijkstra();
		printf("%d\n",ans);
		if(T) printf("\n");
	}
}
