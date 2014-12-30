//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=195

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 38;
const int INF = 1e9;

int source = 0, sink = 37;
int total;
int res[MAX][MAX];
vector<int> graph[MAX];
int path[MAX];

inline void pb(int a, int b) { graph[a].push_back(b), graph[b].push_back(a); }

void clear() {
	total = 0;
	for(int i = 0; i < MAX; i++) {
		graph[i].clear();
	}
	memset(res,0,sizeof res);
	for(int i = 27; i <= 36; i++) {
		res[i][sink] = 1;
		pb(i,sink);
	}
}

void connect(char *word) {
	int app = word[0]-'A'+1, qt_user = word[1]-'0', pos = 3;
	total += qt_user;
	res[source][app] = qt_user;
	pb(source,app);
	while(word[pos] != ';') {
		int computer = (word[pos]-'0')+27;
		res[app][computer] = INF;
		pb(app,computer);
		pos++;
	}
}

int augment(int v, int minEdge) {
	if(v == source)
		return minEdge;
	else if (path[v] != -1) {
		int t = augment(path[v], min(minEdge,res[path[v]][v]));
		res[path[v]][v] -= t; res[v][path[v]] += t;
		return t;
	}
	return 0;
}

bool bfs() {
	bool visited[MAX];
	memset(visited,false,sizeof visited);
	memset(path,-1,sizeof path);
	queue<int> qe; qe.push(source);
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		if(v == sink) return true;
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(res[v][nv] > 0 && !visited[nv])
				visited[nv] = true, qe.push(nv), path[nv] = v;
		}
	}
	return false;
}

int edmond() {
	int ret = 0;
	while(bfs())
		ret += augment(sink,INF);
	return ret;
}

void prt(int p) {
	for(int i = 0; i < graph[p].size(); i++) {
		int v = graph[p][i];
		if(v == sink) continue;
		if(res[p][v] == 1) {
			printf("%c",v-1+'A');
			return;
		}
	}
	printf("_");
}

int main() {
	char word[30];
	while(fgets(word,30,stdin) && word[0] != '\n') {
		clear();
		connect(word);
		while(fgets(word,30,stdin) && word[0] != '\n') connect(word);
		int maxflow = edmond();
		if(maxflow == total) for(int i = 27; i <= 36; i++)
			prt(i);
		else
			printf("!");
		puts("");
	}
}
