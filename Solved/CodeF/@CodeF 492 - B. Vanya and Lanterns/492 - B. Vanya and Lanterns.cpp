//Author: Gilberto A. dos Santos
//Website:

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const double EPS = 1e-9;

bool less_than(double a, double b) { return (a - b) < EPS; }
bool greater_than(double a, double b) { return (a - b) > EPS; }

int main() {
  int n, l;
  scanf("%d %d",&n, &l);

  vector<int> lt;
  for(int i = 0; i < n; i++) {
    int p; scanf("%d",&p);
    lt.push_back(p);
  }

  sort(lt.begin(),lt.end());

  double ans = 0.0;
  if(lt[0] != 0)
    ans = lt[0];
  if(lt[lt.size()-1] != l)
    ans = max(lt[0], l - lt[lt.size()-1]);
  
  for(int i = 0; i+1 < lt.size(); i++) {
    int p1 = lt[i], p2 = lt[i+1];
    int dist = lt[i+1] - lt[i];
    
    double mid = (double) dist / 2.0;
    if (!greater_than(ans,mid))
      ans = mid;
  }

  printf("%.10lf\n",ans);
  
}
