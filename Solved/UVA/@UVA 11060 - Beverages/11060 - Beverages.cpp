//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2001

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

typedef map<char*,int>::iterator IT;

const bool UNVISITED = 0, VISITED = 1;

struct cmp_str {
	bool operator() (char const *a, char const *b) const { return strcmp(a,b) < 0; }
};

vector<vector<int> > graph(100);
int in_degree[100];
bool visited[100];
map<char *,int,cmp_str> map_beer;
map<int,char *> map_int;
queue<int> ans;

void clear() {
	for(int i = 0; i < 100; i++) graph[i].clear();
	memset(visited,UNVISITED,sizeof visited);
	memset(in_degree,0,sizeof in_degree);
	while(!ans.empty()) ans.pop();
	map_beer.clear(), map_int.clear();
}

void kahn_algorithm(int n) {
	queue<int> qe;
	bool ok = true;
	while(ok) {
		ok = false;
		for(int i = 0; i < n; i++) {
			if(visited[i] == VISITED || in_degree[i]) continue;
			ok = true;
			visited[i] = VISITED;
			ans.push(i);
			for(int j = 0; j < graph[i].size(); j++) in_degree[graph[i][j]]--;
			break;
		}
	}
}

int main() {
	int n, cases = 1;
	while(scanf("%d",&n) != EOF) {
		clear();
		for(int i = 0; i < n; i++) {
			char *w = new char[53], *w2 = new char[53];
			scanf("%s",w);
			strcpy(w2,w);
			map_beer.insert(make_pair(w,i));
			map_int.insert(make_pair(i,w2));
		}
		int m;
		scanf("%d",&m);
		for(int i = 0, j = 0; i < m; i++) {
			char *a = new char[53], *b = new char[53];
			scanf("%s %s",a,b);
			int v1 = map_beer.find(a)->second, v2 = map_beer.find(b)->second;
			graph[v1].push_back(v2);
			in_degree[v2]++;
		}
		kahn_algorithm(n);
		printf("Case #%d: Dilbert should drink beverages in this order:",cases++);
		while(!ans.empty()) {
			int v = ans.front();
			ans.pop();
			printf(" %s",map_int.find(v)->second);
		}
		printf(".\n\n");
	}
}
