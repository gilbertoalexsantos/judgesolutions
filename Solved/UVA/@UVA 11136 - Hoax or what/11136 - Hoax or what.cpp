//Author:	Gilberto A. dom mantom
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2077

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

int n;

int main() {
	while(scanf("%d",&n) && n) {
		long long ans = 0;
		multiset<long long> m;
		multiset<long long>::iterator it;
		while(n--) {
			long long k;
			scanf("%lld",&k);
			for(long long i = 0; i < k; i++) {
				long long t;
				scanf("%lld",&t);
				m.insert(t);
			}
			it = m.end();
			it--;
			ans += *it - *m.begin();
			m.erase(it);
			m.erase(m.begin());
		}
		printf("%lld\n",ans);
	}
}
