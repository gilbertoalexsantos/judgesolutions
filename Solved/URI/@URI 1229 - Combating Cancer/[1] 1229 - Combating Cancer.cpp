//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1229
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_VERT = 10005;

int qt_vert;
vector<int> t1[MAX_VERT], t2[MAX_VERT];
vector<int> l1[MAX_VERT], l2[MAX_VERT];

bool cmp(const vector<int> &a, const vector<int> &b) {
  if(a.size() != b.size())
    return a.size() < b.size();
  int left = 0, right = a.size(), mid;
  for(int i = 0; i < a.size(); i++)
    if(a[i] != b[i])
        return a[i] < b[i];
  return false;
}

void clear() {
  for(int i = 0; i < qt_vert; i++) {
    t1[i].clear(), t2[i].clear();
    l1[i].clear(), l2[i].clear();
  }
}

void getLevelChild(vector<int> level[], vector<int> tree[]) {
  for(int i = 0; i < qt_vert; i++) {
    for(int j = 0; j < tree[i].size(); j++) {
      int v = tree[i][j];
      level[i].push_back(tree[v].size());
    }
    sort(level[i].begin(),level[i].end());
  }
}

void pr(vector<int> t[]) {
  for(int i = 0; i < qt_vert; i++) {
    printf("[%d]",i+1);
    for(int j = 0; j < t[i].size(); j++)
      printf(" => %d",t[i][j]);
    puts("");
  }
}

bool solve() {
  getLevelChild(l1,t1);
  getLevelChild(l2,t2);

  sort(l1,l1+qt_vert,cmp);
  sort(l2,l2+qt_vert,cmp);

  for(int i = 0; i < qt_vert; i++) if(l1[i] != l2[i])
    return false;

  return true;
}

int main() {
  while(scanf("%d",&qt_vert) != EOF) {
    clear();
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
    bool ans = solve();
    printf("%c\n",ans ? 'S' : 'N');
  }
}
