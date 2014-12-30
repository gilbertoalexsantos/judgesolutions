//Author: Gilberto A. dos Santos
//Website:http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=423

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef pair<int,string> ii;

const int MAX = 50000;

char word[MAX];
vector<string> ans(MAX);

int main() {
  int T;
  scanf("%d\n\n",&T);
  while(T--) {
    fgets(word,50000,stdin);
    int cnt = 0;
    char *f = strtok(word," ");
    while(f != NULL) {
      int p = atoi(f);
      cin >> ans[p];
      f = strtok(NULL," ");
      cnt++;
    }
    for(int i = 1; i <= cnt; i++)
      cout << ans[i]<< endl;
    if(T)
      puts("");
    getchar(); getchar();
  }
}

