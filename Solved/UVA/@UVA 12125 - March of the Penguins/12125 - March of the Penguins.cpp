//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3277

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

typedef pair<int,int> ii;

const int MAX_VERT = 100;
const int MAX = MAX_VERT*2+2;
const int INF = 1e9;

struct EDGE {
	int x, y, p, j;
	EDGE (int x, int y, int p, int j) : x(x), y(y), p(p), j(j) {}
};

int qt_vert, total;
int source, sink;
double max_jump;
vector<EDGE> penguin;
vector<int> graph[MAX];
int res[MAX][MAX];
int flag_res[MAX][MAX];
int path[MAX];
bool visited[MAX];

inline bool can_move(int x, int y, int nx, int ny, double d) { return double(pow(x-nx,2)+pow(y-ny,2)) <= pow(d,2); }
inline int pout(int x) { return x+MAX_VERT; }
inline void pb(int a, int b, int w) { graph[a].push_back(b), graph[b].push_back(a), res[a][b] = w; }
inline void split(int p, int w) { pb(p,pout(p),w); }
inline int getRes(int x, int y) { return res[x][y] - flag_res[x][y]; }

void clear() {
	total = 0;
	source = 0;
	penguin.clear();
	memset(res,0,sizeof res);
	for(int i = 0; i < MAX; i++) {
		graph[i].clear();
	}
}

int augment(int v = sink, int minEdge = INF) {
	if(v == source) return minEdge;
	else {
		int t = augment(path[v],min(getRes(path[v],v),minEdge));
		flag_res[path[v]][v] += t, flag_res[v][path[v]] -= t;
		return t;
	}
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
			int nv = graph[v][i], flow = getRes(v,nv);
			if(!visited[nv] && flow > 0)
				visited[nv] = true, path[nv] = v, qe.push(nv);
		}
	}
	return false;
}

int edmond() {
	memset(flag_res,0,sizeof flag_res);
	int maxflow = 0;
	while(bfs())
		maxflow += augment();
	return maxflow;
}

void buildGraph() {
	for(int i = 0; i < qt_vert; i++) {
		EDGE e = penguin[i];
		pb(source,i+1,penguin[i].p);
		split(i+1,penguin[i].j);
		for(int j = i+1; j < qt_vert; j++) {
			EDGE g = penguin[j];
			if(can_move(e.x,e.y,g.x,g.y,max_jump))
				pb(pout(i+1),j+1,INF), pb(pout(j+1),i+1,INF);
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %lf",&qt_vert,&max_jump);
		clear();
		for(int i = 0; i < qt_vert; i++) {
			int x, y, p, j;
			scanf("%d %d %d %d",&x,&y,&p,&j);
			total += p;
			penguin.push_back(EDGE(x,y,p,j));
		}
		buildGraph();
		vector<int> ans;
		for(int i = 0; i < qt_vert; i++) {
			sink = i+1;
			int t = edmond();
			if(total == t)
				ans.push_back(i);
		}
		if(ans.empty())
			printf("-1");
		else {
			printf("%d",ans[0]);
			for(int i = 1; i < ans.size(); i++) printf(" %d",ans[i]);
		}
		printf("\n");
	}
}
