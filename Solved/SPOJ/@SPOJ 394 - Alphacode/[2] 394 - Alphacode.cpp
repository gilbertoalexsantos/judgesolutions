//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/ACODE/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAX_DIGIT = 5005;

ll memo[MAX_DIGIT];
char word[MAX_DIGIT];
int size;

ll dp(int pos=0) {
  if(pos == size)
    return 1;

  ll &ret = memo[pos];
  if(ret != -1)
    return ret;

  ll p1 = 0, p2 = 0;

  // Trying to get two numbers
  if(pos < size - 1) {
    char t[3]; t[0] = word[pos], t[1] = word[pos + 1];
    int n = atoi(t);
    if(n >= 10 && n <= 26)
      p1 = dp(pos + 2);
  }
  
  // Continuing with one number
  if(word[pos] != '0')
    p2 = dp(pos + 1);

  return ret = p1 + p2;
}

int main() {
  while(scanf("%s",word) && word[0] != '0') {
    size = strlen(word);
    memset(memo,-1,sizeof memo);
    ll ans = dp();
    cout << ans << endl;
  }
}
