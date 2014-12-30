//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3312

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000;
const int INF = 1e9;

int l,u,r;
int w[10];

int dist[MAX];

void clear() {
	for(int i = 0; i < MAX; i++) {
		dist[i] = INF;
	}
}

int bfs() {
	if(l == u) return 0;
	queue<int> qe;
	qe.push(l);
	dist[l] = 0;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();

		for(int i = 0; i < r; i++) {
			int nv = (v+w[i])%10000;

			if(dist[nv] != INF) continue;

			dist[nv] = dist[v] + 1;
			if(nv == u) return dist[nv];
			qe.push(nv);
		}

	}

	return -1;
}

int main() {
	int cases = 1;
	while(scanf("%d %d %d",&l,&u,&r) && r) {
		clear();
		for(int i = 0; i < r; i++) scanf("%d",&w[i]);
		int ans = bfs();
		printf("Case %d: ",cases++);
		ans < 0 ? printf("Permanently Locked\n") : printf("%d\n",ans);
	}
}
