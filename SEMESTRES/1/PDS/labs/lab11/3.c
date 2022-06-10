#include <stdio.h>
#include <stdlib.h>

int getn(char str[], int idx, char c) {
  if(str[idx] == '\0')
    return 0;

  if(str[idx] == c)
    return 1 + getn(str, idx+1, c);
  return getn(str, idx+1, c);
}

int main() {
  char str[500];
  char c;

  scanf("%s %c", str, &c);

  printf("%d", getn(str, 0, c));
}