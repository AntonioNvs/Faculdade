#include <stdio.h>
#include <stdlib.h>

void getn(char str[], int idx, char c) {
  if(str[idx] == '\0')
    return;

  if(str[idx] == c) {
    str[idx] = '.';
  }
  getn(str, idx+1, c);
}

int main() {
  char str[500];
  char c;

  scanf("%s %c", str, &c);
  getn(str, 0, c);
  
  for(int i = 0; str[i] != '\0'; i++)
    if(str[i] != '.')
      printf("%c", str[i]);
      
  printf("\n");
}