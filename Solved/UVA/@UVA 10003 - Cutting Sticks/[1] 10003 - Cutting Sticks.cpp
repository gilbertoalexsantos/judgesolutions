//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int INF = 1000000000;
int memo[50][51];

int dp(int left, int right, int arr[]) {
	if(left+1 == right) return 0;

	int &ret = memo[left][right];
	if(ret != -1) return ret;

	ret = INF;
	for(int i = left+1; i < right; i++) {
		int p1 = dp(left,i,arr);
		int p2 = dp(i,right,arr);
		int c = arr[right] - arr[left];
		ret = min(ret,p1+p2+c);
	}

	return ret;
}

void clear() {
	memset(memo,-1,sizeof memo);
}

int main() {
	int l;
	while(scanf("%d",&l) && l) {
		clear();

		int qt_cut;
		scanf("%d",&qt_cut);
		int arr_cut[qt_cut+2];
		arr_cut[0] = 0;
		arr_cut[qt_cut+1] = l;
		for(int i = 1; i <= qt_cut; i++) scanf("%d",&arr_cut[i]);

		int ans = dp(0,qt_cut+1,arr_cut);

		printf("The minimum cutting is %d.\n",ans);
	}
}
