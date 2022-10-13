#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N;
    cin >> T;

    while(T--) {
        cin >> N;
        int arr[N];

        if(N == 1) {
            cin >> arr[0];
            cout << "0" << endl;
            continue;
        }

        int mini = 1010;
        int maxi = -1;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        cout << maxi - mini << endl;
    }

    return 0;
}