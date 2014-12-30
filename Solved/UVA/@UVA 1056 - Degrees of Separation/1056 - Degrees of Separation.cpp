//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3497

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

typedef map<char*,int>::iterator IT;

const int MAX_VERT = 50;
const int MAX_WORD = 100;
const int INF = 1e9;

struct cmp { bool operator() (const char *a, const char *b) const { return strcmp(a,b) < 0; } };

int qt_vert, qt_edge, cnt;
int dist[MAX_VERT][MAX_VERT];
map<char*,int,cmp> MAP;

void clear() {
	cnt = 0;
	MAP.clear();
	for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++)
		dist[i][j] = (i == j) ? 0 : INF;
}

int ins(char *w) {
	IT it = MAP.find(w);
	if(it == MAP.end()) {
		MAP.insert(make_pair(w,cnt++));
		return cnt-1;
	}
	return it->second;
}

void floyd() {
	for(int k = 0; k < qt_vert; k++)
		for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++)
			dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

int solve() {
	int ans = -1;
	for(int i = 0; i < qt_vert; i++) for(int j = i+1; j < qt_vert; j++) {
		if(dist[i][j] == INF) return -1;
		ans = max(ans,dist[i][j]);
	}
	return ans;
}

int main() {
	int cases = 1;
	while(scanf("%d %d",&qt_vert,&qt_edge) && qt_vert+qt_edge) {
		clear();
		for(int i = 0; i < qt_edge; i++) {
			char *w1 = new char[MAX_WORD], *w2 = new char[MAX_WORD];
			scanf("%s %s",w1,w2);
			int x = ins(w1), y = ins(w2);
			dist[x][y] = dist[y][x] = 1;
		}
		floyd();
		int ans = solve();
		printf("Network %d: ",cases++);
		ans < 0 ? printf("DISCONNECTED\n\n") : printf("%d\n\n",ans);
	}
}
