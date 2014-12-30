//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=250

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int MAX_ROW = 50, MAX_COL = 50;
const int EMPTY = 0, BARRIER = 1;
const int EAST = 0, SOUTH = 1, WEST = 2, NORTH = 3;
const int LEFT = -1, RIGHT = 1;
const int INF = 1e9;

// EAST SOUTH WEST NORTH
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};

int qt_row, qt_col;
int grid[MAX_ROW][MAX_COL];
int dist[MAX_ROW][MAX_COL][4];
ii source, sink;
int direction;
char face[6];

inline void setD(int d, ii p, int v) { dist[p.first][p.second][d] = v; }
inline int getD(int d, ii p) { return dist[p.first][p.second][d]; }
bool border(ii p) { 
	if(p.first <= 0 || p.second <= 0 || p.first >= qt_row || p.second >= qt_col) return false;
	if(grid[p.first-1][p.second-1]) return false;
	if(grid[p.first-1][p.second]) return false;
	if(grid[p.first][p.second-1]) return false;
	if(grid[p.first][p.second]) return false;
	return true;
}

void clear() {
	for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
		for(int z = 0; z < 4; z++)
			dist[i][j][z] = INF;
}

void getDirection() {
	if(face[0] == 'e') direction = EAST;
	else if(face[0] == 's') direction = SOUTH;
	else if(face[0] == 'w') direction = WEST;
	else direction = NORTH;
}

int transform(int d, int nd) {
	int ans = d+nd;
	if(ans == 4) ans = 0;
	else if(ans == -1) ans = 3;
	return ans;
}

int bfs() {
	if(!border(source)) return -1;
	if(source == sink) return 0;
	queue<iii> qe;
	qe.push(iii(direction,source));
	setD(direction,source,0);
	while(!qe.empty()) {
		iii t = qe.front(); qe.pop();

		//Change Direction LEFT
		int nd = transform(t.first,LEFT);
		int g1 = getD(nd,t.second), g2 = getD(t.first,t.second);
		if(g1 == INF) {
			setD(nd,t.second,g2+1);
			qe.push(iii(nd,t.second));
		}

		//Change Direction RIGHT
		nd = transform(t.first,RIGHT);
		g1 = getD(nd,t.second);
		if(g1 == INF) {
			setD(nd,t.second,g2+1);
			qe.push(iii(nd,t.second));
		}
		
		//Go ahead!
		for(int i = 1; i <= 3; i++) {
			ii np = ii(t.second.first+i*dr[t.first],t.second.second+i*dc[t.first]);
			if(!border(np)) break;
			if(getD(t.first,np) != INF) continue;
			setD(t.first,np,g2+1);
			if(np == sink) return g2+1;
			qe.push(iii(t.first,np));
		}
	}
	return -1;
}

int main() {
	while(scanf("%d %d",&qt_row,&qt_col) && qt_row+qt_col) {
		clear();
		for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
			scanf("%d",&grid[i][j]);
		scanf("%d %d %d %d %s",&source.first,&source.second,&sink.first,&sink.second,face);
		getDirection();
		int ans = bfs();
		printf("%d\n",ans);
	}	
}
