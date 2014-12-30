//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=350

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char ESPACE = ' ';

int k, e;
vector<string> words;
vector<string> lines;

bool is_c(char l) { return (l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z'); }

void replace(string &s) {
  for(int i = 0; i < s.size(); i++)
    s[i] = is_c(s[i]) ? tolower(s[i]) : ESPACE;
}

vector<string> split_string(string s) {
  vector<string> ret;

  int i = 0;
  while(i < s.size() && s[i] == ESPACE) i++;

  while(i < s.size()) {
    string t;
    while(i < s.size() && s[i] != ESPACE) 
      t.push_back(s[i++]);
    ret.push_back(t);
    while(i < s.size() && s[i] == ESPACE)
      i++;
  }

  return ret;
}

void solve() {
  int counter[e]; memset(counter,0,sizeof counter);
  int max_counter = -1;
  for(int i = 0; i < e; i++) {
    string l = lines[i];
    replace(l);
    vector<string> tokens = split_string(l);
    int flag = 0;
    for(int a = 0; a < k; a++) {
      string t1 = words[a];
      replace(t1);
      for(int b = 0; b < tokens.size(); b++) {
        if(t1 == tokens[b])
          flag++;
      }
    }
    max_counter = max(max_counter,flag);
    counter[i] = flag;
  }
  for(int i = 0; i < e; i++) {
    if(counter[i] == max_counter)
      cout << lines[i] << endl;
  }
  cout << endl;
}

int main() {
  int cases = 1;
  while(cin >> k >> e) {
    words.clear(); lines.clear();
    for(int i = 0; i < k; i++) {
      string w; cin >> w;
      words.push_back(w);
    }
    getchar();
    for(int i = 0; i < e; i++) {
      string w; getline(cin,w);
      lines.push_back(w);
    }
    cout << "Excuse Set #" << cases++ << endl;
    solve();
  }
}
