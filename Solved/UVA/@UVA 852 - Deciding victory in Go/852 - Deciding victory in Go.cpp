//Author: Gilberto A. do Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=793

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const char EMPTY = '.', WHITE = 'O', BLACK = 'X';
const int dr[4] = {0, 1,  0, -1};
const int dc[4] = {1, 0, -1,  0};

bool visited[10][10];
char board[10][10];
int black, white;

inline bool can(int x, int y) { return x >= 0 && y >= 0 && x < 9 && y < 9; }

void floodfill(int x, int y) {
  queue<ii> qe; qe.push(ii(x,y));
  visited[x][y] = true;
  int qt = 1;
  int s_black = 0, s_white = 0;
  while(!qe.empty()) {
    int ux = qe.front().first, uy = qe.front().second; qe.pop();
    for(int i = 0; i < 4; i++) {
      int vx = ux+dr[i], vy = uy+dc[i];
      if(!can(vx,vy) || visited[vx][vy])
        continue;
      char c = board[vx][vy];
      if(c == EMPTY) {
        qt++;
        visited[vx][vy] = true;
        qe.push(ii(vx,vy));
      } else
        (c == WHITE) ? s_white++ : s_black++;
    }
  }
  if(s_black != 0 || s_white != 0) {
    if(s_black > 0 && s_white == 0)
      black += qt;
    else if(s_black == 0 && s_white > 0)
      white += qt;
  }
}

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    for(int i = 0; i < 9; i++)
      scanf("%s",board[i]);
    black = 0, white = 0;
    memset(visited,false,sizeof visited);
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        char c = board[i][j];
        if(c == WHITE)
          white++;
        else if(c == BLACK)
          black++;
        else if(!visited[i][j])
          floodfill(i,j);
      }
    }
    printf("Black %d White %d\n",black,white);
  }
}
