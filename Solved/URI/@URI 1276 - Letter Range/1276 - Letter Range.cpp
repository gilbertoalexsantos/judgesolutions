#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<char, char> cc;

const int MAX = 100;

char word[MAX];
int size;

vector<cc> ans;

void solve() {
  sort(word,word + size);
  char f1 = word[0];
  int ind = 0, flag = word[0];
  while(true) {
    while(ind < size && (flag == word[ind] || flag == word[ind]+1))
      ind++, flag += (flag != word[ind]);
    if(ind == size) {
      ans.push_back(cc(f1,word[ind-1]));
      break;
    } else {
      ans.push_back(cc(f1,word[ind-1]));
      f1 = word[ind];
      flag = f1;
    }
  }
  printf("%c:%c",ans[0].first,ans[0].second);
  for(int i = 1; i < ans.size(); i++)
    printf(", %c:%c",ans[i].first,ans[i].second);
  puts("");
}

int main() {
  char c; 
  size = 0;
  while(scanf("%c",&c) != EOF) {
    ans.clear();
    if(c == ' ')
      continue;
    else if(c == '\n') {
      if(size == 0)
        printf("\n");
      else {
        solve();
        size = 0;
      }
    } else
      word[size++] = c;
  }
}
