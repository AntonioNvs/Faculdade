#include <stdio.h>

int main() {
    int T;

    scanf("%d", &T);

    while(T--) {
        int N;

        scanf("%d", &N);

        int values[N];

        for(int i = 0; i < N; i++)
            scanf("%d", &values[i]);

        int bf = values[0], ans = 0;

        for(int i = 1; i < N; i++) {
            if(values[i] == values[i+1])
                ans++;
        }

        printf("%d\n", ans-1);
    }

    return 0;
}