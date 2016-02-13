//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1378

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_N = 1005;

struct Point {
  ll x, y;
  Point() : x(0), y(0) {}
  Point(ll x, ll y) : x(x), y(y) {}
};

Point points[MAX_N];
vector<vector<ll> > dists(MAX_N);
int n;

inline ll dist(Point u, Point v) {
  return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}

void init() {
  for (int i = 0; i < n; i++)
    dists[i].clear();
}

ll augmentPosWhileInPosition(int pos, vector<ll> &v) {
  while (pos+1 < v.size() && v[pos] == v[pos+1])
    pos++;
  return pos+1;
}

ll solve() {
  ll ans = 0;
  
  for (int i = 0; i < n; i++) {
    sort(dists[i].begin(), dists[i].end());

    int pos = 0;
    while (pos+1 < n) {
      int npos = augmentPosWhileInPosition(pos, dists[i]);
      
      ll qt = npos - pos;
      ans += (qt * (qt-1)) / 2L;

      pos = npos;
    }
  }
  
  return ans;
}

int main() {
  while (scanf("%d", &n) && n) {
    init();
    
    for (int i = 0; i < n; i++)
      scanf("%lld %lld", &points[i].x, &points[i].y);
    
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        dists[i].push_back(dist(points[i], points[j]));
      }

    ll ans = solve();
    printf("%lld\n", ans);
  }
}
