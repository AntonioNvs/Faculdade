#include <stdio.h>
#include <string.h>

int main()
{
  
  char name[100];
  
  scanf("%s", name);
  
  FILE *file = fopen(name, "rb");
    
    
  char txt[3000000];
  int count = 0;
  
  fread(&txt, sizeof(char), 3000000,file);
  
  for(int i = 0; txt[i] != '\0'; i++)
    if(txt[i] == 'a')
      count++;   
  
  fclose(file);
  
  printf("%d\n", count);
  
  return 0;
}