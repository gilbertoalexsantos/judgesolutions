//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1611

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> andars;

int main() {
  int ts;
  scanf("%d", &ts);
  for (int t = 0; t < ts; t++) {
    int n, cap, p;
    scanf("%d %d %d", &n, &cap, &p);
    andars.clear();
    for (int i = 0; i < p; i++) {
      int a;
      scanf("%d", &a);
      andars.push_back(a);
    }
    sort(andars.begin(), andars.end());
    reverse(andars.begin(), andars.end());
    int cost = 0;
    for (int i = 0; i < p; i += cap) {
      int max_andar = 0;
      for (int j = i; j < min(p, i + cap); j++) {
        max_andar = max(max_andar, andars[i]);
      }
      cost += 2 * max_andar;
    }
    printf("%d\n", cost);
  }

  return 0;
}
