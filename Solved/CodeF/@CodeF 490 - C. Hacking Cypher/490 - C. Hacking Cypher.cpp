//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/490/problem/C

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000005;

int dp1[MAX], dp2[MAX];

int main() {
  char line[MAX];
  scanf("%s",line);
  int n1, n2; scanf("%d %d",&n1, &n2);
  int s = strlen(line);

  dp1[0] = 1; dp2[0] = 1;
  for(int i = 1; i < MAX; i++) {
    dp1[i] = (dp1[i-1] * 10) % n1;
    dp2[i] = (dp2[i-1] * 10) % n2;
  }

  bool a1[s], a2[s];
  memset(a1,false,sizeof a1);
  memset(a2,false,sizeof a2);

  // BACK
  int flag = 0;
  for(int i = s-1, p = 0; i >= 1; i--, p++) {
    int n = line[i] - '0';
    if(n == 0) continue;
    flag = (flag + (dp2[p] * n)) % n2;
    a2[i] = flag == 0;
  }

  // FRONT
  flag = 0;
  for(int i = 0; i < s-1; i++) {
    int n = line[i] - '0';
    flag = ((flag * 10) + n) % n1;
    a1[i] = flag == 0;
  }

  char *w1, *w2;
  for(int i = 0; i < s-1; i++) {
    if(a1[i] && a2[i+1]) {
      char c = line[i+1];
      line[i+1] = '\0';
      printf("YES\n");
      printf("%s\n",line);
      line[i+1] = c;
      printf("%s\n",line+i+1);
      return 0;
    }
  }

  printf("NO\n");
}
