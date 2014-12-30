// Author: Gilberto A. dos Santos
// Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

int n;

int main() {
	while(scanf("%d",&n) != EOF) {
		int v[n];
		bool m[n+1];
		memset(m,0,sizeof m);
		for(int i = 0; i < n; i++) scanf("%d",&v[i]);
		for(int i = 1; i < n; i++) {
			int val = abs(v[i] - v[i-1]);
			if(val > (n-1)) continue;
			m[val] = 1;
		}
		bool bateu = true;
		for(int i = 1; i < n; i++) {
			if(m[i]) continue;
			bateu = false;
			break;
		}
		if(bateu) printf("Jolly\n");
		else printf("Not jolly\n");
	}
}
