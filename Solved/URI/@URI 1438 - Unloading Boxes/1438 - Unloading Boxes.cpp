https://www.urionlinejudge.com.br/judge/en/problems/view/1438

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1005;
const int TO_LEFT = -1, TO_RIGHT = +1;

int p, n;
int index_one, size_one;
int st[MAX];

int get(int pos, int wanted, int to) {
  if(pos < 0 || pos >= n || st[pos] <= wanted)
    return 0;
  return (st[pos] - wanted) + get(pos+to,wanted,to);
}

int main() {
  while(scanf("%d %d",&p,&n) && p+n) {
    memset(st,0,sizeof st);

    for(int i = 0; i < n; i++) {
      int qt; scanf("%d",&qt);
      for(int j = 0; j < qt; j++) {
        int x; scanf("%d\n",&x);
        if(x == 1) {
          index_one = i;
          size_one = j+1;
        }
      }
      st[i] = qt;
    }

    int ret = st[index_one] - size_one;
    int get_left = get(index_one + TO_LEFT,size_one-1,TO_LEFT);
    int get_right = get(index_one + TO_RIGHT,size_one-1,TO_RIGHT);
    ret = min(ret+get_left,ret+get_right);

    printf("%d\n",ret);
  }
}
