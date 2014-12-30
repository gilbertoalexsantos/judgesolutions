//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3108

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 105;
const int MODULO = 1000007;
const int dr[] = {-1,-1};
const int dc[] = {-1, 1};

int size;
char grid[MAX][MAX];
int memo[MAX][MAX];
ii init;

inline bool border(ii p) { return p.first < 0 || p.second < 0 || p.first >= size || p.second >= size; }

void clear() {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			memo[i][j] = -1;
		}
	}
}

void getInit() {
	for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
		if(grid[i][j] == 'W') {
			init = ii(i,j);
			return;
		}
}

int dp(ii v = init) {
	if(v.first == 0) return 1;

	int &ret = memo[v.first][v.second];
	if(ret != -1) return ret;

	ret = 0;
	for(int i = 0; i < 2; i++) {
		ii nv = ii(v.first+dr[i],v.second+dc[i]);
		if(border(nv)) continue;
		if(grid[nv.first][nv.second] != 'B') {
			ret += dp(nv);
			ret %= MODULO;
		} else {
			nv.first += dr[i], nv.second += dc[i];
			if(border(nv) || grid[nv.first][nv.second] == 'B') continue;
			ret += dp(nv) % MODULO;
			ret %= MODULO;
		}
	}

	return ret;
}

int main() {
	int cases = 1, T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&size);
		clear();
		for(int i = 0; i < size; i++)
			scanf("%s",grid[i]);
		getInit();
		int ans = dp();
		printf("Case %d: %d\n",cases++,ans);
	}
}
