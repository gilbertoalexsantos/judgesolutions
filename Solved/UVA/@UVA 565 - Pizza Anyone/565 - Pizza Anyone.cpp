//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=506

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int MAX = 16;

vector<vector<int> > pizzas;
vector<int> psLt;
set<int> letters;
bool hasAns;
bool ans[MAX];
char line[50];

void clear() {
  pizzas.clear();
  memset(ans, false, sizeof ans);
  hasAns = false;
  psLt.clear();
}

void transform() {
  int size = strlen(line) - 1;
  vector<int> cns; cns.assign(MAX, -1);
  for (int i = 0; i < size; i += 2) {
    letters.insert(line[i+1] - 'A');
    cns[line[i+1] - 'A'] = line[i] == '+' ? 1 : 0;
  }
  pizzas.push_back(cns);
}

bool bt(vector<int> &nt, int pos=0) {
  if (nt.empty()) {
    return true;
  } else if (pos == psLt.size()) {
    return false;
  }

  int lt = psLt[pos];

  vector<int> newNtTrue, newNtFalse;
  for (int i = 0; i < nt.size(); i++) {
    vector<int> pref = pizzas[nt[i]];
    
    // Getting
    if (pref[lt] != 1) {
      newNtTrue.push_back(nt[i]);
    } else {
      ans[lt] = true;
    }

    //Not Getting
    if (pref[lt] != 0) {
      newNtFalse.push_back(nt[i]);
    }
  }

  bool p = false;

  if (newNtTrue.size() != nt.size()) {
    p = bt(newNtTrue, pos + 1);
    if (p) {
      return true;
    }
  }

  ans[lt] = false;
  p = bt(newNtFalse, pos + 1);

  return p;
}

void solve() {
  for (set<int>::iterator it = letters.begin(); it != letters.end(); it++) {
    psLt.push_back(*it);
  }
  
  vector<int> nt(pizzas.size());
  for (int i = 0; i < pizzas.size(); i++) {
    nt[i] = i;
  }
  hasAns = bt(nt);
}

void printAns() {
  if (hasAns) {
    printf("Toppings: ");
    for (int i = 0; i < MAX; i++) {
      if (ans[i]) {
        printf("%c", i + 'A');
      }
    }
  } else {
    printf("No pizza can satisfy these requests.");
  }
  puts("");
}

int main() {
  while (scanf("%s", line) != EOF) {
    clear();
    transform();
    while (scanf("%s", line) && line[0] != '.') {
      transform();
    }
    solve();
    printAns();
  }
}
