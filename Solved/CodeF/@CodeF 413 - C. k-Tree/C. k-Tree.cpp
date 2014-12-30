#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

const int MODULO = 1000000007;

ll memo[150][150][2];

int n, k, d;

ll dp(int altura=0, ll sum=0, bool has = false) {
  if(sum == n)
    return has;
  if(sum > n)
    return 0;

  ll &ret = memo[altura][sum][has];
  if(ret != -1)
    return ret % MODULO;

  ret = 0;

  for(ll i = 1; i <= k; i++) {
    ret += dp(altura + 1,sum + i,(has | (i >= d))) % MODULO;
    ret %= MODULO;
  }

  return ret % MODULO;
}


int main() {
  memset(memo,-1,sizeof memo);
  scanf("%d %d %d",&n,&k,&d);
  ll ans = dp();
  cout << ans << endl;
}
