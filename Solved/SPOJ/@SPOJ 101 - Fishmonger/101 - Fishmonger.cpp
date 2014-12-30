//Author:	Gilberto A. dos Santos
//Website:	http://www.spoj.com/problems/FISHER/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 50;
const int MAX_TIME = 1001;
const int INF = 1e9;

int qt_state, t;
int cost_time[MAX][MAX], cost_tool[MAX][MAX];
ii memo[MAX][MAX_TIME];

void clear() {
	for(int i = 0; i < qt_state; i++) for(int j = 0; j <= t; j++) {
		memo[i][j] = ii(-1,-1);
	}
}

ii dp(int pos = 0, int time_left = t) {
	if(time_left < 0) return ii(INF,INF);	
	if(pos == qt_state-1) return ii(0,0);

	if(memo[pos][time_left].first != -1)
		return memo[pos][time_left];

	ii &ret = memo[pos][time_left];
	ret = ii(INF,INF);

	for(int i = 0; i < qt_state; i++) if(i != pos) {
		ii next = dp(i,time_left - cost_time[pos][i]);
		if(next.first + cost_tool[pos][i] < ret.first) {
			ret.first = next.first + cost_tool[pos][i];
			ret.second = next.second + cost_time[pos][i];
		}
	}

	return ret;
}

int main() {
	while(scanf("%d %d",&qt_state,&t) && qt_state+t) {
		clear();
		for(int i = 0; i < qt_state; i++) for(int j = 0; j < qt_state; j++)	
			scanf("%d",&cost_time[i][j]);
		for(int i = 0; i < qt_state; i++) for(int j = 0; j < qt_state; j++)	
			scanf("%d",&cost_tool[i][j]);
		ii ans = dp();
		printf("%d %d\n",ans.first, ans.second);
	}
}
