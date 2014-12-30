//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/LITE/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

struct DATA {
  int on, off;
  bool to_update;

  DATA() {
    on = off = 0;
    to_update = false;
  }

  DATA(int on, int off, bool to_update=false) {
    this->on = on;
    this->off = off;
    this->to_update = to_update;
  }

};

const int MAX_RANGE = 100005;
const int LIGHT = 0, RANGE = 1;

int n, m;
bool bucket[MAX_RANGE];
struct DATA range[MAX_RANGE];
int MAX;

void in_change(int L, int R) {
  swap(range[L].on,range[L].off);
  range[L].to_update = !range[L].to_update;
}

void out_change(int L, int R, int left, int right) {
  int sum = 0;
  for(int i = L; i <= R; i++) {
    if(range[L].to_update) {
      if(i < left || i > right)
        bucket[i] = !bucket[i];
      sum += bucket[i];
    } else {
      if(i >= left && i <= right)
        bucket[i] = !bucket[i];
      sum += bucket[i];
    }
  }
  range[L] = DATA(sum,R - L + 1 - sum,false);
}

void press(int L, int R) {
  int left, right;
  for(left = 0; left+(2*MAX) <= n; left += MAX) {
    right = left + MAX - 1;
    if(left > R || right < L)
      continue;
    else if(L <= left && R >= right)
      in_change(left,right);
    else
      out_change(left,right,L,R); 
  }
  right = n - 1;
  if(left > R || right < L)
    return;
  if(L <= left && R >= right)
    in_change(left,right);
  else
    out_change(left,right,L,R);
}

int out_range(int L, int R, int left, int right) {
  int sum = 0;
  for(int i = L; i <= R; i++) {
    if(range[L].to_update)
      bucket[i] = !bucket[i];
    if(i >= left && i <= right)
      sum += bucket[i];
  }
  if(range[L].to_update)
    range[L].to_update = false;
  return sum;
}

int getRange(int L, int R) {
  int left, right, ret = 0;
  for(left = 0; left+(2*MAX) <= n; left += MAX) {
    right = left + MAX - 1;
    if(left > R || right < L)
      continue;
    else if(L <= left && R >= right)
      ret += range[left].on;
    else
      ret += out_range(left,right,L,R);
  }
  right = n - 1;
  if(left > R || right < L) {}
  else if(L <= left && R >= right)
    ret += range[left].on;
  else
    ret += out_range(left,right,L,R);
  return ret;
}

void init() {
  int left, right;
  for(left = 0; left+(2*MAX) <= n; left += MAX) {
    right = left + MAX - 1;
    range[left] = DATA(0,right - left + 1);
  }
  right = n - 1;
  range[left] = DATA(0,right - left + 1);
}

int main() {
  memset(bucket,0,sizeof bucket);
  scanf("%d %d",&n,&m);
  MAX = (int) sqrt(n);
  init();
  for(int i = 0; i < m; i++) {
    int p, left, right;
    scanf("%d %d %d",&p,&left,&right);
    left--, right--;
    if(p == LIGHT)
      press(left,right);
    else
      printf("%d\n",getRange(left,right));
  }
}
