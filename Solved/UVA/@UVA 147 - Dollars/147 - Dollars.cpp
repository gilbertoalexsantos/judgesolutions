//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=83

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

typedef long long ll;

const int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

int size = 11;
int n;
ll memo[300005];

int main() {
  ll a, b;
  while(scanf("%lld.%lld",&a,&b) && a+b) {
    n = (a * 100) + b;

    memset(memo,0,sizeof memo);
    memo[0] = 1;
    for(int i = 0; i < size; i++)
      for(int j = coin[i]; j <= n; j++)
        memo[j] = memo[j - coin[i]] + memo[j]; 

    printf("%3lld.%02lld",a,b);
    printf("%17lld\n",memo[n]);
  }
}
