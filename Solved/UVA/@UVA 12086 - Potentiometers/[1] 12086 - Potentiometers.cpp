//Author: Gilberto A. dos Santos
//website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3238

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 200001;

char word[30];
int bit[MAX], arr[MAX];
int n;

inline int LSOne(int a) { return a & -a; }

void update(int pos, int value) {
  value -= arr[pos - 1];
  arr[pos - 1] += value;
  for(; pos <= n; pos += LSOne(pos))
    bit[pos] += value;
}

int range(int pos) {
  int sum = 0;
  for(; pos; pos -= LSOne(pos))
    sum += bit[pos];
  return sum;
}

inline int range(int left, int right) { return range(right) - range(left - 1); }

void clear(int qt) {
  for(int i = 0; i <= qt; i++)
    arr[i] = bit[i] = 0;
}

int main() {
  bool first = true;
  int cases = 1;
  while(scanf("%d",&n) && n) {
    first ? first = false : puts("");
    clear(n);
    for(int i = 0; i < n; i++) {
      int v; scanf("%d",&v);
      update(i+1,v);
    }
    printf("Case %d:\n",cases++);
    getchar();
    while(fgets(word,30,stdin) && word[0] != 'E') {
      char op = word[0];
      int a, b;
      char *f = strtok(word," ");
      f = strtok(NULL," "); a = atoi(f);
      f = strtok(NULL," "); b = atoi(f);
      if(op == 'M')
        printf("%d\n",range(a,b));
      else
        update(a,b);
    }
  }
}
