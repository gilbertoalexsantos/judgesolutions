//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4720

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000005

int a, b, qt_w, qt_b, size;
int i, j;
char word[MAX];

int main() {
  while(scanf("%d %d",&a,&b) != EOF) {
    b = a - b;
    qt_w = qt_b = 0;
    scanf("%s",word);
    size = strlen(word);
    for(i = 0; i < size; i++) {
      qt_w += word[i] == 'W';
      qt_b += word[i] == 'B';
    }
    i = qt_b-1, j = i+1;
    while(i >= 0 && word[i] == 'B') i--;
    while(j < size && word[j] == 'W') j++;
    long long sum = 0;
    while(i >= 0 && j < size) {
      int dist = j-i;
      if(dist*b > a)
        while(j < size) sum += word[j++] == 'B' ? a : 0;
      else {
        i--, j++;
        sum += dist*b;
      }
      while(i >= 0 && word[i] == 'B') i--;
      while(j < size && word[j] == 'W') j++;
    }
    printf("%lld\n",sum);
  }
}
