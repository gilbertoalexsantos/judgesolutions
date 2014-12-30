//Author: Gilberto A. dos Santos
//website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3238

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 200001;

char word[30];
int seg[MAX * 4];
int n;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
inline int mid(int a, int b) { return (a + b) >> 1; }

int update(int i, int j, int value=-1, int p=1, int l=0, int r=n-1) {
  if(i > r || j < l)
    return 0;
  if(i <= l && j >= r)
    return seg[p] = (value == -1 ? seg[p] : value);
  int p1 = update(i,j,value,left(p),l,mid(l,r));
  int p2 = update(i,j,value,right(p),mid(l,r)+1,r);
  seg[p] = seg[left(p)] + seg[right(p)];
  return p1 + p2;
}

int main() {
  bool first = true;
  int cases = 1;
  while(scanf("%d",&n) && n) {
    first ? first = false : puts("");
    memset(seg,0,sizeof seg);
    for(int i = 0; i < n; i++) {
      int v; scanf("%d",&v);
      update(i,i,v);
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
        printf("%d\n",update(a-1,b-1));
      else
        update(a-1,a-1,b);
    }
  }
}

