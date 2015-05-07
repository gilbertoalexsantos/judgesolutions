//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1246

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> ii;

int c, n;
map<int, ii> toRange;
vector<ii> ranges;

void clear() {
  toRange.clear();
  ranges.clear();
  ranges.push_back(ii(1, c+1));
}

int findAppropriateRange(int plaque, int size) {
  for (int i = 0; i < ranges.size(); i++) {
    ii r = ranges[i];
    int diff = r.second - r.first;
    if (diff >= size) {
      toRange[plaque] = ii(ranges[i].first, ranges[i].first + size);
      ranges[i].first += size;
      if (ranges[i].first == ranges[i].second) {
        ranges.erase(ranges.begin() + i);
      }
      return 1;
    }
  }
  return 0;
}

void removeRange(int plaque) {
  ii r = toRange[plaque];
  toRange.erase(plaque);
  
  if (ranges.empty()) {
    ranges.push_back(r);
    return;
  }
  
  for (int i = 0; i < ranges.size(); i++) {
    if (ranges[i].first > r.second) {
      ranges.insert(ranges.begin() + i, r);
      return;
    } else if(ranges[i].first == r.second) {
      ranges[i].first = r.first;
      return;
    } else if (ranges[i].second == r.first) {
      ranges[i].second = r.second;
      
      if (i+1 < ranges.size()) {
        if (ranges[i].second == ranges[i+1].first) {
          ranges[i].second = ranges[i+1].second;
          ranges.erase(ranges.begin() + i+1);
        }
      }
      
      return;
    }
  }

  ranges.push_back(r);
}

int main() {
  while (scanf("%d %d\n", &c, &n) != EOF) {
    clear();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      char type;
      int plaque, size;
      scanf("%c %d", &type, &plaque);
      if (type == 'C') {
        scanf("%d", &size);
        ans += findAppropriateRange(plaque, size);
      } else {
        removeRange(plaque);
      }
      getchar();
    }
    printf("%d\n", ans * 10);
  }
}
