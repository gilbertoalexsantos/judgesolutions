//Author:	Gilberot A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3399

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int INF = 1e9;

int p1[3], p2[2];

int has(int n, bool t) {
	if(t) {
		for(int i = 0; i < 3; i++)
			if(p1[i] == n)
				return true;
		return false;
	} else {
		for(int i = 0; i < 2; i++)
			if(p2[i] == n)
				return true;
		return false;
	}
}

int bt(int mask1 = 0, int mask2 = 0, int score = 0) {

	if(mask2 == 3) {

		if(score == 2)
			return INF;

		if(score == 0) {
			for(int i = 1; i <= 52; i++) {
				if(!has(i,true) && !has(i,false))
					return i;
			}
		}

		for(int i = 0; i < 3; i++) {
			if(!(mask1 & (1 << i))) {
				for(int j = p1[i]; j <= 52; j++) {
					if(!has(j,true) && !has(j,false))
						return j;
				}
				return INF;
			}
		}
	}

	int ret = -1;
	for(int i = 0; i < 3; i++) if(!(mask1 & (1 << i))) {
		for(int j = 0; j < 2; j++) {
			if((mask2 & (1 << j)))
				continue;
			ret = max(ret,bt(mask1 | (1 << i),mask2 | (1 << j),score + (p1[i] > p2[j])));
		}
	}

	return ret;
}

int main() {
	while(scanf("%d %d %d %d %d",&p1[0],&p1[1],&p1[2],&p2[0],&p2[1]) && p1[0]) {
		int ans = bt();	
		printf("%d\n",ans == INF ? -1 : ans);
	}
}
