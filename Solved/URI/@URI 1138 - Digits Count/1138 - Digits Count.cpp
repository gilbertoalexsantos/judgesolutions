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

int calc(int number, int digit, int flag=-1, int factor=1, int rest=0) {
  if(flag == -1) 
    flag = number;
  if(number < 10)
    return digit <= number;
  if(flag == 0)
    return 0;

  int ret = 0;

  int digit_unit = flag % 10;
  flag /= 10;

  ret += (flag - (digit == 0 && flag && factor != 1)) * factor;

  if(digit != 0 || (digit == 0 && flag)) {
    if(digit_unit == digit)
      ret += rest + 1;
    else if(digit_unit > digit)
      ret += factor;
  }

  factor *= 10;
  return ret + calc(number,digit,flag,factor,number % factor);
}

inline int calc(int digit) { return calc(b,digit) - calc(a-1,digit); }

int main() {
  while(scanf("%d %d",&a,&b) && a+b) {
    printf("%d",calc(0));
    for(int i = 1; i < 10; i++)
      printf(" %d",calc(i));
    puts("");
  } 
}
