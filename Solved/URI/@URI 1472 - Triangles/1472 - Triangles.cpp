//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1472

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 2 * (1e5 + 5);

int n;
vector<int> arr(MAX), sums(MAX);

int main() {
  while (scanf("%d", &n) != EOF) {
    int side = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      side += arr[i];
    }
    if (side % 3 != 0) {
      printf("0\n");
      continue;
    }
    side /= 3;

    sums[0] = 1;
    for (int i = 1; i <= n; i++) {
      sums[i] = sums[i-1] + arr[i - 1];
    }
    for (int i = n+1, j = 0; j < n; j++, i++) {
      sums[i] = sums[i-1] + arr[j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int v1 = sums[i], v2 = v1 + side, v3 = v2 + side;
      bool l1 = binary_search(sums.begin()+i, sums.begin()+i+n, v2);
      bool l2 = binary_search(sums.begin()+i, sums.begin()+i+n, v3);
      ans += l1 & l2;
    }
    printf("%d\n", ans / 3);
  }
}
