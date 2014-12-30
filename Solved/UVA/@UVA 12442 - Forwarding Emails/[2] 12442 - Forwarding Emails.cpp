//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pint;

const bool UNVISITED = 0, VISITED = 1;

vector<vector<int> > graph(50000);
int email[50000];
bool visited[50000];
bool is_cycle[50000];
int pos_cycle[50000];
int comp[50000];
vector<bool> has_cycle_comp(50000);
int qt_vert, cnt_comp;

void clear(int n) {
	cnt_comp = 0;
	for(int i = 0; i < qt_vert; i++) {
		has_cycle_comp[i] = false;
		is_cycle[i] = false;
		pos_cycle[i] = i;
		comp[i] = -1;
		visited[i] = UNVISITED;
		email[i] = 0;
		graph[i].clear();
	}
}

void connectCycles() {
	for(int i = 0; i < qt_vert; i++) {
		if(visited[i] == VISITED || has_cycle_comp[comp[i]]) continue;

		int cycle_start = i;
		while(visited[cycle_start] == UNVISITED) {
			visited[cycle_start] = VISITED;
			cycle_start = graph[cycle_start][0];
		}

		int cur = cycle_start, cnt = 0;
		do {
			cnt++;
			pos_cycle[cur] = cycle_start;
			cur = graph[cur][0];
		} while(cur != cycle_start);

		if(cnt == 2) cnt = 1;

		email[cycle_start] = cnt;
		has_cycle_comp[comp[cycle_start]] = true;
	}
}

int dfs2(int vert) {
	visited[vert] = VISITED;
	int nvert = graph[vert][0];
	if(visited[nvert]) comp[vert] = comp[nvert] == -1 ? cnt_comp++ : comp[nvert];
	else comp[vert] = dfs2(nvert);
	return comp[vert];
}

void getComp() {
	for(int i = 0; i < qt_vert; i++) if(visited[i] == UNVISITED)
		dfs2(i);
	memset(visited,UNVISITED,sizeof visited);
}

int dfs(int vert) {
	int tvert = graph[vert][0];
	int nvert = pos_cycle[tvert];
	return email[vert] = 1 + (email[nvert] ? email[nvert] : dfs(nvert));
}

int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&qt_vert);
		clear(qt_vert);
		for(int i = 0; i < qt_vert; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			graph[x-1].push_back(y-1);
		}

		getComp();
		connectCycles();

		pint ans(0,-1);
		for(int i = 0; i < qt_vert; i++) {
			int t = email[pos_cycle[i]] ? email[pos_cycle[i]] : dfs(i);
			if(ans.second < t) {
				ans.first = i;
				ans.second = t;
			}
		}

		printf("Case %d: %d\n",cases++,ans.first+1);
	}
}
