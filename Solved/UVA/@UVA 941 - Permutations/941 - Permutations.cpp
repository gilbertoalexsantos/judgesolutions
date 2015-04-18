//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=882

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll fact[21];

void init() {
  fact[0] = 0, fact[1] = 1;
  for (int i = 2; i < 21; i++) {
    fact[i] = fact[i-1] * i;
  }
}

int main() {
  init();
  
  int samples; scanf("%d", &samples);
  char word[21];
  ll n;
  while (samples--) {
    scanf("%s %lld", word, &n);
    
    int size = strlen(word);
    sort(word, word + size);

    int positionOfChange = 0;
    int changeTime = 1;
    while (n) {
      ll f = fact[size - positionOfChange - 1];

      if (n >= f) {
        n -= f;
        swap(word[positionOfChange], word[changeTime]);
        changeTime++;
      } else {
        positionOfChange++;
        changeTime = positionOfChange + 1;
      }
    }

    printf("%s\n",word);
    
  }
}
