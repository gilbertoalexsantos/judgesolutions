//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int solve(int size, const char field[]) {
	int ans = 0;
	for(int i = 0; i < size; i++) {
		if(field[i] == '#') continue;
		ans++, i += 2;
	}
	return ans;
}

int main() {
	int cases = 1, T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		char field[n];
		scanf("%s",field);
		printf("Case %d: %d\n",cases++,solve(n,field));
	}
}
