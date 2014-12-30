//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=865

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 2500;
const int INF = 1e9;

vector<int> graph[MAX];
bool visited[MAX];

int qt_vert;

inline void ps(int i, int j) { graph[i].push_back(j); }

ii bfs(int x) {
	for(int i = 0; i < qt_vert; i++) visited[i] = false;
	queue<int> qe;
	qe.push(x);
	visited[x] = true;

	int qt_in_queue = 1, day = 1;
	ii ans(0,0);
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		qt_in_queue--;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(visited[nv]) continue;
			visited[nv] = true;
			qe.push(nv);
		}
		if(!qt_in_queue) {
			if(ans.first < qe.size()) ans = ii(qe.size(),day);
			qt_in_queue = qe.size(), day++;
		}
	}
	return ans;
}

int main() {
	scanf("%d",&qt_vert);
	for(int i = 0; i < qt_vert; i++) {
		int e;
		scanf("%d",&e);
		while(e--) {
			int j;
			scanf("%d",&j);
			ps(i,j);
		}
	}
	int T;
	scanf("%d",&T);
	while(T--) {
		int x;
		scanf("%d",&x);
		ii ans = bfs(x);
		printf("%d",ans.first);
		if(ans.first) printf(" %d",ans.second);
		printf("\n");
	}
}
