//Author: Gilberto A. dos Santos
//Website:  http://br.spoj.com/problems/POPULAR/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 100;

int n;
int votes[MAX];

int main() {
  while(scanf("%d",&n) && n) {
    memset(votes, 0, sizeof votes);
    int winner = -1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int x; scanf("%d",&x);
        votes[j] += x;
        winner = max(winner,votes[j]);
      }
    }
    printf("%d\n",winner);
  }
}
