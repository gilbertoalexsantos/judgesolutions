//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=473

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> pint;
typedef pair<int,pair<int,int> > piint;

const int MAX = 31;
const char EMPTY = '.', ROCK = '#', SOURCE = 'S', SINK = 'E';
const int dl[] = {0,1,-1};
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

char grid[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int qt_level, qt_row, qt_col;
int source_l, source_r, source_c;

void getSource() {
	for(int c = 0; c < qt_level; c++)
		for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
			if(grid[c][i][j] == SOURCE) {
				source_l = c, source_r = i, source_c = j;	
				return;
			}
}

inline bool check_level(int l) { return !(l >= qt_level || l < 0); }
inline bool check_rc(int r, int c) { return !(r < 0 || c < 0 || r >= qt_row || c >= qt_col); }

int bfs() {
	queue<piint> qe;
	qe.push(piint(source_l,pint(source_r,source_c)));
	while(!qe.empty()) {
		int l = qe.front().first, r = qe.front().second.first, c = qe.front().second.second;
		qe.pop();
		if(grid[l][r][c] == ROCK) continue;

		for(int i = 0; i < 3; i++) {
			int nl = l+dl[i];
			if(!check_level(nl) || grid[nl][r][c] == ROCK) continue;
			dist[nl][r][c] = dist[l][r][c] + (l != nl);
			qe.push(piint(nl,pint(r,c)));
			if(grid[nl][r][c] == SINK) return dist[nl][r][c];
		}
		
		for(int i = 0; i < 4; i++) {
			int nr = r+dr[i], nc = c+dc[i];
			if(!check_rc(nr,nc) || grid[l][nr][nc] == ROCK) continue;
			dist[l][nr][nc] = dist[l][r][c] + 1;
			qe.push(piint(l,pint(nr,nc)));
			if(grid[l][nr][nc] == SINK) return dist[l][nr][nc];
		}
		grid[l][r][c] = ROCK;
	}
	return 0;
}

void clear() {
	memset(dist,0,sizeof dist);
}

int main() {
	while(scanf("%d %d %d",&qt_level,&qt_row,&qt_col) && qt_level+qt_row+qt_col) {
		clear();
		for(int i = 0; i < qt_level; i++) for(int j = 0; j < qt_row; j++) 
			scanf("%s",grid[i][j]);
		getSource();
		int ans = bfs();
		ans ? printf("Escaped in %d minute(s).\n",ans) : printf("Trapped!\n");
	}
}
