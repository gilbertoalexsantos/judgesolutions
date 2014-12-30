//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3688

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int INF = 1e9;

int n, m;
int dist[30][30], path[30][30], qt[30][30];

inline int gv(char l) { return l - 'A'; }
inline char gc(int l) { return l + 'A'; }

void floyd() {
  for(int k = 0; k < 30; k++)
    for(int i = 0; i < 30; i++)
      for(int j = 0; j < 30; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          path[i][j] = path[k][j];
          qt[i][j] = qt[k][j] + 1;
        } else if(dist[i][j] == dist[i][k] + dist[k][j] && 
            qt[i][j] > qt[k][j]+1) {
          qt[i][j] = qt[k][j]+1;
          path[i][j] = path[k][j];
        }
      }
}

void pr(char a, char b) {
  if(a != b) {
    pr(a,gc(path[gv(a)][gv(b)]));
    printf(" %c",b);
  } else
    printf("%c",b);
}

int main() {
  for(int i = 0; i < 30; i++)
    for(int j = 0; j < 30; j++) {
      dist[i][j] = i == j ? 0 : INF;
      path[i][j] = i;
      qt[i][j] = i == j ? INF : 0;
    }

  scanf("%d %d\n",&n,&m); 
  for(int i = 0; i < m; i++) {
    int w;
    char x, y;
    scanf("%c %c %d\n",&x,&y,&w);
    dist[gv(x)][gv(y)] = dist[gv(y)][gv(x)] = w;
  }
  floyd();
  int T; scanf("%d\n",&T);
  while(T--) {
    char x, y;
    scanf("%c %c\n",&x,&y);
    pr(x,y);
    puts("");
  }
}
