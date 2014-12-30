//Author:	Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2267

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int solve(int qt_dragon, int qt_knight, int arr_dragon[], int arr_knight[]) {
	sort(arr_dragon,arr_dragon + qt_dragon);
	sort(arr_knight,arr_knight + qt_knight);
	int i = 0, j = 0, ans = 0;
	while(i < qt_dragon && j < qt_knight) {
		while(arr_dragon[i] > arr_knight[j] && j < qt_knight) j++;
		if(j == qt_knight) break;
		ans += arr_knight[j];
		i++, j++;
	}
	return (i != qt_dragon) ? 0 : ans;
}

int main() {
	int qt_dragon, qt_knight;
	while(scanf("%d %d",&qt_dragon,&qt_knight) && qt_dragon+qt_knight) {
		int arr_dragon[qt_dragon], arr_knight[qt_knight];
		for(int i = 0; i < qt_dragon; i++) scanf("%d",&arr_dragon[i]);
		for(int i = 0; i < qt_knight; i++) scanf("%d",&arr_knight[i]);
		int ans = solve(qt_dragon,qt_knight,arr_dragon,arr_knight);
		ans ? printf("%d\n",ans) : printf("Loowater is doomed!\n");
	}
}
