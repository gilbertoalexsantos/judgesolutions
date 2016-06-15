//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1202

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_CARS = 205;
const int MAX_SIZE = 1e4 + 5;
const int LEFT = 0, RIGHT = 1;

vector<int> cars;
vector<int> sum;
int l;
bool memo[MAX_CARS][MAX_SIZE];
int choose[MAX_CARS][MAX_SIZE];

void init() {
  cars.clear();
  sum.clear();
  memset(memo, false, sizeof memo);
  for (int i = 0; i < MAX_CARS; i++)
    for (int j = 0; j < MAX_SIZE; j++)
      choose[i][j] = -1;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    init();
    scanf("%d", &l);
    l *= 100;

    sum.push_back(0);
    int c;
    while (scanf("%d", &c) && c) {
      cars.push_back(c);
      sum.push_back(sum[sum.size()-1] + c);
    }

    memo[0][0] = true;

    int sumLeft = 0, qtCars = 0;
    for (int i = 0; i < cars.size(); i++) {
      bool load = false;
      for (int s = 0; s <= l; s++) {
        if (!memo[i][s])
          continue;

        // Can put in left and right is ok
        if (s + cars[i] <= l && sum[i] - s <= l) {
          memo[i+1][s+cars[i]] = true;
          choose[i][s+cars[i]] = LEFT;
          sumLeft = s+cars[i];
          load = true;
        }

        // Can put in right (S is obviously ok, because we do: s <= l)
        if (sum[i+1] - s <= l) {
          memo[i+1][s] = true;
          choose[i][s] = RIGHT;
          sumLeft = s;
          load = true;
        }
      }
      if (!load)
        break;
      qtCars++;
    }

    bool answer[qtCars];
    memset(answer, LEFT, sizeof answer);
    int i = qtCars - 1;
    while (i >= 0) {
      if (choose[i][sumLeft] == LEFT) {
        answer[i] = true;
        sumLeft -= cars[i];
      } else {
        answer[i] = false;
      }
      i--;
    }


    printf("%d\n", qtCars);
    for (int i = 0; i < qtCars; i++)
      printf("%s\n", answer[i] ? "port" : "starboard");
    if (t)
      puts("");

  }
}
