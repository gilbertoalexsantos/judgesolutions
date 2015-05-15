//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1138

//Source: http://math.stackexchange.com/questions/47477/number-of-occurrences-of-the-digit-1-in-the-numbers-from-0-to-n

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int a, b;

int calc(int digit, int number) {
  if (number == 0) {
    return digit == 0;
  }

  int prefix = number, factor = 1, cnt = 0;

  while (prefix) {
    int rdigit = prefix % 10;
    int remainder = number % factor;
    int nprefix = prefix / 10;

    cnt += nprefix * factor;
    if (rdigit == digit) {
      cnt += remainder + 1;
    } else if (rdigit > digit) {
      cnt += factor;
    }

    factor *= 10;
    prefix = nprefix;
  }

  if (!digit) {
    int diff = 0;
    for (int i = 10; i <= (factor / 10); i *= 10) {
      diff += i;
    }
    cnt -= diff;
  }

  return cnt;
}

inline int calc(int digit) { return calc(digit, b) - calc(digit, a-1); }

int main() {
  while(scanf("%d %d",&a,&b) && a+b) {
    printf("%d",calc(0));
    for(int i = 1; i < 10; i++)
      printf(" %d",calc(i));
    puts("");
  }
}
