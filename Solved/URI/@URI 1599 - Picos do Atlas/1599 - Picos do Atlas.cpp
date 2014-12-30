//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1599

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 1005;
const int dr[] = {0,1,1, 1, 0,-1,-1,-1};
const int dc[] = {1,1,0,-1,-1,-1, 0,1};

int n, m;
int matrix[MAX][MAX];

inline bool can(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

int main() {
  while(scanf("%d %d",&n,&m) != EOF) {
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < m; j++)
      scanf("%d",&matrix[i][j]);
    vector<ii> ans;
    for(int x = 0; x < n; x++) {
      for(int y = 0; y < m; y++) {
        bool win = true;
        for(int i = 0; i < 8; i++) {
          int xf = x + dr[i], yf = y + dc[i];
          if(!can(xf,yf))
            continue;
          if(matrix[x][y] <= matrix[xf][yf]) {
            win = false;
            break;
          }
        }
        if(win)
          ans.push_back(ii(x,y));
      }
    }
    if(ans.empty()) {
      printf("%d\n",-1);
    } else {
      for(int i = 0; i < ans.size(); i++) {
        printf("%d %d\n",ans[i].first+1,ans[i].second+1);
      }
    }
    puts("");
  }
}
