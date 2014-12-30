//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2458

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_VERT = 100;
const int INF = 1e9;

int qt_vert, qt_edge;
int dist[MAX_VERT][MAX_VERT];
int source, sink;

void clear() {
	for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++) {
		dist[i][j] = (i == j) ? 0 : INF;
	}
}

void floyd() {
	for(int k = 0; k < qt_vert; k++)
		for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++)
			dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

int solve() {
	int ans = -1;
	for(int i = 0; i < qt_vert; i++)
		ans = max(ans,dist[source][i] + dist[i][sink]);
	return ans;
}

int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_vert,&qt_edge);
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y; scanf("%d %d",&x,&y);
			dist[x][y] = dist[y][x] = 1;
		}
		scanf("%d %d",&source,&sink);
		floyd();
		int ans = solve();
		printf("Case %d: %d\n",cases++,ans);
	}
}
