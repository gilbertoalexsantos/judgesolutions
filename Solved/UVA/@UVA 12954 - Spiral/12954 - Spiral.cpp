//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4833

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> ii;

ull n, b;

ull pa(ull layer) { return (layer * (1 + layer)) / 2; }

ull qtBlocksLayer(ull layer) {
  ull diff = n - (layer * 2);
  return diff*4 - 4;
}

ull totalBlocksUntilLayer(ull layer) {
  ull blockLayer = qtBlocksLayer(layer);
  if (blockLayer == 0)
    return pa(layer) * 8 + 1;
  return blockLayer + (blockLayer * layer) + pa(layer) * 8;
}

int getLayer() {
  int lo = 0, hi = n / 2;
  while (lo <= hi) {
    int m = (lo + hi) / 2;
    ull t = totalBlocksUntilLayer(m);
    if (t >= b)
      hi = m-1;
    else
      lo = m+1;
  }
  return hi+1;
}

ii solve() {
  int layer = getLayer();
  ull ql = qtBlocksLayer(layer);
  ull t = totalBlocksUntilLayer(layer);
  
  int pos = ql - (t - b);

  int x, y;
  ull qtFirstBound = (ql+4)/4;

  if (pos <= qtFirstBound)
    return ii(layer, layer+pos-1+(pos==0));
  pos -= qtFirstBound;
  if (pos <= qtFirstBound-1)
    return ii(layer+pos, layer+qtFirstBound-1);
  pos -= (qtFirstBound-1);
  if (pos <= qtFirstBound-1)
    return ii(layer+qtFirstBound-1, layer+((qtFirstBound-1)-pos));
  pos -= (qtFirstBound-1);
  return ii(layer+((qtFirstBound-2)-pos)+1, layer);
}

int main() {
  while (scanf("%llu %llu", &n, &b) != EOF) {
    ii ans = solve();
    printf("%d %d\n", ans.first+1, ans.second+1);
  }
}
