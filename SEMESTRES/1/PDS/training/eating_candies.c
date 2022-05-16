#include <stdio.h>

int main() {
    int T;

    scanf("%d", &T);

    while(T--) {
        int N;

        scanf("%d", &N);

        int candies[N], l = 0, r = N-1, maxi = 0, crr = 0, tl = 0, tr = 0;

        for(int i = 0; i < N; i++)
            scanf("%d", &candies[i]);

        while(l <= r) {
            if(tl == tr && l != r) {

                tl += candies[l++];
                tr += candies[r--];

                crr += 2;
            } else if(tl < tr) {
                tl += candies[l++];
                crr++;
            } else {
                tr += candies[r--];
                crr++;
            }
            if(tl == tr)
                maxi = crr;
        }

        printf("%d\n", maxi);
    }
    return 0;
}