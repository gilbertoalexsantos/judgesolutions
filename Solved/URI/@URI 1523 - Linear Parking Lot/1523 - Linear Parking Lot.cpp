//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1523

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

const int MAX = 1e4 + 5;

int enter[MAX], leave[MAX];
int n, k;

int car;
stack<int> s;

void init() {
  car = 0;
  while (!s.empty())
    s.pop();
}

bool fill() {
  if (s.empty()) {
    s.push(car++);
    return true;
  }

  if (leave[s.top()] <= enter[car]) {
    s.pop();
    s.push(car++);
    return true;
  }

  if (s.size() == k ||
      leave[s.top()] < leave[car])
    return false;

  s.push(car++);
  return true;
}

void clean() {
  if (s.size() <= 1)
    return;

  int f = s.top(); s.pop();
  if (leave[s.top()] < enter[f]) {
    s.pop();
    s.push(f);
    clean();
  }
  else
    s.push(f);
}

bool withdraw() {
  while (s.size() > 1) {
    int f = s.top(); s.pop();
    if (leave[f] > leave[s.top()])
      return false;
  }
  return true;
}

bool solve() {
  s.push(car++);
  while (car < n && fill())
    clean();
  return car == n && withdraw();
}

int main() {
  while (scanf("%d %d", &n, &k) && n+k) {
    init();
    for (int i = 0; i < n; i++)
      scanf("%d %d", &enter[i], &leave[i]);
    bool ans = solve();
    printf("%s\n", ans ? "Sim" : "Nao");
  }
}
