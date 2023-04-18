#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

typedef long long ll;

using namespace std;

int main() {
    ll N, X, maxi = -INF, sum = 0; cin >> N;

    vector<ll> stacks(N);

    for(auto &s : stacks) cin >> s;
    for(auto s : stacks) maxi = max(maxi, s), sum += s;

    cin >> X;

    if(X + sum >= N*maxi and (X+sum) % N == 0) cout << "Boa Sorte" << endl;
    else cout << "Sem Sorte" << endl;    
}