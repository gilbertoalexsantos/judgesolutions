//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/2050

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> names(6);
int isFriend[6][6];
map<int, string> is;
map<string, int> si;

bool threeFriends(int a, int b, int c) {
  return isFriend[a][b] && isFriend[a][c] && isFriend[b][c];
}

bool threeEnemies(int a, int b, int c) {
  return !isFriend[a][b] && !isFriend[a][c] && !isFriend[b][c];
}

string people(int a, int b, int c) {
  vector<string> nms;
  nms.push_back(is[a]); nms.push_back(is[b]); nms.push_back(is[c]);
  return is[a] + " " + is[b] + " " + is[c];
}

string answerFriend(int a, int b, int c) {
  return people(a, b, c) + " " + "sao amigos";
}

string answerEnemies(int a, int b, int c) {
  return people(a, b, c) + " " + "sao inimigos";
}

int main() {
  int m;
  int instance = 1;
  while (cin >> m && m != -1) {
    if (instance > 1)
      cout << "\n";

    memset(isFriend, 0, sizeof isFriend);
    is.clear(); si.clear();

    for (int i = 0; i < 6; i++)
      cin >> names[i];

    sort(names.begin(), names.end());
    for (int i = 0; i < 6; i++)
      is[i] = names[i], si[names[i]] = i;

    for (int i = 0; i < m; i++) {
      string a, b; cin >> a >> b;
      int ia = si[a], ib = si[b];
      isFriend[ia][ib] = isFriend[ib][ia] = 1;
    }

    vector<string> ans;

    for (int i = 0; i < 6; i++) {
      for (int j = i+1; j < 6; j++) {
        for (int z = j+1; z < 6; z++) {
          if (threeFriends(i, j, z))
            ans.push_back(answerFriend(i, j, z));
          else if (threeEnemies(i, j, z))
            ans.push_back(answerEnemies(i, j, z));
        }
      }
    }

    cout << "Instancia " << instance++ << endl;
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] << endl;
  }
}
