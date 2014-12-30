//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=357

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int digit[] = { 126,48,109,121,51,91,95,112,127,123 };

bool backtrack(int number, int size, int led[], int cont = 0, int mask = 0) {
	if(cont == size) return true;	
	if(mask & led[cont]) return false;

	int	new_mask = digit[number] ^ led[cont];
	if(new_mask & led[cont]) return false;

	return backtrack(number-1,size,led,cont+1,new_mask | mask);
}

int main() {
	int n;
	while(scanf("%d",&n) && n) {
		int led[n];
		for(int i = 0; i < n; i++) {
			int v = 0;
			char t[8];
			scanf("%s",t);
			for(int j = 0, x = 6; j < 7; j++,x--) if(t[j] == 'Y') v |= 1 << x;
			led[i] = v;
		}
		bool ans = false;
		for(int i = 9; i >= n-1; i--) {
			ans = backtrack(i,n,led);
			if(ans) break;
		}
		ans ? printf("MATCH\n") : printf("MISMATCH\n");
	}
}
