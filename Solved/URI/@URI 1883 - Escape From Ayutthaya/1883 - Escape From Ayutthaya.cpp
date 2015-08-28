//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/pt/problems/view/1883

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

const char FIRE = 'F', BARRIER = '#', END = 'E', PERSON = 'S';

int n, m;
char grid[1000][1000];
queue<ii> person, fire;
ii e;

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

void init() {
  while (!fire.empty())
    fire.pop();
  while (!person.empty())
    person.pop();
}

bool canMove(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != BARRIER;
}

void propagate_person() {
  int size = person.size();
  for (int i = 0; i < size; i++) {
    int x = person.front().first, y = person.front().second;
    person.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dr[i], ny = y + dc[i];
      if (!canMove(nx, ny) || grid[x][y] == FIRE)
        continue;
      if (grid[nx][ny] != FIRE && grid[nx][ny] != PERSON) {
        grid[nx][ny] = PERSON;
        person.push(ii(nx, ny));
      }
    }
  }
}

void propagate_fire() {
  int size = fire.size();
  for (int i = 0; i < size; i++) {
    int x = fire.front().first, y = fire.front().second;
    fire.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dr[i], ny = y + dc[i];
      if (!canMove(nx, ny))
        continue;
      if (grid[nx][ny] != FIRE) {
        grid[nx][ny] = FIRE;
        fire.push(ii(nx, ny));
      }
    }
  }
}

bool solve() {
  while (true) {
    propagate_person();
    propagate_fire();
    if (grid[e.first][e.second] == FIRE) {
      return false;
    } else if (grid[e.first][e.second] == PERSON) {
      return true;
    } else if (person.empty() && fire.empty()) {
      return false;
    }
  }
  return false;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    init();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%s", grid[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == FIRE) {
          fire.push(ii(i, j));
        } else if (grid[i][j] == PERSON) {
          person.push(ii(i, j));
        } else if (grid[i][j] == END) {
          e = ii(i, j);
        }
      }
    }
    bool ans = solve();
    printf("%c\n", ans ? 'Y' : 'N');
  }
}
