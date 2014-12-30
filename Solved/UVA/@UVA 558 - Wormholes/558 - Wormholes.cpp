//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int MAX_VERT = 1000;
const int MAX_EDGE = 2000;
const int INF = 1e9;

int qt_vert, qt_edge;
vector<ii> graph[MAX_VERT];
int dist[MAX_VERT];

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
		dist[i] = INF;
	}
}

bool ford() {
	dist[0] = 0;
	for(int i = 0; i < qt_vert-1; i++)
		for(int j = 0; j < qt_vert; j++) for(int z = 0; z < graph[j].size(); z++) {
			int nv = graph[j][z].first, nw = graph[j][z].second;
			dist[nv] = min(dist[nv],dist[j]+nw);
		}
	for(int i = 0; i < qt_vert; i++) for(int j = 0; j < graph[i].size(); j++) {
		int nv = graph[i][j].first, nw = graph[i][j].second;
		if(dist[nv] > dist[i]+nw) return true;
	}
	return false;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_vert,&qt_edge);
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, c;
			scanf("%d %d %d",&x,&y,&c);
			graph[x].push_back(ii(y,c));
		}
		bool ans = ford();
		printf("%s\n",ans ? "possible" : "not possible");
	}
}
