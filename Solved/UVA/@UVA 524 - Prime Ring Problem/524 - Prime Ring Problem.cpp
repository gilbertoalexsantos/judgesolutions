//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=465

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

bool checked[17];
int ans[17];
bool prime[33];

bool isPrime(int n) {
	if(n == 0 || n == 1) return true;
	for(int i = 2; i < sqrt(n)+1; i++) if(!(n % i)) return false;
	return true;
}

void preprocess() {
	prime[0] = prime[1] = prime[2] = 1;
	for(int i = 3; i <= 32; i++) prime[i] = isPrime(i);
}

void backtrack(int n, int cont) {
	if(cont == n) {
		if(!prime[ans[cont-1]+1]) return;
		printf("%d",ans[0]);
		for(int i = 1; i < n; i++) printf(" %d",ans[i]);
		printf("\n");
		return;
	}

	for(int i = 2; i <= n; i++) {
		if(!prime[ans[cont-1]+i] || checked[i]) continue;
		checked[i] = 1;
		ans[cont] = i;
		backtrack(n,cont+1);
		checked[i] = 0;
	}
}

int main() {
	int n, cases = 1;
	preprocess();
	int first = true;
	while(scanf("%d",&n) != EOF) {
		if(first) first ^= 1;
		else printf("\n");
		memset(checked,0,sizeof checked);
		checked[1] = ans[0] = 1;
		printf("Case %d:\n",cases++);
		backtrack(n,1);
	}
}
