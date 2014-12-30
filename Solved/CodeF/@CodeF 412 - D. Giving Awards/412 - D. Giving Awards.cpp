//Author:	Gilberto A. dos Santos
//Website:	http://codeforces.com/contest/412/problem/D

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 30000;

int qt_vert, qt_edge;
vector<int> ans;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int v) {
	visited[v] = true;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(!visited[nv])
			dfs(nv);
	}
	ans.push_back(v);
}

int main() {
	memset(visited,false,sizeof visited);

	scanf("%d %d",&qt_vert,&qt_edge);
	for(int i = 0; i < qt_edge; i++) {
		int x, y; scanf("%d %d",&x,&y);
		x--, y--;
		graph[y].push_back(x);
	}

	for(int i = 0; i < qt_vert; i++) if(!visited[i])
		dfs(i);

	printf("%d",ans[ans.size()-1]+1);
	for(int i = ans.size()-2; i >= 0; i--)
		printf(" %d",ans[i]+1);
	printf("\n");
}
