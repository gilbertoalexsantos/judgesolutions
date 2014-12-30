//Author:	Gilberto A. dos Santos
//website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1517

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

int main() {
	ll s, d;
	while(scanf("%lld %lld",&s,&d) != EOF) {
		ll ans = -1;
		for(int i = 0; i < (1 << 12); i++) {
			ll qt = 0;
			bool check = true;
			for(int j = 0; j < 12; j++) {
				qt += (i & (1 << j)) ? s : -d;
				if(j + 5 <= 12) {
					ll temp = 0;
					for(int k = j; k < j+5; k++)
						temp += (i & (1 << k)) ? s : -d;
					if(temp >= 0) {
						check = false;
						break;
					}
				}
			}
			if(check) ans = max(ans,qt);
		}
		(ans < 0) ? printf("Deficit\n") : printf("%lld\n",ans);
	}
}
