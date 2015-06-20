//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3154

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

const int MAX = 1e5 * 3 + 5;

ii bucket[MAX];
int arr[MAX];

int bb(int l, int r, int value) {
  return (lower_bound(bucket+l, bucket+r+1, ii(value, 0)) - bucket) - l;
}

int out_bucket(int l, int r, int cl, int cr, int value) {
  int sum = 0;
  for (; l <= r; l++) {
    if (bucket[l].first < value && bucket[l].second >= cl && bucket[l].second <= cr)
      sum++;
  }
  return sum;
}

void change(int l, int r, int pos) {
  for (int i = l; i <= r; i++) {
    if (bucket[i].second == pos) {
      bucket[i].first = arr[pos];
      break;
    }
  }
  sort(bucket+l, bucket+r+1);
}

int main() {
  int n, m, u;
  scanf("%d %d %d",&n, &m, &u);

  const int SIZE_BUCKET = sqrt(n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    bucket[i] = ii(arr[i], i);
  }

  int cnt;
  for (cnt = 0; cnt+(2*SIZE_BUCKET) <= n; cnt += SIZE_BUCKET) {
    int left = cnt, right = left +  SIZE_BUCKET;
    sort(bucket+left, bucket+right);
  }
  sort(bucket+cnt, bucket+n);

  int L, R, v, p;
  while (m--) {
    scanf("%d %d %d %d",&L, &R, &v, &p);
    L--; R--; p--;
    int left, right, sum = 0;
    for (left = 0; left+(2*SIZE_BUCKET) <= n; left += SIZE_BUCKET) {
      right = left + SIZE_BUCKET - 1;
      if (L <= left && R >= right)
        sum += bb(left, right, v);
      else if (left <= R && right >= L)
        sum += out_bucket(left, right, L, R, v);
    }
    right = n - 1;
    if (L <= left && R >= right)
      sum += bb(left, right, v);
    else if (left <= R && right >= L)
      sum += out_bucket(left, right, L, R, v);

    R++; L++;
    arr[p] = (long long) u * sum / (R - L + 1);

    for (left = 0; left+(2*SIZE_BUCKET) <= n; left += SIZE_BUCKET) {
      right = left + SIZE_BUCKET - 1;
      if (p >= left && p <= right)
        change(left, right, p);
    }
    right = n - 1;
    if (p >= left && p <= right)
      change(left, right, p);
  }
  for(int i = 0; i < n; i++) {
    printf("%d\n",arr[i]);
  }
}
