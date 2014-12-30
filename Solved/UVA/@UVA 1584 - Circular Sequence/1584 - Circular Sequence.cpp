//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4459

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

char word[105];
int size;

void solve(vector<ii> &mins) {
  if(mins[0].first == mins[0].second) {
    printf("%c\n",word[mins[0].first]);
    return;
  }
  printf("%c",word[mins[0].first]);
  vector<ii> nmins;
  char c_min = 'Z';
  for(int i = 0; i < mins.size(); i++) {
    int next = mins[i].first+1 == size ? 0 : mins[i].first+1;
    c_min = min(c_min,word[next]);
  }
  for(int i = 0; i < mins.size(); i++) {
    int next = mins[i].first+1 == size ? 0 : mins[i].first+1;
    if(word[next] == c_min)
      nmins.push_back(ii(next,mins[i].second));
  }
  solve(nmins);
}

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%s",word);
    size = strlen(word);
    char c_min = 'Z';
    for(int i = 0; i < size; i++)
      c_min = min(c_min,word[i]);
    vector<ii> mins;
    for(int i = 0; i < size; i++) {
      if(word[i] == c_min)
        mins.push_back(ii(i,i-1 < 0 ? size-1 : i-1));
    }
    solve(mins);
  }
}
