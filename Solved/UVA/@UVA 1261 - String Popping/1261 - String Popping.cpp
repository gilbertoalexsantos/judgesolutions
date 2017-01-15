//Author:   Gilberto A. dos Santos
//Website:  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3702
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> ii;

map<vector<ii>, int> memo;

vector<ii> transform(char *str) {
  vector<ii> ret;
  ret.push_back(ii(str[0] != 'a', 1));
  int size = strlen(str);
  int i = 1;
  while (i < size) {
    if (str[i] == str[i-1]) {
      ret[ret.size()-1].second++;
    } else {
      ret.push_back(ii(str[i] != 'a', 1));
    }
    i++;
  }
  return ret;
}

vector<ii> pop(vector<ii> v, int p) {
  vector<ii> ret;

  for (int i = 0; i < p; i++)
    ret.push_back(v[i]);

  if (v.size() == 1 || p == (int)v.size()-1)
    return ret;

  if (p == 0 || v.size() == 2) {
    for (int i = p+1; i < (int)v.size(); i++)
      ret.push_back(v[i]);
    return ret;
  }

  ret[ret.size()-1].second += v[p+1].second;
  for (int i = p+2; i < (int)v.size(); i++)
    ret.push_back(v[i]);

  return ret;
}

int dp(vector<ii> v) {
  if (v.size() == 0)
    return 1;

  if (memo.find(v) != memo.end())
    return memo[v];

  int ret = 0;

  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i].second == 1)
      continue;

    vector<ii> nv = pop(v, i);
    ret |= dp(nv);
  }

  return memo[v] = ret;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    char ans[30]; scanf("%s", ans);
    vector<ii> r = transform(ans);
    int a = dp(r);
    printf("%d\n", a);
  }
}
