#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX = 100005;

ll a[MAX], b[MAX];

int size;

int main() {
  scanf("%d",&size);  
  for(int i = 1; i <= size; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  a[0] = b[0] = 0;
  sort(b+1,b+size+1);
  for(int i = 2; i <= size; i++) {
    a[i] += + a[i-1];
    b[i] += + b[i-1];
  }
  int qt; scanf("%d",&qt);
  while(qt--) {
    int t, left, right;
    ll ans;
    scanf("%d %d %d",&t,&left,&right);
    if(t == 1)
      ans = a[right] - a[left-1];
    else
      ans = b[right] - b[left-1];
    cout << ans << endl;
  }
}
