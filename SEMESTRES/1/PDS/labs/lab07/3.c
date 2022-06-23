#include <stdio.h>
#include <string.h>

int main()
{
  
  char name[100];
  
  scanf("%s", name);
  
  FILE *file = fopen(name, "rb");
    
    
  long long int m[5][5];
  long long int n[5][5];
  
  int count = 0;
  
  for(int i = 0; i < 5; i++) 
      for(int j = 0; j < 5; j++) 
          fscanf(file, "%lld", &m[i][j]);
  for(int i = 0; i < 5; i++) 
      for(int j = 0; j < 5; j++) 
          fscanf(file, "%lld", &n[i][j]);
  
  for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
          printf("%lld ", m[i][j] + n[i][j]);
      }
      printf("\n");
  } 
  
  fclose(file);
  
  return 0;
}