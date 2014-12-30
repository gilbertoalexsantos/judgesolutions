//Author:	Gilberto A. dos Santos
//Website:	http://www.spoj.com/problems/EZDIJKST/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> pint;

vector<pint> graph[100001];
bool visited[100001];
int dist[100001];

int dijkstra(int x, int y) {
	priority_queue<pint> pq;
	pint temp(0,x);
    pq.push(temp);
	dist[x] = 0;
	while(!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		if(visited[v]) continue;
		for(register int i = 0; i < graph[v].size(); i++) {
			int z = graph[v][i].first, w = graph[v][i].second;
			if(visited[z]) continue;
			if(dist[z] > dist[v] + w || dist[z] == -1) {
				dist[z] = dist[v] + w;
				pint v_temp(-dist[z],z);
				pq.push(v_temp);
			}
		}
		visited[v] = 1;
	}
	return dist[y];
}

void clear(int n) {
	for(register int i = 1; i <= n; i++) {
		visited[i] = 0;
		dist[i] = -1;
		graph[i].clear();
	}
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int qt_v, qt_e;
		scanf("%d %d",&qt_v,&qt_e);
		clear(qt_v);
		for(int i = 0; i < qt_e; i++) {
			int a, b, p;
			scanf("%d %d %d",&a,&b,&p);
			pint temp(b,p);
			graph[a].push_back(temp);
		}
		int A, B;
		scanf("%d %d",&A,&B);
		int ans = dijkstra(A,B);
		(ans == -1) ? printf("NO\n") : printf("%d\n",ans);
	}
}
