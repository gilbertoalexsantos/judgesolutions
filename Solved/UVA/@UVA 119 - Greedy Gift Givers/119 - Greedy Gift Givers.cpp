//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=55

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

const int MAX = 10;

typedef map<char*,int>::iterator IT;

struct cmp { bool operator() (const char *a, const char *b) const {
  return strcmp(a,b) < 0;  } };

int qt_people, cnt;
char *word;
char *words[MAX];
IT it;
map<char*,int,cmp> MAP;

int main() {
  bool first = true;
  while(scanf("%d",&qt_people) != EOF) {
    first ? first = false : puts("");
    MAP.clear();
    for(int i = 0; i < qt_people; i++) {
      word = new char[20];
      scanf("%s",word);
      words[i] = new char[20];
      strcpy(words[i],word);
      MAP.insert(make_pair(word,0));
    }
    for(int i = 0; i < qt_people; i++) {
      word = new char[20];
      scanf("%s",word);
      int qt, k; scanf("%d %d",&qt,&k);
      int qt_up = 0, qt_down = 0;
      if(k != 0) {
        qt_up = qt / k;
        qt_down = qt_up * k;
      } 
      it = MAP.find(word);
      it->second -= qt_down;
      for(int j = 0; j < k; j++) {
        word = new char[20];
        scanf("%s",word);
        it = MAP.find(word);
        it->second += qt_up;
      }
    }
    for(int i = 0; i < qt_people; i++) {
      it = MAP.find(words[i]);
      printf("%s %d\n",it->first,it->second);
    }
  }
}
