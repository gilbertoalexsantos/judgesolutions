//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1591

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int n, m, p;
vector<string> words;
vector<string> snippets;
int back[55][55];

void kmpPreprocess(int pos, string &w) {
  int i = 0, j = -1; back[pos][0] = -1;
  while(i < w.size()) {
    while(j >= 0 && w[i] != w[j])
      j = back[pos][j];
    back[pos][++i] = ++j;
  }
}

int kmpSearch(int pos, string &sni, string &wor) {
  int ret = 0;
  int i = 0, j = 0;
  while(i < wor.size()) {
    while(j >= 0 && sni[j] != wor[i])
      j = back[pos][j];
    i++, j++;
    if(j == sni.size())
      ret++;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  while(T--) {
    snippets.clear();
    words.clear();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
      string w; cin >> w;
      words.push_back(w);
    }
    for(int i = 0; i < m; i++) {
      string w;
      for(int j = 0; j < n; j++)
        w += words[j][i];
      words.push_back(w);
    }
    cin >> p;
    for(int i = 0; i < p; i++) {
      string w; cin >> w;
      snippets.push_back(w);
    }
    for(int i = 0; i < p; i++)
      kmpPreprocess(i,snippets[i]);
    for(int i = 0; i < snippets.size(); i++) {
      int ans = 0;
      int offset = (snippets[i].size() == 1) ? m : 0;
      for(int j = 0; j < words.size() - offset; j++)
        ans += kmpSearch(i,snippets[i],words[j]);
      cout << ans << endl;
    }
  }
}
