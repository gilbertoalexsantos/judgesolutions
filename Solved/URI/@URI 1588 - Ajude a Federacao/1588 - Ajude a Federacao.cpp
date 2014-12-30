//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1588

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct TYPE {
  string name;
  int id, p, w, g;
  TYPE() {}
  TYPE(string name, int id, int p, int w, int g) : name(name), id(id), p(p), w(w), g(g) {}
  bool operator<(const TYPE &v) const  {
    if(p != v.p)
      return p > v.p;
    else if(w != v.w)
      return w > v.w;
    else if(g != v.g)
      return g > v.g;
    else
      return id < v.id;
  }
};

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    int n, m;
    scanf("%d %d",&n,&m); 
    vector<TYPE> v; v.assign(n,TYPE());
    map<string, int> MAP;
    for(int i = 0; i < n; i++) {
      string w; cin >> w;
      v[i] = TYPE(w,i,0,0,0);
      MAP[w] = i;
    }
    for(int i = 0; i < m; i++) {
      int x, y;
      string a, b;
      cin >> x >> a >> y >> b;
      int p1 = MAP[a], p2 = MAP[b];
      if(x > y) {
        v[p1].p += 3, v[p1].w += 1, v[p1].g += x;
        v[p2].g += y;
      } else if(x < y) {
        v[p2].p += 3, v[p2].w += 1, v[p2].g += y;
        v[p1].g += x;
      } else {
        v[p1].p += 1, v[p1].g += x;
        v[p2].p += 1, v[p2].g += y;
      }
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++)
      cout << v[i].name << endl;
  }
}
