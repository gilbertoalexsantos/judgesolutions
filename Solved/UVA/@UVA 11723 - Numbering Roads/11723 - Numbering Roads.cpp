//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2823

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int r, n;

int solve() {
	if(n >= r)
		return 0;
	int needed = r - n;
	int x = needed / n + (needed % n != 0);
	return x > 26 ? -1 : x;
}

int main() {
	int cases = 1;
	while(scanf("%d %d",&r,&n) && r+n) {
		int ans = solve();
		printf("Case %d: ",cases++);	
		ans != -1 ? printf("%d\n",ans) : printf("impossible\n");
	}
}
