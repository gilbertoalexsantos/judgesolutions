//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1472

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 1e8 + 5;

int n;
bool arr[MAX];

int main() {
  while (scanf("%d", &n) != EOF) {
    memset(arr, false, sizeof arr);
    arr[0] = 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      sum += x;
      arr[sum] = 1;
    }

    if (sum % 3 != 0) {
      puts("0");
      continue;
    }
    
    int side = sum / 3, ans = 0;
    for (int i = 0; i < side; i++) {
      ans += arr[i] && arr[i+side] && arr[i+side+side];
    }

    printf("%d\n", ans);
    
  }
}
