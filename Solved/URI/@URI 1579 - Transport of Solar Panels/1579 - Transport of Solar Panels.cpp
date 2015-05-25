//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1579

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 105;

int q, t, f;
int panels[MAX];

bool can(int wanted) {
  int left = 0, sum = 0;
  for (int i = 0; i < t; i++) {
    while (left < q && sum + panels[left] <= wanted) {
      sum += panels[left++];
    }
    sum = 0;
  }
  return left == q;
}

int main() {
  int qt; scanf("%d",&qt);
  while (qt--) {
    int sum = 0;
    scanf("%d %d %d",&q,&t,&f);
    for(int i = 0; i < q; i++) {
      scanf("%d", &panels[i]);
      sum += panels[i];
    }
    int left = 0, right = sum, mid;
    while (left+1 <= right) {
      mid = (left + right) / 2;
      if (can(mid)) {
        right = mid;
      } else {
        left = mid+1;
      }
    }
    printf("%d $%d\n", right, right * t * f);
  }

}
