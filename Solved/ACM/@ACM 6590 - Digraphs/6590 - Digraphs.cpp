//Author: Giberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=610&page=show_problem&problem=4601

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 26;
const int UNVISITED = -1, VISITED = 1, EXPLORED = 2;

bool graph[MAX][MAX];
int dfs_num[MAX], dfs_parent[MAX], dp[MAX];

void dfs(int u) {
  dfs_num[u] = EXPLORED;
  for(int v = 0; v < MAX; v++) {
    if(!graph[u][v]) continue;
    if(dfs_num[v] == EXPLORED) {
      dfs_parent[v] = u;
      throw v;
    }
    if(dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      dfs(v);
    }
    dp[u] = max(dp[u],1 + dp[v]);
  }
  dfs_num[u] = VISITED;
}

void clear() {
  memset(graph,true,sizeof graph);
  for(int i = 0; i < MAX; i++) {
    dfs_parent[i] = -1;
    dp[i] = 0;
    dfs_num[i] = UNVISITED;
  }
}

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    clear();
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++) {
      char w[3]; scanf("%s",w);
      graph[w[0]-'a'][w[1]-'a'] = false;
    }
    
    int cycle = -1;
    try {
      for(int i = 0; i < MAX; i++)
        dfs(i);
    } catch (int beg_cycle) {
      cycle = beg_cycle;
    }
    
    int path[100], path_len = 0;
    if(cycle != -1) {
      path_len = 39;
      for(int i = path_len-1; i >= 0; i--, cycle = dfs_parent[cycle])
        path[i] = cycle;
    } else {
      int u  = 0;
      for(int i = 0; i < MAX; i++)
        if(dp[i] > dp[u])
          u = i;
      while(dp[u] != 0) {
        path[path_len++] = u;
        for(int v = 0; v < MAX; v++) {
          if(graph[u][v] && dp[v] == dp[u]-1) {
            u = v;
            break;
          }
        }
      }
      path[path_len++] = u;
    }
    
    path_len = (path_len+1) / 2;
    for(int i = 0; i < path_len; i++) {
      for(int j = 0; j < path_len; j++)
        printf("%c",path[i+j]+'a');
      puts("");
    }
  }
}
