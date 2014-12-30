//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1444

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

vector<int> board[15];
bool marked[15][15];

int backtrack(int n, int f, int s, int cont = 0) {
	if(cont > n) return 0;

	if(cont == n) return (f == s);

	int ans = 0;

	for(int i = 0; i < board[f].size(); i++) {
		int v = board[f][i];
		if(marked[f][v]) continue;
		marked[f][v] = marked[v][f] = 1;
		ans = max(ans,backtrack(n,v,s,cont+1));
		if(ans) break;
		marked[f][v] = marked[v][f] = 0;
	}

	return ans;
}

void clear() {
	for(int i = 0; i < 15; i++) board[i].clear();
	memset(marked,0,sizeof marked);
}

int main() {
	int n;
	while(scanf("%d",&n) && n) {
		clear();
		int m;
		scanf("%d",&m);
		int f[2], s[2];
		scanf("%d %d %d %d",&f[0],&f[1],&s[0],&s[1]);
		for(int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d",&a,&b);
			board[a].push_back(b);
			if(a != b) board[b].push_back(a);
		}
		int ans = backtrack(n,f[1],s[0]);
		ans ? printf("YES\n") : printf("NO\n");
	}
}
