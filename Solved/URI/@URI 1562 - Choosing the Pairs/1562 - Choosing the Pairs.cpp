//Author:   Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1562

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10005;

int qt_vert;
int adj[MAX], parent[MAX], degree[MAX];

bool check() {
  for(int i = 1; i <= qt_vert; i++) if(!parent[i])
    return false;
  return true;
}

inline void cparent(int v) { parent[v] = adj[v], parent[adj[v]] = v; }

void bfs(int v) {
  queue<int> qe;
  qe.push(v);
  while(!qe.empty()) {
    int v = qe.front(); qe.pop();
    if(parent[v] || parent[adj[v]])
      continue;
    cparent(v);
    qe.push(adj[adj[v]]);
  }
}

bool solve() {
  memset(parent,0,sizeof parent);

  queue<int> qe;
  for(int i = 1; i <= qt_vert; i++) if(degree[i] == 0)
    qe.push(i);

  // Need to satisfy vertices with 0 degree first
  while(!qe.empty()) {
    int v = qe.front(); qe.pop();
    if(parent[adj[v]])
      return false;
    cparent(v);
    degree[adj[adj[v]]]--;
    if(degree[adj[adj[v]]] == 0)
      qe.push(adj[adj[v]]);
  }

  // Only rest the cycles
  for(int i = 1; i <= qt_vert; i++) if(!parent[i])
    bfs(i);
  
  return check();
}

int main() {
  while(scanf("%d",&qt_vert) != EOF) {
    memset(degree,0,sizeof degree);
    for(int i = 1; i <= qt_vert; i++) {
      int x; scanf("%d",&x);
      adj[i] = x;
      degree[x]++;
    }
    if(solve()) {
      printf("%d",parent[1]);
      for(int i = 2; i <= qt_vert; i++)
        printf(" %d",parent[i]);
      puts("");
    } else
      puts("IMPOSSIBLE");
  }
}
