//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int INF = 1000000000;
int memo[55][55];

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

		for(int left = 0; left <= qt_cut; left++) memo[left][left+1] = 0;

		for(int right_menos_left = 2; right_menos_left <= qt_cut+1; right_menos_left++) {
			for(int left = 0; left+right_menos_left <= qt_cut+1; left++) {
				int right = left + right_menos_left;
				int &ret = memo[left][right];
				ret = INF;
				for(int i = left+1; i < right; i++) {
					int p1 = memo[left][i];
					int p2 = memo[i][right];
					int c = arr_cut[right] - arr_cut[left];
					ret = min(ret,p1+p2+c);
				}
			}
		}

		int ans = memo[0][qt_cut+1];

		printf("The minimum cutting is %d.\n",ans);
	}
}
