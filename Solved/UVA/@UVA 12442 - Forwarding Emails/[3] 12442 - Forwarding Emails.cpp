//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pint;

const bool UNVISITED = 0, VISITED = 1;
const int MAX = 50000;

vector<vector<int> > graph(MAX);
bool visited[MAX];
int email[MAX];
int qt_vert, d2;

void clear(int n) {
	d2 = -1;
	for(int i = 0; i < qt_vert; i++) {
		email[i] = 0;
		visited[i] = UNVISITED;
		graph[i].clear();
	}
}

void dfs2(int vert) {
	int flag_vert = graph[vert][0];
	int len = 0;
	while(flag_vert != vert) {
		len++;
		flag_vert = graph[flag_vert][0];
	}
	email[vert] = len;
	flag_vert = graph[vert][0];
	while(flag_vert != vert) {
		email[flag_vert] = len;
		flag_vert = graph[flag_vert][0];
	}
}

int dfs(int vert) {
	if(email[vert]) return email[vert] = email[vert];
	visited[vert] = VISITED;
	int nvert = graph[vert][0];
	if(email[nvert]) return email[vert] = 1 + email[nvert];
	if(visited[nvert] == VISITED) {
		d2 = nvert;
		return 0;
	}
	return email[vert] = 1 + dfs(nvert);
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
		for(int i = 0; i < qt_vert; i++) {
			dfs(i);
			if(d2 != -1) {
				dfs2(d2);
				d2 = -1;
			}
		}
		pint ans(0,-1);
		for(int i = 0; i < qt_vert; i++) if(ans.second < email[i]) ans = pint(i+1,email[i]);
		printf("Case %d: %d\n",cases++,ans.first);
	}
}
