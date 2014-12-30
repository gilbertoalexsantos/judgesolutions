//Author:   Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1564

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n;

int main() {
  while(scanf("%d",&n) != EOF)
    printf("%s\n",!n ? "vai ter copa!" : "vai ter duas!");
}
