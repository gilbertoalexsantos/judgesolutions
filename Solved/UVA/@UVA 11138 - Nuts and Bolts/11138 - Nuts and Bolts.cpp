//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2079

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_NUT = 530;
const int MAX_BOLT = 530;
const int MAX_VERT = MAX_NUT + MAX_BOLT;

int nut, bolt;
int m[MAX_BOLT][MAX_NUT];
vector<int> graph[MAX_VERT];
int match[MAX_VERT];
bool visited[MAX_VERT];

void clear() {
	for(int i = 0; i < MAX_VERT; i++) {
		graph[i].clear();
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
	for(int i = 0; i < bolt; i++) {
		memset(visited,false,sizeof visited);
		ret += augment_path(i);
	}
	return ret;
}

int main() {
	int cases = 1, T; scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&bolt,&nut);
		clear();
		for(int i = 0; i < bolt; i++) for(int j = 0; j < nut; j++)
			scanf("%d",&m[i][j]);
		for(int i = 0; i < bolt; i++) for(int j = 0; j < nut; j++) {
			if(m[i][j])
				graph[i].push_back(j+bolt), graph[j+bolt].push_back(i);
		}
		int ans = MCBM();
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",cases++,ans);
	}
}
