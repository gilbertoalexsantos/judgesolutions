//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1602

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;

const int MAX = 2000005;

int _sieve_size;
bitset<10000010> bs;
vi primes;
int divs[MAX];
int summed_hps[MAX];

void sieve() {
  _sieve_size = MAX;
  bs.set();
  bs[0] = bs[1] = 0;
  for (int i = 2; i <= 1500; i++) {
    if (bs[i]) {
      for (int j = i+i; j <= _sieve_size; j += i) {
        bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

int numDiv(int n) {
  int PF_idx = 0,
      PF = primes[PF_idx],
      ret = 1;
  while (PF * PF <= n) {
    int power = 0;
    while (n % PF == 0) { 
      n /= PF; 
      power++; 
    }
    ret *= (power + 1);
    if (power > 0) {
      return ret * divs[n];
    }
    PF = primes[++PF_idx];
  }
  if (n != 1)
    ret *= 2;
  return ret;
}

int n;

int main() {
  sieve();

  divs[0] = 0;
  divs[1] = 1;
  divs[2] = 2;
  for(int i = 3; i < MAX; i++) {
    divs[i] = numDiv(i);
  }

  summed_hps[2] = 1;
  for (int i = 3; i < MAX; i++) {
    summed_hps[i] = summed_hps[i - 1];
    if (bs[divs[i]])
      summed_hps[i]++;
  }

  while(scanf("%d",&n) != EOF) {
    printf("%d\n", summed_hps[n]);
  }
}
