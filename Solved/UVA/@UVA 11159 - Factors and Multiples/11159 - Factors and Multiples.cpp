//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2100

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_NUMBER = 105;
const int MAX_VERT = MAX_NUMBER * 2;

int size1, size2;
int set1[MAX_NUMBER], set2[MAX_NUMBER];
int match[MAX_VERT];
bool visited[MAX_VERT];
vector<int> graph[MAX_VERT];

inline void pb(int a, int b) { graph[a].push_back(b), graph[b].push_back(a); }

void clear() {
	for(int i = 0; i < MAX_VERT; i++) {
		graph[i].clear();
	}
}

void buildGraph() {
	for(int i = 0; i < size1; i++) {
		int a = set1[i];
		for(int j = 0; j < size2; j++) {
			int b = set2[j];
			if((a == 0 && b == 0) || (a != 0 && (b == 0 || b % a == 0)))
				pb(i,size1+j);
		}
	}
}

int augment_path(int v) {
	if(visited[v])
		return 0;
	visited[v] = true;
	for(int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if(match[nv] == -1 || augment_path(match[nv])) {
			match[nv] = v;
			return 1;
		}
	}
	return 0;
}

int MCBM() {
	memset(match,-1,sizeof match);
	int ret = 0;
	int limit = min(size1,size2);
	for(int i = 0; i < size1 && ret < limit; i++) {
		memset(visited,false,sizeof visited);
		ret += augment_path(i);
	}
	return ret;
}

int main() {
	int cases = 1, T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&size1); 
		for(int i = 0; i < size1; i++)
			scanf("%d",&set1[i]);
		scanf("%d",&size2);
		for(int i = 0; i < size2; i++)
			scanf("%d",&set2[i]);
		clear();
		buildGraph();
		int ans = MCBM();
		printf("Case %d: %d\n",cases++,ans);
	}
}
