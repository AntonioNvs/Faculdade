#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;

const int INF = 0x3f3f3f3f;
int N, K;
int h[MAXN];
int memo[MAXN];

int dp(int x) {
	if(x == 0)
		return 0;
	
	if(memo[x] != -1) 
		return memo[x];

	int res = INF;
	for(int i = max(0, x-K); i < x; i++)
		res = min(res, dp(i) + abs(h[i] - h[x]));

	return memo[x] = res;
}

int main() {
	cin >> N >> K;

	memset(memo, -1, sizeof(memo));

	for(int i = 0; i < N; i++) cin >> h[i];

	cout << dp(N-1) << endl;
}
