//Author:   Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1556

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1005;

inline bool cmp(const char *a, const char *b) { return strcmp(a,b) < 0; }

char word[MAX], flag[MAX];
vector<char*> ans;
int size;

void ins(const char *c) {
  char *f = new char[strlen(c)+1];
  strcpy(f,c);
  ans.push_back(f);
}

void backtrack(int pos, int num_pegos, char ultimo) {
  if(pos == size) {
    flag[num_pegos] = '\0';
    ins(flag);
    return;
  }

  flag[num_pegos] = word[pos];
  backtrack(pos+1,num_pegos+1,word[pos]);

  if(word[pos] != ultimo)
    backtrack(pos+1,num_pegos,ultimo);
}

int main() {
  while(scanf("%s",word) != EOF) {
    ans.clear();
    size = strlen(word);
    backtrack(0,0,0);
    sort(ans.begin(),ans.end(),cmp);
    for(int i = 1; i < ans.size(); i++)
      puts(ans[i]);
    puts("");
  }
}
