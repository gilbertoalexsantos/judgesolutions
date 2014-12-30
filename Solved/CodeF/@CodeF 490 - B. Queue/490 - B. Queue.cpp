//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/490/problem/B

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 1000010;

int main() {
  int qt[MAX]; memset(qt, false, sizeof qt);
  bool where[MAX]; memset(where, false, sizeof where);
  vector<ii> pairs;
  vector<int> numbers_front;
  vector<int> numbers;
  
  int n; scanf("%d",&n);
  for(int i = 0; i < n; i++) {
    int front, behind; scanf("%d %d",&front,&behind);
    if(front && !qt[front]) numbers.push_back(front);
    if(behind && !qt[behind]) numbers.push_back(behind);
    pairs.push_back(ii(front,behind));
    numbers_front.push_back(front);
    where[front] = true; where[behind] = false;
    qt[front]++; qt[behind]++;
  }

  int ans[n];
  for(int i = 0; i < n; i++) {
    int number = numbers[i];
    if(qt[number] == 1) {
      if(where[number]) ans[0] = number;
      else ans[n-1] = number;
    }
  }
  
  sort(pairs.begin(),pairs.end());
  sort(numbers_front.begin(),numbers_front.end());
  for(int i = 1; i < n-1; i++) {
    int number = (i == 1) ? 0 : ans[i-2];
    vector<int>::iterator it = lower_bound(numbers_front.begin(),numbers_front.end(),number);
    int pos = it - numbers_front.begin();
    ans[i] = pairs[pos].second;
  }

  printf("%d",ans[0]);
  for(int i = 1; i < n; i++)
    printf(" %d",ans[i]);
  puts("");
  
}
