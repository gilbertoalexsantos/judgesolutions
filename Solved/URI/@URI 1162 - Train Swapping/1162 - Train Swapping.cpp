//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1162
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 50;

int arr[MAX];
int size;

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d",&size);
    for(int i = 0; i < size; i++) 
      scanf("%d",&arr[i]);

    int ans = 0;
    for(int i = 0; i < size; i++)
      for(int j = 0; j < size - i - 1; j++) {
        if(arr[j] > arr[j + 1])
          swap(arr[j],arr[j + 1]), ans++;
      }
    printf("Optimal train swapping takes %d swaps.\n",ans);
  }
}
