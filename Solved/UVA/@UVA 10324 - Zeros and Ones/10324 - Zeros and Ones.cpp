//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1265

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 1000005;

int sum[MAX];
char word[MAX];
int size;

void solve(int left, int right) {
  bool ok;
  int range = right - left + 1;
  if(word[right] == '1') {
    ok = (sum[right+1] - sum[left]) == range;
  }
  else
    ok = (sum[right+1] - sum[left]) == 0;
  printf("%s\n",ok ? "Yes" : "No");
}

int main() {
  int cases = 1;
  while(fgets(word,MAX,stdin) && word[0] != '\n') {
    size = strlen(word)-1;
    sum[0] = 0;
    for(int i = 1; i <= size; i++)
      sum[i] = sum[i-1] + (word[i-1] == '1');
    printf("Case %d:\n",cases++);
    int Q; scanf("%d",&Q);
    while(Q--) {
      int x, y; scanf("%d %d\n",&x,&y);
      solve(min(x,y),max(x,y));
    }
  }
}
