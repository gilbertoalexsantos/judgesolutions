#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int T = 100000;
const int MODULE = 5;

int main() {
  srand(time(NULL));
  printf("%d\n",T);
  for(int i = 0; i < T; i++) {
    int a = abs(rand() % MODULE);
    int b = rand() % MODULE;
    while(b == a)
      b = rand() % MODULE;
    printf("%d %d\n",a,b);
  }
}
