//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1537

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_VERT = 200;

int degree[MAX_VERT];
int qt_vert, qt_edge;

bool solve() {
	for(int i = 0; i < qt_vert; i++)
		if(degree[i] % 2 != 0 || degree[i] == 0)
			return false;
	return true;
}

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		degree[i] = 0;
	}
}

int main() {
	while(scanf("%d %d",&qt_vert,&qt_edge) != EOF) {
		clear();
		for(int i = 0; i < qt_edge; i++) {
			int x, y; scanf("%d %d",&x,&y);
			degree[x]++, degree[y]++;
		}
		bool ans = solve();
		printf("%s\n",ans ? "Possible" : "Not Possible");
	}
}
