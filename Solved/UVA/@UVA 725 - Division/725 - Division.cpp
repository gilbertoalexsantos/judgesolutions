//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=666

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int n;
vector<ii> ans;
vector<int> numbers;
bool number[11];

bool check(int v) {
  stringstream s;
  s << v;
  string result = s.str();
  if(v < 10000)
    number[0] = true;
  for(int i = 0; i < result.size(); i++) {
    int p = result[i] - '0';
    if(number[p])
      return false;
    number[p] = true;
  }
  return true;
}

void getMultiples() {
  ans.clear();
  for(int i = 0; i < numbers.size(); i++) {
    memset(number,false,sizeof number);
    int a = numbers[i];
    int b = a * n;
    if(b > 99999)
      return;
    if(a < 10000 && b < 10000)
      continue;
    if(!check(a) || !check(b))
      continue;
    ans.push_back(ii(b,a));
  }
}

void init() {
  int a = 1000;
  int s = a * 2;
  while(s < 100000) {
    memset(number,false,sizeof number);
    if(check(a))
      numbers.push_back(a);
    a++;
    s = a * 2;
  }
}

int main() {
  init();
  bool first = true;
  while(scanf("%d",&n) && n) {
    first ? first = false : puts(""); 
    getMultiples();
    if(ans.size() == 0)
      printf("There are no solutions for %d.\n",n);
    else {
      for(int i = 0; i < ans.size(); i++)
        printf("%05d / %05d = %d\n",ans[i].first,ans[i].second,n);
    }
  }
}
