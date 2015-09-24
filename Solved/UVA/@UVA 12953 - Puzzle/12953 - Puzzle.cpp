//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4832

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef map<string, int>::iterator IT;

const int ALPHA = 150;
const int MAX_L = 205;

int cnt[ALPHA][ALPHA];
bool calculated[ALPHA][ALPHA];
vector<string> _grid[MAX_L];
map<string, int> grid[MAX_L];
int row[MAX_L];
int l, c;

void insert(int pos, string &a) {
  IT it = grid[pos].find(a);
  if (it != grid[pos].end())
    it->second++;
  else
    grid[pos][a] = 1;
}

void init() {
  memset(cnt, -1, sizeof cnt);
  memset(calculated, false, sizeof calculated);
  for (int i = 0; i < MAX_L; i++) {
    _grid[i].clear();
    grid[i].clear();
  }
}

void buildMap() {
  int size = l+c;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < _grid[i].size(); j++)
      insert(i, _grid[i][j]);
}

int qtCalculated(int pos) {
  int qt = 0;
  for (IT it = grid[pos].begin(); it != grid[pos].end(); it++) {
    string t = it->first;
    qt += calculated[t[0]][t[1]];
  }
  return qt;
}

bool alreadyCalculated(int pos) {
  return grid[pos].size() == qtCalculated(pos);
}

bool hasAns(int pos) {
  return (grid[pos].size() - qtCalculated(pos)) == 1;
}

void updateAns(int pos) {
  string upd;
  int upd_count;
  int upd_others = 0;
  for (IT it = grid[pos].begin(); it != grid[pos].end(); it++) {
    string t = it->first;
    if (!calculated[t[0]][t[1]])
      upd = t, upd_count = it->second;
    else
      upd_others += it->second * cnt[t[0]][t[1]];
  }
  cnt[upd[0]][upd[1]] = (row[pos] - upd_others) / upd_count;
  calculated[upd[0]][upd[1]] = true;
}

void solve() {
  int size = l+c;
  bool has = true;
  while (has) {
    has = false;
    for (int i = 0; i < size; i++) {
      if (hasAns(i)) {
        has = true;
        updateAns(i);
      }
    }
  }
}


int main() {
  while (cin >> l >> c) {
    init();
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        string a; cin >> a;
        _grid[i].push_back(a);
      }
      cin >> row[i];
    }
    for (int j = 0; j < c; j++)
      for (int i = 0; i < l; i++)
        _grid[j+l].push_back(_grid[i][j]);
    for (int i = 0; i < c; i++)
      cin >> row[i+l];

    buildMap();
    solve();

    for (int i = 0; i < ALPHA; i++)
      for (int j = 0; j < ALPHA; j++)
        if (calculated[i][j])
          cout << char(i) << char(j) << " " << cnt[i][j] << endl;
  }
}
