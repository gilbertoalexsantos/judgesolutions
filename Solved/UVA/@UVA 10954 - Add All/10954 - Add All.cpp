//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int n;

int main() {
	while(scanf("%d",&n) && n) {
		priority_queue<int> pq;
		int ans = 0;
		while(n--) {
			int t;
			scanf("%d",&t);
			pq.push(-t);
		}
		while(pq.size() > 1) {
			int a1 = -pq.top(); pq.pop();
			int a2 = -pq.top(); pq.pop();
			int a3 = a1 + a2;
			ans += a3;
			pq.push(-a3);
		}
		cout << ans << endl;
	}
}
