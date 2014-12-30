//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3053

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_VERT = 100;
const bool VISITED = 1, UNVISITED = 0;

vector<vector<int> > graph(MAX_VERT);
bool visited[MAX_VERT];
bool flag_visited[MAX_VERT];

void pword(int n) {
	printf("+");
	for(int i = 0; i < 2*n-1; i++) printf("-");
	printf("+\n");
}

void clear() {
	for(int i = 0; i < MAX_VERT; i++) {
		graph[i].clear();
		visited[i] = UNVISITED;
		flag_visited[i] = UNVISITED;
	}
}

void dfs(int vert) {
	visited[vert] = VISITED;
	for(int i = 0; i < graph[vert].size(); i++) {
		int nvert = graph[vert][i];
		if(visited[nvert] == VISITED) continue;
		dfs(nvert);
	}
}

void dfs(int vert, int out) {
	if(vert == out) return;

	flag_visited[vert] = VISITED;
	for(int i = 0; i < graph[vert].size(); i++) {
		int nvert = graph[vert][i];
		if(flag_visited[nvert] == VISITED) continue;
		dfs(nvert,out);
	}
}


int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		clear();
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
			int p;
			scanf("%d",&p);
			if(p) graph[i].push_back(j);
		}
		dfs(0);
		printf("Case %d:\n",cases++);
		pword(n);
		for(int i = 0; i < n; i++) {
			printf("|");
			dfs(0,i);
			for(int j = 0; j < n; j++) {
				if(visited[j] == UNVISITED) {
					printf("N|");
					continue;
				}
				flag_visited[j] == VISITED ? printf("N|") : printf("Y|");
			}
			memset(flag_visited,UNVISITED,sizeof flag_visited);
			printf("\n");
			pword(n);
		}
	}
}
