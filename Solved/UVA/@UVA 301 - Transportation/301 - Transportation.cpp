#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_CITIES = 10;
const int MAX_BLOCKS = 25;

struct Block {
  int u, v, w;

  int cost() {
    return (v - u) * w;
  }
};

int n, b, e;
vector<Block> blocks[MAX_CITIES];
bool carrying[MAX_BLOCKS][MAX_BLOCKS];

void clear() {
  for (int i = 0; i < MAX_CITIES; i++)
    blocks[i].clear();
  memset(carrying, false, sizeof carrying);
}

int getTotalCarryingPassengers(int u) {
  int passengers = 0;
  for (int i = 0; i <= b; i++) {
    for (int j = 0; j < blocks[i].size(); j++) {
      if (carrying[i][j] && blocks[i][j].v > u) {
        passengers += blocks[i][j].w;
      }
    }
  }
  return passengers;
}

int unload() {
  int ret = 0;
  for (int i = 0; i <= b; i++) {
    for (int j = 0; j < blocks[i].size(); j++) {
      if (carrying[i][j]) {
        ret += blocks[i][j].cost();
      }
    }
  }
  return ret;
}

int bt(int u, int p=0) {
  if (u == b) {
    return unload();
  }

  int sum = -1e9;

  for (int i = p; i < blocks[u].size(); i++) {
    if (!carrying[u][i] &&
        getTotalCarryingPassengers(u) + blocks[u][i].w <= n) {

      carrying[u][i] = true;
      sum = max(sum, bt(u, i+1));
      carrying[u][i] = false;
    }
  }

  sum = max(sum, bt(u+1, 0));

  return sum;
}

int main() {
  while (scanf("%d %d %d", &n, &b, &e) && n+b+e) {
    clear();
    for (int i = 0; i < e; i++) {
      Block t; scanf("%d %d %d", &t.u, &t.v, &t.w);
      blocks[t.u].push_back(t);
    }
    printf("%d\n", bt(0));
  }
}
