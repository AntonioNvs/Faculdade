#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    int v[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

    int ans = 0, idx = 13;
    while(T) {
        if(T >= v[idx])
            T -= v[idx], ans++;
        else
            idx--;
    }

    cout << ans << endl;
}