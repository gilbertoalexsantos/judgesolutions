//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1475
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX_HOLE = 1005;

int n, c, t1, t2;
int holes[MAX_HOLE];

int get_next(int v, int qt) {
  while(v < n && holes[v] <= qt)
    v++;
  return v;
}

int bfs() {
  int dist[MAX_HOLE+1];
  memset(dist,-1,sizeof dist);
  priority_queue<int> qe;
  qe.push(0);
  dist[0] = 0;
  while(!qe.empty()) {
    int v = -qe.top();
    qe.pop();

    if(v == n)
      return dist[v];

    // T1
    int nv = get_next(v,holes[v] + t1);
    if(dist[nv] == -1)
      dist[nv] = dist[v] + t1, qe.push(-nv);
    else if(dist[nv] > dist[v] + t1)
      dist[nv] = dist[v] + t1;

    // T2
    nv = get_next(v,holes[v] + t2);
    if(dist[nv] == -1)
      dist[nv] = dist[v] + t2, qe.push(-nv);
    else if(dist[nv] > dist[v] + t2)
      dist[nv] = dist[v] + t2;
  }
  return dist[n];
}

int main() {
  while(scanf("%d %d %d %d",&n,&c,&t1,&t2) != EOF) {
    for(int i = 0; i < n; i++)
      scanf("%d",&holes[i]);
    int ans = bfs();
    printf("%d\n",ans);
  }
}
