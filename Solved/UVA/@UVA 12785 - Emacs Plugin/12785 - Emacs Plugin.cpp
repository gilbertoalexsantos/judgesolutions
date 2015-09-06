//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4650

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 5;

char t[MAX], reg[MAX], p[MAX];
int n, m, sreg;
int b[MAX];

void computeNext() {
  int i = 0, j = -1; b[0] = -1;
  while (i < m) {
    while (j >= 0 && p[i] != p[j]) j = b[j];
    i++; j++;
    b[i] = j;
  }
}

int kmp(int lo) {
  computeNext();
  int i = lo, j = 0;
  while (i < n) {
    while (j >= 0 && t[i] != p[j]) j = b[j];
    i++; j++;
    if (j == m)
      return i;
  }
  return -1;
}

bool solve() {
  int cnt = 0, lo = 0, sr = strlen(reg);
  for (int i = 0; i < sr; i++) {
    if (reg[i] == '*') {
      if (cnt == 0)
        continue;
      m = cnt;
      cnt = 0;
      lo = kmp(lo);
      if (lo == -1)
        return false;
      continue;
    }
    p[cnt++] = reg[i];
  }
  if (cnt != 0 && reg[sr-1] != '*') {
    m = cnt;
    return kmp(lo) != -1;
  }
  return true;
}

int main() {
  int T;
  while (scanf("%d", &T) != EOF) {
    scanf("%s", t);
    n = strlen(t);
    for (int i = 0; i < T; i++) {
      scanf("%s", reg);
      printf("%s\n", solve() ? "yes" : "no");
    }
  }
}
