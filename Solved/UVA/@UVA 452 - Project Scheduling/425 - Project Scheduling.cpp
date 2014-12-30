//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=393

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 26;

char w[50];
vector<int> graph[MAX];
int dist[MAX], degree[MAX], cost[MAX];
bool visited[MAX];

void clear() {
	for(int i = 0; i < MAX; i++) {
		graph[i].clear();
		dist[i] = 0;
		degree[i] = 0;
	}
}

int max_dag_path() {
	int ret = -1;
	queue<int> qe;
	for(int i = 0; i < MAX; i++) if(visited[i] && degree[i] == 0) {
		qe.push(i);	
		dist[i] = cost[i];
	}
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i]; degree[nv]--;
			dist[nv] = max(dist[nv],dist[v] + cost[nv]);
			ret = max(ret,dist[nv]);
			if(degree[nv] == 0)
				qe.push(nv);
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d\n\n",&T);
	while(T--) {
		clear();
		while(fgets(w,50,stdin) && w[0] != '\n') {
			char *f = strtok(w," ");
			int v = f[0] - 'A';
			visited[v] = true;
			f = strtok(NULL, " ");
			cost[v] = atoi(f);
			f = strtok(NULL, " ");
			if(f != NULL) {
				for(int i = 0; i < strlen(f)-1; i++) {
					int nv = f[i]-'A';
					graph[v].push_back(nv);
					degree[nv]++;
					visited[nv] = true;
				}
			}
		}
		int ans = max_dag_path();
		printf("%d\n",ans);
		if(T) puts("");
	}
}
