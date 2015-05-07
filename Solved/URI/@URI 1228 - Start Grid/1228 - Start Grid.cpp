//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1228

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 25;

int n;
int startGrid[MAX], endGrid[MAX], arr[MAX];

int bubbleSort() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j+i+1 < n; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &startGrid[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &endGrid[i]);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (endGrid[j] == startGrid[i]) {
          arr[i] = j;
          break;
        }
      }
    }

    int ans = bubbleSort();

    printf("%d\n", ans);
  }
}
