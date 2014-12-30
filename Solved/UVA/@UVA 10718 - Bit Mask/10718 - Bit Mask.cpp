//Author:	Gilbeto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1659

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int lli;

lli solve(lli n, lli left, lli right) {
	lli mask = 0, beg = 0, end = 0;
	for(lli i = 0; i <= 31; i++) {
		if(1UL << i >= right) break;
		end = i;
	}
	for(lli i = 0; i <= 31; i++) {
		if(1UL << i >= beg) {
			beg = i;
			break;
		}
	}
	for(lli i = end; i >= beg; i--) {
		lli t = mask | (1UL << i);
		if(t < left) {
			mask |= 1UL << i;
		} else if(t >= left && t <= right) {
			if(mask + (1UL << i) - 1 < left) {
				mask |= 1UL << i;
				continue;
			}
			if(n & (1UL << i)) continue;
			mask |= 1UL << i;
		}
	}
	return mask;
}

int main() {
	lli n, l, u;
	while(scanf("%lld %lld %lld",&n,&l,&u) != EOF) {
		printf("%lld\n",solve(n,l,u));
	}
}
