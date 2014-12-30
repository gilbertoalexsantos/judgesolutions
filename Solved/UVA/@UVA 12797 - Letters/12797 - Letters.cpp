//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4662

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 105;
const int INF = 1e9;
const int dr[] = {0,1,0,-1};
const int dc[] = {1,0,-1,0};

int n;
char grid[MAX][MAX];

inline int get(char c) { return tolower(c) - 'a'; }
bool border(ii p) { 
  return p.first < 0 || p.second < 0 || p.first >= n || p.second >= n; 
}
bool can(char c, int mask) {
	bool d = (1 << get(c)) & mask;
	return islower(c) ? !d : d;
}

int bfs(int mask) {
  if(!can(grid[0][0],mask))
    return INF;
	int dist[MAX][MAX];
	memset(dist,-1,sizeof dist);
	dist[0][0] = 1;
	queue<ii> qe;
	qe.push(ii(0,0));
	while(!qe.empty()) {
		ii u = qe.front(); qe.pop();
		if(u.first == n-1 && u.second == n-1)
			return dist[n-1][n-1];
		for(int i = 0; i < 4; i++) {
			ii v = ii(u.first+dr[i],u.second+dc[i]);
			if(border(v) || !can(grid[v.first][v.second],mask) || dist[v.first][v.second] != -1)
				continue;
			dist[v.first][v.second] = dist[u.first][u.second]+1;
			qe.push(v);
		}
	}
	return INF;
}

int bfs() {
	int ret = INF;
	for(int i = 0; i <= (1 << 10) - 1; i++)
		ret = min(ret,bfs(i));
	return ret == INF ? -1 : ret;
}

int main() {
	while(scanf("%d",&n) != EOF) {
		scanf("%d\n",&n);	
		for(int i = 0; i < n; i++)
			scanf("%s",grid[i]);
		int ans = bfs();
		printf("%d\n",ans);
	}
}
