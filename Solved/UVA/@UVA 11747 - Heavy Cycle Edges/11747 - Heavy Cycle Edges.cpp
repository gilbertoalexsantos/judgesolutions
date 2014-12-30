//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2847

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 1000;

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

UnionFind uf(MAX);
vector<EDGE> edge;
vector<int> ans;
int qt_vert, qt_edge;

void clear() {
	uf.clear(qt_vert);
	edge.clear();
	ans.clear();
}

bool comp(EDGE a, EDGE b) { return a.c < b.c; }

void Kruskal() {
	sort(edge.begin(),edge.end(),comp);
	for(int i = 0; i < edge.size(); i++) {
		int x = edge[i].x, y = edge[i].y, c = edge[i].c;
		if(!uf.same(x,y)) {
			uf.unite(x,y);
		} else ans.push_back(i);
	}
}

int main() {
	while(scanf("%d %d",&qt_vert,&qt_edge) && qt_vert+qt_edge) {
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			edge.push_back(EDGE(x,y,z));
		}
		Kruskal();
		if(ans.empty()) printf("forest");
		else {
			printf("%d",edge[ans[0]].c);
			for(int i = 1; i < ans.size(); i++) printf(" %d",edge[ans[i]].c);
		}
		printf("\n");
	}
}
