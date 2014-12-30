//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/pt/problems/view/1495

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int n, g;
ii arr[100005];

int main() {
  while(scanf("%d %d",&n,&g) != EOF) {
    for(int i = 0; i < n; i++)
      scanf("%d %d",&arr[i].first,&arr[i].second);
    int sum = 0;
    vector<int> new_array;
    for(int i = 0; i < n; i++) {
      int diff = arr[i].first - arr[i].second;
      if(diff < 0)
        new_array.push_back(abs(diff));
      else if(diff > 0)
        sum += 3;
      else
        sum += g > 0 ? 3 : 1, g--;
    }
    sort(new_array.begin(),new_array.end());
    for(int i = 0; i < new_array.size(); i++) {
      int diff = new_array[i];
      if(g > diff) {
        g -= diff+1;
        sum += 3;
      } else if(g == diff) {
        sum += 1;
        g = 0;
      }
    }
    printf("%d\n",sum);
  }
}
