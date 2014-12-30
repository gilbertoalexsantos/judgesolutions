//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1421

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int BLACK = -1, WHITE = 0;
const int MAX_VERT = 50;
const int INF = 1e9;

vector<int> graph[MAX_VERT];
int color[MAX_VERT];
int res[MAX_VERT][MAX_VERT];
int path[MAX_VERT];
int qt_vert, qt_edge;
int source = 0, sink = 1;

void clear() {
	memset(res,0,sizeof res);
	for(int i = 0; i < qt_vert; i++)
		graph[i].clear();
}

inline void pb(int x, int y, int w) { graph[x].push_back(y), graph[y].push_back(x), res[x][y] = res[y][x] = w; }

int augment(int v = sink, int MIN = INF) {
	if(path[v] == -1) return MIN;
	else {
		int t = augment(path[v],min(res[path[v]][v],MIN));
		res[path[v]][v] -= t, res[v][path[v]] += t;
		return t;
	}
	return 0;
}

bool bfs() {
	memset(path,-1,sizeof path);
	bool visited[MAX_VERT];
	memset(visited,false,sizeof visited);
	queue<int> qe; qe.push(source);
	visited[source] = true;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		if(v == sink) return true;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(!visited[nv] && res[v][nv])
				visited[nv] = true, path[nv] = v, qe.push(nv);
		}
	}
	return false;
}

void edmond() {
	while(bfs())
		augment();
}

void separateColor() {
	memset(path,false,sizeof path);
	memset(color,WHITE,sizeof color);
	queue<int> qe; qe.push(source);
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		color[v] = BLACK;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(!path[nv] && res[v][nv] > 0)
				path[nv] = true, qe.push(nv);
		}
	}
}

int main() {
	while(scanf("%d %d",&qt_vert,&qt_edge) && qt_vert+qt_edge) {
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, w;
			scanf("%d %d %d",&x,&y,&w);
			x--, y--;
			pb(x,y,w);
		}

		edmond();
		separateColor();

		vector<ii> ans;
		queue<int> qe; qe.push(source);
		memset(res,false,sizeof res);
		memset(path,false,sizeof path);
		path[source] = true;
		while(!qe.empty()) {
			int v = qe.front(); qe.pop();
			for(int i = 0; i < graph[v].size(); i++) {
				int nv = graph[v][i];
				if(color[v] != color[nv] && !res[v][nv])
					ans.push_back(ii(v,nv)), res[v][nv] = res[nv][v] = true;
				if(path[nv]) continue;
				path[nv] = true;
				qe.push(nv);
			}
		}

		for(int i = 0; i < ans.size(); i++)
			printf("%d %d\n",ans[i].first+1,ans[i].second+1);
		printf("\n");
	}
}
