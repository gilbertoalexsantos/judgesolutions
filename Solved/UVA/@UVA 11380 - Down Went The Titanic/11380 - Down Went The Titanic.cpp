//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2375

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
const int MAX = 35;
const int MAX_GRAPH = 2600;
const char PEOPLE = '*', WATER = '~', ICE = '.', LICE = '@', WOOD = '#';
const int dr[] = {0, 1,  0, -1};
const int dc[] = {1, 0, -1,  0};

char grid[MAX][MAX];
int qt_row, qt_col, p;
int source = 0, sink = MAX_GRAPH-1;

int res[MAX_GRAPH][MAX_GRAPH];
int path[MAX_GRAPH];
bool visited[MAX_GRAPH];
vector<int> graph[MAX_GRAPH];

inline bool border(int x, int y) { return (x >= 0 && y >= 0 && x < qt_row && y < qt_col); }
inline int pin(int x, int y) { return qt_col * x + y + 1; }
inline int pout(int x, int y) { return pin(x,y) + qt_row * qt_col; }
void inline pb(int a, int b, int w) { graph[a].push_back(b), graph[b].push_back(a); res[a][b] = w; }

void clear() {
	for(int i = 0; i < MAX_GRAPH; i++) {
		graph[i].clear();
	}
	memset(res,0,sizeof res);
}

bool bfs() {
	memset(path,-1,sizeof path);
	memset(visited,false,sizeof visited);
	queue<int> qe; qe.push(source);
	visited[source] = true;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		if(v == sink) return true;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(!visited[nv] && res[v][nv] > 0)
				path[nv] = v, visited[nv] = true, qe.push(nv);
		}
	}
	return false;
}

int augment(int v = sink, int MIN = INF) {
	if(v == source)
		return MIN;
	else {
		int t = augment(path[v],min(res[path[v]][v],MIN));
		res[path[v]][v] -= t, res[v][path[v]] += t;
		return t;
	}
}

int edmond() {
	int maxflow = 0;
	while(bfs()) {
		int flagflow = augment();
		maxflow += flagflow;
	}
	return maxflow;
}

void connectAdjacent(int x, int y) {
	for(int i = 0; i < 4; i++) {
		int nx = x+dr[i], ny = y+dc[i];
		if(!border(nx,ny)) continue;
		if(grid[nx][ny] == WATER) continue;
		int a = pout(x,y), b = pin(nx,ny);
		pb(a,b,INF);
	}
}

void split(int i, int j, char c) {
	if(c == PEOPLE)
		pb(pin(i,j),pout(i,j),1), pb(source,pin(i,j),1);
	else if(c == ICE)
		pb(pin(i,j),pout(i,j),1);
	else if(c == LICE)
		pb(pin(i,j),pout(i,j),INF);
	else if(c == WOOD) 
		pb(pin(i,j),pout(i,j),INF), pb(pout(i,j),sink,p);
}

void createGraph() {
	for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++) {
		char c = grid[i][j];
		if(c == WATER) continue;
		connectAdjacent(i,j);
		split(i,j,c);
	}
}

int main() {
	while(scanf("%d %d %d",&qt_row,&qt_col,&p) != EOF) {
		clear();
		for(int i = 0; i < qt_row; i++) scanf("%s",grid[i]);
		createGraph();
		int ans = edmond();
		printf("%d\n",ans);
	}
}
