//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=848

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX_VERT = 602;
const int MAX_NIGHT = 302;
const int INF = 1e9;

int qt_vert, night;
int dist[MAX_VERT];
int memo[MAX_VERT][MAX_NIGHT];
int source = 0, sink;

void clear() {
	memset(memo,-1,sizeof memo);
	dist[0] = 0;
	sink = qt_vert+1;
}

int dp(int v = source, int k = 0) {
	if(k == night || v == sink)
		return dist[sink] - dist[v];

	int &ret = memo[v][k];
	if(ret != -1)
		return ret;

	ret = INF;

	int p1 = max(dp(v+1,k+1),dist[v+1] - dist[v]);
	ret = min(ret,p1);
	for(int i = v+2; i <= sink - (night - k); i++) {
		int p2 = max(dp(i,k+1),dist[i] - dist[v]);
		ret = min(ret,p2);
	}

	return ret;
}

int main() {
	while(scanf("%d %d",&qt_vert,&night) != EOF) {
		clear();
		for(int i = 1; i <= qt_vert+1; i++) {
			scanf("%d",&dist[i]);
			dist[i] += dist[i-1];
		}
		int ans = dp();
		printf("%d\n",ans);
	}
}
