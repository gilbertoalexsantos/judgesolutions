//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1400

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int MAX_VERT = 5000;

int qt_vert;
vector<int> graph[MAX_VERT];
int dist[MAX_VERT];
int path[MAX_VERT];
bool has[MAX_VERT][MAX_VERT];
ii diamater;

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
	}
	memset(has,false,sizeof has);
}

int bfs(int v) {
	memset(path,-1,sizeof path);
	memset(dist,-1,sizeof dist);
	queue<int> qe; qe.push(v);
	dist[v] = 0;
	path[v] = -1;
	int max_len = -1, ret;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(dist[nv] == -1)
				dist[nv] = dist[v] + 1, path[nv] = v, qe.push(nv);
			if(dist[nv] > max_len) {
				max_len = dist[nv];
				ret = nv;
			}
		}
	}
	return ret;
}

vector<int> leaf(int v) {
	queue<int> qe; qe.push(v);
	memset(dist,-1,sizeof dist);
	int max_dist = -1;
	dist[v] = 0;
	vector<int> ans;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];	
			if(dist[nv] == -1)
				dist[nv] = dist[v] + 1, max_dist = max(max_dist,dist[nv]), qe.push(nv);
		}
	}
	for(int i = 0; i < qt_vert; i++)
		if(dist[i] == max_dist)
			ans.push_back(i+1);
	sort(ans.begin(),ans.end());
	return ans;
}

int main() {
	while(scanf("%d",&qt_vert) != EOF) {
		clear();
		for(int i = 0; i < qt_vert; i++) {
			int k; scanf("%d",&k);
			while(k--) {
				int x; scanf("%d",&x); x--;
				if(!has[i][x] || !has[x][i]) {
					has[i][x] = has[x][i] = true;
					graph[i].push_back(x), graph[x].push_back(i);
				}
			}
		}
		int x = bfs(0);
		int y = bfs(x);
		vector<int> p; p.push_back(y);
		while(path[y] != -1) {
			p.push_back(path[y]);
			y = path[y];
		}

		vector<int> ans;
		if(p.size() % 2 != 0)
			ans.push_back(p[p.size()/2]);
		else
			ans.push_back(p[p.size()/2]), ans.push_back(p[p.size()/2-1]);
		sort(ans.begin(),ans.end());

		printf("Best Roots  :");
		for(int i = 0; i < ans.size(); i++)
			printf(" %d",ans[i]+1);
		puts("");
		printf("Worst Roots :");
		vector<int> worst = leaf(ans[0]);
		if(ans.size() == 2) {
			vector<int> ad = leaf(ans[1]);
			worst.insert(worst.end(),ad.begin(),ad.end());
			sort(worst.begin(),worst.end());
		}
		for(int i = 0; i < worst.size(); i++)
			if(i == 0 || worst[i] != worst[i-1])
				printf(" %d",worst[i]);
		puts("");
	}
}
