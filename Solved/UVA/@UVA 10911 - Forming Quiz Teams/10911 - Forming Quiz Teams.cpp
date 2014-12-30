//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1852

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef pair<int,int> ii;

const int INF = 1e9;
const int MAX = 16;

int n, limit;
int size;
double dist[MAX][MAX];
ii point[MAX];
double memo[1 << 16];

void clear() {
	limit = n << 1;
	size = (1 << limit) - 1;
	memset(memo,-1,sizeof memo);
}

double dp(int mask = 0) {
	if(mask == size)
		return 0;

	double &ret = memo[mask];
	if(ret == ret)
		return ret;

	ret = INF;
	int p1, p2;
	for(int i = 0; i < limit; i++)
		if(!(mask & (1 << i))) {
			p1 = i;
			break;
		}
	for(int i = 0; i < limit; i++)
		if(!(mask & (1 << i)) && i != p1)
			ret = min(ret,dist[p1][i] + dp(mask | (1 << p1) | (1 << i)));

	return ret;
}

int main() {
	int cases = 1;
	while(scanf("%d",&n) && n) {
		clear();
		int arr[limit];
		for(int i = 0; i < limit; i++)
			scanf("%*s %d %d",&point[i].first,&point[i].second);
		for(int i = 0; i < limit; i++) for(int j = i+1; j < limit; j++)
			dist[i][j] = dist[j][i] = hypot(point[i].first - point[j].first,point[i].second - point[j].second);
		double ans = dp();
		printf("Case %d: %.2lf\n",cases++, ans);
	}
}
