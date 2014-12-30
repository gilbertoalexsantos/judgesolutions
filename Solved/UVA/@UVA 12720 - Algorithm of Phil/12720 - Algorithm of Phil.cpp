//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4572

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long long ll;

const ll MODULE = 1000000007;

bool odd(ll size) { return size%2; }

ll memo[100009];
char word[100009];

ll bb(ll b, ll poten) {
	ll l = poten/2;
	ll &ret = memo[poten];
	if(ret != -1) return ret = ret % MODULE;
	if(poten == 0) return ret = 1;
	if(poten == 1) return ret = 2;
	if(odd(poten)) return ret = (bb(b,l) * bb(b,l+1)) % MODULE;
	else return ret = (bb(b,l) * bb(b,l)) % MODULE;
}

ll ans(char w[]) {
	ll resp = 0, mid = 0, size = strlen(w);
	ll i = 0, j = 0, cont = size-1;
	bool e_odd = false, usei_i = false;

	if(odd(size)) e_odd = true;
	i = (size-1)/2, j = i+1;

	while(size--) {
		if(e_odd) {
			mid = usei_i ? j++ : i--;
		} else {
			if(w[j] > w[i]) {
				mid = j;
				usei_i = false;
				j++;
			} else {
				mid = i;
				usei_i = true;
				i--;
			}
		}
		e_odd = !e_odd;
		if(w[mid] == '1') {
			resp += bb(2,cont);
			resp %= MODULE;
		}
		cont--;
	}

	return resp;
}

int main() {
	memset(memo,-1,sizeof memo);
	int qt, cases = 1;
	scanf("%d",&qt);
	while(qt--) {
		scanf("%s",word);
		printf("Case #%d: %llu\n",cases++,ans(word));
	}
}
