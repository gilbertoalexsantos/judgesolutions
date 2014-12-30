//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=813

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 26;

vector<vector<int> > graph(MAX);
bool flag_vert[MAX];
int degree[MAX];
int qt_vert;
vector<int> ans(MAX);
bool has_order;

void print_ans() {
	printf("%c",ans[0]+'A');
	for(int i = 1; i < qt_vert; i++)
		printf(" %c",ans[i]+'A');
	printf("\n");
	has_order = true;
}

inline void cntDegree(int v, int n) { for(int i = 0; i < graph[v].size(); i++) degree[graph[v][i]] += n; }

void top_sort(int v, int pos = 1) {
	cntDegree(v,-1);

	for(int i = 0; i < MAX; i++) if(flag_vert[i] && degree[i] == 0) {
		ans[pos] = i;
		flag_vert[i] = false;
		top_sort(i,pos+1);
		flag_vert[i] = true;
	}

	cntDegree(v,+1);

	if(pos == qt_vert-1) print_ans();
}

void top_sort() {
	for(int i = 0; i < MAX; i++) if(degree[i] == 0) {
		ans[0] = i;
		flag_vert[i] = false;
		top_sort(i);
		flag_vert[i] = true;
	}
}

void clear() {
	qt_vert = 0;
	has_order = false;
	for(int i = 0; i < MAX; i++) {
		degree[i] = -1;
		flag_vert[i] = true;
		graph[i].clear();
	}
}

int main() {
	int T;
	char w[50];
	scanf("%d\n\n",&T);
	while(T--) {
		clear();
		fgets(w,50,stdin);
		char *f = strtok(w," ");
		while(f != NULL) {
			qt_vert++;
			degree[f[0]-'A'] = 0;
			f = strtok(NULL," ");
		}
		fgets(w,50,stdin);
		f = strtok(w," ");
		while(f != NULL) {
			int a = f[0]-'A', b = f[2]-'A';
			graph[a].push_back(b);
			degree[b]++;
			f = strtok(NULL," ");
		}
		top_sort();
		if(!has_order) printf("NO\n");
		if(T) {
			fgets(w,50,stdin);
			printf("\n");
		}
	}
}
