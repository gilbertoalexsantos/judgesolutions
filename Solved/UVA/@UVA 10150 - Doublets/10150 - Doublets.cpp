//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1091

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef map<char*,int>::iterator IT;

const int MAX = 26000;

struct cmp { bool operator() (const char* a, const char* b) const { return strcmp(a,b) < 0; } };

map<char*,int,cmp> toint;

char word[MAX][20];
int len[MAX];
vector<int> arr_len[20];

vector<int> graph[MAX];
bool visited[MAX];
int parent[MAX];
int qt_vert = 0;

bool check(int p1, int p2) {
	int sum = 0;
	for(int i = 0; i < len[p1]; i++) {
		sum += (word[p1][i] != word[p2][i]);
		if(sum > 1) return false;
	}
	return true;
}

void createGraph() {
	for(int l = 1; l <= 16; l++) {
		for(int i = 0; i < arr_len[l].size(); i++) {
			int a = arr_len[l][i];
			for(int j = i+1; j < arr_len[l].size(); j++) {
				int b = arr_len[l][j];
				if(check(a,b))
					graph[a].push_back(b), graph[b].push_back(a);
			}
		}
	}
}

void bfs(int a, int b) {
	memset(visited,false,sizeof visited);
	for(int i = 0; i < qt_vert; i++) parent[i] = i;
	queue<int> qe;
	qe.push(a);
	visited[a] = true;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(visited[nv]) continue;
			parent[nv] = v;
			visited[nv] = true;
			if(nv == b) return;
			qe.push(nv);
		}
	}
}

void pr(int a) {
	if(parent[a] == a) {
		printf("%s\n",word[a]);
	} else {
		pr(parent[a]);
		printf("%s\n",word[a]);
	}
}

int main() {
	char* w = new char[50];
	while(scanf("%[^\n]",w) && w[0] != '\n') {
		toint.insert(make_pair(w,qt_vert));
		strcpy(word[qt_vert],w);
		len[qt_vert] = strlen(w);

		arr_len[len[qt_vert]].push_back(qt_vert);

		qt_vert++;
		w = new char[50];
		getchar();
	}

	createGraph();

	getchar();
	w = new char[50];
	bool first = true;
	while(fgets(w,50,stdin) && w[0] != '\n') {
		first ? first = false : printf("\n");
		int a,b;

		char* f = strtok(w," ");
		IT it = toint.find(f);
		if(it == toint.end()) {
			printf("No solution.\n");
			continue;
		}
		a = it->second;

		f = strtok(NULL,"\n ");
		it = toint.find(f);
		if(it == toint.end()) {
			printf("No solution.\n");
			continue;
		}
		b = it->second;

		bfs(a,b);
		if(!visited[b]) printf("No solution.\n");
		else pr(b);
	}
}
