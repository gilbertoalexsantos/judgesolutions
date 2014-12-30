//Author:   Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1559

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m[4][4];

bool can_right() {
  for(int c = 0; c < 3; c++) { 
    for(int l = 0; l < 4; l++) if(m[l][c]) {
      if(m[l][c] == m[l][c+1] || m[l][c+1] == 0)
        return true;
    }
  }
  return false;
}

bool can_left() {
  for(int c = 3; c > 0; c--) { 
    for(int l = 0; l < 4; l++) if(m[l][c]) {
      if(m[l][c] == m[l][c-1] || m[l][c-1] == 0)
        return true;
    }
  }
  return false;
}

bool can_down() {
  for(int l = 0; l < 4 - 1; l++) { 
    for(int c = 0; c < 4; c++) if(m[l][c]) {
      if(m[l][c] == m[l+1][c] || m[l+1][c] == 0)
        return true;
    }
  }
  return false;
}

bool can_up() {
  for(int l = 3; l > 0; l--) { 
    for(int c = 0; c < 4; c++) if(m[l][c]) {
      if(m[l][c] == m[l-1][c] || m[l-1][c] == 0)
        return true;
    }
  }
  return false;
}

const char *word[4] = {"DOWN","LEFT","RIGHT","UP"};

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
     scanf("%d",&m[i][j]);
    bool a, b, c, d;
    a = can_down(), b = can_left(), c = can_right(), d = can_up();
    bool ans[] = {a, b, c, d};
    int qt = a + b + c + d;
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
      if(m[i][j] == 2048)
        qt = 0;
    if(qt == 0)
      printf("NONE");
    else {
      int i;
      for(i = 0; i < 4; i++) if(ans[i]) {
        printf("%s",word[i]);
        break;
      }
      for(i = i+1; i < 4; i++) if(ans[i])
        printf(" %s",word[i]);
    }
    puts("");
  }
}
