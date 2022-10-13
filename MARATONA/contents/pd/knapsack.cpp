#include <bits/stdc++.h>
#define MAXN 110
#define MAXW 100100

typedef long long int ll;
using namespace std;

const ll LINF = 0x3f3f3f3f3f3f;

int N, W;
ll memo[MAXN][MAXW];
int v[MAXN], w[MAXN];

ll solve(int i, int cap) {
    if(i == N)
        return 0;

    if(memo[i][cap] != -1)
        return memo[i][cap];
    
    if(cap-w[i] < 0)
        return memo[i][cap] = solve(i+1, cap);
        
    return memo[i][cap] = max(solve(i+1, cap), solve(i+1, cap-w[i]) + v[i]);
}

int main() {
    cin >> N >> W;

    memset(memo, -1, sizeof(memo));

    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];

    cout << solve(0, W) << endl;
}