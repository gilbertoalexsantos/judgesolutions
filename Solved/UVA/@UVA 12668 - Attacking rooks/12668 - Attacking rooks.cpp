//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=602&page=show_problem&problem=4406

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

struct type {
  int v, p, b, e;
  type(int v=-1, int p=-1, int b=-1, int e=-1) : v(v), p(p), b(b), e(e) {}
};

const int MAX = 105;
const int MAX_VERT = 30000;
const char EMPTY = '.', BLOCK = 'X';

int n;
char grid[MAX][MAX];
vector<type> row, col;
vector<int> graph[MAX_VERT];
vector<int> match, visited;
int cnt_row, cnt_col;

inline void up_col(int r, int &c, char t) { while(c != n && grid[r][c] == t) c++; }
inline void up_row(int &r, int c, char t) { while(r != n && grid[r][c] == t) r++; }

void initRow() {
  cnt_row = 0; row.clear();
  for(int r = 0; r < n; r++) {
    int c = 0;
    while(c != n) {
      if(grid[r][c] != BLOCK) {
        int b = c;
        type t(cnt_row++, r, b);
        up_col(r,c,EMPTY);
        int e = c;
        t.e = e;
        row.push_back(t);
        up_col(r,c,BLOCK);
      } else
        up_col(r,c,BLOCK);
    }
  }
}

void initCol() {
  cnt_col = 0; col.clear();
  for(int c = 0; c < n; c++) {
    int r = 0;
    while(r != n) {
      if(grid[r][c] != BLOCK) {
        int b = r;
        type t(cnt_col++, c, b);
        up_row(r,c,EMPTY);
        int e = r;
        t.e = e;
        col.push_back(t);
        up_row(r,c,BLOCK);
      } else
        up_row(r,c,BLOCK);
    }
  }
}

bool between(int v, int l, int r) { return v >= l && v < r; }
void pb(int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}

void createGraph() {
  initRow(); initCol();

  for(int i = 0; i < row.size()+col.size(); i++)
    graph[i].clear();

  for(int i = 0; i < row.size(); i++) {
    type r = row[i];
    for(int j = 0; j < col.size(); j++) {
      type c = col[j];
      if(between(r.p,c.b,c.e) && between(c.p,r.b,r.e))
        pb(r.v,c.v+n*n);
    }
  }
}

int augment_path(int u) {
  if(visited[u]) return 0;
  visited[u] = true;
  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if(match[v] == -1 || augment_path(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}

int MCBM() {
  int ret = 0;
  match.assign(MAX_VERT, -1);
  int qt_vert = row.size()+col.size();
  for(int i = 0; i < row.size(); i++) {
    visited.assign(MAX_VERT, false);
    ret += augment_path(row[i].v);
  }
  return ret;
}

int main() {
  while(scanf("%d",&n) != EOF) {
    for(int i = 0; i < n; i++)
      scanf("%s",grid[i]);
    createGraph();
    int ans = MCBM();
    printf("%d\n",ans);
  }
}
