//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1892

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, string> ii;

long long n;
long long steps;
vector<ii> v;

bool cmp(ii &a, ii &b) {
  return a.first < b.first && a.second > b.second;
}

void merge(long long l, long long r) {
  long long m = (l + r) / 2;
  vector<ii> flag(r - l + 1);
  long long cnt = 0;


  long long toAdd = m - l + 1;

  long long ll = l, rr = m+1;
  while (ll <= m && rr <= r) {
    if (cmp(v[ll], v[rr])) {
      flag[cnt++] = v[rr++];
      steps += toAdd;
    } else {
      flag[cnt++] = v[ll++];
      toAdd--;
    }
  }


  while (ll <= m)
    flag[cnt++] = v[ll++];
  while (rr <= r)
    flag[cnt++] = v[rr++];

  cnt = 0;
  while (l <= r)
    v[l++] = flag[cnt++];
}

void mergesort(long long l, long long r) {
  if (l >= r) {
    return;
  }

  long long m = (l + r) / 2;
  mergesort(l, m);
  mergesort(m+1, r);
  merge(l, r);
}

void clear() {
  v.clear();
  steps = 0;
}

int main() {
  while (cin >> n) {
    clear();
    for (long long i = 0; i < n; i++) {
      string x; cin >> x;
      v.push_back(ii(i, x));
    }

    mergesort(0, n-1);

    cout << steps << endl;
  }
}
