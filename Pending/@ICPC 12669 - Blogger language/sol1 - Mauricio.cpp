#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

const int NODES = 32*262144;
int esq[NODES], dir[NODES], segtree[NODES];
int nnodes;

void create(const int* v, int root, int l, int r) {
  if(l == r) { segtree[root] = v[l]; return; }

  esq[root] = nnodes++;
  dir[root] = nnodes++;

  int mid = (l+r)/2;
  create(v, esq[root], l, mid);
  create(v, dir[root], mid+1, r);

  segtree[root] = segtree[esq[root]] + segtree[dir[root]];
}

int query(int root, int l, int r, int a, int b) {
  if(b < l || a > r) return 0;
  if(l >= a && r <= b) return segtree[root];

  int mid = (l+r)/2;
  return query(esq[root], l, mid, a, b) + query(dir[root], mid+1, r, a, b);
}

void swap2(int root1, int root2, int l, int r, int a, int b) {
  if(b < l || a > r) return;
  int mid = (l+r)/2;

  if(l >= a && mid <= b) swap(esq[root1], esq[root2]);
  else swap2(esq[root1], esq[root2], l, mid, a, b);

  if(mid+1 >= a && r <= b) swap(dir[root1], dir[root2]);
  else swap2(dir[root1], dir[root2], mid+1, r, a, b);

  segtree[root1] = segtree[esq[root1]] + segtree[dir[root1]];
  segtree[root2] = segtree[esq[root2]] + segtree[dir[root2]];
}

char post[100001];
char text[6];
int inp[32][100001];

int main() {
  int n;

  while(scanf("%d %s", &n, text) != EOF) {
    scanf("%s", post);
    int lenp = strlen(post);
    int lent = strlen(text);
    int root[1<<lent];

    {
      nnodes = 0;

      memset(inp, 0, sizeof inp);
      for(int i = 0; i <= lenp - lent; i++) {
        int mask = 0;
        bool ok = true;

        for(int j = 0; j < lent; j++) {
          if(tolower(post[i+j]) != tolower(text[j]))
            ok = false;
          if(post[i+j] != text[j])
            mask |= 1<<j;
        }

        if(ok)
          inp[mask][i] = 1;
      }

      for(int i = 0; i < (1<<lent); i++) {
        root[i] = nnodes++;
        create(inp[i], root[i], 0, lenp - lent + 1);
      }
    }

    int l, r;
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &l, &r);
      l--; r--;

      int maxi = -1;
      for(int i = 0; i < (1<<lent); i++)
        if(query(root[i], 0, lenp - lent + 1, l, r - lent + 1))
          maxi = max(maxi, i == 0 ? 0 : __builtin_popcount(i));

      printf("%d\n", maxi);

      for(int i = 0; i < (1<<lent); i++) {
        break;
        if(i < (((1<<lent)-1)^i))
          swap2(root[i], root[((1<<lent)-1)^i], 0, lenp - lent + 1, l, r - lent + 1);

        for(int j = lent-1; j >= 1; j--) {
          int mask = (1<<j)-1, start = r - j + 1;
          if(i < (mask^i))
            swap2(root[i], root[mask^i], 0, lenp - lent + 1, start, start);

          mask <<= lent-j; start = l-(lent-j);
          if(start < 0) continue;
          if(i < (mask^i))
            swap2(root[i], root[mask^i], 0, lenp - lent + 1, start, start);
        }
      }
    }
  }
}
