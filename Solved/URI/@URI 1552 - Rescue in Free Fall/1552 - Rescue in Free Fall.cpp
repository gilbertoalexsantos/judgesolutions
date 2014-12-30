//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1552
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

const double EPS = 1e-9;
const double INF = 1e20;

struct NODE {
  int x, y;
  NODE(int x, int y) : x(x), y(y) {}
};

inline double calc_dist(NODE a, NODE b) { 
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); 
}
inline bool less_than(double a, double b) { return (a - b) < EPS; }

int qt_vert;
vector<NODE> vert;

double prim() {
  double dist[qt_vert];
  bool used[qt_vert];
  memset(used,false,sizeof used);
  for(int i = 0; i < qt_vert; i++)
    dist[i] = INF;
  dist[0] = 0;
  double ret = 0;
  for(int i = 0; i < qt_vert; i++) {
    double flag = INF;
    int ind = -1;
    for(int j = 0; j < qt_vert; j++) {
      if(!used[j] && less_than(dist[j],flag)) {
        flag = dist[j];
        ind = j;
      }
    }
    ret += flag;
    used[ind] = true;
    for(int j = 0; j < qt_vert; j++) {
      double d = calc_dist(vert[j],vert[ind]);
      if(!used[j] && less_than(d,dist[j]))
        dist[j] = d;
    }
  }
  return ret;
}

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    vert.clear();
    scanf("%d",&qt_vert);
    for(int i = 0; i < qt_vert; i++) {
      int x, y; scanf("%d %d",&x,&y);
      vert.push_back(NODE(x,y));
    }
    double ans = prim();
    printf("%.2lf\n",ans/100.0);
  }
}
