//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2451

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int qt_car;
		scanf("%d",&qt_car);
		int arr_car[qt_car];
		for(int i = 0; i < qt_car; i++) scanf("%d",&arr_car[i]);
		reverse(arr_car,arr_car+qt_car);

		int lis[qt_car], lds[qt_car];
		for(int i = 0; i < qt_car; i++) lis[i] = lds[i] = 1;
		for(int i = 0; i < qt_car; i++) {
			int t = arr_car[i], l = lis[i]+1, d = lds[i]+1;
			for(int j = i+1; j < qt_car; j++) {
				if(t < arr_car[j] && lis[j] < l) lis[j] = l;
				if(t > arr_car[j] && lds[j] < d) lds[j] = d;
			}
		}

		int ans = 0;
		for(int i = 0; i < qt_car; i++) ans = max(ans,lis[i]+lds[i]-1);
		printf("%d\n",ans);
	}
}
