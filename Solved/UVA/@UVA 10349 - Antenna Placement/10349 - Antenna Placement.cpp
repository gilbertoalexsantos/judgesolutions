//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=35&category=15&page=show_problem&problem=1290

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int MAX_ROW = 45;
const int MAX_COL = 15;
const int MAX_VERT = MAX_ROW * MAX_COL;
const int INF = 1e9;
const char OPEN = 'o', INTEREST = '*';
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

int qt_row, qt_col;
char grid[MAX_ROW][MAX_COL];
vector<int> graph[MAX_VERT];
int match[MAX_VERT], visited[MAX_VERT];
vector<ii> set1;
int size1, size2;

inline int in(ii x) { return x.first * qt_col + x.second; }
inline bool border(ii x) { return x.first < 0 || x.second < 0 || x.first >= qt_row || x.second >= qt_col; }

void clear() {
	size1 = size2 = 0;
	set1.clear();
	for(int i = 0; i < MAX_VERT; i++) {
		graph[i].clear();
	}
}

void buildGraph() {
	for(int i = 0; i < qt_row; i++) {
		for(int j = 0; j < qt_col; j++) if(grid[i][j] == INTEREST) {
			ii x(i,j);
			if((i + j) % 2 == 0) {
				set1.push_back(x);
				size1++;
			}
			else
				size2++;
			for(int k = 0; k < 4; k++) {
				ii y(x.first + dr[k],x.second + dc[k]);
				if(border(y) || grid[y.first][y.second] != INTEREST) continue;
				graph[in(x)].push_back(in(y));
			}
		}
	}
}

int augment_path(int v) {
	if(visited[v]) return 0;
	visited[v] = true;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(match[nv] == -1 || augment_path(match[nv])) {
			match[nv] = v;
			return 1;
		}
	}
	return 0;
}

int solve() {
	int ret = 0;
	memset(match,-1,sizeof match);
	int limit = max(size1, size2);
	for(int i = 0; i < size1 && ret < limit; i++) {
		memset(visited,false,sizeof visited);
		ret += augment_path(in(set1[i]));
	}
	return (size1 + size2 - ret);
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_row,&qt_col);
		clear();
		for(int i = 0; i < qt_row; i++)
			scanf("%s",grid[i]);
		buildGraph();
		int ans = solve();
		printf("%d\n",ans);
	}
}
