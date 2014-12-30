//Author: Gilberto A. dos Santos
//Webiste:  https://www.urionlinejudge.com.br/judge/en/problems/view/1520

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
  while(scanf("%d",&n) != EOF) {
    vector<int> numbers;
    for(int i = 0; i < n; i++) {
      int x, y; scanf("%d %d",&x,&y);
      for(int j = x; j <= y; j++)
        numbers.push_back(j);
    }
    int k; scanf("%d",&k);
    sort(numbers.begin(),numbers.end());
    int i = 0;
    while(i < numbers.size()) {
      if(numbers[i] == k)
        break;
      i++;
    }
    int j = i+1;
    while(j < numbers.size()) {
      if(numbers[j] > k)
        break;
      j++;
    }
    if(i == numbers.size())
      printf("%d not found\n",k);
    else
      printf("%d found from %d to %d\n",k,i,j-1);
  }
}
