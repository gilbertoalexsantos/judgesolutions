//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=129

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

enum Color { WHITE, BLACK };

int qt_black;
vector<int> graph[101];
vector<int> ans, flag_ans;
Color color[101];

void backtrack(int vertex, int size, int flag_black = 0) {
	if(vertex > size) {
		if(flag_black > qt_black) {
			qt_black = flag_black;
			ans.clear();
			for(int i = 0; i < flag_ans.size(); i++) ans.push_back(flag_ans[i]);
		}
		return;
	}

	bool ok_black = true;
	for(int i = 0; i < graph[vertex].size(); i++) {
		int vtemp = graph[vertex][i];
		if(color[vtemp] != BLACK) continue;
		ok_black = false;
		break;
	}

	if(ok_black) {
		color[vertex] = BLACK;
		flag_ans.push_back(vertex);
		backtrack(vertex+1,size,flag_black+1);
		flag_ans.pop_back();
	}

	color[vertex] = WHITE;
	backtrack(vertex+1,size,flag_black);
}

void clear() {
	for(int i = 0; i < 101; i++) graph[i].clear();
	qt_black = -1;
	ans.clear(); flag_ans.clear();
	memset(color,0,sizeof color);
}

int main() {
	int m;
	scanf("%d",&m);
	while(m--) {
		clear();
		int n, k;
		scanf("%d %d",&n,&k);
		while(k--) {
			int a, b;
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		backtrack(1,n);
		printf("%d\n",qt_black);
		if(!ans.empty()) printf("%d",ans[0]);
		for(int i = 1; i < ans.size(); i++) printf(" %d",ans[i]);
		printf("\n");
	}
}
