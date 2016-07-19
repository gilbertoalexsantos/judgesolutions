//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1710

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct plane {
  int a, b, c, d;
};

struct planet {
  int x, y, z;
};

int m, n;
vector<plane> planes;
vector<planet> planets;

bool cp(plane &pl, planet &pt) {
  int p = pl.a * pt.x + pl.b * pt.y + pl.c * pt.z, d = pl.d;
  return p < d ? false : true;
}

int main() {
  while (scanf("%d %d", &m, &n) != EOF) {
    planes.clear();
    planets.clear();

    vector<vector<bool> > regions;
    for (int i = 0; i < n; i++) {
      vector<bool> region;
      region.assign(m, false);
      regions.push_back(region);
    }

    for (int i = 0; i < m; i++) {
      plane t; scanf("%d %d %d %d", &t.a, &t.b, &t.c, &t.d);
      planes.push_back(t);
    }

    for (int i = 0; i < n; i++) {
      planet t; scanf("%d %d %d", &t.x, &t.y, &t.z);
      planets.push_back(t);
    }

    for (int i = 0; i < n; i++) {
      planet &pt = planets[i];
      for (int j = 0; j < m; j++) {
        plane &pl = planes[j];
        regions[i][j] = cp(pl, pt);
      }
    }

    int ans = -1;
    map<vector<bool>, int> regionsCondensed;
    for (int i = 0; i < n; i++) {
      if (regionsCondensed.find(regions[i]) != regionsCondensed.end()) {
        regionsCondensed[regions[i]]++;
        ans = max(ans, regionsCondensed[regions[i]]);
      } else {
        ans = max(ans, 1);
        regionsCondensed[regions[i]] = 1;
      }
    }

    printf("%d\n", ans);
  }
}
