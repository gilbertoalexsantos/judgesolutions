//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2482

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const char EMPTY = '.', OBSTACLE = '#';
const int MAX_SIZE = 15;
const int MAX_LEN = 105;
const int MODULO = 20437;
const int INF = 1e9;
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

int size, max_len;
char grid[MAX_SIZE][MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE][MAX_LEN];
int dist[MAX_SIZE][MAX_SIZE];
ii source, sink;
char t_sink;

inline bool border(ii p) { return p.first < 0 || p.second < 0 || p.first >= size || p.second >= size; }

int bfs(ii s, ii t) {
	queue<ii> qe; qe.push(s);
	memset(dist,-1,sizeof dist);
	dist[s.first][s.second] = 0;
	while(!qe.empty()) {
		ii v = qe.front(); qe.pop();
		if(v == t) return dist[t.first][t.second];
		for(int i = 0; i < 4; i++) {
			ii nv = ii(v.first + dr[i], v.second + dc[i]);
			if(border(nv) || dist[nv.first][nv.second] != -1)
				continue;
			char c = grid[nv.first][nv.second];
			if(c == OBSTACLE || (c >= t_sink+1 && c <= 'Z'))
				continue;
			dist[nv.first][nv.second] = dist[v.first][v.second] + 1;
			qe.push(nv);
		}
	}
	return -1;
}

void getSS(char a, char b) {
	for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) {
		if(grid[i][j] == a)
			source = ii(i,j);
		else if(grid[i][j] == b)
			sink = ii(i,j);
	}
}

int dp(ii v = source, int len = 0) {
	char c = grid[v.first][v.second];
	if(len > max_len || c == OBSTACLE || (c >= t_sink+1 && c <= 'Z'))
		return 0;
	else if(len == max_len)
		return v == sink;

	int &ret = memo[v.first][v.second][len];
	if(ret != -1)
		return ret;

	ret = 0;

	for(int i = 0; i < 4; i++) {
		ii nv = ii(v.first + dr[i], v.second + dc[i]);
		if(border(nv))
			continue;
		ret += dp(nv,len+1);
		ret %= MODULO;
	}

	return ret;
}

int getAllLetters() {
	int ans = 0;
	for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
		ans += (grid[i][j] >= 'A' && grid[i][j] <= 'Z');
	return ans;
}

ii solve() {
	ii ans(0,1);
	for(int i = 1; i < getAllLetters(); i++) {
		getSS('A' + (i - 1),'A' + i);
		t_sink = 'A' + i;
		int min_dist = bfs(source,sink);

		if(min_dist == -1)
			return ii(INF,INF);

		max_len = min_dist;
		memset(memo,-1,sizeof memo);

		ans.first += min_dist;
		ans.second *= dp();
		ans.second %= MODULO;
	}
	return ans;
}

int main() {
	int cases = 1;
	while(scanf("%d",&size) && size) {
		for(int i = 0; i < size; i++)
			scanf("%s",grid[i]);
		ii ans = solve();
		printf("Case %d: ",cases++);
		if(ans.first == INF)
			printf("Impossible\n");
		else
			printf("%d %d\n",ans.first,ans.second);
	}	
}
