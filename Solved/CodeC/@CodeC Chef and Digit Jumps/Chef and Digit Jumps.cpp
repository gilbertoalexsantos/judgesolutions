#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100005;

vector<int> numbers[10];
char word[MAX];
int size;

int bfs() {
  int dist[size];
  bool visited[10];
  memset(dist,-1,sizeof dist);
  memset(visited,false,sizeof visited);
  queue<int> qe;
  dist[0] = 0;
  qe.push(0);
  int sink = size-1;
  while(!qe.empty()) {
    int v = qe.front(), n = word[v]-'0'; qe.pop();

    if(v == sink)
      return dist[v];

    // Same number
    if(visited[n] == false) {
      visited[n] = true;
      for(int i = 0; i < numbers[n].size(); i++) {
        int nv = numbers[n][i];
        if(nv == v) 
          continue;
        if(dist[nv] == -1)
          dist[nv] = dist[v]+1, qe.push(nv);
      }
    }

    // Backward
    if(v != 0) {
      int nv = v-1;
      if(dist[nv] == -1)
        dist[nv] = dist[v]+1, qe.push(nv);
    }

    // Forward
    int nv = v+1;
    if(dist[nv] == -1)
      dist[nv] = dist[v]+1, qe.push(nv);
  }
  return dist[sink];
}

int main() {
  scanf("%s",word);
  size = strlen(word);
  for(int i = 0; i < size; i++) {
    int n = word[i] - '0';
    numbers[n].push_back(i);
  }
  int ans = bfs();
  printf("%d\n",ans);
}
