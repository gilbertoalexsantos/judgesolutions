//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1029
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<int,int> ii;

ii memo[40];
int n;

ii dp(int v=n) {
  ii &ret = memo[v];
  if(ret.first != -1)
    return ret;

  ii a = dp(v-1);
  ii b = dp(v-2);

  ret = ii(a.first+b.first+1,a.second+b.second);
  return ret;
}

int main() {
  memset(memo,-1,sizeof memo); 
  memo[0] = ii(1,0), memo[1] = ii(1,1);
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d",&n);
    ii ans = dp();
    printf("fib(%d) = %d calls = %d\n",n,ans.first-1,ans.second);
  }
}
