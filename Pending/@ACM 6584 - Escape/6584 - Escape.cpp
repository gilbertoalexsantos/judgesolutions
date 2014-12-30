//Author: Gilberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=610&page=show_problem&problem=4595

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

#define fr first
#define sn second

typedef pair<int,set<int> > iss;

const int MAX = (1e5 * 2) + 10;

int qt_verts, source=1, sink;
int magic[MAX];
vector<int> graph[MAX];

void clear() {
  for(int i = 0; i <= qt_verts; i++) {
    graph[i].clear();
  }
  graph[0].push_back(source);  
}


int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&qt_verts, &sink); clear();
    for(int i = 1; i <= qt_verts; i++)
      scanf("%d",&magic[i]);
    for(int i = 0; i < qt_verts-1; i++) {
      int u, v; scanf("%d %d",&u,&v);
      graph[u].push_back(v), graph[v].push_back(u);
    }
  }
}
