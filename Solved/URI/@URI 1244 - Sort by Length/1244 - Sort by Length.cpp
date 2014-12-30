//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1244

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct TYPE {
  char *w;
  int len;
  int index;

  TYPE(char *a, int ind) {
    len = strlen(a);
    w = new char[len+1];
    strcpy(w,a);
    index = ind;
  }
};

int n;
char word[3000];
vector<TYPE> v;

bool comp(TYPE a, TYPE b) { 
  if(a.len == b.len)
    return a.index < b.index;
  return a.len > b.len;
}

int main() {
  scanf("%d\n",&n);
  for(int i = 0; i < n; i++) {
    v.clear();
    scanf("%[^\n]",word);
    getchar();
    char *f = strtok(word, " ");
    int cnt = 0;
    while(f != NULL) {
      TYPE t(f,cnt++);
      v.push_back(t);
      f = strtok(NULL, " ");
    }
    sort(v.begin(),v.end(),comp);
    printf("%s",v[0].w);
    for(int i = 1; i < v.size(); i++)
      printf(" %s",v[i].w);
    puts("");
  }
}
