//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1437

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> pint;

inline int mdistance(pint a, pint b) { return abs(a.first-b.first) + abs(a.second-b.second); }

int row, col;
int qt_vert;
pint init;

int dist[20][20];
int memo[10][1 << 10];

vector<vector<int> > graph(20);

void clear() {
	memset(memo,-1,sizeof memo);
	for(int i = 0; i < 20; i++) {
		graph[i].clear();
		for(int j = 0; j < 20; j++) {
			dist[i][j] = 1e9;
		}
	}
}

int dp(int size, int pos = 0, int mask = 1) {
	if(mask == (1 << size) - 1) return dist[pos][0];

	int &ret = memo[pos][mask];
	if(ret != -1) return ret;
	
	ret = 1e9;
	for(int i = 0; i < size; i++) {
		if(mask & (1 << i)) continue;
		ret = min(ret,dp(size,i,mask | 1 << i) + dist[pos][i]);	
	}

	return ret;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		clear();
		scanf("%d %d %d %d",&row,&col,&init.first,&init.second);
		init.first--, init.second--;
		vector<pint> vert;
		vert.push_back(init);
		int qt_beeper;
		scanf("%d",&qt_beeper);
		for(int i = 1; i <= qt_beeper; i++) {
			pint t;
			scanf("%d %d",&t.first,&t.second);
			t.first--, t.second--;
			vert.push_back(t);
		}
		for(int i = 0; i < vert.size(); i++) for(int j = 0; j < vert.size(); j++) if(i != j) {
			dist[i][j] = dist[j][i] = mdistance(vert[i],vert[j]);
			graph[i].push_back(j), graph[j].push_back(i);
		}
		int ans = dp(qt_beeper+1);
		printf("The shortest path has length %d\n",ans);
	}
}
