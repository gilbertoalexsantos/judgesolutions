//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/ELIM/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 100000;

char word[MAX];

void parse(char *w, vector<int> &p) {
  char *f = strtok(w, " ");
  while(f != NULL) {
    p.push_back(atoi(f));
    f = strtok(NULL, " ");
  }
}

int solve(const vector<int> &pl, const vector<int> &cp) {
  int qt = 1, left = cp.size()-1;
  int winner = 1;
  while(qt != pl.size()) {
    winner = cp[left+winner-1];
    qt *= 2;
    left -= qt;
  }
  return pl[winner-1];
}

int main() {
  while(scanf("%[^\n]\n", word) && word[0] != '0') {
    vector<int> pl, cp;
    parse(word,pl);
    scanf("%[^\n]\n",word);
    parse(word, cp);
    int ans = solve(pl, cp);
    printf("%d\n",ans);
  }
}
