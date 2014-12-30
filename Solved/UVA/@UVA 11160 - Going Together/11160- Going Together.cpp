//Author:	Gilberto A. dos Santos
//Website:	http://www.urionlinejudge.com.br/judge/pt/problems/view/1057

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> pint;

struct POINT {
	pint a, b, c;
	POINT(pint a, pint b, pint c) { this->a = a, this->b = b, this->c = c; }
};

const char EMPTY = '.', BARRIER = '#', TARGET = 'X', R1 = 'A', R2 = 'B', R3 = 'C';
const int MAX = 10;
const int dr[] = {1,0, 0,-1};
const int dc[] = {0,1,-1, 0};
const int INF = 1e9;

pint r1, r2, r3;
int size, BEST;
char grid[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX][MAX][MAX];
int dist[MAX][MAX][MAX][MAX][MAX][MAX];

inline bool check(pint v) { return !(v.first < 0 || v.second < 0 || v.first >= size || v.second >= size); }
inline char gd(pint a) { return grid[a.first][a.second]; }
inline void mark(pint a, pint b, pint c) { visited[a.first][a.second][b.first][b.second][c.first][c.second] = true; }
inline bool isMark(pint a, pint b, pint c) { return visited[a.first][a.second][b.first][b.second][c.first][c.second]; }
inline int getDist(pint a, pint b, pint c) { return dist[a.first][a.second][b.first][b.second][c.first][c.second]; }
inline void setDist(pint a, pint b, pint c, int d) { dist[a.first][a.second][b.first][b.second][c.first][c.second] = d;}
inline bool isDiff(pint a, pint b, pint c) { return ((a != b) && (b != c) && (a != c)); }

void clear() {
	BEST = INF;
	memset(visited,false,sizeof visited);
	memset(dist,0,sizeof dist);
}

void getPos() {
	for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) {
		if(grid[i][j] == R1) r1 = pint(i,j);
		else if(grid[i][j] == R2) r2 = pint(i,j);
		else if(grid[i][j] == R3) r3 = pint(i,j);
	}
}

int bfs() {
	queue<POINT> qe;
	qe.push(POINT(r1,r2,r3));
	while(!qe.empty()) {
		pint a = qe.front().a, b = qe.front().b, c = qe.front().c; qe.pop();
		if(isMark(a,b,c)) continue;
		for(int i = 0; i < 4; i++) {
			pint nr1(a.first+dr[i],a.second+dc[i]);
			pint nr2(b.first+dr[i],b.second+dc[i]);
			pint nr3(c.first+dr[i],c.second+dc[i]);

			bool c1 = false, c2 = false, c3 = false;
			if(!check(nr1) || gd(nr1) == BARRIER) nr1 = a, c1 = true;
			if(!check(nr2) || gd(nr2) == BARRIER) nr2 = b, c2 = true;
			if(!check(nr3) || gd(nr3) == BARRIER) nr3 = c, c3 = true;
			if(c1&c2&c3) continue;
			if(nr1 == nr2) nr1 = a, nr2 = b, c1 = c2 = true;
			if(nr1 == nr3) nr1 = a, nr3 = c, c1 = c3 = true;
			if(nr2 == nr3) nr2 = b, nr3 = c, c2 = c3 = true;
			if(c1&c2&c3) continue;

			if(getDist(nr1,nr2,nr3) > 0) continue;

			int nd = getDist(a,b,c)+1;
			setDist(nr1,nr2,nr3,nd);

			if(gd(nr1) == TARGET && gd(nr2) == TARGET && gd(nr3) == TARGET && isDiff(nr1,nr2,nr3)) {
				BEST = min(BEST,nd);
				return BEST;
			}

			qe.push(POINT(nr1,nr2,nr3));
		}
		mark(a,b,c);
	}
	return BEST;
}

int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		clear();
		scanf("%d",&size);
		for(int i = 0; i < size; i++) scanf("%s",grid[i]);
		getPos();
		int ans = bfs();
		(ans == INF) ? printf("Case %d: trapped\n",cases++) : printf("Case %d: %d\n",cases++,ans);
	}
}
