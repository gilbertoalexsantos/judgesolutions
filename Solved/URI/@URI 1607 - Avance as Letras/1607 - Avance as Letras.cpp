//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1607

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_LEN = 1e4 + 10;

int diff(char a, char b) {
  if (b >= a) return b - a;
  return ('z' - a) + (b - 'a' + 1);
}

int main() {
  int t;
  scanf("%d", &t);

  char a[MAX_LEN], b[MAX_LEN];
  for (int tt = 0; tt < t; tt++) {
    scanf("%s\n", a);
    scanf("%s\n", b);
    int total_diff = 0;
    for (int i = 0; i < strlen(a); i++) {
      total_diff += diff(a[i], b[i]);
    }
    printf("%d\n", total_diff);
  }
  return 0;
}
