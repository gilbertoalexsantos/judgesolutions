#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

const int MAX_WORDS = 27;
const ll MAX_QUERY = 100000005;

int n, q;
vector<string> words(MAX_WORDS);
vector<ll> sum;

void initSum() {
  sum.clear();

  ll factor = n;
  ll index = 1;
  sum.push_back(n * index);

  while (sum[sum.size() - 1] < MAX_QUERY) {
    factor *= n; index++;
    sum.push_back(factor * index);
    sum[sum.size()-1] += sum[sum.size()-2];
  }
}

int lb(ll p, int hi) {
  int lo = 0, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (sum[mid] < p)
      lo = mid+1;
    else
      hi = mid-1;
  }
  return hi+1;
}

ll ssum(int ind) {
  return sum[ind] - (ind == 0 ? 0 : sum[ind-1]);
}

int bt(ll query) {
  if (query <= n)
    return query - 1;

  int bigBlock = lb(query, sum.size() - 1);
  ll qtBlocksInRow = (ssum(bigBlock) / (bigBlock+1)) / n;

  query -= sum[bigBlock-1];
  if (((query-1) % (bigBlock+1)) == 0)
    return (query-1) / (qtBlocksInRow * (bigBlock+1));

  ll qtBlocksBefore = ssum(bigBlock-1) / bigBlock;
  ll blockPosition = ceil(double(query) / double(bigBlock+1));
  ll qtFirstInRow = ((blockPosition - 1) % qtBlocksInRow) + 1;

  if (blockPosition > qtBlocksInRow)
    query -= qtBlocksInRow * (bigBlock+1) * ((blockPosition-1) / qtBlocksBefore);
  query -= qtFirstInRow;

  if (bigBlock > 1)
    query += sum[bigBlock-2];

  return bt(query);
}

string solve(ll query) {
  if (n == 1)
    return words[0];
  return words[bt(query)];
}

int main() {
  while (cin >> n >> q) {
    if (!(n+q))
      break;

    initSum();

    for (int i = 0; i < n; i++)
      cin >> words[i];

    for (int i = 0; i < q; i++) {
      ll q; cin >> q;
      cout << solve(q) << endl;
    }

    cout << endl;
  }
}
