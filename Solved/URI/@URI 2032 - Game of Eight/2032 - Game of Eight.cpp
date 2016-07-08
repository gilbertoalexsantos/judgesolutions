//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/2032

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, int> li;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, 1, -1};


int grid[3][3];
map<ll, li> dist;
ll sink;

inline bool inBorder(int i, int j) {
  return i >= 0 && i < 3 && j >= 0 && j < 3;
}

void swap(int m[3][3], int i, int j, int ni, int nj) {
  int tmp = m[i][j];
  m[i][j] = m[ni][nj];
  m[ni][nj] = tmp;
}

int getPosFromMask(ll mask, int number, bool isLine) {
  ll qtShift = 6 * number;
  int offset = isLine ? 0 : 3;
  for (int i = offset; i < 3+offset; i++) {
    ll b = 1LL << (qtShift + i);
    if (b & mask)
      return i - offset;
  }
  return -1;
}

void getMatrixFromMask(ll mask, int m[3][3]) {
  for (int i = 0; i < 9; i++) {
    int l = getPosFromMask(mask, i, true);
    int c = getPosFromMask(mask, i, false);
    m[l][c] = i;
  }
}

ll getMaskFromMatrix(int m[3][3]) {
  ll mask = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ll qtShift = m[i][j] * 6;
      ll lmask = 1LL << (qtShift + i);
      ll cmask = 1LL << (qtShift + 3 + j);
      mask |= lmask | cmask;
    }
  }
  return mask;
}


int bfs() {
  queue<ll> qe;

  ll at = getMaskFromMatrix(grid);
  dist[at] = li(-1, 0);
  qe.push(at);

  while (!qe.empty()) {
    ll u = qe.front(); qe.pop();

    int du = dist[u].second;

    if (u == sink)
      return du;

    int r = getPosFromMask(u, 0, true);
    int c = getPosFromMask(u, 0, false);
    int m[3][3]; getMatrixFromMask(u, m);
    int m2[3][3];

    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i], nc = c + dc[i];
      if (!inBorder(nr, nc))
        continue;

      getMatrixFromMask(u, m2);
      swap(m2, r, c, nr, nc);
      ll v = getMaskFromMatrix(m2);

      if (dist.find(v) == dist.end()) {
        dist[v] = li(u, du + 1);
        qe.push(v);
      }

    }

  }

  return -1;
}

void prMatrix(int m[3][3]) {
  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d", m[i][j]);
    }
    puts("");
  }
}

void prMask(ll mask) {
  int m[3][3]; getMatrixFromMask(mask, m);
  prMatrix(m);
}

void prSolution() {

  vector<ll> verts;

  ll u = sink;
  while (u != -1) {
    verts.push_back(u);
    u = dist[u].first;
  }

  for (int i = verts.size()-2; i >= 0; i--) {
    prMask(verts[i]);
    if (i != 0)
      puts("");
  }

}

int main() {
  int m[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };
  sink = getMaskFromMatrix(m);
  char gr[3][3];
  bool first = false;
  while (scanf("%c%c%c\n%c%c%c\n%c%c%c\n",
               &gr[0][0], &gr[0][1], &gr[0][2],
               &gr[1][0], &gr[1][1], &gr[1][2],
               &gr[2][0], &gr[2][1], &gr[2][2]) != EOF) {
    grid[0][0] = gr[0][0] - '0';
    grid[0][1] = gr[0][1] - '0';
    grid[0][2] = gr[0][2] - '0';
    grid[1][0] = gr[1][0] - '0';
    grid[1][1] = gr[1][1] - '0';
    grid[1][2] = gr[1][2] - '0';
    grid[2][0] = gr[2][0] - '0';
    grid[2][1] = gr[2][1] - '0';
    grid[2][2] = gr[2][2] - '0';
    dist.clear();

    int dist = bfs();

    if (dist == -1) {
      printf("Problema sem solucao\n");
    } else {
      printf("Quantidade minima de passos = %d\n", dist);
      prSolution();
    }
  }
}
