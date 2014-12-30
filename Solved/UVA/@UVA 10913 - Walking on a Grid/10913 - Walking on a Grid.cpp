//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1854

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<int,int> ii;

// RIGHT DOWN LEFT
const int RIGHT = 0, DOWN = 1, LEFT = 2;
const int dr[] = {0, 1,  0};
const int dc[] = {1, 0, -1};

const int MAX_SIZE = 75;
const int MAX_K = 6;
const int INF = 1e9;

int size, k;
ii source = ii(0,0), sink;
int grid[MAX_SIZE][MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE][MAX_K][3];

inline bool border(ii p) { return p.first < 0 || p.second < 0 || p.first >= size || p.second >= size; }

void clear() {
	sink = ii(size-1,size-1);
	for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
		for(int z = 0; z <= k; z++)
			for(int h = 0; h < 3; h++)
				memo[i][j][z][h] = INF;
}

int dp(ii v = source, int minus = 0, int dir = DOWN) {
	if(minus > k)
		return -INF;

	if(v == sink) {
		if(grid[sink.first][sink.second] < 0 && minus+1 > k)
			return -INF;
		else
			return grid[sink.first][sink.second];
	}

	int &ret = memo[v.first][v.second][minus][dir];
	if(ret != INF)
		return ret;

	ret = -INF;

	for(int i = 0; i < 3; i++) {
		if(dir == RIGHT && i == LEFT) continue;
		if(dir == LEFT && i == RIGHT) continue;

		ii nv = ii(v.first+dr[i],v.second+dc[i]);
		if(border(nv)) continue;
		int p = dp(nv,minus + (grid[v.first][v.second] < 0),i);
		if(p == -INF)
			continue;
		ret = max(ret,p + grid[v.first][v.second]);
	}

	return ret;
}

int main() {
	int cases = 1;
	while(scanf("%d %d",&size,&k) && size+k) {
		clear();
		for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
			scanf("%d",&grid[i][j]);
		int ans = dp();
		printf("Case %d: ",cases++);
		ans != -INF ? printf("%d\n",ans) : printf("impossible\n");
	}
}
