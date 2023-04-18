#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll euclidian_distance(ll x, ll y) {
    return pow(x, 2) + pow(y, 2);
}

int main() {
    int C, T; cin >> C >> T;

    vector<ll> circles(C);

    for(int i = 0; i < circles.size(); i++) {
        cin >> circles[i];
        circles[i] *= circles[i];
    }

    ll ans = 0;
    while(T--) {
        ll x, y; cin >> x >> y;

        ll dist = euclidian_distance(x, y);
        ans += circles.end() - lower_bound(circles.begin(), circles.end(), dist);
    }

    cout << ans << endl;

    return 0;
}