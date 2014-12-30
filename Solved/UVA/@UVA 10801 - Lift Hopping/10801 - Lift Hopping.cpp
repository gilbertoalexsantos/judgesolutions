//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1742

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int CHANGE = 60;
const int INF = 1e9;
const int MAX = 600;
const int DESTINY = 599;

int n, k, qt_vert, destiny;
int consume[5];
vector<ii> graph[MAX];
vector<int> same_floor[100];
int dist[MAX];

int dijkstra() {
	priority_queue<ii> pq;
	pq.push(ii(0,0));
	dist[0] = 0;
	while(!pq.empty()) {
		int v = pq.top().second, w = -pq.top().first; pq.pop();
		if(dist[v] > w) continue;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i].first, nw = graph[v][i].second;
			if(dist[nv] > dist[v]+nw) {
				dist[nv] = dist[v]+nw;
				if(nv == DESTINY) return dist[nv];
				pq.push(ii(-dist[nv],nv));
			}
		}
	}
	return -1;
}

void clear() {
	qt_vert = 1;
	for(int i = 0; i < MAX; i++) {
		graph[i].clear();
		dist[i] = INF;
	}
	for(int i = 0; i < 100; i++) {
		same_floor[i].clear();
	}
}

void pr() {
	for(int i = 0; i < qt_vert; i++) {
		printf("%d",i);
		for(int j = 0; j < graph[i].size(); j++) {
			printf(" => (%d,%d)",graph[i][j].first,graph[i][j].second);
		}
		printf("\n");
	}
}

inline void pb(int a, int b, int c) { graph[a].push_back(ii(b,c)), graph[b].push_back(ii(a,c)); }

int main() {
	while(scanf("%d %d",&n,&k) != EOF) {
		clear();
		for(int i = 0; i < n; i++) scanf("%d",&consume[i]);
		getchar();

		for(int i = 0; i < n; i++) {
			vector<int> edge;
			char w[300];
			fgets(w,300,stdin);
			char *f = strtok(w," ");
			while(f != NULL) {
				edge.push_back(atoi(f));
				f = strtok(NULL,"\n ");
			}

			same_floor[edge[0]].push_back(qt_vert);
			if(edge[0] == k) pb(qt_vert,DESTINY,0);
			qt_vert++;
			for(int j = 1; j < edge.size(); j++) {
				if(edge[j] == k) pb(qt_vert,DESTINY,0);
				same_floor[edge[j]].push_back(qt_vert);
				int w = (edge[j] - edge[j-1]) * consume[i];
				pb(qt_vert,qt_vert-1,w);
				qt_vert++;
			}
		}

		for(int i = 0; i < same_floor[0].size(); i++)
			pb(0,same_floor[0][i],0);
		for(int i = 1; i < 100; i++) for(int j = 0; j < same_floor[i].size(); j++)
				for(int z = 0; z < same_floor[i].size(); z++) if(j != z) {
					graph[same_floor[i][j]].push_back(ii(same_floor[i][z],60));
				}

		int ans = dijkstra();
		ans < 0 ? printf("IMPOSSIBLE\n") : printf("%d\n",ans);
	}	
}
