//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3362

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<int, int> pint;

pint solve(int arr_b[], int arr_s[]) {
	pint ans(0,1e9);

	int i = 60, j = 60;
	while(i >= 2 && j >= 2) {
		if(!arr_b[i] || !arr_s[j]) {
			if(!arr_b[i]) i--; if(!arr_s[j]) j--;
			continue;
		}
		int to_less = min(arr_b[i],arr_s[j]);
		arr_b[i] -= to_less, arr_s[j] -= to_less;
	}

	for(int z = 2; z <= 60; z++) {
		if(arr_b[z]) {
			ans.first += arr_b[z];
			ans.second = min(z,ans.second);
		}
	}

	return ans;
}

int main() {
	int cases = 1, qt_bachelor, qt_spinster;
	while(scanf("%d %d",&qt_bachelor,&qt_spinster) && qt_bachelor,qt_spinster) {
		int arr_bachelor[61], arr_spinster[61];
		memset(arr_bachelor,0,sizeof arr_bachelor);
		memset(arr_spinster,0,sizeof arr_spinster);
		for(int i = 0; i < qt_bachelor; i++) {
			int t;
			scanf("%d",&t);
			arr_bachelor[t]++;
		}
		for(int i = 0; i < qt_spinster; i++) {
			int t;
			scanf("%d",&t);
			arr_spinster[t]++;
		}
		pint ans = solve(arr_bachelor,arr_spinster);
		(ans.first) ? printf("Case %d: %d %d\n",cases++,ans.first,ans.second) : printf("Case %d: 0\n",cases++);
	}
}
