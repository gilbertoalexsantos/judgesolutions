//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3077

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
using namespace std;

#define MAX 1000000
typedef bitset<MAX> bs;

bs bit;
int n, m;

bool check(int x, int y) {
	for(int i = x; i < y; i++) {
		if(x >= MAX) return true;
		if(bit[i]) return false;
		bit.set(i);
	}
	return true;
}

int main() {
	while(scanf("%d %d",&n, &m) &&	!((n == 0) && (m == 0))) {
		bool ok = true;
		while(n--) {
			int x, y;
			scanf("%d %d",&x, &y);
			if(ok) ok = check(x,y);
		}
		while(m--) {
			int x, y, z;
			scanf("%d %d %d",&x, &y, &z);
			int t = 0;
			while(ok && (x+t) < MAX) {
				ok = check(x+t,y+t);
				t += z;
			}
		}
		(ok) ? printf("NO CONFLICT\n") : printf("CONFLICT\n");
		bit.reset();
	}
}
