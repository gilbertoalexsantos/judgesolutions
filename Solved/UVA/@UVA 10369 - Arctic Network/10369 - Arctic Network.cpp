//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1310

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 500;
const double EPS = 1e-9;

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

UnionFind uf(MAX);
vector<pint> vert;
int qt_vert, qt_edge, qt_sat;

struct EDGE {
	int x, y;
	double c;
	EDGE(int x, int y) {
		this->x = x, this->y = y;
		c = sqrt(pow(vert[x].first-vert[y].first,2)+pow(vert[x].second-vert[y].second,2));
	}
};

vector<EDGE> edge;

inline bool gt(double a, double b) { return (a-b) > EPS; }
inline bool comp(EDGE a, EDGE b) { return gt(b.c,a.c); }

void clear() {
	uf.clear(qt_vert);
	vert.clear();
	edge.clear();
}

void connectEdge() {
	for(int i = 0; i < vert.size(); i++)
		for(int j = i+1; j < vert.size(); j++)
			edge.push_back(EDGE(i,j));
}

double Kruskal() {
	sort(edge.begin(),edge.end(),comp);
	double ans = 0.0;
	for(int i = 0; i < edge.size(); i++) {
		if(!uf.same(edge[i].x,edge[i].y)) {
			uf.unite(edge[i].x,edge[i].y);
			if(gt(edge[i].c,ans)) ans = edge[i].c;
		}
		if(uf.getSet() == qt_sat) break;
	}
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_sat,&qt_vert);
		clear();
		for(int i = 0; i < qt_vert; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			vert.push_back(pint(x,y));
		}
		connectEdge();
		double ans = Kruskal();
		printf("%.2lf\n",ans);
	}
}
