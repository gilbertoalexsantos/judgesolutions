//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1322

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int k, w, qtEdges;
set<int> visited;
map<int, vi> adj;
set<ii> has_edge;
stack<int> verts;
map<int, int> degree;

void init() {
  adj.clear();
  has_edge.clear();
  visited.clear();
  while (!verts.empty())
    verts.pop();
  qtEdges = 0;
  degree.clear();
}

bool isVisited(int u) { return visited.find(u) != visited.end(); }
void visitedSomeone(int u) { visited.insert(u); }

void push(int u, int v) {
  map<int, vi>::iterator it = adj.find(u);
  if (it == adj.end()) {
    vi edges;
    adj[u] = edges;
    push(u, v);
    return;
  }
  it->second.push_back(v);
}

void incDegree(int u) {
  map<int, int>::iterator it = degree.find(u);
  if (it == degree.end())
    degree[u] = 1;
  else
    it->second++;
}

void dfs(int u, int p=-1) {
  visitedSomeone(u);
  vi ed = adj[u];
  for (int i = 0; i < ed.size(); i++) {
    int v = ed[i];
    if (!isVisited(v)) {
      verts.push(v);
      dfs(v, u);
    } else if (v != p) {
      int cycle_begin = v, cycle_size = 1;
      while (verts.top() != cycle_begin) {
        cycle_size++;
        verts.pop();
      }
      throw cycle_size;
    }
  }
  verts.pop();
}

bool dfs() {
  for (map<int, int>::iterator it = degree.begin(); it != degree.end(); it++) {
    if (it->second > 2)
      return false;
  }
  if (adj.empty())
    return true;
  for (map<int, vi>::iterator it = adj.begin(); it != adj.end(); it++) {
    int u = it->first;
    if (isVisited(u))
      continue;
    try {
      verts.push(u);
      dfs(u);
    } catch (int e) {
      return e == k && qtEdges == k;
    }
  }
  return true;
}

int main() {
  while (scanf("%d %d", &k, &w) && k+w) {
    init();
    for (int i = 0; i < w; i++) {
      int u, v; scanf("%d %d", &u, &v);
      if (u > v)
        swap(u, v);
      if (has_edge.find(ii(u, v)) == has_edge.end()) {
        incDegree(u);
        incDegree(v);
        qtEdges++;
        push(u, v); push(v, u);
        has_edge.insert(ii(u, v));
      }
    }
    printf("%c\n", dfs() ? 'Y' : 'N');
  }
}
