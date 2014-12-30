//Author:   Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1561

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char w[10];
int hour, minute;
bool ans[10];
const char word[3] = {' ','o','\0'};

void get_ans() {
  int num_hour[] = {8,4,2,1};
  int num_minute[] = {32,16,8,4,2,1};
  memset(ans,false,sizeof ans);
  for(int i = 0; i < 4; i++) {
    if(hour >= num_hour[i]) {
      ans[i] = true;
      hour -= num_hour[i];
    }
  }
  for(int i = 0, a = 4; i < 6; i++, a++) {
    if(minute >= num_minute[i]) {
      ans[a] = true;
      minute -= num_minute[i];
    }
  }
}

void solve() {
  printf(" ____________________________________________\n");
  printf("|                                            |\n");
  printf("|    ____________________________________    |_\n");
  printf("|   |                                    |   |_)\n");
  printf("|   |   8         4         2         1  |   |\n");
  printf("|   |                                    |   |\n");

  printf("|   |   "); 
  printf("%c",word[ans[0]]);
  printf("         "); 
  printf("%c",word[ans[1]]);
  printf("         "); 
  printf("%c",word[ans[2]]);
  printf("         "); 
  printf("%c",word[ans[3]]);
  printf("  |   |\n");

  printf("|   |                                    |   |\n");
  printf("|   |                                    |   |\n");

  printf("|   |   "); 
  printf("%c",word[ans[4]]);
  printf("     "); 
  printf("%c",word[ans[5]]);
  printf("     "); 
  printf("%c",word[ans[6]]);
  printf("     "); 
  printf("%c",word[ans[7]]);
  printf("     "); 
  printf("%c",word[ans[8]]);
  printf("     "); 
  printf("%c",word[ans[9]]);
  printf("  |   |\n");

  printf("|   |                                    |   |\n");
  printf("|   |   32    16    8     4     2     1  |   |_\n");
  printf("|   |____________________________________|   |_)\n");
  printf("|                                            |\n");
  printf("|____________________________________________|\n");
  printf("\n");
}

int main() {
  while(scanf("%s",w) != EOF) {
    hour = atoi(w);
    minute = atoi(w+3);
    get_ans();
    solve();
  }
}
