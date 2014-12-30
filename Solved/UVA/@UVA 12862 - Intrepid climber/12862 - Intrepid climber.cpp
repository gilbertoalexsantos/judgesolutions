//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4727

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

#define fs first
#define sd second

typedef long long ll;
typedef pair<int, ll> ii;

const int MAX = 1e5 + 10;
const ll INF = ((unsigned long long)1) << 61;

int qt_vert, qt_friend;
bool is_friend[MAX];
vector<ii> adj[MAX], dfs_tree[MAX];

void clear() {
  for(int i = 0; i <= qt_vert; i++) {
    adj[i].clear();
    dfs_tree[i].clear();
    is_friend[i] = false;
  }
}

bool has_friend(int u) {
  bool ret = is_friend[u];
  for(int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i].fs;
    if(has_friend(v)) {
      dfs_tree[u].push_back(adj[u][i]);
      ret = true;
    }
  }
  return ret;
}

ii costs(int u) {
  int sum = 0;
  ll max_cost_path = 0;
  for(int i = 0; i < dfs_tree[u].size(); i++) {
    int v = dfs_tree[u][i].fs;
    ll w = dfs_tree[u][i].sd;
    ii cost = costs(v);
    sum += cost.fs + w;
    max_cost_path = max(max_cost_path, cost.sd + w);
  }
  return ii(sum,max_cost_path);
}

int main() {
  while(scanf("%d %d",&qt_vert, &qt_friend) != EOF) {
    clear();
    for(int i = 0; i < qt_vert-1; i++) {
      int u, v;
      ll w;
      scanf("%d %d %lld",&u,&v,&w);
      adj[u].push_back(ii(v,w));
    }
    for(int i = 0; i < qt_friend; i++) {
      int x; scanf("%d",&x);
      is_friend[x] = true;
    }
    has_friend(1);
    ii ans = costs(1);
    printf("%lld\n",ans.fs - ans.sd);
  }
}
