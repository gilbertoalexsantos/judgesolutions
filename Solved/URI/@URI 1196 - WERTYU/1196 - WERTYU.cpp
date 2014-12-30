#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 10000;

char word[MAX];

char map2(char c) {
 if(c == '1')
   return '`';
 else if(c == '2')
   return '1';
 else if(c == '3')
   return '2';
 else if(c == '4')
   return '3';
 else if(c == '5')
   return '4';
 else if(c == '6')
   return '5';
 else if(c == '7')
   return '6';
 else if(c == '8')
   return '7';
 else if(c == '9')
   return '8';
 else if(c == '0')
   return '9';
 else if(c == '-')
   return '0';
 else if(c == '=')
   return '-';
 else if(c == 'W')
   return 'Q';
 else if(c == 'E')
   return 'W';
 else if(c == 'R')
   return 'E';
 else if(c == 'T')
   return 'R';
 else if(c == 'Y')
   return 'T';
 else if(c == 'U')
   return 'Y';
 else if(c == 'I')
   return 'U';
 else if(c == 'O')
   return 'I';
 else if(c == 'P')
   return 'O';
 else if(c == '[')
   return 'P';
 else if(c == ']')
   return '[';
 else if(c == '\\')
   return ']';
 else if(c == 'S')
   return 'A';
 else if(c == 'D')
   return 'S';
 else if(c == 'F')
   return 'D';
 else if(c == 'G')
   return 'F';
 else if(c == 'H')
   return 'G';
 else if(c == 'J')
   return 'H';
 else if(c == 'K')
   return 'J';
 else if(c == 'L')
   return 'K';
 else if(c == ';')
   return 'L';
 else if(c == '\'')
   return ';';
 else if(c == 'X')
   return 'Z';
 else if(c == 'C')
   return 'X';
 else if(c == 'V')
   return 'C';
 else if(c == 'B')
   return 'V';
 else if(c == 'N')
   return 'B';
 else if(c == 'M')
   return 'N';
 else if(c == ',')
   return 'M';
 else if(c == '.')
   return ',';
 else if(c == '/')
  return '.';
 else
   return ' ';
}

int main() {
  while(fgets(word,MAX,stdin) && word[0] != '\n') {
    for(int i = 0; i < strlen(word)-1; i++) {
      if(word[i] == ' ')
        printf(" ");
      else
        printf("%c",map2(word[i]));
    }
    puts("");
  }
}
