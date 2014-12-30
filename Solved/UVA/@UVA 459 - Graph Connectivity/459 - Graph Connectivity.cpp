//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const bool UNVISITED = 0, VISITED = 1;
const int MAX = 26;

vector<vector<int> > graph(MAX);
bool visited[MAX];

void clear() {
	memset(visited,UNVISITED,sizeof visited);
	for(int i = 0; i < MAX; i++) graph[i].clear();
}

void dfs(int vert) {
	visited[vert] = VISITED;
	for(int i = 0; i < graph[vert].size(); i++) {
		int nvert = graph[vert][i];
		if(visited[nvert] == UNVISITED) dfs(nvert);
	}
}

int main() {
	int T;
	char w[4];
	scanf("%d\n\n",&T);
	while(T--) {
		clear();	

		fgets(w,4,stdin);
		int qt_vert = w[0] - 'A';

		while(fgets(w,4,stdin) && w[0] != '\n') {
			int p1 = w[0] - 'A', p2 = w[1] - 'A';
			graph[p1].push_back(p2), graph[p2].push_back(p1);
		}

		int ans = 0;
		for(int i = 0; i <= qt_vert; i++) {
			if(visited[i] == UNVISITED) {
				dfs(i);
				ans++;
			}
		}

		printf("%d\n",ans);
		if(T) printf("\n");
	}
}
