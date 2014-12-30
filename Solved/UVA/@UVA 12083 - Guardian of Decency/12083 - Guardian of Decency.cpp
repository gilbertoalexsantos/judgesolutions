//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3235

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

struct TYPE {
	int h;
	char *music, *sport, s;
	TYPE(int h, char s, char *music, char*sport) : h(h), s(s), music(music), sport(sport) {}
};

const int MAX_VERT = 500;
const int MAX_WORD = 105;

int qt_vert;
int size_set_m, size_set_f;
vector<int> graph[MAX_VERT];
vector<int> match, visited;
vector<TYPE> arr_vert_m;
vector<TYPE> arr_vert_f;

inline bool is_couple(TYPE a, TYPE b) { return abs(a.h-b.h) <= 40 && a.s != b.s && strcmp(a.music,b.music) == 0 && strcmp(a.sport,b.sport) != 0; }

void clear() {
	arr_vert_m.clear();
	arr_vert_f.clear();
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
	}
}

void buildEdge() {
	for(int i = 0; i < size_set_m; i++) {
		for(int j = 0; j < size_set_f; j++) {
			if(!is_couple(arr_vert_m[i],arr_vert_f[j])) continue;
			graph[i].push_back(j+size_set_m), graph[j+size_set_m].push_back(i);
		}
	}
}

int augment_path(int v) {
	if(visited[v]) return 0;
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

// Max Independent Set = Quantity_Vertices - Max Cardinality Bipartite Matching
int MCBM() {
	int ret = 0;
	match.assign(qt_vert,-1);
	int limit = max(size_set_f,size_set_m);
	for(int i = 0; i < size_set_m && ret < limit; i++) {
		visited.assign(size_set_m,false);
		ret += augment_path(i);
	}
	return qt_vert - ret;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&qt_vert);
		clear();
		int h;
		char s;
		char *music, *sport;
		for(int i = 0; i < qt_vert; i++) {
			music = new char[MAX_WORD], sport = new char[MAX_WORD];	
			scanf("%d %c %s %s",&h,&s,music,sport);
			if(s == 'M')
				arr_vert_m.push_back(TYPE(h,s,music,sport));	
			else
				arr_vert_f.push_back(TYPE(h,s,music,sport));	
		}
		size_set_m = arr_vert_m.size(), size_set_f = arr_vert_f.size();
		buildEdge();
		int ans = MCBM();
		printf("%d\n",ans);
	}
}
