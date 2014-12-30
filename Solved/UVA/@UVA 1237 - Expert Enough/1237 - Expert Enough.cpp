//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3678

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int t, d, l, h, q, p;
int ll[10000], rr[10000];
char m[10000][21];

int getK(int n, int &pos) {
	int ans = 0;
	for(int i = 0; i < d; i++) {
		if(ans > 1) break;
		if(ll[i] > n || rr[i] < n) continue;
		ans++;
		pos = i;
	}
	return (ans > 1) ? 0 : ans;
}

int main() {
	scanf("%d",&t);
	bool first = true;
	while(t--) {
		if(first) first ^= 1;
		else printf("\n");
		scanf("%d",&d);
		for(int i = 0; i < d; i++) {
			scanf("%s %d %d",m[i],&l,&h);
			ll[i] = l;
			rr[i] = h;
		}
		scanf("%d",&q);
		for(int i = 0; i < q; i++) {
			int pos;
			scanf("%d",&p);
			getK(p,pos) ? printf("%s\n",m[pos]) : printf("UNDETERMINED\n");
		}
	}
}
