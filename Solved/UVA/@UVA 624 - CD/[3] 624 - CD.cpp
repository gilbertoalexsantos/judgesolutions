//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	int wanted;
	while(scanf("%d",&wanted) != EOF) {
		int qt_track;
		scanf("%d",&qt_track);
		int arr[qt_track];
		for(register int i = 0; i < qt_track; i++) scanf("%d",&arr[i]);

		int flag_sum = -1, ans = -1;
		for(register int i = ((1 << qt_track) - 1); i >= 0; i--) {
			int sum = 0;
			for(register int j = 0; (1 << j) <= i; j++) if((1 << j) & i) sum += arr[j];
			if(sum > flag_sum && sum <= wanted) {
				flag_sum = sum;
				ans = i;
			}
		}

		for(register int i = 0; (1 << i) <= ans; i++)
			if((1 << i) & ans) printf("%d ",arr[i]);
		printf("sum:%d\n",flag_sum);
	}
}


