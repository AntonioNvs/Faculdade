#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;

    vector<int> arr(N+1);

    arr[0] = 0;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    for(int i = 1; i <= N; i++) {
        if(min(arr[i], M-arr[i]) >= arr[i-1])
            arr[i] = min(arr[i], M-arr[i]);
        else if(max(arr[i], M-arr[i]) >= arr[i-1])
            arr[i] = max(arr[i], M-arr[i]);
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    long long sum = 0;
    for(int i = 1; i <= N; i++) sum += (long long)arr[i];

    cout << sum << endl;

}