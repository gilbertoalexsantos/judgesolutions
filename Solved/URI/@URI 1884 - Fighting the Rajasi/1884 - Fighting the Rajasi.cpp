//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/pt/problems/view/1884

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<long long, long long> ii;

int n, k;
long long h;
ii a[2000];
bool killed[2000];

int findBest() {
  int ret = -1;
  long long diff = -1e18;
  for (int i = 0; i < n; i++) {
    if (killed[i] || h <= a[i].first)
      continue;
    long long d = a[i].second - a[i].first;
    if (d > diff || (d == diff && a[i].second > a[ret].second)) {
      ret = i;
      diff = d;
    }
  }
  if (ret != -1)
    killed[ret] = true;
  return ret;
}

bool cmp(const ii t1, const ii t2) {
  int diff1 = t1.second - t1.first;
  int diff2 = t2.second - t2.first;
  return diff1 == diff2 ? t1.first > t2.first : diff1 > diff2;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d %lld %d", &n, &h, &k);

    memset(killed, false, sizeof killed);
    for (int i = 0; i < n; i++)
      scanf("%lld %lld", &a[i].first, &a[i].second);

    int qt = 0, b = findBest();
    while (b != -1 && qt < n) {
      qt++;
      h = h - a[b].first + a[b].second;
      b = findBest();
    }

    qt += k;

    printf("%c\n", qt >= n ? 'Y' : 'N');
  }
}
