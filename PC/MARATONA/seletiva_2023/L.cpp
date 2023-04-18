#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int N; cin >> N;

    vector<int> X(N+1);
    vector<int> Y(N+1);

    for(int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    vector<int> pX(N+1);
    vector<int> pY(N+1);

    vector<int> spX(N+1);
    vector<int> spY(N+1);


    pX[1] = X[1];
    pY[1] = Y[1];
    spX[1] = pow(X[1], 2);
    spY[1] = pow(Y[1], 2);

    for(int i = 2; i <= N; i++) {
        pX[i] = X[i] + pX[i-1];
        pY[i] = Y[i] + pY[i-1];
        spX[i] = pow(X[i], 2) + spX[i-1];
        spY[i] = pow(Y[i], 2) + spY[i-1];
    }

    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += (ll)((N-i)*pow(X[i], 2) - 2*X[i]*(pX[N] - pX[i]) + (spX[N] - spX[i]));
        ans += (ll)((N-i)*pow(Y[i], 2) - 2*Y[i]*(pY[N] - pY[i]) + (spY[N] - spY[i]));
    }

    cout << ans << endl;
}