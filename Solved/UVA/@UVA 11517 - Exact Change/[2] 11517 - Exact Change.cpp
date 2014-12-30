//Author:	Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2512

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<int,int> pint;

const int INF = 1e9;
const int MAX = 10001;

pint memo[MAX];
int n, k, T;
int arr_coin[100];

int main() {
	scanf("%d",&T);
	while(T--) {

		scanf("%d %d",&n,&k);
		for(int i = 0; i < k; i++) scanf("%d",&arr_coin[i]);

		for(int i = 1; i < MAX; i++) memo[i] = pint(INF,INF);
		memo[0] = pint(0,0);

		for(int i = 0; i < k; i++) for(int j = MAX; j >= arr_coin[i]; j--) {
			pint &ret = memo[j-arr_coin[i]];
			if(ret.first != INF)
				memo[j] = min(memo[j],pint(ret.first+arr_coin[i],ret.second+1));
		}

		pint ans;
		for(int i = n; i <= MAX; i++) {
			if(memo[i].first != INF) {
				ans = memo[i];
				break;
			}
		}
		printf("%d %d\n",ans.first,ans.second);
	}
}
