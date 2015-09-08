//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3654

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int MAX_N = 1125;
const int MAX_K = 15;

vector<int> primes;
int n, k;
int memo[MAX_K][MAX_N];
bitset<MAX_N> isPrime;

void sieveOfEratosthenes() {
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;

  int upper = ceil(sqrt(MAX_N));
  for (int i = 2; i <= upper; i++) {
    if (!isPrime[i])
      continue;
    for (int j = i*i; j < MAX_N; j += i)
      isPrime[j] = false;
  }

  for (int i = 0; i < MAX_N; i++)
    if (isPrime[i])
      primes.push_back(i);
}


void dp_bottom_up() {
  n = MAX_N-1; k = MAX_K-1;
  memset(memo, 0, sizeof memo);
  for (int i = 0; i < primes.size(); i++) {
    int p = primes[i];
    for (int sum = n; sum >= p; sum--) {
      for (int j = 1; j <= k; j++) {
        if (j == 1)
          memo[j][sum] = p == sum;
        else
          memo[j][sum] += memo[j-1][sum-p];
      }
    }
  }
}

int main() {
  sieveOfEratosthenes();
  dp_bottom_up();
  while (scanf("%d %d", &n, &k) && n+k) {
    printf("%d\n", memo[k][n]);
  }
}
