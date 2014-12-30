//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=929

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 50000;

int qt_vert;
int source;
vector<int> graph[MAX];
int degree[MAX], path[MAX];

void clear() {
	source = 0;
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
		degree[i] = path[i] = 0;
	}
}

int solve() {
	int ret = 0;
	queue<int> qe;
	qe.push(source);
	path[source] = 1;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		if(graph[v].empty())
			ret += path[v];
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i]; degree[nv]--;
			path[nv] += path[v];
			if(degree[nv] == 0)
				qe.push(nv);
		}
	}
	return ret;
}

int main() {
	bool first = true;
	while(scanf("%d",&qt_vert) != EOF) {
		first ? first = false : puts("");
		clear();
		for(int i = 0; i < qt_vert; i++) {
			int k; scanf("%d",&k);
			while(k--) {
				int x; scanf("%d",&x);
				graph[i].push_back(x);
				degree[x]++;
			}
		}
		int ans = solve();
		printf("%d\n",ans);
	}
}
