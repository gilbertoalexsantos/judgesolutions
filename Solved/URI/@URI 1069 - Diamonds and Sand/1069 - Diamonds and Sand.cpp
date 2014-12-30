//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1069
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char word[1002];

const char OPEN = '<', CLOSE = '>';

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%s",word);
    int ans = 0, stack = 0;
    for(int i = 0; i < strlen(word); i++) {
      if(word[i] == OPEN)
        stack++;
      else if(word[i] == CLOSE && stack)
        ans++, stack--;
    }
    printf("%d\n",ans);
  }
}
