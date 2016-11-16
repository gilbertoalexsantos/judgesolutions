//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/2346

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int MAX_N = 1e5 + 5;

int n, m, a, b;
vector<int> adj[MAX_N];
map<int, set<int> > dg;
int degree[MAX_N];
bool removed[MAX_N];
int removedVerts;

void init() {
  memset(removed, false, sizeof removed);
  removedVerts = 0;
}

int invert(int d) {
  return n - removedVerts - 1 - d;
}

void insertVertex(int u, int d) {
  if (dg.count(d)) {
    dg[d].insert(u);
  } else {
    set<int> s; s.insert(u);
    dg[d] = s;
  }
}

void removeVertex(int u) {
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (removed[v])
      continue;

    int oldD = degree[v], newD = --degree[v];

    if (dg.count(oldD)) {
      set<int> &s = dg[oldD];
      s.erase(v);
      if (s.empty())
        dg.erase(oldD);
    }

    insertVertex(v, newD);
  }

  int d = degree[u];
  if (dg.count(d)) {
    set<int> &s = dg[d];
    s.erase(u);
    if (s.empty())
      dg.erase(d);
  }

  removedVerts++;
  removed[u] = true;
}

bool satisfyA() {
  bool ok = true;

  auto it = dg.begin();
  while (it != dg.end() && it->first < a) {
    auto &s = it->second;

    vector<int> toRemove(s.size());
    copy(s.begin(), s.end(), toRemove.begin());
    for (int i = 0; i < (int)toRemove.size(); i++)
      removeVertex(toRemove[i]);

    it = dg.begin();

    ok = false;
  }

  return ok;
}

bool satisfyB() {
  bool ok = true;

  auto it = dg.rbegin();
  while (it != dg.rend() && invert(it->first) < b) {
    auto &s = it->second;

    vector<int> toRemove(s.size());
    copy(s.begin(), s.end(), toRemove.begin());
    for (int i = 0; i < (int)toRemove.size(); i++)
      removeVertex(toRemove[i]);

    it = dg.rbegin();

    ok = false;
  }

  return ok;
}

int main() {
  scanf("%d %d %d %d", &n, &m, &a, &b);

  init();

  for (int i = 0; i < m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    u--, v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++, degree[v]++;
  }

  for (int i = 0; i < n; i++)
    insertVertex(i, degree[i]);

  while (removedVerts < n && (!satisfyA() || !satisfyB()));

  printf("%d\n", n - removedVerts);
}
