//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=870

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef unsigned long long ll;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int INF = 1e9;
const int MAX = 999;
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

int qt_row, qt_col;
int grid[MAX][MAX], dist[MAX][MAX];

inline bool border(ii p) { return p.first >= 0 && p.second >= 0 && p.first < qt_row && p.second < qt_col; }

void clear() {
	for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
		dist[i][j] = INF;
}

int dijkstra() {
	priority_queue<iii> pq;
	pq.push(iii(-grid[0][0],ii(0,0)));
	dist[0][0] = grid[0][0];
	while(!pq.empty()) {
		int qdist = -pq.top().first;
		ii v = pq.top().second; pq.pop();
		int d = dist[v.first][v.second];

		if(qdist > d) continue;
		for(int i = 0; i < 4; i++) {
			ii nv = ii(v.first+dr[i],v.second+dc[i]);
			if(!border(nv)) continue;
			int &r = dist[nv.first][nv.second], w = grid[nv.first][nv.second];
			if(r > d+w) {
				r = d+w;
				pq.push(iii(-r,nv));
			}
		}

	}
	return dist[qt_row-1][qt_col-1];
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_row,&qt_col);
		clear();
		for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
			scanf("%d",&grid[i][j]);
		int ans = dijkstra();
		printf("%d\n",ans);
	}
}
