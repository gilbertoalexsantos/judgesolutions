//Author:	Gilberto A. dos Santos
//Website:	http://www.urionlinejudge.com.br/judge/en/problems/view/1275

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pint;

int n, m;
int grid[7][7];

vector<pint> row[7];
vector<pint> col[7];

void clear() {
  for(int i = 0; i < 7; i++) row[i].clear(), col[i].clear();
}

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    int b;
    scanf("%d", &b);

    memset(grid,-1,sizeof grid);

    for(int i = 0; i < b; i++) {
      int r, c, k;
      scanf("%d %d %d", &r, &c, &k);
      grid[r-1][c-1] = k;
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        printf("%d ",grid[i][j]);
      }
      printf("\n");
    }

    for(int i = 0; i < n; i++) {
      int left = 0, right;
      for(int j = 0; j < m; j++) {
        if(grid[i][j] == -1) continue;
        if(left == j) {
          left++;
          continue;
        }
        row[i].push_back(pint(left,j-1));
        left = j;
      }
      if(grid[i][m-1] == -1) {
        row[i].push_back(pint(left,m-1));
      }
    }

    for(int i = 0; i < n; i++) {
      printf("[%d] =>",i);
      for(int j = 0; j < row[i].size(); j++) {
        printf(" (%d,%d)",row[i][j].first,row[i][j].second);
      }
      printf("\n");
    }
    clear();
  }
}
