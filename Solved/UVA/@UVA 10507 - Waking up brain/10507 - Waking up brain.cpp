//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1448

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<int> graph[30];
vector<int> verts;
char word[30];
int active[30];
int taken[30];

void clear() {
  verts.clear();
  for (int i = 0; i < 30; i++) {
    graph[i].clear();
    active[i] = 0;
    taken[i] = 0;
  }
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    clear();

    int e; scanf("%d %s", &e, word);
    for (int i = 0; i < strlen(word); i++) {
      char c = word[i] - 'A';
      active[c] = 1;
      taken[c] = 1;
    }

    for (int i = 0; i < e; i++) {
      scanf("%s", word);
      char u = word[0] - 'A', v = word[1] - 'A';
      taken[u] = taken[v] = 1;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < 30; i++) {
      if (taken[i]) {
        verts.push_back(i);
      }
    }

    int someoneWoke = 0, qtYears = 0;
    do {
      someoneWoke = 0;
      vector<int> toActive;
      for (int i = 0; i < verts.size(); i++) {
        int u = verts[i];
        if (active[u]) {
          continue;
        }

        int qt = 0;
        for (int j = 0; j < graph[u].size(); j++) {
          int v = graph[u][j];
          qt += active[v];
        }
        if (qt >= 3) {
          toActive.push_back(u);
        }
      }
      someoneWoke = !toActive.empty();
      qtYears += !toActive.empty();
      for (int j = 0; j < toActive.size(); j++) {
        active[toActive[j]] = 1;
      }
    } while (someoneWoke);

    int qtWoke = 0;
    for (int i = 0; i < verts.size(); i++) {
      qtWoke += active[verts[i]];
    }

    if (qtWoke != n) {
      printf("THIS BRAIN NEVER WAKES UP\n");
    } else {
      printf("WAKE UP IN, %d, YEARS\n", qtYears);
    }
  }
}
