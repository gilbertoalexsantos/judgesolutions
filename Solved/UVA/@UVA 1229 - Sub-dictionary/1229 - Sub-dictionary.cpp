//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3670

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

const int MAX = 105;

map<string, int> MAP;
map<int, string> PAM;

int qt_dict, cnt;
bool edge[MAX][MAX];
int degree[MAX];
vector<int> graph[MAX];

int ins(string w) {
  map<string, int>::iterator it = MAP.find(w);
  if(it == MAP.end()) {
    MAP.insert(make_pair<string, int>(w,cnt));
    PAM.insert(make_pair<int, string>(cnt,w));
    return cnt++;
  } else
    return it->second;
}

string getStr(int n) {
  map<int, string>::iterator it = PAM.find(n);
  return it == PAM.end() ? "" : it->second;
}

void clear() {
  MAP.clear(); PAM.clear();
  cnt = 0;
  memset(edge,false,sizeof edge);
  memset(degree, 0, sizeof degree);
  for(int i = 0; i < MAX; i++)
    graph[i].clear();
}

int main() {
  while(scanf("%d\n",&qt_dict) && qt_dict) {
    clear();
    string word;
    for(int i = 0; i < qt_dict; i++) {
      getline(cin, word);
      istringstream iss(word);
      vector<string> tokens;
      copy(istream_iterator<string>(iss),
          istream_iterator<string>(),
          back_inserter<vector<string> >(tokens));
      int u = ins(tokens[0]);
      for(int i = 1; i < tokens.size(); i++) {
        int v = ins(tokens[i]);
        if(!edge[u][v]) {
          graph[u].push_back(v);
          edge[u][v] = true;
          degree[v]++;
        }
      }
    }
    int ret = cnt;
    queue<int> qe;
    for(int i = 0; i < cnt; i++) if(!degree[i])
      qe.push(i);
    while(!qe.empty()) {
      int u = qe.front(); qe.pop();
      for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        degree[v]--;
        if(!degree[v])
          qe.push(v);
      }
      ret--;
    }
    cout << ret << endl;
    vector<string> ans;
    for(int i = 0; i < cnt; i++) if(degree[i] != 0)
      ans.push_back(getStr(i));
    sort(ans.begin(), ans.end());
    if(ans.size() > 0)
      cout << ans[0];
    for(int i = 1; i < ans.size(); i++)
      cout << " " << ans[i];
    cout << endl;
  }
}
