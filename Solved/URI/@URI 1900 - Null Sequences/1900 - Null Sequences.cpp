//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1900

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_NUMBERS = 1e5 + 5;

ll sum[MAX_NUMBERS];
map<ll, vector<int> > positions;
int n;

ll qt(int i, vector<int> &v) {
  int low = (lower_bound(v.begin(), v.end(), i) - v.begin());
  return v.size() - low;
}

int main() {
  scanf("%d", &n);
  sum[0] = 0;

  for (int i = 1; i <= n; i++) {
    ll x; scanf("%lld", &x);
    sum[i] = sum[i-1] + x;
    if (positions.find(sum[i]) == positions.end()) {
      vector<int> v; v.push_back(i);
      positions[sum[i]] = v;
    } else {
      (*positions.find(sum[i])).second.push_back(i);
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (positions.find(sum[i-1]) == positions.end())
      continue;
    ans += qt(i, positions[sum[i-1]]);
  }

  printf("%lld\n", ans);
}
