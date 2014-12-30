//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1224
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAX_ARR = 10005;
const ll INF = (ll) 1 << 33;

int n;
ll arr[MAX_ARR];
ll memo[MAX_ARR];

ll dp() {
  for(int leftq = 0; leftq < n-1; leftq++)
    memo[leftq] = max(arr[leftq],arr[leftq+1]);

  if(n == 2) {
    ll maxq = -INF;
    for(int i = 0; i < n-1; i++)
      maxq = max(maxq,memo[i]);
    return maxq;
  }

  for(int len = 4, a = 3; len <= n; len += 2, a += 2) {
    for(int leftq = 0; leftq < n - a; leftq++) { 
      memo[leftq] = max(
            min(memo[leftq],memo[leftq+1]) + arr[len-1 + leftq],
            min(memo[leftq+1],memo[leftq+2]) + arr[leftq]
          );
    }
  }

  return memo[0];
}

int main() {
  while(scanf("%d",&n) != EOF) {
    for(int i = 0; i < n; i++)
      scanf("%lld",&arr[i]);
    ll ans = dp();
    printf("%lld\n",ans);
  }
}
