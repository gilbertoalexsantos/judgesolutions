//Author:   Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_LEN = 1005;

int memo[MAX_LEN][MAX_LEN];
char w1[MAX_LEN], w2[MAX_LEN];

int main() {
  while(fgets(w1,MAX_LEN,stdin) && w1[0] != '\n') {
    memset(memo,0,sizeof memo);
    fgets(w2,MAX_LEN,stdin);
    int s1 = strlen(w1), s2 = strlen(w2);
    for(int i = 1; i < s1; i++) {
      for(int j = 1; j < s2; j++) {
        if(w1[i-1] == w2[j-1])
          memo[i][j] = memo[i-1][j-1] + 1;
        else
          memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
      }
    }
    printf("%d\n",memo[s1-1][s2-1]);
  }
}
