//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1368

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<int> cube;
 
int n;

void rotate_vertical_face(cube &v) {
  cube r(6);
  r[0] = v[1]; r[1] = v[5];
  r[2] = v[2]; r[3] = v[0];
  r[4] = v[4]; r[5] = v[3];
  for (int i = 0; i < 6; i++) {
    v[i] = r[i];
  }
}

void rotate_vertical_side(cube &v) {
  cube r(6);
  r[0] = v[4]; r[1] = v[1];
  r[2] = v[0]; r[3] = v[3];
  r[4] = v[5]; r[5] = v[2];
  for (int i = 0; i < 6; i++) {
    v[i] = r[i];
  }    
}

void rotate_horizontal(cube &v) {
  cube r(6);
  r[0] = v[0]; r[1] = v[4];
  r[2] = v[1]; r[3] = v[2];
  r[4] = v[3]; r[5] = v[5];
  for (int i = 0; i < 6; i++) {
    v[i] = r[i];
  }
}

string transform(const cube &c) {
  string ret;
  for (int i = 0; i < 6; i++) {
    ret.push_back(char(c[i]));
  }
  return ret;
}

string representative(cube &c) {
  string ret = transform(c);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int z = 0; z < 4; z++) {
        string t = transform(c);
        if (t < ret) {
          ret = t;
        }
        rotate_vertical_side(c);
      }
      rotate_horizontal(c);
    }
    rotate_vertical_face(c);
  }
  return ret;
}

int main() {
  while (scanf("%d", &n) && n) {
    vector<string> represents;
    for (int i = 0; i < n; i++) {
      cube c(6);
      for (int j = 0; j < 6; j++) {
        scanf("%d", &c[j]);
      }
      represents.push_back(representative(c));
    }
    sort(represents.begin(), represents.end());
    represents.erase(unique(represents.begin(), represents.end()), represents.end());
    printf("%lu\n", represents.size());
  }
}
