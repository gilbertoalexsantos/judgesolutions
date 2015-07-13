//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1492

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long cnt[66];

void init() {
  cnt[0] = 0, cnt[1] = 0, cnt[2] = 1;
  long long pw = 2;
  for (int i = 3, j = 1; i <= 65; i++, j++) {
    cnt[i] = cnt[i-1] * 2 + pw;
    pw *= 2;
  }
}

vector<int> transform(long long n) {
  vector<int> ret;
  while (n != 0) {
    ret.push_back(n % 2);
    n /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

long long countOnes(long long u) {
  vector<int> u_bin = transform(u);
  long long ret = 0, v = 0;
  for (int i = 0, j = u_bin.size(); i < u_bin.size(); i++, j--) {
    if (!u_bin[i]) {
      continue;
    }
    v |= 1LL << (j-1);
    long long qtBetween = u - v + 1;
    ret += cnt[j] + qtBetween;
  }
  return ret;
}

int main() {
  init();
  long long u, v;
  while (scanf("%lld %lld", &u, &v) != EOF) {
    long long ans = countOnes(v) - countOnes(u-1);
    printf("%lld\n", ans);
  }
}
