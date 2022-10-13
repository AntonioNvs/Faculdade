#include <stdio.h>

int dp(int r) {
    if(r == 0)
        return 1;

    int count = 0;

    for(int i = 1; i <= r; i++) {
        count += dp(r-1);
    }

    return count;
}


int main() {
    int t, n;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        printf("%d\n", dp(n));
    }

    return 0;
}