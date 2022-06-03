
#include <stdio.h>

int primo(long long int n) {
    long long int i;
    for(i = 2; i*i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main() {
  long long int n;

  while(scanf("%lld", &n) != EOF) {
    if (n >= 2)
      printf("%d\n", primo(n));
    else
      printf("-1\n");
  }

  return 0;
}