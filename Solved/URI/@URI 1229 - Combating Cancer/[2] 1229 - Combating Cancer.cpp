//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1229
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_VERT = 10005;

int qt_vert;
vvi tree, subtreeLabels, level;
vi parent;

inline bool cmp(int a, int b) { return subtreeLabels[a] < subtreeLabels[b]; }
inline bool equals(int a, int b) { return subtreeLabels[a] == subtreeLabels[b]; }

vi findCenter(int offset=0) {
  int cnt = qt_vert;
  vi a, deg(qt_vert);
  for(int i = 0; i < qt_vert; i++) {
    deg[i] = tree[i + offset].size();
    if(deg[i] <= 1) {
      a.push_back(i + offset);
      cnt--;
    }
  }
  while(cnt > 0) {
    vi na;
    for(int i = 0; i < a.size(); i++) {
      int u = a[i];
      for(int j = 0; j < tree[u].size(); j++) {
        int v = tree[u][j];
        if(--deg[v - offset] == 1) {
          na.push_back(v);
          cnt--;
        }
      }
    }
    a = na;
  }
  return a;
}

int dfs(int v, int p=-1, int dep=0) {
  level[dep].push_back(v);
  int h = 0;
  for(int i = 0; i < tree[v].size(); i++) {
    int nv = tree[v][i];
    if(nv == p)
      continue;
    parent[nv] = v;
    h = max(h,dfs(nv,v,dep+1));
  }
  return h + 1;
}

bool rootedTreeIsomorphism(int r1, int r2) {
  level.assign(qt_vert,vi());
  parent.assign(2 * qt_vert,-1);

  int h1 = dfs(r1);
  int h2 = dfs(r2);
  if(h1 != h2)
    return false;

  int h = h1 - 1;
  vi label(2 * qt_vert);
  subtreeLabels.assign(2 * qt_vert, vi());
  for(int i = h-1; i >= 0; i--) {
    int sum_a = 0, sum_b = 0;
    for(int j = 0; j < level[i+1].size(); j++) {
      int v = level[i+1][j];
      subtreeLabels[parent[v]].push_back(label[v]);
    }
    for(int j = 0; j < level[i].size(); j++) {
      int v = level[i][j];
      if(v < qt_vert)
        sum_a += subtreeLabels[v].size();
      else
        sum_b += subtreeLabels[v].size();
      sort(subtreeLabels[v].begin(),subtreeLabels[v].end());
    }

    if(sum_a != sum_b || level[i].size() % 2 != 0)
      return false;

    sort(level[i].begin(),level[i].end(),cmp);

    for(int j = 0, cnt = 0; j < level[i].size(); j++) {
      if(j && !equals(level[i][j],level[i][j-1]))
        cnt++;
      label[level[i][j]] = cnt;
    }
  }

  return equals(r1,r2);
}

bool treeIsomorphism() {
  vi c1 = findCenter();
  vi c2 = findCenter(qt_vert);
  if(c1.size() == c2.size()) {
    if(rootedTreeIsomorphism(c1[0],c2[0]))
      return true;
    else if(c1.size() > 1)
      return rootedTreeIsomorphism(c1[1],c2[0]);
  }
  return false;
}

int main() {
  while(scanf("%d",&qt_vert) != EOF) {
    vvi t1(qt_vert), t2(qt_vert);
    for(int i = 0; i < qt_vert-1; i++) {
      int x, y; scanf("%d %d",&x,&y);
      x--, y--;
      t1[x].push_back(y), t1[y].push_back(x);
    }
    for(int i = 0; i < qt_vert-1; i++) {
      int x, y; scanf("%d %d",&x,&y);
      x--, y--;
      t2[x].push_back(y), t2[y].push_back(x);
    }
    tree.assign(2 * qt_vert,vi());
    for(int i = 0; i < qt_vert; i++) {
      for(int j = 0; j < t1[i].size(); j++)
        tree[i].push_back(t1[i][j]);
      for(int j = 0; j < t2[i].size(); j++)
        tree[i + qt_vert].push_back(t2[i][j] + qt_vert);
    }
    bool ans = treeIsomorphism();
    printf("%c\n",ans ? 'S' : 'N');
  }
}
