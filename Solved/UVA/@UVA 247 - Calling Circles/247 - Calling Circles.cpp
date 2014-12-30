//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=183

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef map<char*,int>::iterator IT;

const bool UNVISITED = 0, VISITED = 1;
const int MAX = 25;
const int MAX_LETTER = 27;

struct cmp { bool operator()(const char *a, const char *b) const { return strcmp(a,b) < 0; } };

vi graph[MAX];
int dfs_low[MAX], dfs_num[MAX], visited[MAX];
vector<int> ans;
map<char*,int,cmp> map_charint;
map<int,char*> map_intchar;
bool has_vert[MAX][MAX];
int qt_vert, qt_edge, dfsCounter;

void pr() {
	for(int i = 0; i < qt_vert; i++) {
		printf("[%d]",i);
		for(int j = 0; j < graph[i].size(); j++) printf(" => %d",graph[i][j]);
		printf("\n");
	}
}

void clear() {
	dfsCounter = 0;
	for(int i = 0; i < qt_vert; i++) {
		visited[i] = false;
		graph[i].clear();
		dfs_low[i] = dfs_num[i] = -1;
	}
	memset(has_vert,false,sizeof has_vert);
	map_charint.clear(), map_intchar.clear();
}

void TarjanSCC(int v) {
	dfs_num[v] = dfs_low[v] = dfsCounter++;
	ans.push_back(v);
	visited[v] = VISITED;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(dfs_num[nv] == -1) TarjanSCC(nv);
		if(visited[nv] == VISITED) dfs_low[v] = min(dfs_low[v],dfs_low[nv]);
	}

	if(dfs_low[v] == dfs_num[v]) {
		int a = ans.back(); ans.pop_back(); visited[a] = UNVISITED;
		printf("%s",map_intchar.find(a)->second);
		while(!ans.empty() && v != a) {
			a = ans.back(); ans.pop_back(); visited[a] = UNVISITED;
			printf(", %s",map_intchar.find(a)->second);
		}
		printf("\n");
	}
}

void TarjanSCC() {
	for(int i = 0; i < qt_vert; i++) if(dfs_num[i] == -1)
		TarjanSCC(i);
}

int main() {
	int cases = 1;
	bool first = true;
	while(scanf("%d %d",&qt_vert,&qt_edge) && qt_vert+qt_edge) {
		clear();
		first ? first = false : printf("\n");
		for(int i = 0, pos = 0; i < qt_edge; i++) {
			char *a = new char[MAX_LETTER], *b = new char[MAX_LETTER];
			scanf("%s %s",a,b);
			if(map_charint.find(a) == map_charint.end()) {
				map_charint.insert(make_pair(a,pos));
				map_intchar.insert(make_pair(pos++,a));
			}
			if(map_charint.find(b) == map_charint.end()) {
				map_charint.insert(make_pair(b,pos));
				map_intchar.insert(make_pair(pos++,b));
			}
			int na = map_charint.find(a)->second, nb = map_charint.find(b)->second;
			if(!has_vert[na][nb]) {
				graph[na].push_back(nb);
				has_vert[na][nb] = true;
			}
		}
		printf("Calling circles for data set %d:\n",cases++);
		TarjanSCC();
	}
}
