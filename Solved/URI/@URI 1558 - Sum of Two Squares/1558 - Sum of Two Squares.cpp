//Author:   Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1558

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

int numbers[101];

inline void init() { for(int i = 0; i < 101; i++) numbers[i] = i*i; }

bool solve() {
  int limit = sqrt(n);
  for(int a = 0; a <= limit; a++) {
    int m = pow(a,2);
    int M = n - m;
    if(binary_search(numbers+a,numbers+limit+1,M))
      return true;
  }
  return false;
}

int main() {
  init();
  while(scanf("%d",&n) != EOF) {
    bool ans = solve();
    printf("%s\n",ans ? "YES" : "NO");
  }
}
