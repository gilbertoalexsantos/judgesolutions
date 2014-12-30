//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2169

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
const double EPS = 1e-9;
const double INF = 1e9;

vector<pint> vert;

double euclides(pint a, pint b) { return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2)); }

struct EDGE {
	int x, y;
	double c;
	EDGE(int x, int y) { this->x = x, this->y = y, c = euclides(vert[x],vert[y]); }
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
double threshold;

void clear() {
	edge.clear();
	uf.clear(qt_vert);
	vert.clear();
}

bool gt(double a, double b) { return (a-b) > EPS; }
bool sameState(int x, int y) { return gt(threshold,euclides(vert[x],vert[y])); }
bool comp(EDGE a, EDGE b) { return gt(b.c,a.c); }

int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %lf",&qt_vert,&threshold);
		clear();
		for(int i = 0; i < qt_vert; i++) {
			int x, y;
			scanf("%d %d",&x,&y);
			vert.push_back(pint(x,y));
		}
        
		for(int i = 0; i < qt_vert; i++) for(int j = i+1; j < qt_vert; j++)
			edge.push_back(EDGE(i,j));
        
		int qt_state = qt_vert;
		double road = 0, railroad = 0;
		sort(edge.begin(),edge.end(),comp);
		for(int i = 0; i < edge.size(); i++) {
			int x = edge[i].x, y = edge[i].y;
			double c = edge[i].c;
			if(!uf.same(x,y)) {
				uf.unite(x,y);
				if(sameState(x,y)) {
					qt_state--;
					road += c;
				} else railroad += c;
			}
		}
        
		int a2 = round(road), a3 = round(railroad);
        
		printf("Case #%d: %d %d %d\n",cases++,qt_state,a2,a3);
	}
}

