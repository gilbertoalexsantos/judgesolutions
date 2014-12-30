//Author: Gilberto A. dos Santos
//Website:  http://br.spoj.com/problems/CAPITA13/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int area[4];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  scanf("%d %d %d %d",&area[0],&area[1],&area[2],&area[3]);
  bool can = false;
  do {
    int g1 = gcd(area[0],area[1]);
    int g2 = gcd(area[2],area[3]);
    int a = area[0] / g1, b = area[1]/g1;
    int c = area[2] / g2, d = area[3]/g2;
    if(a == c && b == d) {
      can = true;
      break;
    }
  } while(next_permutation(area,area+4));
  printf("%c\n",can ? 'S' : 'N');
}
