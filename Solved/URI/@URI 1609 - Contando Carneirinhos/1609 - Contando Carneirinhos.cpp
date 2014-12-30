//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1609

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cars;

int main() {
  int ts;
  scanf("%d", &ts);
  for (int t = 0; t < ts; t++) {
    int n;
    scanf("%d\n", &n);
    cars.clear();
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      cars.push_back(a);
    }
    sort(cars.begin(), cars.end());
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (cars[i] != cars[i - 1]) cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
