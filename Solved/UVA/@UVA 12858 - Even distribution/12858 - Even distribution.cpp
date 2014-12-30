//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4723

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> ii;

const int MAX_GCD = 1e5 + 10;
const int MAX_VERT = 1e4 + 10;

int qt_vert, qt_edge;
int candie[MAX_VERT];
vector<int> adj[MAX_VERT];

inline int gcd (int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void clear() {
  for(int i = 0; i < qt_vert; i++) {
    adj[i].clear();
  }
}

int bfs() {
  queue<ii> qe;
  set<int> visited[MAX_VERT], total;
  for(int i = 0; i < qt_vert; i++) {
    visited[i].insert(candie[i]);
    total.insert(candie[i]);
    qe.push(ii(i,candie[i]));
  }
  while(!qe.empty()) {
    int u = qe.front().first, ug = qe.front().second; qe.pop();
    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i], ng = gcd(ug, candie[v]);
      if(visited[v].find(ng) == visited[v].end()) {
        visited[v].insert(ng);
        total.insert(ng);
        qe.push(ii(v,ng));
      }
    }
  }
  return total.size();
}

int main() {
  while(scanf("%d %d",&qt_vert,&qt_edge) != EOF) {
    clear();
    for(int i = 0; i < qt_vert; i++)
      scanf("%d",&candie[i]);
    for(int i = 0; i < qt_edge; i++) {
      int u, v; scanf("%d %d",&u, &v);
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    printf("%d\n",bfs());
  }
}
