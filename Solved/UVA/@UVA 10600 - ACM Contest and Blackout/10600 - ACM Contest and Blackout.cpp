//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541

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
int qt_vert, qt_edge;

void clear() {
	uf.clear(qt_vert);
	edge.clear();
}

bool comp(EDGE a, EDGE b) { return a.c < b.c; }

pint Kruskal() {
	sort(edge.begin(),edge.end(),comp);
	pint ans(0,1e9);
	vector<int> flag;
	for(int i = 0; i < edge.size(); i++) {
		int x = edge[i].x, y = edge[i].y, c = edge[i].c;
		if(!uf.same(x,y)) {
			uf.unite(x,y);
			flag.push_back(i);
			ans.first += c;
		}
		if(uf.getSet() == 1) break;
	}
	for(int i = 0; i < flag.size(); i++) {
		uf.clear(qt_vert);
		int sum = 0;
		for(int j = 0; j < edge.size(); j++) {
			if(j == flag[i]) continue;
			int x = edge[j].x, y = edge[j].y, c = edge[j].c;
			if(!uf.same(x,y)) {
				uf.unite(x,y);
				sum += c;
			}
			if(uf.getSet() == 1) break;
		}
		if(uf.getSet() > 1) continue;
		ans.second = min(ans.second,sum);
	}
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_vert,&qt_edge);
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y, c;
			scanf("%d %d %d",&x,&y,&c);
			x--, y--;
			edge.push_back(EDGE(x,y,c));
		}
		pint ans = Kruskal();
		printf("%d %d\n",ans.first,ans.second);
	}
}

