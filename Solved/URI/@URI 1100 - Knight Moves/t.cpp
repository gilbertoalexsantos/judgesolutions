//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1100

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int dr[] = {-2, -2, 2, 2, -1, 1, 1, -1};
const int dc[] = { 1, -1,-1, 1,  2, 2,-2, -2};

ii getCoord(string w) {
  int x = 7 - ((w[1] - '0') - 1);
  int y = w[0] - 'a';
  return ii(x,y);
}

bool can(ii u) { return u.first >= 0 && u.second >= 0 && u.first < 8 && u.second < 8; }

int bfs(ii a, ii b) {
  int dist[8][8];
  memset(dist,-1,sizeof dist);
  queue<ii> qe;
  qe.push(a);
  dist[a.first][a.second] = 0;
  while(!qe.empty()) {
    ii u = qe.front(); qe.pop();
    if(u == b)
      return dist[u.first][u.second];
    for(int i = 0; i < 8; i++) {
      ii v(u.first+dr[i],u.second+dc[i]);
      if(can(v) && dist[v.first][v.second] == -1)
        dist[v.first][v.second] = dist[u.first][u.second] + 1, qe.push(v);
    }
  }
  return 0;
}

string a, b;
ii source, sink;

int main() {
  printf("int m[8][8][8][8];\n");
  for(int xi = 0; xi < 8; xi++) {
    for(int yi = 0; yi < 8; yi++) {
      for(int xf = 0; xf < 8; xf++) {
        for(int yf = 0; yf < 8; yf++) {
          ii a(xi,yi), b(xf,yf);
          printf("m[%d][%d][%d][%d] = %d;\n",xi,yi,xf,yf,bfs(a,b));
        }
      }
    }
  }
}
