#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int N;
int happy[MAXN][3];
int memo[MAXN][3];

int solve() {
    for(int k = 0; k < 3; k++)
        memo[1][k] = happy[1][k];
    
    for(int i = 2; i <= N; i++) {
        for(int k = 0; k < 3; k++) {
            int f, s;
            if(k == 0) f = 1, s = 2;
            if(k == 1) f = 0, s = 2;
            if(k == 2) f = 0, s = 1;

            memo[i][k] = max(memo[i-1][f], memo[i-1][s]) + happy[i][k];
        }
    }

    return max(memo[N][0], max(memo[N][1], memo[N][2]));
}

int main() {
    cin >> N;

    for(int i = 1; i <= N; i++) 
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];

    memset(memo, -1, sizeof(memo));

    cout << solve() << endl;

    return 0;
}