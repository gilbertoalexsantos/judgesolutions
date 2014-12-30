//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> pint;
typedef priority_queue<pint> prq;

const int INF = 1 << 30;

vector<vector<pint> > graph(20000);
int fdist[20000];
bool visited[20000];

void clear(int n) {
	for(int i = 0; i < n; i++) {
		visited[i] = false;
		graph[i].clear();
		fdist[i] = INF;
	}
}

int dijkstra(int x, int y) {	
	prq prior;
	prior.push(pint(0,x));
	fdist[x] = 0;
	while(!prior.empty()) {
		int vert = prior.top().second;
        if(vert == y) return -prior.top().first;
		prior.pop();
		if(visited[vert]) continue;
		for(int i = 0; i < graph[vert].size(); i++) {
			int nvert = graph[vert][i].first, ndist = graph[vert][i].second;
			if(visited[nvert]) continue;
			if(fdist[nvert] > fdist[vert] + ndist) {
				fdist[nvert] = fdist[vert] + ndist;
				prior.push(pint(-fdist[nvert],nvert));
			}
		}
		visited[vert] = true;
	}
	return fdist[y];
}

int main() {
	int N, cases = 1;
	scanf("%d",&N);
	while(N--) {
		int n, m, s, t;
		scanf("%d %d %d %d",&n,&m,&s,&t);
		clear(n);
		for(int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			graph[x].push_back(pint(y,z)), graph[y].push_back(pint(x,z));
		}
		int ans = dijkstra(s,t);
		ans == INF ? printf("Case #%d: unreachable\n",cases++) : printf("Case #%d: %d\n",cases++,ans);
	}
}
