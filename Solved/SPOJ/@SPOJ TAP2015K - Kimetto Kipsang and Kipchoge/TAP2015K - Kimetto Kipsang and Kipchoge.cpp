//Author: Gilberto A. dos Santos
//Website: http://www.spoj.com/problems/TAP2015K/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;


const int MAX_NUMBER = 1e6;
const int MAX_TREES = 1e4 * 5;
const int INF = 1e9;

set<int> indexes[MAX_NUMBER+10];
int trees[MAX_TREES + 10];
int backPointer[MAX_TREES + 10];
int st[(MAX_TREES+10) * 4];
int n, r;

inline int gleft(int p) { return p * 2; }
inline int gright(int p) { return p * 2 + 1; }
inline int gmid(int i, int j) { return (i + j) / 2; }

void clear() {
  for (int i = 0; i <= MAX_NUMBER; i++)
    indexes[i].clear();
  memset(st, -1, sizeof st);
}

void construct(int p, int l, int r) {
  if (l > r)
    return;

  if (l == r) {
    st[p] = backPointer[l];
    return;
  }

  construct(gleft(p), l, gmid(l, r));
  construct(gright(p), gmid(l, r) + 1, r);

  st[p] = max(st[gleft(p)], st[gright(p)]);
}

int query(int p, int l, int r, int i, int j, int v = -2) {
  if (i > r || j < l)
    return -INF;

  if (l >= i && r <= j) {
    if (v != -2)
      st[p] = v;
    return st[p];
  }

  int left = query(gleft(p), l, gmid(l, r), i, j, v);
  int right = query(gright(p), gmid(l, r) + 1, r, i, j, v);

  st[p] = max(st[gleft(p)], st[gright(p)]);
  return max(left, right);
}

int lb(int right, int number) {
  set<int>::iterator it = indexes[number].lower_bound(right);
  return it == indexes[number].end() ? -1 : *it;
}

void constructBackPointers() {
  int backPointersHelper[MAX_NUMBER+10];
  memset(backPointersHelper, -1, sizeof backPointersHelper);
  for (int i = 0; i < n; i++) {
    int t = trees[i];
    if (backPointersHelper[t] == -1) {
      backPointersHelper[t] = i;
      backPointer[i] = -1;
    } else {
      backPointer[i] = backPointersHelper[t];
      backPointersHelper[t] = i;
    }
  }
}

void constructSt() {
  constructBackPointers();
  construct(1, 0, n-1);
}

void pr() {
  puts("BACK");
  for (int i = 0; i < n; i++)
    printf("%d ", backPointer[i]);
  puts("");

  puts("ST");
  for (int i = 0; i < n; i++)
    printf("%d ", query(1, 0, n-1, i, i));
  puts("");
}

int qr(int p) {
  int q = query(1, 0, n-1, 0, p);
  return p - q;
}

void upd(int p, int v) {
  if (v == trees[p])
    return;

  // Update pointers for actual number
  int actualN = trees[p];
  indexes[actualN].erase(p);
  int nextActualI = lb(p, actualN);
  if (nextActualI != -1) {
    backPointer[nextActualI] = backPointer[p];
    query(1, 0, n-1, nextActualI, nextActualI, backPointer[nextActualI]);
  }

  // Update pointers for the next number
  int nextVI = lb(p, v);
  if (nextVI != -1) {
    backPointer[p] = backPointer[nextVI];
    backPointer[nextVI] = p;

    query(1, 0, n-1, nextVI, nextVI, backPointer[nextVI]);
    query(1, 0, n-1, p, p, backPointer[p]);
  } else {
    // We still can have a number 'v' to the left of p
    if (!indexes[v].empty()) {
      backPointer[p] = *indexes[v].rbegin();
    } else {
      backPointer[p] = -1;
    }

    query(1, 0, n-1, p, p, backPointer[p]);
  }

  indexes[v].insert(p);
  trees[p] = v;
}

int main() {
  while (scanf("%d %d", &n, &r) != EOF && n+r) {
    clear();

    for (int i = 0; i < n; i++) {
      scanf("%d", &trees[i]);
      indexes[trees[i]].insert(i);
    }

    constructSt();

    for (int i = 0; i < r; i++) {
      char c; int p;
      scanf("\n%c %d", &c, &p);
      p--;
      if (c == 'E')
        printf("%d\n", qr(p));
      else {
        int v; scanf("%d", &v);
        upd(p, v);
      }
    }
  }
}
