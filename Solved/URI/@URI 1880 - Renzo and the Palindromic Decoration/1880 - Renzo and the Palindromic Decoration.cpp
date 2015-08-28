//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1880

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string cnv(int n, int base) {
  if (n == 0) {
    string t; t += '0';
    return t;
  }
  
  string ret;
  while (n >= base) {
    char c = (n % 10) + '0';
    ret += c;
    n /= 10;
  }

  if (n >= 10) {
    char c = 65 + (n - 10);
    ret += c;
  } else {
    ret += n + '0';
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

string convert(int n, int base) {
  string ret;
  while (n >= base) {
    int md = n % base;
    string t = cnv(md, base);
    ret += t;
    n /= base;
  }
  string t = cnv(n, base);
  ret += t;
  return ret;
}

bool palindrome(string &p) {
  int i = 0, j = p.size() - 1;
  while (i <= j) {
    if (p[i] != p[j]) {
      return false;
    }
    i++, j--;
  }
  return true;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    int n; scanf("%d", &n);
    vector<int> ans;
    for (int i = 2; i <= 16; i++) {
      string t = convert(n, i);
      if (palindrome(t)) {
        ans.push_back(i);
      }
    }
    if (ans.empty()) {
      printf("-1\n");
    } else {
      printf("%d", ans[0]);
      for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
      }
      puts("");
    }
  }
}
