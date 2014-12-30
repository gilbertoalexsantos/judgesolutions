//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/ACODE/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef unsigned long long ull;

const int MAX_DIGIT = 5005;

ull memo[MAX_DIGIT];
char word[MAX_DIGIT];
int size;

int main() {
  while(scanf("%s",word) && word[0] != '0') {
    size = strlen(word);
    memo[0] = memo[1] = 1;
    for(int i = 2; i <= size; i++) {
      memo[i] = 0;
      char t[2];
      t[0] = word[i-2]; t[1] = word[i-1];
      int n = atoi(t);
      if(n <= 26 && n >= 10)
        memo[i] += memo[i-2];
      if(word[i-1] != '0')
        memo[i] += memo[i-1];
    }
    printf("%llu\n",memo[size]);
  }
}
