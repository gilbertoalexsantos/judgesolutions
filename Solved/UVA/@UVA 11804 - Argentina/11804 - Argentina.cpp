//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2904

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct TYPE {
  int atq, def;
  string name;

  TYPE(int atq, int def, string name) : atq(atq), def(def), name(name) {}
  TYPE() {}

  bool operator< (TYPE a) {
    if(atq != a.atq)
      return atq > a.atq;
    if(def != a.def)
      return def < a.def;
    return name < a.name;
  }
};

inline bool cmp1(TYPE a, TYPE b) { return a < b; }
inline bool cmp2(TYPE a, TYPE b) { return a.name < b.name; }

int main() {
  ios_base::sync_with_stdio(false);
  int T, cases = 1; cin >> T;
  while(T--) {
    vector<TYPE> v(10);
    for(int i = 0; i < 10; i++) {
      TYPE t;
      cin >> t.name >> t.atq >> t.def;
      v[i] = t;
    }
    sort(v.begin(),v.end(),cmp1);
    sort(v.begin(),v.begin()+5,cmp2);
    sort(v.begin()+5,v.end(),cmp2);
    cout << "Case " << cases++ << ":\n";
    cout << "(" << v[0].name;
    for(int i = 1; i < 5; i++)
      cout << ", " << v[i].name;
    cout << ")\n(" << v[5].name;
    for(int i = 6; i < 10; i++)
      cout << ", " << v[i].name;
    cout << ")\n";
  }
}
