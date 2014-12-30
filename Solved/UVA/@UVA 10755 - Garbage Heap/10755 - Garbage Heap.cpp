//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1696

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

const ll INF = 1ULL << 62;

ll m[20][20][20];

int main() {
	int cases;
	bool first = true;
	scanf("%d",&cases);
	while(cases--) {
		first ? first = false : printf("\n");
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		for(int i = 0; i < a; i++) for(int j = 0; j < b; j++) for(int z = 0; z < c; z++) {
			scanf("%lld",&m[i][j][z]);
			ll &ret = m[i][j][z];
			if(i > 0) ret += m[i-1][j][z];
			if(j > 0) ret += m[i][j-1][z];
			if(z > 0) ret += m[i][j][z-1];
			if(i > 0 && j > 0) ret -= m[i-1][j-1][z];
			if(i > 0 && z > 0) ret -= m[i-1][j][z-1];
			if(j > 0 && z > 0) ret -= m[i][j-1][z-1];
			if(i > 0 && j > 0 && z > 0) ret += m[i-1][j-1][z-1];
		}

		ll ans = -INF;

		for(int A = 0; A < a; A++) for(int B = 0; B < b; B++) for(int C = 0; C < c; C++)
			for(int i = A; i < a; i++) for(int j = B; j < b; j++) for(int k = C; k < c; k++) {
				ll sb = m[i][j][k];
				if(A > 0) sb -= m[A-1][j][k];
				if(B > 0) sb -= m[i][B-1][k];
				if(C > 0) sb -= m[i][j][C-1];
				if(A > 0 && B > 0) sb += m[A-1][B-1][k];
				if(A > 0 && C > 0) sb += m[A-1][j][C-1];
				if(B > 0 && C > 0) sb += m[i][B-1][C-1];
				if(A > 0 && B > 0 && C > 0) sb -= m[A-1][B-1][C-1];
				ans = max(ans,sb);
			}

		printf("%lld\n",ans);
	}
}
