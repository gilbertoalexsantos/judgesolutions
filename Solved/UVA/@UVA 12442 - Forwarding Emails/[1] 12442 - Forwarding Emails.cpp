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
int qt_vert;

void clear(int n) {
	for(int i = 0; i < qt_vert; i++) {
		visited[i] = UNVISITED;
		email[i] = 0;
		graph[i].clear();
	}
}

int dfs(int vert) {
	visited[vert] = VISITED;
	int nvert = graph[vert][0];
	int sum = 0;
	if(visited[nvert] == UNVISITED) sum = 1 + dfs(nvert);
	visited[vert] = UNVISITED;
	return sum;
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

		pint ans(0,-1);
		for(int i = 0; i < qt_vert; i++) {
			int t = email[i] ? email[i] : dfs(i);
			if(ans.second < t) {
				ans.first = i+1;
				ans.second = t;
			}
		}

		printf("Case %d: %d\n",cases++,ans.first);
	}
}
