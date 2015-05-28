//Author: Gilberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=610&page=show_problem&problem=4595

/*
   I saw that solution in the website: http://cerc.tcs.uj.edu.pl/2013/data.html

   My code is almost entirely from the website solution... 
   But I fully understood the idea, inclusive the implementation. 
   I changed little pieces of code, because seems more legible to me in that way.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef multiset<pll> SP;
typedef multiset<pll>::iterator SPT;

const int MAX = (1e5 * 2) + 10;
const ll INF = 1LL << 60;

int qt_verts, source=1, sink;
ll magic[MAX];
vector<int> graph[MAX];

void clear() {
  for (int i = 0; i <= qt_verts; i++) {
    graph[i].clear();
  }
}

SP* merge(SP *a, SP *b) {
  for (SPT it = b->begin(); it != b->end(); it++) {
    a->insert(*it);
  }
  delete(b);
  return a;
}

void push(SP *a, pll u) {
  // Leaf
  if (a->empty()) {
    // There's no need to insert leafs with negatives values
    if (u.second > u.first) {
      a->insert(u);
    }
    return;
  }

  pll v = *(a->begin());
  ll x, y;
  if (u.second >= v.first && u.second - v.first + v.second >= u.second) {
    x = u.first;
    y = u.second - v.first + v.second;
    a->erase(a->begin());
  }
  else if (u.first >= u.second) {
    x = u.first - u.second + v.first;
    y = v.second;
    a->erase(a->begin());    
  } else {
    a->insert(u);
    return;
  }

  push(a, pll(x, y));
}

SP *dfs(int u=source, int p=-1) {
  SP *r = new SP;

  if (u == sink) {
    r->insert(pll(max(-magic[u], 0LL), INF));
    return r;
  }

  SP *s;
  for (int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == p) {
      continue;
    }
    
    s = dfs(v, u);
    
    if (r->size() >= s->size()) {
      r = merge(r, s);
    } else {
      r = merge(s, r);
    }
  }

  pll f(0, 0);
  if (magic[u] >= 0) {
    f.second = magic[u];
  } else {
    f.first = -magic[u];
  }

  push(r, f);
  return r;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &qt_verts, &sink);
    clear();
    for (int i = 1; i <= qt_verts; i++) {
      scanf("%lld", &magic[i]);
    }
    for (int i = 0; i+1 < qt_verts; i++) {
      int u, v; scanf("%d %d", &u, &v);
      graph[u].push_back(v), graph[v].push_back(u);
    }
    
    SP *ans = dfs();
    
    ll hp = 0;
    for (SPT it = ans->begin(); it != ans->end(); it++) {
      if (it->first > hp) {
        break;
      }
      hp += it->second - it->first;
    }

    if (hp - INF < 0) {
      printf("trapped\n");
    } else {
      printf("escaped\n");
    }

    delete(ans);
  }
}
