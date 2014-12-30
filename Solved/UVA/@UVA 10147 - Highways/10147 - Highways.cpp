//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1088

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 750;
const int MAX_EDGE = MAX*(MAX-1);
const double EPS = 1e-9;

typedef pair<int,int> pint;

inline bool gt(double a, double b) { return (a - b) > EPS; }
inline double EuclidesDistance(pint a, pint b) { return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2)); }

pint town[MAX];

class UnionFind {
	private:
		vector<int> parent, rank;
		int n, qt_set;
	public:
		UnionFind(int size) {
			parent.assign(size,0);
			rank.assign(size,0);
			n = qt_set = size;
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
			int &ra = rank[fa];
			int &rb = rank[fb];
			if(ra == rb) {
				ra++;
				parent[fb] = fa;
			} else ra < rb ? parent[fa] = fb : parent[fb] = fa;
			qt_set--;
		}
		bool same(int a, int b) { return find(a) == find(b); }
		bool hasOneSet() { return qt_set == 1; }
};

struct EDGE {
	int x, y;
	double c;

	EDGE(int a, int b) { x = a, y = b, c = EuclidesDistance(town[a],town[b]); }
};

inline bool comp(EDGE a, EDGE b) { return gt(b.c,a.c); }

UnionFind uf(MAX_EDGE);
vector<pint> ans;
vector<EDGE> edge;
int qt_vert, qt_edge;

void connectEdge() {
	for(int i = 0; i < qt_vert; i++)
		for(int j = i+1; j < qt_vert; j++) {
			edge.push_back(EDGE(i,j));
		}
}

void Kruskal() {
	sort(edge.begin(),edge.end(),comp);
	for(int i = 0; i < edge.size(); i++) {
		if(uf.hasOneSet()) break;
		int a = edge[i].x, b = edge[i].y;
		if(!uf.same(a,b)) {
			uf.unite(a,b);
			ans.push_back(pint(a,b));
		}
	}
}

void clear() {
	ans.clear();
	edge.clear();
	uf.clear(qt_vert);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&qt_vert);
		clear();
		for(int i = 0; i < qt_vert; i++) {
			pint t;
			scanf("%d %d",&t.first,&t.second);
			town[i] = t;
		}
		scanf("%d",&qt_edge);
		for(int i = 0; i < qt_edge; i++) {
			int x, y, c;
			scanf("%d %d",&x,&y);
			x--, y--;
			uf.unite(x,y);
		}

		connectEdge();

		Kruskal();

		if(ans.empty()) printf("No new highways need\n");
		else for(int i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
		if(T) printf("\n");
	}
}
