//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1760

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pint;
typedef vector<pint> vi;

int main() {
	int qt_money, qt_dot;
	while(scanf("%d %d",&qt_money,&qt_dot) != EOF) {
		bool is_minor = false;
		if(qt_money+200 > 2000) qt_money += 200, is_minor = true;
		vi arr(qt_dot);
		for(int i = 0; i < qt_dot; i++) scanf("%d %d",&arr[i].first,&arr[i].second);

		vi memo(qt_money+1);
		for(int i = 0; i <= qt_money; i++) memo[i].first = 0, memo[i].second = 0;
		memo[0].first = 1, memo[0].second = 0;
		for(int i = 0; i < qt_dot; i++)
			for(int j = qt_money; j >= arr[i].first; j--) {
				if(is_minor && j <= 2000 && j > qt_money-200) continue;
				if(memo[j-arr[i].first].first) {
					memo[j].first = 1;
					memo[j].second = max(memo[j].second,memo[j-arr[i].first].second+arr[i].second);
				}
			}

		int ans = -1;
		for(int i = 0; i <= qt_money; i++) ans = max(ans,memo[i].second);
		printf("%d\n",ans);
	}
}
