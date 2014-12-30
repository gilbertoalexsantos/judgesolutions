//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/MDOSTAVA/

#include <stdio.h>
#include <stdlib.h>

struct point { int x, y; };

#define INF 1000000000
#define MAX_ROW 2005
#define MAX_COL 205
#define L 0
#define R 1

int row, col, LEFT, RIGHT;
int m[MAX_ROW][MAX_COL], sum[MAX_ROW][MAX_COL], memo[MAX_ROW][MAX_ROW][2][2];

int _min(int a, int b) { return a < b ? a : b; }

int distFirstRow(int rx, int ry) {
  int w = m[rx][LEFT];
  int d1 = INF, d2 = INF;
  if(rx+1 <= row)
    d1 = w + m[rx+1][RIGHT] + distFirstRow(rx+1,ry+1);
  d2 = sum[rx][RIGHT-1];
  return memo[rx][ry][L][R] = _min(d1,d2);
}

void distOtherRow() {
  int rx;
  for(rx = 2; rx <= row; rx++) {
    int d1 = m[rx][LEFT] + memo[rx-1][rx-1][L][R] + m[rx-1][RIGHT];
    int d2 = memo[rx][rx][L][R];
    memo[rx][rx][L][R] = _min(d1,d2);
  }
}

void getDistsRow() {
  int i;
  for(i = 1; i <= row; i++)
    memo[i][i][L][L] = memo[i][i][R][R] = 0;
  distFirstRow(1,1);
  distOtherRow();
  for(i = 1; i <= row; i++)
    memo[i][i][R][L] = memo[i][i][L][R] + m[i][RIGHT] - m[i][LEFT];
}

int dp(int rx, int ry, int ssource, int ssink, int came) {
  if(memo[rx][ry][ssource][ssink] != -1)
    return memo[rx][ry][ssource][ssink];
  int ret = INF;
  int w = m[rx][ssource == L ? 1 : col];
  //DOWN
  if(rx+1 <= row)
    ret = _min(ret,w + dp(rx+1,ry,ssource,ssink,-1));
  // RIGHT
  if(ssource == L && came != R)
    ret = _min(ret, memo[rx][rx][L][R] + dp(rx,ry,R,ssink,L));
  //LEFT
  if(ssource == R && came != L)
    ret = _min(ret, memo[rx][rx][R][L] + dp(rx,ry,L,ssink,R));
  return ret;
}

void getAllDists() {
  int i, j;
  for(i = row-1; i >= 1; i--) {
    for(j = i+1; j <= row; j++) {
      memo[i][j][L][L] = dp(i,j,L,L,-1);
      memo[i][j][R][R] = dp(i,j,R,R,-1);
      memo[i][j][L][R] = dp(i,j,L,R,-1);
      memo[i][j][R][L] = dp(i,j,R,L,-1);
      memo[j][i][L][L] = memo[i][j][L][L] - m[i][LEFT] + m[j][LEFT];
      memo[j][i][R][R] = memo[i][j][R][R] - m[i][RIGHT] + m[j][RIGHT];
      memo[j][i][L][R] = memo[i][j][R][L] - m[i][RIGHT] + m[j][LEFT];
      memo[j][i][R][L] = memo[i][j][L][R] - m[i][LEFT] + m[j][RIGHT];
    }
  }
}

int cost_came_right(struct point p) { return sum[p.x][RIGHT] - sum[p.x][p.y]; }
int cost_came_left(struct point p) { return sum[p.x][p.y-1]; }
int cost_go_left(struct point p) { return sum[p.x][p.y] - m[p.x][LEFT]; }
int cost_go_right(struct point p) { return sum[p.x][RIGHT-1] - sum[p.x][p.y-1]; }

void solve() {
  long long ret = 0;
  struct point a = {1,1};
  struct point b;
  int Q; scanf("%d",&Q);
  while(Q--) {
    scanf("%d %d",&b.x,&b.y);
    int left_left = cost_go_left(a) + memo[a.x][b.x][L][L] + cost_came_left(b);
    int left_right = cost_go_left(a) + memo[a.x][b.x][L][R] + cost_came_right(b);
    int right_left = cost_go_right(a) + memo[a.x][b.x][R][L] + cost_came_left(b);
    int right_right = cost_go_right(a) + memo[a.x][b.x][R][R] + cost_came_right(b);
    int r = _min(left_left,_min(left_right,_min(right_left,right_right)));
    if(a.x == b.x) {
      int d;
      if(b.y > a.y)
        d = sum[b.x][b.y-1] - sum[a.x][a.y-1];
      else
        d = sum[a.x][a.y] - sum[b.x][b.y];
      r = _min(r,d);
    }
    ret += r;
    a.x = b.x, a.y = b.y;
  }
  ret += m[b.x][b.y];
  printf("%lld\n",ret);
}

int main() {
  scanf("%d %d",&row,&col);
  LEFT = 1, RIGHT = col;
  int i, j;
  for(i = 1; i <= row; i++) {
    sum[i][0] = 0;
    for(j = 1; j <= col; j++) {
      scanf("%d",&m[i][j]);
      sum[i][j] = m[i][j] + sum[i][j-1];
    }
  }

  int a, b;
  for(i = 1; i <= row; i++)
    for(j = 1; j <= row; j++)
      for(a = 0; a < 2; a++)
        for(b = 0; b < 2; b++)
          memo[i][j][a][b] = -1;

  getDistsRow();
  getAllDists();
  solve();
  return 0;
}
