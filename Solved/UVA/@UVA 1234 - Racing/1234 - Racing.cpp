//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3675

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000;

typedef pair<int,int> pint;
typedef vector<pint> vi;

vi graph[MAX];
bool taken[MAX];
int qt_vert, qt_edge;

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
		taken[i] = false;
	}
}

void process(int v, priority_queue<pint> &pq) {
	taken[v] = true;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i].second, c = graph[v][i].first;
		if(!taken[nv]) pq.push(pint(c,nv));
	}
}

int prim(int sum) {	
	priority_queue<pint> pq;
	process(0,pq);
	while(!pq.empty()) {
		int v = pq.top().second, c = pq.top().first;
		pq.pop();
		if(!taken[v])
			sum -= c, process(v,pq);
	}
	return sum;
}


int main() {
	int T;
	scanf("%d",&T);
	while(scanf("%d",&qt_vert) && qt_vert) {
		clear();
		scanf("%d",&qt_edge);
		int sum = 0;
		for(int i = 0; i < qt_edge; i++) {
			int x, y, coust;
			scanf("%d %d %d",&x,&y,&coust);
			x--, y--;
			sum += coust;
			graph[x].push_back(pint(coust,y)), graph[y].push_back(pint(coust,x));
		}
		int ans = prim(sum);
		printf("%d\n",ans);
	}
}
