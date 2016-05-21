//Author: Gilberto A. dos Santos
//Website: http://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll lower_bound(ll v[], ll l, ll r, ll p) {
  ll m;
  while (l <= r) {
    m = (l+r)/2;
    if (v[m] < p)
      l = m+1;
    else
      r = m-1;
  }
  return r+1;
}

bool can(ll v[], ll size, ll qtWanted, ll p) {
  ll i = 0, qt = 0;
  while (i+1 < size && qt < qtWanted) {
    i = lower_bound(v, i+1, size-1, v[i] + p);
    qt++;
  }
  return i < size && qt == qtWanted;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    ll n, c; scanf("%lld %lld", &n, &c);

    ll v[n];
    for (ll i = 0; i < n; i++)
      scanf("%lld", &v[i]);

    sort(v, v+n);

    ll l = 0, r = 1e9, m;
    ll ans = -1;
    while (l <= r) {
      m = (l+r)/2;
      if (can(v, n, c-1, m)) {
        l = m+1;
        ans = m;
      } else {
        r = m-1;
      }
    }

    printf("%lld\n", ans);
  }
}
