//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=995

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

const int MAX = 50;

int qt_vert, cnt;
int graph[MAX][MAX];
int tr[MAX], bg[MAX];
int degree[MAX];
bool visited[MAX];

void clear() {
	cnt = 0;
	for(int i = 0; i < MAX; i++) {
		tr[i] = -1;
		visited[i] = false;
		degree[i] = 0;
		for(int j = 0; j < MAX; j++) {
			graph[i][j] = 0;
		}
	}
}

void dfs(int v) {
	visited[v] = true;
	for(int i = 0; i < MAX; i++) {
		if(!graph[v][i] && !visited[i])
			dfs(i);
	}
}

bool has_tour() {
	for(int i = 0; i < cnt; i++)
		if(degree[i] % 2 != 0)
			return false;
	dfs(0);
	for(int i = 0; i < cnt; i++)
		if(!visited[i])
			return false;
	return true;
}

void EulerTour(int v) {
	for(int i = 0; i < MAX; i++) {
		if(graph[v][i]) {
			graph[v][i]--, graph[i][v]--;
			EulerTour(i);
			printf("%d %d\n",bg[i]+1,bg[v]+1);
		}
	}
}

int ins(int x) {
	if(tr[x] == -1) {
		tr[x] = cnt++;
		bg[tr[x]] = x;
		return tr[x];
	}
	return tr[x];
}

int main() {
	int cases = 1, T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&qt_vert);
		clear();
		for(int i = 0; i < qt_vert; i++) {
			int x, y; scanf("%d %d",&x,&y); x--, y--;
			int a = ins(x), b = ins(y);
			graph[a][b]++; graph[b][a]++;
			degree[a]++, degree[b]++;
		}
		printf("Case #%d\n",cases++);
		if(has_tour()) {
			EulerTour(0);
		} else
			printf("some beads may be lost\n");
		if(T)
			puts("");
	}
}
