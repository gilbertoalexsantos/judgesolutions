//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/DFLOOR/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 16;
const int INF = 1e9;
const int dr[] = {0, 0, 1,  0, -1};
const int dc[] = {0, 1, 0, -1,  0}; 

int row, col;
int m[MAX][MAX];
int flag[MAX][MAX];
vector<ii> ans;

void dance(int x, int y) {
  if(x >= 0 && y >= 0 && x < row && y < col)
    flag[x][y] = !flag[x][y];
}

// Fall Out boys
void DanceDance(int x, int y) {
  ans.push_back(ii(y+1,x+1));
  for(int i = 0; i < 5; i++)
    dance(x+dr[i],y+dc[i]);
}

void GoDanceBoy() {
  for(int r = 0; r < row-1; r++)
    for(int c = 0; c < col; c++) if(!flag[r][c])
      DanceDance(r+1,c);
}

bool check() {
  for(int c = 0; c < col; c++)
    if(!flag[row-1][c]) {
      ans.clear();
      return false;
    }
  return true;
}

void copyFlag() {
  for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
      flag[i][j] = m[i][j];
}

void solve() {
  for(int i = 0; i < 1 << col; i++) {
    copyFlag();
    for(int j = 0; j < col; j++) {
      if(i & 1 << j)
        DanceDance(0,j);
    }
    GoDanceBoy();
    if(check())
      return;
  }
}

bool initialCheck() {
  bool ok = true;
  for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
      if(!m[i][j])
        ok = false;
  if(ok == true)
    printf("0\n");
  return ok;
}

int main() {
  while(scanf("%d %d\n",&col,&row) && row+col) {
    ans.clear();
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        char c; scanf("%c",&c);
        m[i][j] = (c == '1');
      }
      getchar();
    }
    if(initialCheck())
      continue;
    solve();
    if(ans.empty())
      printf("-1\n");
    else {
      printf("%lu\n",ans.size());
      for(int i = 0; i < ans.size(); i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
  }
}
