#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int memo[1<<14][8][7];
signed char tab[8][7];
int m, n;

int doit(int mask, int i, int j) {
	if(i == n+1) return 0;

	int& ret = memo[mask][i][j];
	if(ret != -1) return ret;
	ret = 0x3f3f3f3f;

	for(int k = 0; k < 2; k++) {
		if(tab[i][j] != -2 && k == 1) continue;

		int vizinhos = k + !!(mask & (1<<(2*m-1)));

		if(j != 0) vizinhos += !!(mask & (1<<m));
		if(j != m-1) vizinhos += !!(mask & (1<<(m-2)));
		if(i != 0 && vizinhos != tab[i-1][j] && tab[i-1][j] >= 0 && tab[i-1][j] <= 4) continue; 
     
		if(j != m-1)
	  	    ret = min(ret, k + doit(((mask << 1) & ((1<<(2*m))-1)) + k, i, j+1));
		else
	  	    ret = min(ret, k + doit(((mask << 1) & ((1<<(2*m))-1)) + k, i+1, 0));
	}

	return ret;
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
		int b;
		scanf("%d", &b);

		memset(tab, -2, sizeof tab);
		for(int i = 0; i < m; i++)
			tab[n][i] = -1; 

		for(int i = 0; i < b; i++) {
			int r, c, k;
			scanf("%d %d %d", &r, &c, &k);
			tab[r-1][c-1] = k;
		}

		memset(memo, -1, sizeof memo);
		int ans = doit(0, 0, 0);

		if(ans >= 0x3f3f3f3f)
			printf("No solution\n");
		else
			printf("%d\n", ans);
	}
}
