//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 100;
const int UNVISITED = 0, VISITED = 1;
const int INF = 1e9;

struct EDGE {
	int x, y, c;
	EDGE(int x, int y, int c) { this->x = x, this->y = y, this->c = c; }
};

class UnionFind {
	private:
		vector<int> parent, rank;
		int qt_set;
	public:
		UnionFind(int size) {
			parent.assign(size,0);
			rank.assign(size,0);
			clear(size);
		}
		void clear(int x) {
			for(int i = 0; i < x; i++) {
				parent[i] = i;
				rank[i] = 0;
			}
			qt_set = x;
		}
		int find(int a) { return parent[a] = ((a == parent[a]) ? a : find(parent[a]));  }
		void unite(int a, int b) {
			int fa = find(a), fb = find(b);
			if(fa == fb) return;
			int &ra = rank[fa], &rb = rank[fb];
			if(ra == rb) {
				ra++;
				parent[fb] = fa;
			} else ra < rb ? parent[fa] = fb : parent[fb] = fa;
			qt_set--;
		}
		bool same(int a, int b) { return find(a) == find(b); }
		int getSet() { return qt_set; }
};

vector<pint> graph[MAX];
UnionFind uf(MAX);
bool visited[MAX];
vector<EDGE> edge;
int qt_vert, qt_edge;

void clear() {
	uf.clear(qt_vert);
	edge.clear();
	for(int i = 0; i < qt_vert; i++) {
		visited[i] = UNVISITED;
		graph[i].clear();
	}
}

bool comp(EDGE a, EDGE b) { return a.c < b.c; }

void Kruskal() {
	sort(edge.begin(),edge.end(),comp);
	for(int i = 0; i < edge.size(); i++) {
		int x = edge[i].x, y = edge[i].y, c = edge[i].c;
		if(!uf.same(x,y)) {
			uf.unite(x,y);
			graph[x].push_back(pint(y,c)), graph[y].push_back(pint(x,c));
		}
		if(uf.getSet() == 1) break;
	}
}

int dfs(int v, int wanted, int nvalue = -INF) {
	visited[v] = VISITED;
	if(v == wanted) return nvalue;
	int ans = -INF;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i].first, c = graph[v][i].second;
		if(visited[nv]) continue;
		int q = dfs(nv,wanted,c);
		ans = (q == -INF) ? ans : max(ans,max(nvalue,q));
	}
	return ans;
}

int main() {
	int qt_querie, cases = 1;
	bool first = true;
	while(scanf("%d %d %d",&qt_vert,&qt_edge,&qt_querie) && qt_vert+qt_edge+qt_querie) {
		first ? first = false : printf("\n");
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, c;
			scanf("%d %d %d",&x,&y,&c);
			x--, y--;
			edge.push_back(EDGE(x,y,c));
		}
		printf("Case #%d\n",cases++);
		Kruskal();
		for(int i = 0; i < qt_querie; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			int ans = dfs(x-1,y-1);
			ans == -INF ? printf("no path\n") : printf("%d\n",ans);
			memset(visited,UNVISITED,sizeof visited);
		}
	}
}
