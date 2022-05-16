#include <stdio.h>

int sum(int n) {
    int s = 0;

    while(n > 0) {
        int dig = n % 10;
        s += dig;
        n /= 10;
    }

    return s;
}

int main() {
    int target, A, B, mini = 999999999, maxi = -1;

    scanf("%d %d %d", &target, &A, &B);

    for(int i = A; i <= B; i++) {
        if(sum(i) == target) {
            if(i < mini) {
                mini = i;
            }

            if(i > maxi) {
                maxi = i;
            }
        }
    }
    
    printf("%d\n%d\n", mini, maxi);
}