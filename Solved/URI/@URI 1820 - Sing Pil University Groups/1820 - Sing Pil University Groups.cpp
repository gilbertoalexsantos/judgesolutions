//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1820

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_M = 51;
const int MAX_N = 101;

vector<vector<int> > groups;
bool number[MAX_N];
vector<int> numbers;
set<vector<int> > already;
int m;

void init() {
  memset(number, false, sizeof number);
  groups.clear();
  numbers.clear();
  already.clear();
}

bool has(vector<int> &v, int n) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == n) {
      return true;
    }
  }
  return false;
}

bool has(vector<vector<int> > &v, vector<int> &n) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == n) {
      return true;
    }
  }
  return false;
}

bool has(vector<vector<int> > &v1, vector<vector<int> > &v2) {
  for (int i = 0; i < v2.size(); i++) {
    if (!has(v1, v2[i])) {
      return false;
    }
  }
  return true;
}

int main() {
  int cases = 1;
  while (scanf("%d", &m) && m) {
    // if (cases > 1) {
      // puts("");
    // }
    init();
    for (int i = 0; i < m; i++) {
      int a, b, c; scanf("%d %d %d", &a, &b, &c);
      number[a] = number[b] = number[c] = true;
      vector<int> temp(3);
      temp[0] = a; temp[1] = b; temp[2] = c;
      sort(temp.begin(), temp.end());
      groups.push_back(temp);
    }
    sort(groups.begin(), groups.end());
    
    for (int i = 0; i < MAX_N; i++) {
      if (number[i]) {
        numbers.push_back(i);
      }
    }

    vector<vector<int> > ans;
    for (int i = 0; i < m; i++) {
      if (i > 0 && groups[i] == groups[i-1]) {
        continue;
      }
      for (int j = 0; j < numbers.size(); j++) {
        vector<int> perms(3);
        perms[0] = groups[i][0];
        perms[1] = groups[i][1];
        perms[2] = groups[i][2];
        if (!has(groups[i], numbers[j])) {
          perms.push_back(numbers[j]);
          sort(perms.begin(), perms.end());
          if (already.count(perms) > 0) {
            continue;
          }
          already.insert(perms);
          
          vector<vector<int> > tperms;
          for (int a = 0; a+2 < 4; a++) {
            for (int b = a+1; b+1 < 4; b++) {
              for (int c = b+1; c < 4; c++) {
                vector<int> t(3);
                t[0] = perms[a];
                t[1] = perms[b];
                t[2] = perms[c];
                tperms.push_back(t);
              }
            }
          }
          
          if (has(groups, tperms)) {
            ans.push_back(perms);
          }
        }
      }
    }
    
    printf("Instancia %d\n", cases++);
    if (ans.empty()) {
      printf("ok\n");
    }
    for (int i = 0; i < ans.size(); i++) {
      printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }
    puts("");
  }
}
