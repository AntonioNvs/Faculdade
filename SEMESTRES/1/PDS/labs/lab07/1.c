#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  
  char name[100];
  
  strcpy(name, argv[1]);
  
  FILE *file = fopen(name, "r");

  char txt[1200];
  
  int count = 0;
  
  while(fgets(txt, 1200, file) != NULL) {
      for(int i = 0; txt[i] != '\n'; i++) {
          if(txt[i] == 'a')
            count++;
      }
  }
  
  printf("%d\n", count);
  
  return 0;
}