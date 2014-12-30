//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1615

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 1e6;

int n, m;

int votes[MAX];

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&n,&m);
    for(int i = 0; i <= n; i++)
      votes[i] = 0;
    for(int i = 0; i < m; i++) {
      int x; scanf("%d",&x);
      votes[x]++;
    }
    int votes_max = m / 2;
    int winner = -1, qt = 0;
    for(int i = 0; i <= n; i++)
      if(votes[i] > votes_max)
        winner = i, qt++;
    printf("%d\n",qt > 1 ? -1 : winner);
  }
}
