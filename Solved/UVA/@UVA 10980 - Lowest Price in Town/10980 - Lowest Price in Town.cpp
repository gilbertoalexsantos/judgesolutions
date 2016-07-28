//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1921

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;
const int MAX_ITEMS = 25;
const int MAX_CATCH = 105;

int memo[MAX_ITEMS][MAX_CATCH];
int numberInteger, numberDecimal;
int m;
vector<int> qt;
vector<int> prices;

void init() {
  memset(memo, -1, sizeof memo);
  prices.clear();
  qt.clear();
}

int dp(int p, int qtCaught) {
  if (p == m || qtCaught <= 0)
    return qtCaught <= 0 ? 0 : INF;

  int &ret = memo[p][qtCaught];

  if (ret != -1)
    return ret;

  ret = INF;

  //Pass the item
  ret = min(ret, dp(p+1, qtCaught));

  //Catch the item and stay
  ret = min(ret, prices[p] + dp(p, qtCaught - qt[p]));

  return ret;
}

vector<ii> getQueries() {
  vector<ii> queries;

  getchar();
  char line[11000];
  fgets(line, 11000, stdin);
  char *ptr = strtok(line, " ");
  int i = 0;
  while (ptr != NULL) {
    queries.push_back(ii(atoi(ptr), i++));
    ptr = strtok(NULL, " ");
  }

  return queries;
}

int main() {
  int cases = 1;
  while (scanf("%d.%d %d", &numberInteger, &numberDecimal, &m) != EOF) {
    init();

    prices.push_back(numberInteger * 100 + numberDecimal);
    qt.push_back(1);
    int sumPrices = prices[0];
    for (int i = 0; i < m; i++) {
      int quantity, pr, prInt, prDec;
      scanf("%d %d.%d", &quantity, &prInt, &prDec);
      pr = prInt * 100 + prDec;
      qt.push_back(quantity);
      prices.push_back(pr);
      sumPrices += pr;
    }

    m += 1;

    vector<ii> queries = getQueries();
    sort(queries.begin(), queries.end());

    vector<ii> ans(queries.size());
    for (int i = 0; i < (int)queries.size(); i++) {
      dp(0, queries[i].first);
      ans[queries[i].second] = ii(queries[i].first, memo[0][queries[i].first]);
    }


    printf("Case %d:\n", cases++);
    for (int i = 0; i < (int)ans.size(); i++) {
      printf("Buy %d for $%d.%02d\n", 
          ans[i].first, ans[i].second / 100, ans[i].second%100);
    }
  }
}
