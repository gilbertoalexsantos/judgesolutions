//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1084

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_NUMBERS = 1e5+5;
const int INF = 1e9;

int numbers[MAX_NUMBERS];
int n, d;
vector<int> ans;
vector<int> numbersPosition[10];

int lb(vector<int> &v, int n) {
  int lo = 0, hi = v.size()-1, mid;
  while (lo <= hi) {
    mid = (lo+hi)/2;
    if (v[mid] < n)
      lo = mid+1;
    else
      hi = mid-1;
  }
  return hi+1;
}

int getNumberPosition(int number, int lo, int hi) {
  vector<int> &nbs = numbersPosition[number];

  if (nbs.size() == 0)
    return -1;

  int lower = lb(nbs, lo);
  if (lower == nbs.size() || nbs[lower] > hi)
    return -1;

  return nbs[lower];
}

void clear() {
  ans.clear();
  for (int i = 0; i < 10; i++)
    numbersPosition[i].clear();
}

int main() {
  while (scanf("%d %d\n", &n, &d) && n+d) {
    clear();

    char c;
    for (int i = 0; i < n; i++) {
      scanf("%c", &c);
      numbers[i] = c - '0';
    }

    for (int i = 0; i < n; i++)
      numbersPosition[numbers[i]].push_back(i);

    int lo = 0;
    for (int leftDigits = n-d; leftDigits > 0; leftDigits--) {
      int rangeNumbers = n - lo;
      int qtDigitsPossible = rangeNumbers - (leftDigits - 1);

      int maxIndex, maxValue;
      for (int i = 9; i >= 0; i--) {
        int n = getNumberPosition(i, lo, lo+qtDigitsPossible-1);
        if (n != -1) {
          maxIndex = n;
          maxValue = i;
          break;
        }
      }

      ans.push_back(maxValue);
      lo = maxIndex+1;
    }

    for (int i = 0; i < ans.size(); i++)
      printf("%d", ans[i]);
    puts("");
  }
}
