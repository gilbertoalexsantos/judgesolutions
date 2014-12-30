//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2108

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int>::iterator IT;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int MAX = 50000+100+10;
const int INF = 1e9;

int n, m;
int total;
vector<int> interval;
vector<int> graph[MAX];
vector<iii> edge;
vector<iii> monkey[100];

inline int id(int value) { return lower_bound(interval.begin(),interval.end(),value) - interval; }

void clear() {
	total = 0;
	interval.clear();
	edge.clear();
	for(int i = 0; i < MAX; i++) {
		graph[i].clear();
	}
}

void add(int u, int v, int w) {
	edge.push_back(iii(w,ii(u,v)));
	edge.push_back(iii(0,ii(v,u)));
	int pos = edge.size();
	graph[u].push_back(pos-2);
	graph[v].push_back(pos-1);
}


void createGraph() {
	for(int i = 0; i < n; i++) {
		add(i,i+1,mk[i].first);
		int a = id(mk[i].second.first), b = id(mk[i].second.second);
		for(int j = a; j < b; j++) {
			int diff = interval[j+1] - interval[j];
			add(i+1,n+1+j,diff);
		}
	}
	for(int i = 0; i < interval.size()-1; i++) {
		int diff = interval[i+1] - interval[i];
		add(n+1+i,n+interval.size(),m*diff);
	}
}

int main() {
	int cases = 1;
	while(scanf("%d",&n) && n) {
		clear();
		scanf("%d",&m);
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d",&mk[i].first,&mk[i].second.first,&mk[i].second.second);	
			total += mk[i].first;
			interval.push_back(mk[i].second.first), interval.push_back(mk[i].second.second);
		}
		IT it = unique(interval.begin(),interval.end());
		interval.erase(it,interval.end());
	}
}
