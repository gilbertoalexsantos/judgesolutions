//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=370

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 201;
const int MAX_WORD = 11;
const int INF = 1e9;

struct cmp{ bool operator() (const char *a, const char *b) const { return strcmp(a,b) < 0; } };

char word[MAX][MAX_WORD];
vector<int> st[MAX_WORD];
int dist[MAX], len[MAX];
map<char*,int,cmp> m;
int qt_vert, qt_transformation;

void clear() {
	for(int i = 0; i < MAX_WORD; i++) st[i].clear();
	qt_vert = qt_transformation = 0;
	m.clear();
}

bool check(const int a, const int b) {
	int sum = 0;
	for(int i = 0; i < len[a]; i++) {
		if(word[a][i] != word[b][i]) sum++;	
		if(sum > 1) return false;
	}
	return true;
}

int bfs(int a, int b) {
	for(int i = 0; i < qt_vert; i++) dist[i] = INF;
	int l = len[a];
	queue<int> qe;
	qe.push(a);
	dist[a] = 0;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < st[l].size(); i++) {
			int nv = st[l][i];
			if(nv == v || dist[nv] < INF || !check(v,nv)) continue;
			dist[nv] = dist[v]+1;
			qe.push(nv);
			if(nv == b) return dist[nv];
		}
	}
	return INF;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		clear();
		while(scanf("%s",word[qt_vert]) && word[qt_vert][0] != '*') {
			len[qt_vert] = strlen(word[qt_vert]);
			st[len[qt_vert]].push_back(qt_vert);
			m.insert(make_pair(word[qt_vert],qt_vert));
			qt_vert++;
		}
		getchar();
		char w[25];
		while(fgets(w,25,stdin) && w[0] != '\n') {
			int a, b;
			char *f = strtok(w," ");
			a = m.find(f)->second;
			f = strtok(NULL,"\n ");
			b = m.find(f)->second;
			int ans = bfs(a,b);
			printf("%s %s %d\n",word[a],word[b],ans);
		}
		if(T) printf("\n");
	}
}
