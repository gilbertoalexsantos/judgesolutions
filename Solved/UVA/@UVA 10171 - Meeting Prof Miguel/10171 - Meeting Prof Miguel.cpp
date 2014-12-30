//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1112

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int MAX = 26;
const int YOUNG = 0, AGED = 1;
const int INF = 1e9;

int qt_edge;
int dist[MAX][MAX][2];
int source, sink;

void clear() {
	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) {
		dist[i][j][YOUNG] = (i == j) ? 0 : INF;
		dist[i][j][AGED] = (i == j) ? 0 : INF;
	}
}

void floyd() {
	for(int k = 0; k < MAX; k++)
		for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) {
			dist[i][j][YOUNG] = min(dist[i][j][YOUNG],dist[i][k][YOUNG]+dist[k][j][YOUNG]);
			dist[i][j][AGED] = min(dist[i][j][AGED],dist[i][k][AGED]+dist[k][j][AGED]);
		}
}

void solve() {
	int best = INF;
	for(int i = 0; i < MAX; i++) {
		int w = dist[source][i][YOUNG] + dist[sink][i][AGED];
		best = min(best,w);
	}

	if(best == INF) {
		printf("You will never meet.\n");
		return;
	}

	vector<char> ans;
	for(int i = 0; i < MAX; i++) {
		int w = dist[source][i][YOUNG] + dist[sink][i][AGED];
		if(w == best) ans.push_back(i+'A');
	}
	printf("%d %c",best,ans[0]);
	for(int i = 1; i < ans.size(); i++) printf(" %c",ans[i]);
	printf("\n");
}

int main() {
	while(scanf("%d\n",&qt_edge) && qt_edge) {
		clear();
		char type, con, x, y; 
		int w;
		for(int i = 0; i < qt_edge; i++) {
			scanf("%c %c %c %c %d\n",&type,&con,&x,&y,&w);
			int a = x-'A', b = y-'A';
			int t = type == 'Y' ? YOUNG : AGED;
			dist[a][b][t] = min(dist[a][b][t],w);
			if(con == 'B') dist[b][a][t] = min(dist[b][a][t],w);
		}
		scanf("%c %c",&x,&y);
		source = x-'A', sink = y-'A';
		floyd();
		solve();
	}
}
