//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3978

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 100005;

int qt_vert, cnt_comp;
int adj[MAX];
bool is_cycle[MAX], visited[MAX];
int cod_comp[MAX];
int pos_cycle[MAX], first_cycle[MAX];
int cycle_start[MAX], cycle_size[MAX];
int dis_cycle[MAX], beg_cycle[MAX];
int tail[MAX];
vector<int> edges[MAX];

void dfs(int u, int begin_cycle, int cnt_tail) {
  beg_cycle[u] = begin_cycle;
  for(int i = 0; i < edges[u].size(); i++) {
    int v = edges[u][i];
    if(pos_cycle[v] == -1) {
      tail[v] = cnt_tail;
      dis_cycle[v] = dis_cycle[u] + 1;
      dfs(v,u,cnt_tail);
    }
  }
}

void connect_cycles() {
  for(int i = 1; i <= qt_vert; i++) {
    if(pos_cycle[i] != -1) continue;

    int cycle_start = i;
    while(!visited[cycle_start]) {
      visited[cycle_start] = true;
      cycle_start = adj[cycle_start];
    }

    int cur = cycle_start, cnt = 0;
    do {
      pos_cycle[cur] = cnt++;
      cod_comp[cur] = cnt_comp;
      is_cycle[cur] = true;
      cur = adj[cur];
    } while(cur != cycle_start);

    int cnt_tail = 0;
    do {
      dfs(cur,cur,cnt_tail++);
      cur = adj[cur];
    } while(cur != cycle_start);
  
    cycle_size[cnt_comp] = cnt;
    first_cycle[cnt_comp++] = cycle_start;
  }
}

int solve(int u, int v) {
  if(cod_comp[u] != cod_comp[v])
    return -1;
  int comp = cod_comp[u];

  int cu = beg_cycle[u], cv = beg_cycle[v];
  int size = cycle_size[comp];
  int pu = pos_cycle[cu], pv = pos_cycle[cv];

  int d1, d2;
  if(pu > pv) {
    d1 = pu - pv;
    d2 = size - pu + pv;
  } else {
    d1 = pv - pu;
    d2 = size - pv + pu;
  }

  int du = dis_cycle[u], dv = dis_cycle[v];
  int dx = du + dv;
  return min(dx+d1,dx+d2);
}

void clear() {
  cnt_comp = 0;
  for(int i = 0; i <= qt_vert; i++) {
    beg_cycle[i] = -1;
    pos_cycle[i] = i;
    is_cycle[i] = false;
    visited[i] = false;
    dis_cycle[i] = 0;
    cycle_start[i] = -1;
    tail[i] = -1;
    edges[i].clear();
  }
}

int main() {
  while(scanf("%d",&qt_vert) != EOF) {
    clear();
    for(int i = 1; i <= qt_vert; i++) {
      scanf("%d",&adj[i]);
      edges[adj[i]].push_back(i);
    }
    int Q; scanf("%d",&Q);
    while(Q--) {
      int u, v; scanf("%d %d",&u,&v);
      printf("%d\n",solve(u,v));
    }
  }
}
