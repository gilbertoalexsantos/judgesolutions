//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1731

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAX_C = 105;

char w1[MAX_C], w2[MAX_C];
int subStr[MAX_C][MAX_C];
int s1, s2;

vector<char> calcSubStr() {
  vector<char> ret;
  
  memset(subStr, 0, sizeof subStr);
  for (int i = 1; i <= s1; i++) {
    for (int j = 1; j <= s2; j++) {
      if (w1[i-1] == w2[j-1]) {
        subStr[i][j] = subStr[i-1][j-1] + 1;
      } else {
        subStr[i][j] = max(subStr[i][j-1], subStr[i-1][j]);
      }
    }
  }

  int row = s1, col = s2;
  while (row && col) {
    int p1 = row-1, p2 = col-1;
    if (w1[p1] == w2[p2]) {
      ret.push_back(w1[p1]);
      row--; col--;
    } else {
      if (subStr[row][col-1] > subStr[row-1][col]) {
        col--;
      } else {
        row--;
      }
    }
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  while (scanf("%s %s", w1, w2) != EOF) {
    s1 = strlen(w1), s2 = strlen(w2);
    if (s1 < s2) {
      swap(s1, s2);
      swap(w1, w2);
    }
    
    vector<char> sub = calcSubStr();

    int ptW1 = 0, ptW2 = 0, ptSub = 0;
    while (ptSub < sub.size()) {
      while (w1[ptW1] != sub[ptSub]) printf("%c", w1[ptW1++]);
      while (w2[ptW2] != sub[ptSub]) printf("%c", w2[ptW2++]);
      printf("%c", sub[ptSub]);
      ptW1++, ptW2++, ptSub++;
    }
    while (ptW1 < s1) printf("%c", w1[ptW1++]);
    while (ptW2 < s2) printf("%c", w2[ptW2++]);
    puts("");
  }
}
